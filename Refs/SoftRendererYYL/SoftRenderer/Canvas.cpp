#include"Canvas.h"

Canvas::Canvas(int w, int h, void *fb)
{
	int need = w * h * 8 + sizeof(void*)*(h * 2);
	char *ptr = (char*)malloc(need);
	char *framebuf,*zbuf;
	assert(ptr);
	// Allocate index memeory
	// The line number index of frame buffer
	frameBuffer = (UINT32 **)ptr;
	// The line number index of z buffer
	ptr += sizeof(void*) * h;

	// Allocate buffer memory
	framebuf = (char*)ptr;
	ptr += w * h * 4;

	if (fb != nullptr) framebuf = (char*)fb;
	for (int j = 0; j < h; ++j)
	{
		frameBuffer[j] = (UINT32 *)(framebuf + w * 4 * j);
	}

	zBuffer = (float **)(ptr);
	ptr += sizeof(void*) * h;
	zbuf = (char*)ptr;
	ptr += w * h * 4;
	for (int j = 0; j < h; ++j)
	{
		zBuffer[j] = (float *)(zbuf + w * 4 * j);
	}

	width = w;
	height = h;
}

Canvas::~Canvas()
{
	if (frameBuffer)
		free(frameBuffer);
	frameBuffer = nullptr;
	zBuffer = nullptr;
}

void Canvas::ClearFrameBuffer(void *fb)
{
	// memset is more faster
	int buffer_size = width * height * 4;
	char *ptr = (char*)fb;
	memset(ptr, 0, buffer_size);
	/*int y, x;
	// Clear frame buffer
	for (y = 0; y < height; ++y)
	{
		UINT32 *dst = frameBuffer[y];
		for (x = width; x > 0; ++dst, --x)
			dst[0] = 0;
	}*/
}

void Canvas::ClearZBuffer()
{
	int y, x;
	for (y = 0; y < height; ++y)
	{
		float *dst = zBuffer[y];
		for (x = width; x > 0; ++dst, --x)
			dst[0] = 1.0f;
	}
}

