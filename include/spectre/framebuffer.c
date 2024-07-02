#include <spectre/framebuffer.h>

frameBuffer frameBufferInit(unsigned int iFrameBufferSizeX, unsigned int iFrameBufferSizeY)
{
    frameBuffer fb;
    fb.g_iFrameBufferWidth  = iFrameBufferSizeX;
    fb.g_iFrameBufferHeight = iFrameBufferSizeY;
    fb.g_iFrameBufferData   = (unsigned int*)malloc(iFrameBufferWidth * iFrameBufferHeight * sizeof(unsigned int));
    frameBufferClear(&fb, 0xFF000000);
    return fb;
}

void frameBufferClear(frameBuffer* fb, unsigned int hColorValue)
{
    for(unsigned int m_nCounterX = 0; m_nCounterX < fb->g_iFrameBufferWidth; ++m_nCounterX)
    {
        for(unsigned int m_nCounterY = 0; m_nCounterY < fb->g_iFrameBufferHeight; ++m_nCounterY)
        {
            fb->g_iFrameBufferData[m_nCounterY * fb->g_iFrameBufferWidth + m_nCounterX] = hColorValue;
        }
    }
}

void frameBufferDrawLine(frameBuffer* fb, Vector2i* iPointA, Vector2i* iPointB);
{
    //TODO: Draw Line Function For The Framebuffer...
    continue;
}

void frameBufferProject(frameBuffer* fb, unsigned int iPosX, unsigned int iPosY, unsigned int hColorValue)
{
    fb->g_iFrameBufferData[iPosY * fb->g_iFrameBufferWidth + iPosX] = hColorValue;
}

void franeBufferResize(frameBuffer* fb, unsigned int iFrameBufferTargetX, unsigned int iFrameBufferTargetY)
{
    fb.g_iFrameBufferWidth  = iFrameBufferTargetX;
    fb.g_iFrameBufferHeight = iFrameBufferTargetY;
    fb.g_iFrameBufferData   = (unsigned int*)realloc(fb.iFrameBufferData, iFrameBufferTargetX * iFrameBufferTargetY * sizeof(unsigned int));
}

void frameBufferCleanup(frameBuffer* fb)
{
    if(fb != NULL)
    {
        free(fb->g_iFrameBufferData);
        free(fb);
    }
}

//------------------------------------------------------------------------------------------------//
// Rylands Demonstration, He Is Upsessed With 720P Resolution Capped At 30 FPS, For Some Reason?  //
//                                                                                                //
// frameBuffer* mainDisplayFrameBuffer = frameBufferInit(1280, 720);                              //
//                                                                                                //
//------------------------------------------------------------------------------------------------//
