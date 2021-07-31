// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdShooterSetVelocity.h"


CmdShooterSetVelocity::CmdShooterSetVelocity(Shooter *shooter,double rpm) 
{
  m_ptrShooter = shooter;
  m_rpm = rpm;
}

void CmdShooterSetVelocity::Initialize()
{
  m_ptrShooter->SetShooterVelocity(m_rpm);
}
