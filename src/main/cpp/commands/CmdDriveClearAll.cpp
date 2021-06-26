// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveClearAll.h"

CmdDriveClearAll::CmdDriveClearAll(Drivetrain *drivetrain) 
{
  m_ptrDrivetrain = drivetrain;
}

void CmdDriveClearAll::Initialize() 
{
  m_ptrDrivetrain->ResetEncoders();
  m_ptrDrivetrain->ResetOdometry();
  m_ptrDrivetrain->ZeroGyro();
}

void CmdDriveClearAll::Execute() {}

void CmdDriveClearAll::End(bool interrupted) {}

bool CmdDriveClearAll::IsFinished() {
  return true;
}
