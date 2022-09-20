/**
 * Pool-allocator.
 *
 * Details: http://dmitrysoshnikov.com/compilers/writing-a-pool-allocator/
 *
 * Allocates a larger block using `malloc`.
 *
 * Splits the large block into smaller chunks
 * of equal size.
 *
 * Uses bump-allocated per chunk.
 *
 */

#include <iostream>

using std::cout;
using std::endl;

/**
 * A chunk within a larger block.
 */
struct Chunk {
    /**
     * When a chunk is free, the `next` contains the
     * address of the next chunk in a list.
     *
     * When it's allocated, this space is used by
     * the user.
     */
    Chunk* next;
};

/**
 * The allocator class.
 *
 * Features:
 *
 *   - Parametrized by number of chunks per block
 *   - Keeps track of the allocation pointer
 *   - Bump-allocates chunks
 *   - Requests a new larger block when needed
 *
 */
class PoolAllocator {
public:
    PoolAllocator(size_t chunksPerBlock) : mChunksPerBlock(chunksPerBlock) {}

    void* allocate(size_t size);
    void deallocate(void* ptr, size_t size);

private:
    /**
     * Number of chunks per larger block.
     */
    size_t mChunksPerBlock;

    /**
     * Allocation pointer.
     */
    Chunk* mAlloc = nullptr;

    /**
     * Allocates a larger block (pool) for chunks.
     */
    Chunk* allocateBlock(size_t chunkSize);
};

// -----------------------------------------------------------

/**
 * Allocates a new block from OS.
 *
 * Returns a Chunk pointer set to the beginning of the block.
 */
Chunk* PoolAllocator::allocateBlock(size_t chunkSize) {
    cout << "\nAllocating block (" << mChunksPerBlock << " chunks):\n\n";

    size_t blockSize = mChunksPerBlock * chunkSize;

    // The first chunk of the new block.
    Chunk* blockBegin = reinterpret_cast<Chunk*>(malloc(blockSize));

    // Once the block is allocated, we need to chain all
    // the chunks in this block:

    Chunk* chunk = blockBegin;

    for (int i = 0; i < mChunksPerBlock - 1; ++i) {
        chunk->next =
            reinterpret_cast<Chunk*>(reinterpret_cast<char*>(chunk) + chunkSize);
        chunk = chunk->next;
    }

    chunk->next = nullptr;

    return blockBegin;
}

/**
 * Returns the first free chunk in the block.
 *
 * If there are no chunks left in the block,
 * allocates a new block.
 */
void* PoolAllocator::allocate(size_t size) {

    // No chunks left in the current block, or no any block
    // exists yet. Allocate a new one, passing the chunk size:

    if (mAlloc == nullptr) {
        mAlloc = allocateBlock(size);
    }

    // The return value is the current position of
    // the allocation pointer:

    Chunk* freeChunk = mAlloc;

    // Advance (bump) the allocation pointer to the next chunk.
    //
    // When no chunks left, the `mAlloc` will be set to `nullptr`, and
    // this will cause allocation of a new block on the next request:

    mAlloc = mAlloc->next;

    return freeChunk;
}

/**
 * Puts the chunk into the front of the chunks list.
 */
void PoolAllocator::deallocate(void* chunk, size_t size) {

    // The freed chunk's next pointer points to the
    // current allocation pointer:

    reinterpret_cast<Chunk*>(chunk)->next = mAlloc;

    // And the allocation pointer is moved backwards, and
    // is set to the returned (now free) chunk:

    mAlloc = reinterpret_cast<Chunk*>(chunk);
}

// -----------------------------------------------------------

/**
 * The `Object` structure uses custom allocator,
 * overloading `new`, and `delete` operators.
 */
struct Object {

    // Object data, 16 bytes:

    uint64_t data[2];

    // Declare out custom allocator for
    // the `Object` structure:

    static PoolAllocator allocator;

    static void* operator new(size_t size) {
        return allocator.allocate(size);
    }

    static void operator delete(void* ptr, size_t size) {
        return allocator.deallocate(ptr, size);
    }
};

// Instantiate our allocator, using 8 chunks per block:

PoolAllocator Object::allocator{ 8 };

int main(int argc, char const* argv[]) {

    // Allocate 10 pointers to our `Object` instances:

    constexpr int arraySize = 10;

    Object* objects[arraySize];

    // Two `uint64_t`, 16 bytes.
    cout << "size(Object) = " << sizeof(Object) << endl << endl;

    // Allocate 10 objects. This causes allocating two larger,
    // blocks since we store only 8 chunks per block:

    cout << "About to allocate " << arraySize << " objects" << endl;

    for (int i = 0; i < arraySize; ++i) {
        objects[i] = new Object();
        cout << "new [" << i << "] = " << objects[i] << endl;
    }

    cout << endl;

    // Deallocate all the objects:

    for (int i = arraySize - 1; i >= 0; --i) {
        cout << "delete [" << i << "] = " << objects[i] << endl;
        delete objects[i];
    }

    cout << endl;

    // New object reuses previous block:

    objects[0] = new Object();
    cout << "new [0] = " << objects[0] << endl << endl;
}