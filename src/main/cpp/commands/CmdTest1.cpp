// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTest1.h"

CmdTest1::CmdTest1() 
{

}


void CmdTest1::Initialize() 
{
   std::cout << "In CmdTest1" << std::endl;
   m_timer.Reset();
   m_timer.Start();


}


void CmdTest1::Execute() 
{

}


void CmdTest1::End(bool interrupted) 
{
  std::cout << "CmdTest1 Complete" << std::endl;
  m_timer.Stop();
}


bool CmdTest1::IsFinished() 
{
  return m_timer.HasElapsed( units::second_t( 3.0 )  );
}
