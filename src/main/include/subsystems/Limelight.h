// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class Limelight : public frc2::SubsystemBase {
 public:
  Limelight();

  void Periodic() override;

  void   LimelightInit(void);
  bool   IsTarget(void);
  double GetHOffset(void);
  double GetDistance(void);
  double GetVAngle(void);
  void   TogglePipeLine(void);


 private:

  //Try this next:
  //std::shared_ptr<NetworkTable> m_ptrTable;

};
