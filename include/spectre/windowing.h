#ifndef __SPECTRE_PLATFORM_WINDOWING_H
#define __SPECTRE_PLATFORM_WINDOWING_H

#include <spectre/framebuffer.h>

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
    unsigned int 
} displayST;

void platformDisplayInit(char* windowName, unsigned int windowSizeX, unsigned int windowSizeY, float fRefreshRate);
void platformDisplayRename(char* windowName);
void platformDisplayResize(unsigned int windowSizeX, unsigned int windowSizeY);
void platformDisplayProject(unsigned int iPosX, unsigned int iPosY, unsigned int hColor);
void platformDisplayFrameBuffer(frameBuffer* fb);
void platformDisplayFullScreen(unsigned char bIsFullScreen);
void platformDisplayClear(void);
void platformDisplayUpdate(void);
void platformDisplayCleanup(void);

inputST   platformDisplayKeyInput(void)
displayST platformDisplayResolution(void)

#endif//__SPECTRE_PLATFORM_WINDOWING_H
