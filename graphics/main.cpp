//Windows Example Code
//Paul Robertson 2014

// Includes
#include <windows.h>
#include <stdio.h>


#include "input.h"
#include "scene.h"

// Globals
HWND	hwnd;				// Handle to a window
Input	myInput;
Scene myScene;

//Prototypes -------------------------------------------
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

void RegisterMyWindow(HINSTANCE);

BOOL InitialiseMyWindow(HINSTANCE, int);

int WINAPI WinMain (HINSTANCE, HINSTANCE, PSTR, int);



// Defines the window ----------------------------------

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

// Attempts to create the window and display it ---------

BOOL InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow)
{
   hwnd = CreateWindow ("FirstWindowClass",			// Classname (same as previous slide)
 						"My First Project",  		// Window name

						 //WS_OVERLAPPEDWINDOW,												// style of window being created
						 //WS_POPUPWINDOW,													// style of window being created
						 //WS_OVERLAPPED | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_SYSMENU,		// style of window being created
						 WS_OVERLAPPED | WS_THICKFRAME | WS_SYSMENU,						// style of window being created


						 //CW_USEDEFAULT,				// Horizontal location of window	
						 //CW_USEDEFAULT,				// Vertical location of window
						 //CW_USEDEFAULT,			// width of window
						 //CW_USEDEFAULT,			// Height of window

						 500,						// Horizontal location of window
						 300,						// Vertical location of window
						 800,						// width of window
						 450,						// Height of window

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

// Entry point. The program start here -----------------------------------

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow)
{

    MSG         msg;								
	RegisterMyWindow(hInstance);

   	if (!InitialiseMyWindow(hInstance, nCmdShow))
	{
		return FALSE;
	}
	else
	{
		myScene.Initialise(&hwnd, &myInput);
	}




	//MessageBox (NULL, "This is a new message from Jiri.",  "NewMsg", MB_YESNO);



	//GAME LOOP
	while (TRUE){

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
			if(myInput.isKeyDown(VK_SPACE))									// if space is pressed
			{
				MessageBox(NULL, "Help me!", "A Dialog", MB_OK);			//display message box
				myInput.SetKeyUp(VK_SPACE);									//force un-pressing of space
			}

			if(myInput.isKeyDown(VK_ESCAPE))								// if space is pressed
			{
				//msg.message = WM_CLOSE;
				//myInput.SetKeyUp(VK_ESCAPE);								//force un-pressing of space
				break;
			}

			if(myInput.isKeyDown('J') && myInput.isKeyDown('K') && myInput.isKeyDown('L'))			// if J+K+L is pressed
			{
				MessageBox(NULL, "J + K + L is pressed.", "JKL", MB_OK);	//display message box
				
				//force un-pressing of space
				myInput.SetKeyUp('J');
				myInput.SetKeyUp('K');
				myInput.SetKeyUp('L');
			}



		}
		myScene.update();		// process input
		myScene.render();		// call render on scene object

    }
    myScene.shutdown();			// release HDCs when exiting application



	return msg.wParam ;										
}


// handles window messages ---------------------------------------------

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
	{

		case WM_CREATE:											
			break;

		case WM_SIZE:
			myScene.setBuffers();
			break;

		case WM_KEYDOWN:
			myInput.SetKeyDown(wParam);			// Pass key value into input obj
			break;

		case WM_KEYUP:
			myInput.SetKeyUp(wParam);			// Pass key value into input obj
			break;

		case WM_MOUSEMOVE:
			myInput.setMouseX(LOWORD (lParam));		// Pass X position
			myInput.setMouseY(HIWORD (lParam));		// Pass Y position
			break;


		case WM_LBUTTONDOWN:
			char position[20];
			sprintf(position, "x=%d y=%d" ,myInput.getMouseX(), myInput.getMouseY());
			MessageBox(NULL, position, "Mouse Position", MB_OK);
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
			PostQuitMessage(WM_QUIT);
			break;			
	}													

	return DefWindowProc (hwnd, message, wParam, lParam);		
															
}