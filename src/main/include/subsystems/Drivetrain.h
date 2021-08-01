// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/drive/DifferentialDrive.h>
#include <frc2/Timer.h>

#include "ctre/Phoenix.h"
#include "AHRS.h"
#include "Constants.h"

using namespace frc;  //Had to add this to get SPI port enum

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  void Periodic() override;

  //Drivetrain Constants
  const static int    LEFT_ENCODER_TPI;       //"Ticks per inch"
  const static int    RIGHT_ENCODER_TPI; 
  const static double RAMP_FACTOR;

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
  bool   IsGyroBusy(void);            //Busy Calibrating
  
  //Odometry
  void    ResetOdometry(void);
  double  GetOdometryX(void);           //inches
  double  GetOdometryY(void);           //inches
  double  GetOdometryVel(void);         //in/sec
  double  GetOdometryLVel(void);        //in/sec
  double  GetOdometryRVel(void);        //in/sec
  double  GetOdometryHeading(void);     //degrees


 private:

    WPI_TalonFX m_leftMotorFront  { LEFTDRIVE_FRONT_CAN_ID };
    WPI_TalonFX m_leftMotorBack   { LEFTDRIVE_BACK_CAN_ID  };
    WPI_TalonFX m_rightMotorFront { RIGHTDRIVE_FRONT_CAN_ID };
    WPI_TalonFX m_rightMotorBack  { RIGHTDRIVE_BACK_CAN_ID };

    frc::DifferentialDrive m_differentialDrive{ m_leftMotorFront, m_rightMotorFront };

    AHRS m_ahrs{SPI::Port::kMXP};	    //NavXd

    frc2::Timer m_timer;


    //Encoder Zeros
    int m_l1_enc_zero;
    int m_l2_enc_zero;
    int m_r1_enc_zero;
    int m_r2_enc_zero;


    //Odometry
    void   OdometryPeriodic(void);
    int    m_prev_left_enc;
    int    m_prev_right_enc;
    double m_prev_timestamp;

    double m_curr_x;  //inches
    double m_curr_y;  //inches
    double m_curr_v;  //inches/sec
    double m_curr_Lv; //inches/sec
    double m_curr_Rv; //inches/sec

};
