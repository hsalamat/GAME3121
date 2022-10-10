//http://dmitrysoshnikov.com/compilers/writing-a-memory-allocator/

#include <cstdint>
#include <iostream>
#include <assert.h>

using namespace std;
/**
 * Machine word size. Depending on the architecture,
 * can be 4 or 8 bytes.
 */
using word_t = intptr_t;

/**
 * Allocated block of memory. Contains the object header structure,
 * and the actual payload pointer.
 */
struct Block {

	// -------------------------------------
	// 1. Object header

	/**
	 * Block size.
	 */
	size_t size;

	/**
	 * Whether this block is currently used.
	 */
	bool used;

	/**
	 * Next block in the list.
	 */
	Block* next;

	// -------------------------------------
	// 2. User data

	/**
	 * Payload pointer. The data field points to the first word of the returning to a user value.
	 */
	word_t data[1];

};

/**
 * Heap start. Initialized on first allocation.
 */
static Block* heapStart = nullptr;

/**
 * Current top. Updated on each allocation.
 */
static auto top = heapStart;

//when allocating a memory, we don’t make any commitment about the logical layout of the objects, and instead work with the size of the block.

/**
* Allocates a block of memory of (at least) `size` bytes.
*/
/**
 * Allocates a block of memory of (at least) `size` bytes.
 */
word_t* alloc(size_t size) {
	size = align(size);

	// ---------------------------------------------------------
	// 1. Search for an available free block:

	if (auto block = findBlock(size)) {                   // (1)
		return block->data;
	}

	// ---------------------------------------------------------
	// 2. If block not found in the free list, request from OS:

	auto block = requestFromOS(size);

	block->size = size;
	block->used = true;

	// Init heap.
	if (heapStart == nullptr) {
		heapStart = block;
	}

	// Chain the blocks.
	if (top != nullptr) {
		top->next = block;
	}

	top = block;

	// User payload:
	return block->data;
}

/**
 * Returns the object header.
 */
Block* getHeader(word_t* data) {
	return (Block*)((char*)data + sizeof(std::declval<Block>().data) -
		sizeof(Block));
}

/**
 * Aligns the size by the machine word.
 */
inline size_t align(size_t n) {
	return (n + sizeof(word_t) - 1) & ~(sizeof(word_t) - 1);
}

/**
 * Frees a previously allocated block.
 */
void free(word_t* data) {
	auto block = getHeader(data);
	block->used = false;
}

void main()
{


	//// Assuming x64 architecture:
	cout << align(3) << endl;  //  8
	cout << align(8) << endl;  //  8
	cout << align(12) << endl; // 16
	cout <<  align(16) << endl; // 16

	// --------------------------------------
  // Test case 1: Alignment
  //
  // A request for 3 bytes is aligned to 8.
  //

	auto p1 = alloc(3);                        // (1)
	auto p1b = getHeader(p1);
	assert(p1b->size == sizeof(word_t));

	// --------------------------------------
	// Test case 2: Exact amount of aligned bytes
	//

	auto p2 = alloc(8);                        // (2)
	auto p2b = getHeader(p2);
	assert(p2b->size == 8);

	// --------------------------------------
// Test case 3: Free the object
//

	free(p2);
	assert(p2b->used == false);

		puts("\nAll assertions passed!\n");



}