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
//#include <stdio.h>	// unused
//#include <mmsystem.h>	// unused
//#include <math.h>		// unused

#include "input.h"

#include "scene3D.h"
//#include "scene2D.h"

#include "timerclass.h"



// GLOBALS /////////////////////////////////////////////////////////////////////
HWND hwnd; 				// Handle to a window (? why it is global?)

Input myInput;

Scene3D myScene;
//Scene myScene;

TimerClass timer;



// FUNCTION DECLARATIONS ///////////////////////////////////////////////////////

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

BOOL WaitFor(unsigned long delay);

void RegisterMyWindow(HINSTANCE hInstance);

BOOL InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow);



// ENTRY POINT - PROGRAM STARTS HERE ///////////////////////////////////////////
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow)			
{
    MSG msg;	

	RegisterMyWindow(hInstance);

   	if (!InitialiseMyWindow(hInstance, nCmdShow))
	{
		return FALSE;
	}
	else
	{
		//myScene.Initialise(&hwnd, &myInput);
		myScene.Init(&hwnd, &myInput);
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
		//myScene.update();		// process input
		//myScene.render();		// call render on scene object
    }
  
    //myScene.shutdown();			// release HDCs when exiting application
	return msg.wParam ;										
}



// FUNCTION DEFINITIONS ////////////////////////////////////////////////////////

// handles window messages -----------------------------------------------------				
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)											
    {														
		case WM_CREATE:		
			
			break;

		case WM_SIZE:
			myScene.Resize();
			//myScene.setBuffers();
			break;	

		case WM_KEYDOWN:
			myInput.SetKeyDown(wParam);				// Pass key value into input obj
			break;

		case WM_KEYUP:
			myInput.SetKeyUp(wParam);				// Pass key value into input obj
			break;

		case WM_MOUSEMOVE:
			myInput.setMouseX(LOWORD (lParam));		// Pass X position
			myInput.setMouseY(HIWORD (lParam));		// Pass Y position
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
			//PostQuitMessage(WM_QUIT);
			PostQuitMessage(0);								
			break;				
	}													

	return DefWindowProc (hwnd, message, wParam, lParam);		
															
}




// Defines the window ----------------------------------------------------------
void RegisterMyWindow(HINSTANCE hInstance)
{
    WNDCLASSEX  wcex;			// Contains window class information									

    wcex.cbSize        = sizeof (wcex);						// Size in bytes of structure				
    wcex.style         = CS_HREDRAW | CS_VREDRAW;			// Class style (in this case re-draw when width or height changes)		
    wcex.lpfnWndProc   = WndProc;							// Pointer to the window procedure						
    wcex.cbClsExtra    = 0;									// extra bytes								
    wcex.cbWndExtra    = 0;								
    wcex.hInstance     = hInstance;							// Handle to the instance that contains Window Proc						
    wcex.hIcon         = 0; 								// System default icon 

    wcex.hCursor       = LoadCursor (NULL, IDC_ARROW);		// System default cursor
	//wcex.hCursor       = LoadCursor (NULL, IDC_HELP);		// System default cursor	
															
    wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);			// Handle for background brush (colour)
    wcex.lpszMenuName  = NULL;								// Set menu, in this case none							
    wcex.lpszClassName = "FirstWindowClass";				// Window’s classname				
    wcex.hIconSm       = 0; 								// Handle to small icon 

	RegisterClassEx (&wcex);								// Registers the window for further calls							
}





// Attempts to create the window and display it --------------------------------
BOOL InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow)
{
   // GetSystemMetrics(SM_CXSCREEN);
   // GetSystemMetrics(SM_CYSCREEN);
  
   hwnd = CreateWindow ("FirstWindowClass",			// Classname (same as previous slide)					
						 "My first Triangle",  		// Window name

						 //WS_OVERLAPPEDWINDOW,												// style of window being created
						 //WS_POPUPWINDOW,													// style of window being created
						 //WS_OVERLAPPED | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_SYSMENU,		// style of window being created
						 WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME,			// style of window being created

						 //CW_USEDEFAULT,			// Horizontal location of window	
						 //CW_USEDEFAULT,			// Vertical location of window
						 //CW_USEDEFAULT,			// width of window
						 //CW_USEDEFAULT,			// Height of window


						 CW_USEDEFAULT,				// Horizontal location of window			
						 CW_USEDEFAULT,				// Vertical location of window			
						 800,						// width of window			
						 600,						// Height of window

						 NULL,						// parent of window					
						 NULL,						// handle to menu					
						 hInstance,					// Handle to instance associated with window				
						 NULL);						// pointer to value to pass to window								

   
   if (!hwnd)
	{
		return FALSE;
	}

    ShowWindow (hwnd, nCmdShow);						
    UpdateWindow (hwnd);

	return TRUE;

}

// -----------------------------------------------------------------------------







// 80 //////////////////////////////////////////////////////////////////////////