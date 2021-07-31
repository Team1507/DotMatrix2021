// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdFeederSetPower.h"


CmdFeederSetPower::CmdFeederSetPower(Shooter *shooter,double power) 
{
  m_ptrShooter = shooter;
  m_power = power;
}

void CmdFeederSetPower::Initialize()
{
  m_ptrShooter->SetFeederPower(m_power);
}
