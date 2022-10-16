//this program is just a pseudocode!

AsyncRequestHandle g_hRequest; // async I/O request handle
typedef char U8;
U8 g_asyncBuffer[512]; // input buffer
static void asyncReadComplete(AsyncRequestHandle hRequest);
void main(int argc, const char* argv[])
{
	// NOTE: This call to asyncOpen() might itself be an
	// asynchronous call, but we'll ignore that detail
	// here and just assume it's a blocking function.
	AsyncFileHandle hFile = asyncOpen(
		"C:\\Windows\\System32\\d3dx10.dll");
	if (hFile)
	{
		// This function requests an I/O read, then
		// returns immediately (non-blocking).
		g_hRequest = asyncReadFile(
			hFile, // file handle
			g_asyncBuffer, // input buffer
			sizeof(g_asyncBuffer), // size of buffer
			asyncReadComplete); // callback function
	}
	// Now go on our merry way...
	// (This loop simulates doing real work while we wait
	// for the I/O read to complete.)
	for (;;)
	{
		OutputDebugString("zzz...\n");
		Sleep(50);
	}
}
// This function will be called when the data has been read.
static void asyncReadComplete(AsyncRequestHandle hRequest)
{
	if (hRequest == g_hRequest
		&& asyncWasSuccessful(hRequest))
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