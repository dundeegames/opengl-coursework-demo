////////////////////////////////////////////////////////////////////////////////
/**
* \file       winmanager.h
* \brief      WinManager class - AG0800A Graphics Programming
*
* \details    Generates Window (Factory pattern) with predefine parameters 
*
* \author     Jiri Klic
* \version    1.0
* \date       December 2014
* \pre        
* \post       
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



#ifndef WINMANAGER_H
#define WINMANAGER_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <resources/resource.h>





// CLASS ///////////////////////////////////////////////////////////////////////

class WinManager
{

public:
  WinManager();
  ~WinManager();

  void RegisterMyWindow(HINSTANCE hInstance, LRESULT (CALLBACK *WinProc)(HWND, UINT, WPARAM, LPARAM));
  BOOL InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow);

  inline HWND getHandle() const {return hwnd;}


private:
  HWND hwnd;          // Handle to a window

};


#endif // WINMANAGER_H




// 80 //////////////////////////////////////////////////////////////////////////