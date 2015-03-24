// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                     MACROS - WinAPI and OpenGL laboratory                   \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef MACROS_H
#define MACROS_H

// DEFINES /////////////////////////////////////////////////////////////////////

// Colours
#define COLOUR_WHITE      1.0f, 1.0f, 1.0f
#define COLOUR_BLACK      0.0f, 0.0f, 0.0f
#define COLOUR_BROWN      0.27f, 0.27f, 0.27f
#define COLOUR_DRKBROWN   0.17f, 0.17f, 0.17f
#define COLOUR_GREEN      0.0f, 0.27f, 0.1f


// GUI.CPP ---------------------------------------------------------------------
#define TEXTURE_WIDTH       256.0f

// Ribbon Coordinates
#define RIB_ORIGIN_X        46.0f
#define RIB_ORIGIN_Y        32.0f
#define RIB_HEIGHT          46.0f
#define RIB_LR_WIDTH        8.0f
#define RIB_M_WIDTH         (windowWidth - (2*RIB_LR_WIDTH) - RIB_ORIGIN_X)
#define RIB_M_X             (RIB_ORIGIN_X + RIB_LR_WIDTH)
#define RIB_R_X             (windowWidth - RIB_LR_WIDTH)

// Ribbon UVs
#define RIB_UV_Y            0.0f
#define RIB_UV_H            (46.0f / TEXTURE_WIDTH)
#define RIB_LR_UV_W         (8.0f / TEXTURE_WIDTH)

#define RIB_L_UV_X          0.0f
#define RIB_M_UV_X          (8.0f / TEXTURE_WIDTH)
#define RIB_M_UV_W          (30.0f / TEXTURE_WIDTH)
#define RIB_R_UV_X          (38.0f / TEXTURE_WIDTH)













// -----------------------------------------------------------------------------



#endif // MACROS_H




// 80 //////////////////////////////////////////////////////////////////////////