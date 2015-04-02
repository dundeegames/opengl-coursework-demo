/*
********************************************************************************
*****                                                                      *****
*****                     WinAPI and OpenGL laboratory                     *****
*****                        by Jiri Klic, Dec 2014                        *****
*****                                                                      *****
********************************************************************************
*/



// INCLUDES ////////////////////////////////////////////////////////////////////

#include <windows.h>
//#include <stdio.h>  // unused
//#include <mmsystem.h>  // unused
//#include <math.h>    // unused

#include <ui/winmanager.h>
#include <ui/input.h>

#include <system/scene3D.h>
#include <system/timerclass.h>



// GLOBALS /////////////////////////////////////////////////////////////////////

WinManager myWinManager;


// HWND hwnd;         // Handle to a window

Input myInput;

Scene3D myScene;
//Scene myScene;

TimerClass timer;



// FUNCTION DECLARATIONS ///////////////////////////////////////////////////////
LRESULT CALLBACK mainWndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);



// ENTRY POINT - PROGRAM STARTS HERE ///////////////////////////////////////////
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow)      
{
  MSG msg;  
  HWND myhandle;         // Handle to a window


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
  

  //GAME LOOP
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
    //myScene.update();    // process input
    //myScene.render();    // call render on scene object
  }
  
  //myScene.shutdown();      // release HDCs when exiting application
  return msg.wParam ;                    
}



// FUNCTION DEFINITIONS ////////////////////////////////////////////////////////

// handles window messages -----------------------------------------------------        
LRESULT CALLBACK mainWndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)                      
    {                            
    case WM_CREATE:    
      
      break;

    case WM_SIZE:
      myScene.Resize();
      //myScene.DrawScene(timer.GetTime());
      //myScene.setBuffers();
      break;

    case WM_GETMINMAXINFO:
      ((MINMAXINFO*)lParam)->ptMinTrackSize.x = WIN_MIN_WIDTH;
      ((MINMAXINFO*)lParam)->ptMinTrackSize.y = WIN_MIN_HEIGHT;
      break;


    case WM_KEYDOWN:
      myInput.SetKeyDown(wParam);        // Pass key value into input objI:/03_STUDY/02_YEAR2/03_GRAPHICS/graphics
      break;

    case WM_KEYUP:
      myInput.SetKeyUp(wParam);        // Pass key value into input obj
      break;

    case WM_MOUSEMOVE:
      myInput.setMouseX(LOWORD (lParam));    // Pass X position
      myInput.setMouseY(HIWORD (lParam));    // Pass Y position
      break;

    case WM_LBUTTONDOWN:
      myInput.setLeftMouseBtn(true);
      myInput.setLDragX(LOWORD (lParam));
      myInput.setLDragY(HIWORD (lParam));
      /*
      char position[20];
      sprintf(position, "x=%d y=%d" ,myInput.getMouseX(), myInput.getMouseY());
      MessageBox(NULL, position, "Mouse Position", MB_OK);
      */
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