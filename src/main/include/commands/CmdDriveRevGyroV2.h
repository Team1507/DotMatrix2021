// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"
#include <frc2/Timer.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdDriveRevGyroV2
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriveRevGyroV2> {
 public:
  CmdDriveRevGyroV2(Drivetrain *drivetrain,double power, double heading, double distance, bool ramp, bool stop, double timeout);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:

  Drivetrain *m_ptrDrivetrain;
  frc2::Timer m_timer;
  
  double m_power;
  double m_heading;
  double m_distance;
  bool   m_stop;
  double m_timeout;   

  bool   m_ramp;
  double m_base;


};
