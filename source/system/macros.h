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
#define COLOUR_DRKGRAY    0.2f, 0.2f, 0.2f
#define COLOUR_YELLOW     1.0f, 0.8f, 0.0f
#define COLOUR_DRKYELLOW  0.49f, 0.41f, 0.17f

// MAIN ------------------------------------------------------------------------
#define WIN_MIN_WIDTH     500     
#define WIN_MIN_HEIGHT    500


// SCENE3D ---------------------------------------------------------------------
#define VIEW_XPOS         46.0f
#define VIEW_YPOS         46.0f

#define VIEW_XOFFSET      (VIEW_XPOS + 4.0f)
#define VIEW_YOFFSET      (VIEW_YPOS + 4.0f)

// VIEWPORT / VIEWMANAGER ------------------------------------------------------
#define Z_POSITION        0.0f

// Background
#define GRADIENT_TOP      0.533f, 0.615f, 0.698f
#define GRADIENT_BOTTOM   0.07f, 0.07f, 0.07f

// Label offsets
#define PERSP_OFFSET      ( (float)(width >> 1) - 15.0f)
#define TOP_OFFSET        ( (float)(width >> 1) - 11.0f)
#define SIDE_OFFSET       ( (float)(width >> 1) - 12.0f)
#define FRONT_OFFSET      ( (float)(width >> 1) - 14.0f)

#define MAX_VIEWPORTS     5
#define VIEWPORT_MAIN     0
#define VIEWPORT_SIDE     1
#define VIEWPORT_FRNT     2
#define VIEWPORT_TOP      3
#define VIEWPORT_PERS     4

// CAMERA ----------------------------------------------------------------------

#define PI                3.1415f
#define RADIANS(x)        x*PI/180.0f
#define YAW               0
#define PITCH             1
#define ROLL              2
#define RETURN_TIME       0.5f


// Default values for FXP_MAIN camera
#define DEF_MAIN_POS      0.0f, 0.0f, 10.0f
#define DEF_MAIN_ROT      0.0f, 0.0f, 0.0f
#define DEF_MAIN_FWD      0.0f, 0.0f, 0.0f
#define DEF_MAIN_UP       0.0f, 1.0f, 0.0f

// Default values for MOV_TOP camera
#define DEF_TOP_POS       0.0f, 10.0f, 0.0f
#define DEF_TOP_ROT       0.0f, -90.0f, 0.0f
#define DEF_TOP_FWD       0.0f, 0.0f, 0.0f
#define DEF_TOP_UP        0.0f, 1.0f, 0.0f

// Default values for MOV_SIDE camera
#define DEF_SIDE_POS      -10.0f, 0.0f, 0.0f
#define DEF_SIDE_ROT      90.0f, 0.0f, 0.0f
#define DEF_SIDE_FWD      0.0f, 0.0f, 0.0f
#define DEF_SIDE_UP       0.0f, 1.0f, 0.0f

// Default values for MOV_FRONT camera
#define DEF_FRNT_POS      0.0f, 0.0f, 10.0f
#define DEF_FRNT_ROT      0.0f, 0.0f, 0.0f
#define DEF_FRNT_FWD      0.0f, 0.0f, 0.0f
#define DEF_FRNT_UP       0.0f, 1.0f, 0.0f

// Default values for FLT_PERSP camera
#define DEF_PERS_POS      10.0f, 7.0f, 10.0f
#define DEF_PERS_ROT      -45.0f, -30.0f, 0.0f
#define DEF_PERS_FWD      0.0f, 0.0f, 0.0f
#define DEF_PERS_UP       0.0f, 1.0f, 0.0f

//#define DEF_PERS_POS      0.0f, 0.0f, 10.0f
//#define DEF_PERS_ROT      0.0f, 0.0f, 0.0f
//#define DEF_PERS_FWD      0.0f, 0.0f, 0.0f
//#define DEF_PERS_UP       0.0f, 1.0f, 0.0f

// GUI -------------------------------------------------------------------------
#define TEXTURE_WIDTH       256.0f

