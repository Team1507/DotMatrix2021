// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Limelight.h"
#include <frc2/Timer.h>

class CmdDriveTurn2Limelight
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriveTurn2Limelight> {
 public:
  CmdDriveTurn2Limelight(Drivetrain *drivetrain, Limelight *limelight);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;


 private:

  Drivetrain *m_ptrDrivetrain;
  Limelight  *m_ptrLimelight;
  frc2::Timer m_timer;

  double m_Kp;
  double m_minPower;
  double m_targetAngle;


};
