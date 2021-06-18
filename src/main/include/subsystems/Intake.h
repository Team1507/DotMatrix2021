// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "ctre/Phoenix.h"
#include "Constants.h"



class Intake : public frc2::SubsystemBase {
 public:
  Intake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void IntakeForward(void);
  void IntakeForward(double power);
  void IntakeStop(void);    
  void IntakeBackward(void); 

 private:
  WPI_VictorSPX m_intakeMotor{INTAKE_CAN_ID};


};
