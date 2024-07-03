#ifndef __SPECTRE_FRAMEBUFFER_H
#define __SPECTRE_FRAMEBUFFER_H

#pragma once

#include <stdlib.h>

typedef struct {
    unsigned int m_iPosX;
    unsigned int m_iPosY;
} Vector2i;

typedef struct {
    unsigned int g_iFrameBufferWidth;
    unsigned int g_iFrameBufferHeight;
    unsigned int* g_iFrameBufferData;
} frameBuffer_t;

frameBuffer* frameBufferInit(unsigned int iFrameBufferSizeX, unsigned int iFrameBufferSizeY);

void frameBufferClear(frameBuffer_t* fb, unsigned int hColorValue);
void frameBufferDrawLine(frameBuffer_t* fb, Vector2i iPointA, Vector2i iPointB);
void frameBufferProject(frameBuffer_t* fb, unsigned int iPosX, unsigned int iPosY, unsigned int hColorValue);
void franeBufferResize(frameBuffer_t* fb, unsigned int iFrameBufferTargetX, unsigned int iFrameBufferTargetY);
void frameBufferCleanup(frameBuffer_t* fb);

#endif//__SPECTRE_FRAMEBUFFER_H
