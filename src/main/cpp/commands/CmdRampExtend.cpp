// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdRampExtend.h"


CmdRampExtend::CmdRampExtend(Shooter *shooter) 
{
  m_ptrShooter = shooter;
}

// Called when the command is initially scheduled.
void CmdRampExtend::Initialize() 
{
  m_ptrShooter->ExtendRamp();
}
