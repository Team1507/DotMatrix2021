// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdShooterStop.h"


CmdShooterStop::CmdShooterStop(Shooter *shooter) 
{
  m_ptrShooter = shooter;
}
  

void CmdShooterStop::Initialize()
{
  m_ptrShooter->StopShooter();
}
