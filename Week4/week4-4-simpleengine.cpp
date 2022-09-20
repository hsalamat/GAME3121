//the simplest “brute-force” approach is to defin explicit start - up and shut - down functions for each singleton manager class.
//These functions take the place of the constructor and destructor, and in fact
//we should arrange for the constructor and destructor to do absolutely nothing.
//That way, the start - up and shut - down functions can be explicitly called in the
//required order from within main() (or from some overarching singleton object that manages the engine as a whole).
//
//Hooman Salamat

class RenderManager
{
public:
	RenderManager()
	{
		// do nothing
	}
	~RenderManager()
	{
		// do nothing
	}
	void startUp()
	{
		// start up the manager...
	}
	void shutDown()
	{
		// shut down the manager...
	}
	// ...
};
class PhysicsManager 
{
public:
	PhysicsManager()
	{
		// do nothing
	}
	~PhysicsManager()
	{
		// do nothing
	}
	void startUp()
	{
		// start up the manager...
	}
	void shutDown()
	{
		// shut down the manager...
	}
	// ...
};
class AnimationManager 
{
public:
	AnimationManager()
	{
		// do nothing
	}
	~AnimationManager()
	{
		// do nothing
	}
	void startUp()
	{
		// start up the manager...
	}
	void shutDown()
	{
		// shut down the manager...
	}
	// ...
};
class MemoryManager 
{
public:
	MemoryManager()
	{
		// do nothing
	}
	~MemoryManager()
	{
		// do nothing
	}
	void startUp()
	{
		// start up the manager...
	}
	void shutDown()
	{
		// shut down the manager...
	}
	// ...
};

class FileSystemManager 
{
public:
	FileSystemManager()
	{
		// do nothing
	}
	~FileSystemManager()
	{
		// do nothing
	}
	void startUp()
	{
		// start up the manager...
	}
	void shutDown()
	{
		// shut down the manager...
	}
	// ...
};

class TextureManager
{
public:
	TextureManager()
	{
		// do nothing
	}
	~TextureManager()
	{
		// do nothing
	}
	void startUp()
	{
		// start up the manager...
	}
	void shutDown()
	{
		// shut down the manager...
	}
	// ...
};


class VideoManager
{
public:
	VideoManager()
	{
		// do nothing
	}
	~VideoManager()
	{
		// do nothing
	}
	void startUp()
	{
		// start up the manager...
	}
	void shutDown()
	{
		// shut down the manager...
	}
	// ...
};

class SimulationManager
{
public:
	SimulationManager()
	{
		//do nothing
	}
	~SimulationManager()
	{
		//do nothing
	}
	void run()
	{
		// run the manager...
	}

};
// ...
RenderManager gRenderManager;
PhysicsManager gPhysicsManager;
AnimationManager gAnimationManager;
TextureManager gTextureManager;
VideoManager gVideoManager;
MemoryManager gMemoryManager;
FileSystemManager gFileSystemManager;
SimulationManager gSimulationManager;
// ...
int main(int argc, const char* argv)
{
	// Start up engine systems in the correct order.
	gMemoryManager.startUp();
	gFileSystemManager.startUp();
	gVideoManager.startUp();
	gTextureManager.startUp();
	gRenderManager.startUp();
	gAnimationManager.startUp();
	gPhysicsManager.startUp();
	// ...
	// Run the game.
	gSimulationManager.run();
	// Shut everything down, in reverse order.
	// ...
	gPhysicsManager.shutDown();
	gAnimationManager.shutDown();
	gRenderManager.shutDown();
	gFileSystemManager.shutDown();
	gMemoryManager.shutDown();
	return 0;
}