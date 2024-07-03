#include <spectre/framebuffer.h>

frameBuffer_t* frameBufferInit(unsigned int iFrameBufferSizeX, unsigned int iFrameBufferSizeY)
{
    frameBuffer* fb;
    fb->g_iFrameBufferWidth  = iFrameBufferSizeX;
    fb->g_iFrameBufferHeight = iFrameBufferSizeY;
    fb->g_iFrameBufferData   = (unsigned int*)malloc(iFrameBufferWidth * iFrameBufferHeight * sizeof(unsigned int));
    frameBufferClear(&fb, 0xFF000000);
    return fb;
}

void frameBufferClear(frameBuffer_t* fb, unsigned int hColorValue)
{
    for(unsigned int m_nCounterX = 0; m_nCounterX < fb->g_iFrameBufferWidth; ++m_nCounterX)
    {
        for(unsigned int m_nCounterY = 0; m_nCounterY < fb->g_iFrameBufferHeight; ++m_nCounterY)
        {
            fb->g_iFrameBufferData[m_nCounterY * fb->g_iFrameBufferWidth + m_nCounterX] = hColorValue;
        }
    }
}

void frameBufferDrawLine(frameBuffer_t* fb, Vector2i iPointA, Vector2i iPointB);
{
    int m_iTempX1 =  abs(iPointB.m_iPosX - iPointA.m_iPosX);
    int m_iTempX2 =  iPointA.m_iPosX < iPointB.m_iPosX ? 1 : -1;
    int m_iTempY1 = -abs(iPointB.m_iPosY - iPointA.m_iPosY);
    int m_iTempY2 =  iPointA.m_iPosY < iPointB.m_iPosY ? 1 : -1;
    int m_iERR = m_iTempX1 + m_iTempY1;
    int m_iE;
    
    unsigned char m_bIsRunning = 1;
    
    while(m_bIsRunning == 1)
    {
        frameBufferProject
        if(iPointA.m_iPosX == iPointB.m_iPosX && iPointA.m_iPosY == iPointB.m_iPosY)
        {
            break;
        }
        m_iE = 2 * m_iERR;
        if(m_iE <= m_iTempX1)
        {
            m_iERR += m_iTempX1;
            iPointA.m_iPosX += m_iTempY2;
        }
        if(m_iE >= m_iTempY1)
        {
            m_iERR += m_iTempY1;
            iPointA.m_iPosY += m_iTempY2;
        }
    }
}

void frameBufferProject(frameBuffer_t* fb, unsigned int iPosX, unsigned int iPosY, unsigned int hColorValue)
{
    fb->g_iFrameBufferData[iPosY * fb->g_iFrameBufferWidth + iPosX] = hColorValue;
}

void franeBufferResize(frameBuffer_t* fb, unsigned int iFrameBufferTargetX, unsigned int iFrameBufferTargetY)
{
    fb->g_iFrameBufferWidth  = iFrameBufferTargetX;
    fb->g_iFrameBufferHeight = iFrameBufferTargetY;
    fb->g_iFrameBufferData   = (unsigned int*)realloc(fb.iFrameBufferData, iFrameBufferTargetX * iFrameBufferTargetY * sizeof(unsigned int));
}

void frameBufferCleanup(frameBuffer_t* fb)
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
