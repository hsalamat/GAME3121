////this program is just a pseudocode!

U8 g_asyncBuffer[512]; // input buffer
void main(int argc, const char* argv[])
{
	AsyncRequestHandle hRequest = ASYNC_INVALID_HANDLE;
	AsyncFileHandle hFile = asyncOpen(
		"C:\\testfile.bin");
	if (hFile)
	{
		// This function requests an I/O read, then
		// returns immediately (non-blocking).
		hRequest = asyncReadFile(
			hFile, // file handle
			g_asyncBuffer, // input buffer
			sizeof(g_asyncBuffer), // size of buffer
			nullptr); // no callback
	}
	// Now do some limited amount of work...
	for (int i = 0; i < 10; i++)
	{
		OutputDebugString("zzz...\n");
		Sleep(50);
	}
	// We can't do anything further until we have that
	// data, so wait for it here.
	asyncWait(hRequest);
	if (asyncWasSuccessful(hRequest))
	{
		// The data is now present in g_asyncBuffer[] and
		// can be used. Query for the number of bytes
		// actually read:
		size_t bytes = asyncGetBytesReadOrWritten(
			hRequest);
		char msg[256];
		snprintf(msg, sizeof(msg),
			"async success, read %u bytes\n",
			bytes);
		OutputDebugString(msg);
	}
}