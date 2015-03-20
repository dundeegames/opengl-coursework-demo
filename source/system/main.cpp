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
//#include <system/scene2D.h>
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


/*
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

BOOL WaitFor(unsigned long delay);

void RegisterMyWindow(HINSTANCE hInstance);

BOOL InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow);
*/


// ENTRY POINT - PROGRAM STARTS HERE ///////////////////////////////////////////
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow)      
{
  MSG msg;  
  HWND myhandle;         // Handle to a window

  myWinManager.RegisterMyWindow(hInstance, mainWndProc);


  //RegisterMyWindow(hInstance);

  if (!myWinManager.InitialiseMyWindow(hInstance, nCmdShow))
  {
    return FALSE;
  }
  else
  {
    myhandle = myWinManager.getHandle();
    //myScene.Initialise(&hwnd, &myInput);
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
      /*
      char position[20];
      sprintf(position, "x=%d y=%d" ,myInput.getMouseX(), myInput.getMouseY());
      MessageBox(NULL, position, "Mouse Position", MB_OK);
      */
      break;

    case WM_LBUTTONUP:
      myInput.setLeftMouseBtn(false);
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