////////////////////////////////////////////////////////////////////////////////
/**
* \file       timerclass.cpp
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




// INCLUDES ////////////////////////////////////////////////////////////////////
#include <system/timerclass.h>







// FUNCTIONS ///////////////////////////////////////////////////////////////////
TimerClass::TimerClass()
{
}


TimerClass::TimerClass(const TimerClass& other)
{
}


TimerClass::~TimerClass()
{
}


// -----------------------------------------------------------------------------

bool TimerClass::Initialize()
{
  // Check to see if this system supports high performance timers.
  QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
  if(m_frequency == 0)
  {
    return false;
  }

  // Find out how many times the frequency counter ticks every second.
  m_ticksPerS = (float)(m_frequency);

  QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);

  return true;
}

// -----------------------------------------------------------------------------

void TimerClass::Frame()
{
  INT64 currentTime;
  float timeDifference;


  // Query the current time.
  QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

  // Calculate the difference in time since the last time we queried for the current time.
  timeDifference = (float)(currentTime - m_startTime);

  // Calculate the frame time by the time difference over the timer speed resolution.
  m_frameTime = timeDifference / m_ticksPerS;

  // Restart the timer.
  m_startTime = currentTime;

  return;
}

// -----------------------------------------------------------------------------

float TimerClass::GetTime()
{
  return m_frameTime;
}


// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////