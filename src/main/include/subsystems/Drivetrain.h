// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/drive/DifferentialDrive.h>

#include "ctre/Phoenix.h"
#include "AHRS.h"
#include "Constants.h"

using namespace frc;  //Had to add this to get SPI port enum

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  void Periodic() override;

  //Support Functions
  void InitFalcons(void);
  void Drive( double left, double right );
  void ArcadeDrive( double speed, double rotation );
  void Stop(void);

  double GetRightMotor(void);
  double GetLeftMotor(void);
  void   WriteFalconTemps(void);

  //Encoders
  int  GetLeftEncoder(void);
  int  GetLeftEncoder2(void);
  int  GetRightEncoder(void);
  int  GetRightEncoder2(void);
  void HardResetEncoders(void);   //Full Falcon Encoder Reset
  void ResetEncoders(void);       //Local Reset

  //NavX
  bool   IsGyroConnected(void);
  double GetGyroYaw(void);            //yaw: Relative -180 to +180
  double GetGyroAngle(void);          //angle: absolute -inf to +inf
  double GetGyroRate(void);
  void   ZeroGyro(void); 
  
     
 private:

    WPI_TalonFX m_leftMotorFront  { LEFTDRIVE_FRONT_CAN_ID };
    WPI_TalonFX m_leftMotorBack   { LEFTDRIVE_BACK_CAN_ID  };
    WPI_TalonFX m_rightMotorFront { RIGHTDRIVE_FRONT_CAN_ID };
    WPI_TalonFX m_rightMotorBack  { RIGHTDRIVE_BACK_CAN_ID };

    frc::DifferentialDrive m_differentialDrive{ m_leftMotorFront, m_rightMotorFront };

    AHRS m_ahrs{SPI::Port::kMXP};	    //NavX


    //Encoder Zeros
    int m_l1_enc_zero;
    int m_l2_enc_zero;
    int m_r1_enc_zero;
    int m_r2_enc_zero;

};
