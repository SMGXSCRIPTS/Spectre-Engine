#include <spectre/framebuffer.h>

frameBuffer_t* frameBufferInit(const char* cFrameBufferType, unsigned int iFrameBufferSizeX, unsigned int iFrameBufferSizeY, unsigned char bIsGlobal)
{
    frameBuffer_t* fb;
    fb->m_iFrameBufferWidth     = iFrameBufferSizeX;
    fb->m_iFrameBufferHeight    = iFrameBufferSizeY;
    fb->m_hFrameBufferColorData = (unsigned int*)malloc(iFrameBufferWidth * iFrameBufferHeight * sizeof(unsigned int));
    fb->g_bIsGlobalAccess       = bIsGlobal;
    fb->g_cFrameBufferType      = cFrameBufferType;
    frameBufferClear(&fb, 0xFF000000);
    return fb;
}

void frameBufferClear(frameBuffer_t* fb, unsigned int hColorValue)
{
    unsigned int m_iTotalFrameBufferPixels = (fb->m_iFrameBufferWidth * fb->m_iFrameBufferHeight);
    for(unsigned int m_nCounter = 0; m_nCounter < m_iTotalFrameBufferPixels; ++m_nCounter)
    {
        m_hFrameBufferColorData[m_nCounter] = hColorValue;
    }
}

void frameBufferDrawLine(frameBuffer_t* fb, Vector2i* iPointA, Vector2i* iPointB, unsigned int hColorValue);
{
    int m_iTempX1 =  abs(iPointB->m_iPosX - iPointA->m_iPosX);
    int m_iTempX2 =  iPointA->m_iPosX < iPointB->m_iPosX ? 1 : -1;
    int m_iTempY1 = -abs(iPointB->m_iPosY - iPointA->m_iPosY);
    int m_iTempY2 =  iPointA->m_iPosY < iPointB->m_iPosY ? 1 : -1;
    int m_iERR    =  m_iTempX1 + m_iTempY1;
    int m_iE;
    
    while(1)
    {
        frameBufferProject(&fb, iPointA->m_iPosX, iPointA->m_iPosY, hColorValue);
        if(iPointA->m_iPosX == iPointB->m_iPosX && iPointA->m_iPosY == iPointB->m_iPosY)
        {
            break;
        }
        m_iE = 2 * m_iERR;
        if(m_iE <= m_iTempX1)
        {
            m_iERR += m_iTempX1;
            iPointA->m_iPosX += m_iTempY2;
        }
        if(m_iE >= m_iTempY1)
        {
            m_iERR += m_iTempY1;
            iPointA->m_iPosY += m_iTempY2;
        }
    }
}

void frameBufferProject(frameBuffer_t* fb, unsigned int iPosX, unsigned int iPosY, unsigned int hColorValue)
{
    fb->m_hFrameBufferColorData[iPosY * fb->m_iFrameBufferWidth + iPosX] = hColorValue;
}

void franeBufferResize(frameBuffer_t* fb, unsigned int iFrameBufferTargetX, unsigned int iFrameBufferTargetY)
{
    fb->m_iFrameBufferWidth     = iFrameBufferTargetX;
    fb->m_iFrameBufferHeight    = iFrameBufferTargetY;
    fb->m_hFrameBufferColorData = (unsigned int*)realloc(fb->iFrameBufferData, iFrameBufferTargetX * iFrameBufferTargetY * sizeof(unsigned int));
}

void frameBufferCleanup(frameBuffer_t* fb)
{
    if(fb != NULL)
    {
        free(fb->m_hFrameBufferColorData);
        free(fb);
    }
}

//------------------------------------------------------------------------------------------------//
// Rylands Demonstration, He Is Upsessed With 720P Resolution Capped At 30 FPS, For Some Reason?  //
//                                                                                                //
// frameBuffer* mainDisplayFrameBuffer = frameBufferInit("#ScreenSpace_Buffer", 1280, 720, 1);    //
//                                                                                                //
//------------------------------------------------------------------------------------------------//
