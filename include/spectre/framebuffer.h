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
} frameBuffer;

frameBuffer frameBufferInit(unsigned short iFrameBufferSizeX, unsigned short iFrameBufferSizeY);

void frameBufferClear(unsigned int hColorValue);
void frameBufferDrawLine(frameBuffer* fb, Vector2i iPointA, Vector2i iPointB);
void frameBufferProject(unsigned int iPosX, unsigned int iPosY, unsigned int hColorValue);
void franeBufferResize(frameBuffer* fb, unsigned int iFrameBufferTargetX, unsigned int iFrameBufferTargetY);
void frameBufferCleanup(frameBuffer* fb);

#endif//__SPECTRE_FRAMEBUFFER_H
