////////////////////////////////////////////////////////////////////////////////
/**
* \file       main.cpp
* \brief      WinMain(), mainWndProc() - AG0800A Graphics Programming
*
* \details    The Win32 Application Entry Point
*
* \author     Jiri Klic
* \version    1.0
* \date       December 2014
* \pre        
* \bug        No known bugs
* \warning    
* \todo       
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////





// INCLUDES ////////////////////////////////////////////////////////////////////
#define OEMRESOURCE
#include <windows.h>
#include <ui/winmanager.h>
#include <ui/input.h>
#include <system/scene3D.h>
#include <system/timerclass.h>
#include <stdlib.h>




// GLOBALS /////////////////////////////////////////////////////////////////////

WinManager myWinManager;    ///< Creates the window (Factory pattern)

Input myInput;              ///< Provides loose coupling between GUI and program

Scene3D myScene;            ///< Handles the OpenGL functionality

TimerClass timer;           ///< Handles the Delta time



// FUNCTION DECLARATIONS ///////////////////////////////////////////////////////
LRESULT CALLBACK mainWndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);



// ENTRY POINT - PROGRAM STARTS HERE ///////////////////////////////////////////


/**
* \brief      Main entry for Win32 program
*
* \details    Display the window, initialize myScene & timer object
*             enter a message retrieval-and-dispatch loop and terminate
*             when it receives a WM_QUIT message
*
* \param      hInstance     - A handle to the current instance of the application
* \param      hPrevInstance - A handle to the previous instance of the application.
*                             This parameter is always NULL
* \param      szCmdLine     - The command line for the application, excluding the program name
* \param      nCmdShow      - Controls how the window is to be shown
*
* \return     exit value contained in that message's wParam parameter if succeeds,
*             terminating when it receives a WM_QUIT message.
*             If the function terminates before entering the message loop,
*             it should return zero
*
*/
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow)      
{
  MSG msg;  
  HWND myhandle;         ///< Handle to a window


  myWinManager.RegisterMyWindow(hInstance, mainWndProc);


  if (!myWinManager.InitialiseMyWindow(hInstance, nCmdShow))
  {
    return FALSE;
  }
  else
  {
    myhandle = myWinManager.getHandle();
    myScene.Init(&myhandle, &myInput);
    timer.Initialize();
  }
  




  ///< GAME LOOP
  while (TRUE)          
  {              
    if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
    {
        if (msg.message==WM_QUIT)
      {
        break;
      }

      TranslateMessage (&msg);              
      DispatchMessage (&msg);

    }
    else
    {  
      timer.Frame();

      if(myInput.isKeyDown(VK_ESCAPE))
      {
        break;
      }

      myScene.DrawScene(timer.GetTime());
    }
  }
  
  return msg.wParam ;                    
}



// FUNCTION DEFINITIONS ////////////////////////////////////////////////////////

/**
* \brief      handles window messages
*
* \details    Sets the input flags based on types of messages from
*             keyboard, mouse and win-menu.
*             Handles resizing of the window, final closing & end of application
*             It is a required component during window creation (see: WinManager)
*             and it will be sole winproc for our program.
*
* \param      hwnd    - handle to the window
* \param      message - the message
* \param      wParam  - additional message info, depends on value of the message
* \param      lParam  - additional message info, depends on value of the message
*
* \return     The return value is the result of the message processing
*
*/
LRESULT CALLBACK mainWndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)                      
    {                            
    case WM_CREATE:      
      break;

    case WM_SIZE:
      myScene.Resize();
      break;

    case WM_GETMINMAXINFO:
      ((MINMAXINFO*)lParam)->ptMinTrackSize.x = WIN_MIN_WIDTH;
      ((MINMAXINFO*)lParam)->ptMinTrackSize.y = WIN_MIN_HEIGHT;
      break;


    case WM_KEYDOWN:
      myInput.SetKeyDown(wParam);      // Pass key value into input obj
      break;

    case WM_KEYUP:
      myInput.SetKeyUp(wParam);        // Pass key value into input obj
      break;

    case WM_MOUSEMOVE:
      myInput.setMouseX(LOWORD (lParam));    // Record mouse X position
      myInput.setMouseY(HIWORD (lParam));    // Record mouse Y position
      break;

    case WM_LBUTTONDOWN:
      myInput.setLeftMouseBtn(true);
      myInput.setLDragX(LOWORD (lParam));
      myInput.setLDragY(HIWORD (lParam));
      break;

    case WM_LBUTTONUP:
      myInput.setLeftMouseBtn(false);
      break;

    case WM_LBUTTONDBLCLK:
      myInput.setLeftMouseDClick(true);
      break;

    case WM_RBUTTONDOWN:
      myInput.setRightMouseBtn(true);
      myInput.setRDragX(LOWORD (lParam));
      myInput.setRDragY(HIWORD (lParam));
      break;

    case WM_RBUTTONUP:
      myInput.setRightMouseBtn(false);
      break;
 

    case WM_MBUTTONDOWN:
      myInput.setMiddleMouseBtn(true);
      break;

    case WM_MBUTTONUP:
      myInput.setMiddleMouseBtn(false);
      break;


    case WM_MOUSEWHEEL:
      myInput.setWheelDelta(GET_WHEEL_DELTA_WPARAM(wParam) );
      break;

    case WM_COMMAND:

      // handle menu slections
      switch(LOWORD(wParam))
      {        
      case ID_MENU_OPEN:
        myScene.loadFile();
        break;

      case ID_VIEW_1VIEW:
        break;

      case ID_VIEW_4VIEW:
        break;

      case ID_HELP_ABOUT:
        ShellExecute(NULL, "open", "..\\..\\doc\\doxygen\\html\\index.html", NULL, NULL, SW_SHOWNORMAL);
        break;

      }
      break;  // end of WM_COMMAND

    case WM_PAINT:
      break;

    case WM_CLOSE:

      int resp;
      
      resp = MessageBox(hwnd, "You sure?", "Quit", MB_YESNO | MB_ICONQUESTION);

      if(resp == IDNO)
      {
        return 0;
      }
      break;

    case WM_DESTROY:  
      PostQuitMessage(0);                
      break;        
  }                          

  return DefWindowProc (hwnd, message, wParam, lParam);    
                              
}


// -----------------------------------------------------------------------------







// 80 //////////////////////////////////////////////////////////////////////////