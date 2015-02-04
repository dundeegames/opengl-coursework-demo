#include "winmanager.h"


WinManager::WinManager()
{

}


WinManager::~WinManager()
{

}


// Defines the window ----------------------------------------------------------
void WinManager::RegisterMyWindow(HINSTANCE hInstance, LRESULT (CALLBACK *WinProc)(HWND, UINT, WPARAM, LPARAM))
{

  WNDCLASSEX  wcex;      // Contains window class information                  

    wcex.cbSize        = sizeof (wcex);                   // Size in bytes of structure        
    wcex.style         = CS_HREDRAW | CS_VREDRAW;         // Class style (in this case re-draw when width or height changes)    
    wcex.lpfnWndProc   = WinProc;                         // Pointer to the window procedure            
    wcex.cbClsExtra    = 0;                               // extra bytes                
    wcex.cbWndExtra    = 0;                
    wcex.hInstance     = hInstance;                       // Handle to the instance that contains Window Proc            
    wcex.hIcon         = 0;                               // System default icon 

    wcex.hCursor       = LoadCursor (NULL, IDC_ARROW);    // System default cursor
    //wcex.hCursor       = LoadCursor (NULL, IDC_HELP);   // System default cursor  
                              
    wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);       // Handle for background brush (colour)
    wcex.lpszMenuName  = NULL;                            // Set menu, in this case none              
    wcex.lpszClassName = "FirstWindowClass";              // Window�s classname        
    wcex.hIconSm       = 0;                               // Handle to small icon 

  RegisterClassEx (&wcex);                                // Registers the window for further calls    

}


// Attempts to create the window and display it --------------------------------
BOOL WinManager::InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow)
{
  // center the screen
  int screenWidth = 800;
  int screenHeight = 600;
  int x = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) >> 1;
  int y = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) >> 1;
  
  hwnd = CreateWindow ("FirstWindowClass",      // Classname (same as previous slide)          
          "My first Triangle",                  // Window name

          /**
          * // style of window being created
          * WS_POPUPWINDOW,
          * WS_OVERLAPPED | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_SYSM
          * WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME,
          */
          WS_OVERLAPPEDWINDOW,


          /**
          * CW_USEDEFAULT,      // Horizontal location of window 
          * CW_USEDEFAULT,      // Vertical location of window
          * CW_USEDEFAULT,      // width of window
          * CW_USEDEFAULT,      // Height of window
          */
          x,                    // Horizontal location of window      
          y,                    // Vertical location of window      
          screenWidth,          // width of window      
          screenHeight,         // Height of window

          NULL,                 // parent of window          
          NULL,                 // handle to menu          
          hInstance,            // Handle to instance associated with window        
          NULL);                // pointer to value to pass to window                

     
  if (!hwnd)
  {
    return FALSE;
  }

  ShowWindow (hwnd, nCmdShow);            
  UpdateWindow (hwnd);

  return TRUE;

}

// -----------------------------------------------------------------------------

/*
BOOL WinManager::WaitFor(unsigned long delay)
{

}
*/

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////