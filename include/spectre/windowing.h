#ifndef __SPECTRE_PLATFORM_WINDOWING_H
#define __SPECTRE_PLATFORM_WINDOWING_H

#include <spectre/framebuffer.h>

#ifdef __WIN32 || __WIN64
    #include <windows.h>
#elif __linux__ || __APPLE__
    #include <unistd.h>
#else
    #error "ERROR! Spectre Does Not Support This Platform!"
#endif

typedef struct {
    unsigned int m_iPosX;
    unsigned int m_iPosY;
} Vector2i;

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
void platformDisplayDrawLine(frameBuffer* fb, Vector2i* fPosA, Vector2i* fPosB);
void platformDisplayClear(void);
void platformDisplayUpdate(void);
void platformDisplayCleanup(void);

inputST   platformDisplayKeyInput(void);
displayST platformDisplayResolution(void);

void platformDisplayFrameCap(const float fRefreshRate, const double deltaTime)
{
    unsigned int m_fTargetFpsMs = (unsigned int)(1000.0f / fRefreshRate);
    if(!(deltaTime >= m_fTargetFpsMs))
    {
        #ifdef __WIN32 || __WIN64
            Sleep((m_fTargetFpsMs - (deltaTime * 1000) / 1000 - 0.005));
        #elif __linux__ || __APPLE__
            usleep((m_fTargetFpsMs - (deltaTime * 1000) - 0.005));
        #endif
    }
}

#endif//__SPECTRE_PLATFORM_WINDOWING_H