// Ribbon Coordinates
#define RIB_ORIGIN_X        46.0f
#define RIB_ORIGIN_Y        0.0f
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


// Sidebar Coordinates
#define SDB_ORIGIN_X        0.0f
#define SDB_ORIGIN_Y        46.0f
#define SDB_WIDTH           46.0f
#define SDB_T_HEIGHT        23.0f
#define SDB_B_HEIGHT        46.0f
#define SDB_M_HEIGHT        (windowHeight - SDB_ORIGIN_Y - SDB_T_HEIGHT - SDB_B_HEIGHT)
#define SDB_M_Y             (SDB_ORIGIN_Y + SDB_T_HEIGHT)
#define SDB_B_Y             (windowHeight - SDB_B_HEIGHT)
#define SDB_S_HEIGHT        23.0f
#define SDB_S_Y             220.0f



// Sidebar UVs
//#define SDB_UV_X            0.0f
#define SDB_UV_X            (-1.0f / TEXTURE_WIDTH)
#define SDB_UV_W            (46.0f / TEXTURE_WIDTH)
#define SDB_MB_UV_H         (46.0f / TEXTURE_WIDTH)

#define SDB_T_UV_Y          (45.0f / TEXTURE_WIDTH)
#define SDB_TS_UV_H         (23.0f / TEXTURE_WIDTH)
#define SDB_M_UV_Y          (92.0f / TEXTURE_WIDTH)
#define SDB_B_UV_Y          (138.0f / TEXTURE_WIDTH)
#define SDB_S_UV_Y          (69.0f / TEXTURE_WIDTH)

// Buttons
#define TOP_BUTTONS         100
#define SIDE_BUTTONS        200
#define VIEW_BUTTONS        300
#define MAX_TOP_BUTTONS     8
#define MAX_SIDE_BUTTONS    4
#define MAX_VIEW_BUTTONS    3


#define BTN_SIZE            32.0f
#define BTN_UV_SIZE         (32.0f / TEXTURE_WIDTH)
#define TBTN_ORIGIN_Y       7.0f
#define SBTN_ORIGIN_X       7.0f

// Button Input
#define BTN_LEFT            foreground.x()
#define BTN_RIGHT           (foreground.x() + BTN_SIZE)
#define BTN_TOP             foreground.y()
#define BTN_BOTTOM          (foreground.y() + BTN_SIZE)


// top buttons
#define TBTN_HIGHTLIGHT     1.0f
#define TBTN_FADE           0.5f

#define TBTN1_SPHERE        100
#define TBTN1_ORIGIN_X      60.0f
#define TBTN1_UV_X          (46.0f / TEXTURE_WIDTH)
#define TBTN1_UV_Y          0.0f

#define TBTN2_CUBE          101
#define TBTN2_ORIGIN_X      105.0f
#define TBTN2_UV_X          (78.0f / TEXTURE_WIDTH)
#define TBTN2_UV_Y          0.0f

#define TBTN3_CYLINDER      102
#define TBTN3_ORIGIN_X      150.0f
#define TBTN3_UV_X          (110.0f / TEXTURE_WIDTH)
#define TBTN3_UV_Y          0.0f

#define TBTN4_CONE          103
#define TBTN4_ORIGIN_X      195.0f
#define TBTN4_UV_X          (142.0f / TEXTURE_WIDTH)
#define TBTN4_UV_Y          0.0f

#define TBTN5_PLANE         104
#define TBTN5_ORIGIN_X      240.0f
#define TBTN5_UV_X          (174.0f / TEXTURE_WIDTH)
#define TBTN5_UV_Y          0.0f

#define TBTN6_TORUS         105
#define TBTN6_ORIGIN_X      285.0f
#define TBTN6_UV_X          (206.0f / TEXTURE_WIDTH)
#define TBTN6_UV_Y          0.0f

#define TBTN7_PYRAMID       106
#define TBTN7_ORIGIN_X      330.0f
#define TBTN7_UV_X          (46.0f / TEXTURE_WIDTH)
#define TBTN7_UV_Y          (32.0f / TEXTURE_WIDTH)

