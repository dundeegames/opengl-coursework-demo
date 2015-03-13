// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                          WinAPI and OpenGL laboratory                       \n
*                             by Jiri Klic, Dec 2014                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef WINMANAGER_H
#define WINMANAGER_H


// INCLUDES ////////////////////////////////////////////////////////////////////

#include <windows.h>




class WinManager
{

public:
  WinManager();
  ~WinManager();

  //LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
  //BOOL WaitFor(unsigned long delay);
  void RegisterMyWindow(HINSTANCE hInstance, LRESULT (CALLBACK *WinProc)(HWND, UINT, WPARAM, LPARAM));
  BOOL InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow);

  inline HWND getHandle() const {return hwnd;}


private:
  HWND hwnd;          // Handle to a window

};


#endif // WINMANAGER_H




// 80 //////////////////////////////////////////////////////////////////////////