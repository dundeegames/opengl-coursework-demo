////////////////////////////////////////////////////////////////////////////////
/**
* \file       timerclass.h
* \brief      TimerClass class - AG0800A Graphics Programming
*
* \details    calculates delta time 
*
* \author     
* \version    1.0
* \date       [2014] Provided during laboratory exercise
* \pre        Initialize() needs to be called before use
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



#ifndef TIMERCLASS_H
#define TIMERCLASS_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>





// CLASS ///////////////////////////////////////////////////////////////////////

class TimerClass
{
public:
  TimerClass();
  TimerClass(const TimerClass&);
  ~TimerClass();

  bool Initialize();
  void Frame();

  float GetTime();

private:
  INT64 m_frequency;
  float m_ticksPerS;
  INT64 m_startTime;
  float m_frameTime;
};

#endif // TIMERCLASS_H




// 80 //////////////////////////////////////////////////////////////////////////