#define TBTN8_PIPE          107
#define TBTN8_ORIGIN_X      375.0f
#define TBTN8_UV_X          (78.0f / TEXTURE_WIDTH)
#define TBTN8_UV_Y          (32.0f / TEXTURE_WIDTH)


// side buttons
#define BGR_SEL_UV_X       (46.0f / TEXTURE_WIDTH)
#define BGR_SEL_UV_Y       (64.0f / TEXTURE_WIDTH)
#define BGR_UNSEL_UV_X     (78.0f / TEXTURE_WIDTH)
#define BGR_UNSEL_UV_Y     (64.0f / TEXTURE_WIDTH)

#define SBTN1_SELECT        200
#define SBTN1_ORIGIN_Y      60.0f
#define SBTN1_UV_X          (110.0f / TEXTURE_WIDTH)
#define SBTN1_UV_Y          (64.0f / TEXTURE_WIDTH)

#define SBTN2_MOVE          201
#define SBTN2_ORIGIN_Y      95.0f
#define SBTN2_UV_X          (142.0f / TEXTURE_WIDTH)
#define SBTN2_UV_Y          (64.0f / TEXTURE_WIDTH)

#define SBTN3_ROTATE        202
#define SBTN3_ORIGIN_Y      130.0f
#define SBTN3_UV_X          (174.0f / TEXTURE_WIDTH)
#define SBTN3_UV_Y          (64.0f / TEXTURE_WIDTH)

#define SBTN4_SCALE         203
#define SBTN4_ORIGIN_Y      165.0f
#define SBTN4_UV_X          (206.0f / TEXTURE_WIDTH)
#define SBTN4_UV_Y          (64.0f / TEXTURE_WIDTH)


// view buttons
#define VBTN1_1VIEW         300
#define VBTN1_ORIGIN_Y      270.0f
#define VBTN1_UV_X          (174.0f / TEXTURE_WIDTH)
#define VBTN1_UV_Y          (32.0f / TEXTURE_WIDTH)

#define VBTN2_4VIEW         301
#define VBTN2_ORIGIN_Y      305.0f
#define VBTN2_UV_X          (206.0f / TEXTURE_WIDTH)
#define VBTN2_UV_Y          (32.0f / TEXTURE_WIDTH)

#define VBTN3_GAME          302
#define VBTN3_ORIGIN_Y      340.0f
#define VBTN3_UV_X          (142.0f / TEXTURE_WIDTH)
#define VBTN3_UV_Y          (32.0f / TEXTURE_WIDTH)


// Logos
#define TRI_ORIGIN_X        7.0f
#define TRI_ORIGIN_Y        (SDB_B_Y + 10.0f)
#define TRI_SIZE            32.0f
#define TRI_UV_X            (110.0f / TEXTURE_WIDTH)
#define TRI_UV_Y            (32.0f / TEXTURE_WIDTH)
#define TRI_UV_SIZE         (32.0f / TEXTURE_WIDTH)


#define L3D_ORIGIN_X        0.0f
#define L3D_ORIGIN_Y        0.0f
#define L3D_SIZE            46.0f
#define L3D_UV_X            0.0f
#define L3D_UV_Y            (184.0f / TEXTURE_WIDTH)
#define L3D_UV_SIZE         (46.0f / TEXTURE_WIDTH)

// MODEL MANAGER ---------------------------------------------------------------

// procedural quad
#define QUAD_TOP            0.5f
#define QUAD_BTM            -0.5f
#define QUAD_LFT            -0.5f
#define QUAD_RGT            0.5f

// procedural plane
#define PLN_OFFSET          -0.5f



// ARM -------------------------------------------------------------------------
#define WRIST_MAXCLOSE      -28.0f
#define WRIST_MAXOPEN       -60.0f
#define ELBOW_MAXROTATION   70.0f
#define ELBOW_MINROTATION   -70.0f










// -----------------------------------------------------------------------------



#endif // MACROS_H




// 80 //////////////////////////////////////////////////////////////////////////