#ifndef __SPECTRE_PLATFORM_WINDOWING_H
#define __SPECTRE_PLATFORM_WINDOWING_H

#pragma once

#include <spectre/framebuffer.h>

#ifdef __WIN32 || __WIN64
    #include <windows.h>
#elif __linux__ || __APPLE__
    #include <unistd.h>
#else
    #error "ERROR! Spectre Does Not Support This Platform!"
#endif

typedef struct {
    double m_fPosX;
    double m_fPosY;
    double m_fPosZ;
} Vector3f;

typedef struct {
    float g_fMousePosX;
    float g_fMousePosY;
    float g_fMouseAccelerationX;
    float g_fMouseAccelerationY;
    char* g_cKeyboardBufferInput;
} inputST;

typedef struct {
    unsigned int g_iScreenResolutionX;
    unsigned int g_iScreenResolutionY;
    float        g_fScreenRefreshRate;
} displayST;

void platformDisplayInit(char* windowName, unsigned int windowSizeX, unsigned int windowSizeY);
void platformDisplayRename(char* windowName);
void platformDisplayResize(unsigned int windowSizeX, unsigned int windowSizeY);
void platformDisplayProject(unsigned int iPosX, unsigned int iPosY, unsigned int hColor);
void platformDisplayFrameBuffer(frameBuffer* fb);
void platformDisplayFullScreen(unsigned char bIsFullScreen);
void platformDisplayClear(void);
void platformDisplayUpdate(void);
void platformDisplayCleanup(void);

inputST   platformDisplayKeyInput(void);
displayST platformDisplayResolution(void);

inline void platformDisplayFrameCap(const float fRefreshRate, const double deltaTime)
{
    unsigned int m_iTargetFpsMs = (unsigned int)(1000.0f / fRefreshRate);
    if(!(deltaTime >= m_iTargetFpsMs))
    {
        #ifdef __WIN32 || __WIN64
            Sleep((m_iTargetFpsMs - (deltaTime * 1000) / 1000 - 4));
        #elif __linux__ || __APPLE__
            usleep((m_iTargetFpsMs - (deltaTime * 1000) - 4000));
        #endif
    }
}

#endif//__SPECTRE_PLATFORM_WINDOWING_H
