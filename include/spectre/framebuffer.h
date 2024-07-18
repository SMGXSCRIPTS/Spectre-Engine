#ifndef __SPECTRE_FRAMEBUFFER_H
#define __SPECTRE_FRAMEBUFFER_H

#pragma once

#include <stdlib.h>

typedef struct {
    unsigned int m_iPosX;
    unsigned int m_iPosY;
} Vector2i;

typedef struct {
    const char*   g_cFrameBufferType;
    unsigned char g_bIsGlobalAccess : 1;
    unsigned int  m_iFrameBufferWidth;
    unsigned int  m_iFrameBufferHeight;
    unsigned int* m_hFrameBufferColorData;
} frameBuffer_t;

frameBuffer* frameBufferInit(const char* cFrameBufferType, unsigned int iFrameBufferSizeX, unsigned int iFrameBufferSizeY, unsigned char bIsGlobal);

void frameBufferClear(frameBuffer_t* fb, unsigned int hColorValue);
void frameBufferDrawLine(frameBuffer_t* fb, Vector2i iPointA, Vector2i iPointB, unsigned int hColorValue);
void frameBufferProject(frameBuffer_t* fb, unsigned int iPosX, unsigned int iPosY, unsigned int hColorValue);
void franeBufferResize(frameBuffer_t* fb, unsigned int iFrameBufferTargetX, unsigned int iFrameBufferTargetY);
void frameBufferCleanup(frameBuffer_t* fb);

#endif//__SPECTRE_FRAMEBUFFER_H
