#ifndef __SPECTRE_PLATFORM_WINDOWING_H
#define __SPECTRE_PLATFORM_WINDOWING_H

#pragma once

#include <spectre/framebuffer.h>

#if defined(_WIN32) || defined(_WIN64) || defined(__MINGW32__) || defined(__MINGW64__)
    #include <windows.h>
#elif defined(__linux__) || defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun) || defined(__SVR4) || defined(__AIX__) || defined(__hpux) || defined(__sgi) || defined(__minix__) || defined(__DragonFly__) || defined(__HAIKU__) || defined(__GNU__) || defined(__CYGWIN__) || defined(__QNX__) || defined(__BEOS__) || defined(M_UNIX) || defined(__USLC__) || defined(__amigaos__) || defined(__NeXT__) || defined(__bsdi__) || defined(__SYSV__)
    #include <unistd.h>
#elif defined(__SMGX_PRT7274_ElysuimOS__)
    #include <sleepthread.h>
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
} input_t;

typedef struct {
    unsigned int m_iScreenResolutionX;
    unsigned int m_iScreenResolutionY;
    float        m_fScreenRefreshRate;
} display_t;

typedef struct {
    unsigned int g_iWindowSizeX;
    unsigned int g_iWindowSizeY;
} window_t;

void platformDisplayInit(const char* windowName, unsigned int windowSizeX, unsigned int windowSizeY);
void platformDisplayRename(const char* windowName);
void platformDisplayResize(unsigned int windowSizeX, unsigned int windowSizeY);
void platformDisplayFrameBuffer(frameBuffer* fb);
void platformDisplayFullScreen(unsigned char bIsFullScreen);
void platformDisplayClear(void);
void platformDisplayUpdate(void);
void platformDisplayCleanup(void);

input_t   platformDisplayKeyInput(void);
window_t  platformDisplayGetWindowRes(void);
display_t platformDisplayResolution(void);
Vector2i  platformDisplayCalculateMouseVelocity(Vector2i lastPosition, Vector2i currentPosition)

inline void platformDisplayFrameCap(const float fRefreshRate, const double deltaTime)
{
    unsigned int m_iTargetFpsMs = (unsigned int)(1000.0f / fRefreshRate);
    if(!(deltaTime >= m_iTargetFpsMs))
    {
        #if defined(_WIN32) || defined(_WIN64) || defined(__MINGW32__) || defined(__MINGW64__)
            Sleep((m_iTargetFpsMs - (deltaTime * 1000) / 1000 - 4));
        #elif defined(__linux__) || defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun) || defined(__SVR4) || defined(__AIX__) || defined(__hpux) || defined(__sgi) || defined(__minix__) || defined(__DragonFly__) || defined(__HAIKU__) || defined(__GNU__) || defined(__CYGWIN__) || defined(__QNX__) || defined(__BEOS__) || defined(M_UNIX) || defined(__USLC__) || defined(__amigaos__) || defined(__NeXT__) || defined(__bsdi__) || defined(__SYSV__)
            usleep((m_iTargetFpsMs - (deltaTime * 1000) - 4000));
        #elif defined(__SMGX_PRT7274_ElysiumOS__)
            threadSleep((m_iTargetFpsMs - (deltaTime * 1000) / 1000 - 4));
        #endif
    }
}

#endif//__SPECTRE_PLATFORM_WINDOWING_H
