// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"
#include <frc/XboxController.h>


class CmdDriveWithGamepad
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriveWithGamepad> {
 public:
  CmdDriveWithGamepad( Drivetrain *drivetrain, frc::XboxController *driver_xbox );

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;


 private:
  Drivetrain          *m_ptrDrivetrain;
  frc::XboxController *m_ptrDriverXbox;

};
