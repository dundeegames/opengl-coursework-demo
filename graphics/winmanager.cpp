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
  //wcex.hCursor       = LoadCursor (NULL, IDC_HELP);     // System default cursor  
                              
    wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);       // Handle for background brush (colour)
    wcex.lpszMenuName  = NULL;                            // Set menu, in this case none              
    wcex.lpszClassName = "FirstWindowClass";              // Window�s classname        
    wcex.hIconSm       = 0;                               // Handle to small icon 

  RegisterClassEx (&wcex);                                // Registers the window for further calls              


}


// Attempts to create the window and display it --------------------------------
BOOL WinManager::InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow)
{
   // GetSystemMetrics(SM_CXSCREEN);
   // GetSystemMetrics(SM_CYSCREEN);
  
   hwnd = CreateWindow ("FirstWindowClass",      // Classname (same as previous slide)          
             "My first Triangle",      // Window name

             //WS_OVERLAPPEDWINDOW,                     // style of window being created
             //WS_POPUPWINDOW,                          // style of window being created
             //WS_OVERLAPPED | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_SYSMENU,    // style of window being created
             WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME,      // style of window being created

             //CW_USEDEFAULT,      // Horizontal location of window  
             //CW_USEDEFAULT,      // Vertical location of window
             //CW_USEDEFAULT,      // width of window
             //CW_USEDEFAULT,      // Height of window


             CW_USEDEFAULT,        // Horizontal location of window      
             CW_USEDEFAULT,        // Vertical location of window      
             800,                  // width of window      
             600,                  // Height of window

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