#include <ui/winmanager.h>


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
    
    //wcex.hIcon         = 0;                               // System default icon
    wcex.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE (IDI_ICON1));   // custom icon    

    wcex.hCursor       = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CUR_NORMAL));    // System default cursor
    //wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);   // System default cursor  
                              
    wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);       // Handle for background brush (colour)
    wcex.lpszMenuName  = MAKEINTRESOURCE (IDR_TOP_MENU);  // Set menu, in this case none              
    wcex.lpszClassName = "FirstWindowClass";              // Window’s classname        
    
    wcex.hIconSm       = 0;                               // Handle to small icon 
    wcex.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE (IDI_ICON1));   // custom small icon


  RegisterClassEx (&wcex);                                // Registers the window for further calls    

}


// Attempts to create the window and display it --------------------------------
BOOL WinManager::InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow)
{
  // center the screen
  int screenWidth = 1000;
  int screenHeight = 750;
  int x = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) >> 1;
  int y = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) >> 1;

  //int screenWidth = GetSystemMetrics(SM_CXSCREEN);
  //int screenHeight = GetSystemMetrics(SM_CYSCREEN);
  //int x = 0;
  //int y = 0;
  
  hwnd = CreateWindow ("FirstWindowClass",      // Classname (same as previous slide)          
          "My first Triangle",                  // Window name

          /**
          * // style of window being created
          * WS_POPUPWINDOW,
          * WS_OVERLAPPED | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_SYSM
          * WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME,
          */
          //WS_OVERLAPPEDWINDOW | WS_MAXIMIZE,
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
          //NULL,                 // handle to menu
          LoadMenu(hInstance, MAKEINTRESOURCE (IDR_TOP_MENU)), // handle to menu

          hInstance,            // Handle to instance associated with window        
          NULL);                // pointer to value to pass to window                

     
  if (!hwnd)
  {
    return FALSE;
  }

  //ShowWindow (hwnd, nCmdShow);   
  ShowWindow (hwnd, SW_SHOWMAXIMIZED);
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