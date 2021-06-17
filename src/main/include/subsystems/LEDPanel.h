// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AddressableLED.h>

class LEDPanel : public frc2::SubsystemBase {
 public:
  LEDPanel();
  void Periodic() override;

  //Our Funtions
  void SetAllLEDColor( int r, int g, int b);
  void SetOneLEDColor(int LEDNum, int r, int g, int b);
  void SetData(void);
  void ClearBuffer( void );
  void LedPanelPeriodic( void );

 private:

  static const int kLEDLength  = 36;
  static const int kLEDPWMPort = 9;
  frc::AddressableLED m_led{kLEDPWMPort};
  std::array<frc::AddressableLED::LEDData, kLEDLength> m_ledBuffer;

  //Rotation
  int m_index;
  int m_count;

};
