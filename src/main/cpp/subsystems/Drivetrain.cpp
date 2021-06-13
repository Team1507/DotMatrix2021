// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include <frc/smartdashboard/SmartDashboard.h>

Drivetrain::Drivetrain()
{


}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}


//******************************************
void Drivetrain::InitFalcons(void)
{
    std::cout<<"Drivetrain: Falcon Init"<<std::endl;

    //reset
    m_leftMotorFront.ConfigFactoryDefault();
    m_leftMotorBack.ConfigFactoryDefault();
    m_rightMotorFront.ConfigFactoryDefault();
    m_rightMotorBack.ConfigFactoryDefault();

    //Setup up Back motors as followers
    m_leftMotorBack.Follow( m_leftMotorFront );
    m_rightMotorBack.Follow( m_rightMotorFront );

    //Set Inverted
    m_leftMotorFront.SetInverted( true );
    m_leftMotorBack.SetInverted( true );
    m_rightMotorFront.SetInverted( true );
    m_rightMotorBack.SetInverted( true );

    //Set Brake Mode
    m_leftMotorFront.SetNeutralMode(NeutralMode::Brake);
    m_leftMotorBack.SetNeutralMode(NeutralMode::Brake);
    m_rightMotorFront.SetNeutralMode(NeutralMode::Brake);
    m_rightMotorBack.SetNeutralMode(NeutralMode::Brake);        

    //Setup Encoders
    m_leftMotorFront.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
    m_leftMotorBack.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
    m_rightMotorFront.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
    m_rightMotorBack.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);


    m_leftMotorFront.SetStatusFramePeriod(StatusFrame::Status_2_Feedback0_,2,10 );
    m_rightMotorFront.SetStatusFramePeriod(StatusFrame::Status_2_Feedback0_,2,10);
    // std::cout << "LeftStatusPeriod = " << m_leftMotorFront.GetStatusFramePeriod(StatusFrame::Status_2_Feedback0_,10 ) << std::endl;
    // std::cout << "RightStatusPeriod = " << m_rightMotorFront.GetStatusFramePeriod(StatusFrame::Status_2_Feedback0_,10) << std::endl;


}


void Drivetrain::Drive( double left, double right )
{
    m_differentialDrive.TankDrive(left,right,false);
}

void Drivetrain::ArcadeDrive( double speed, double rotation )
{
    m_differentialDrive.ArcadeDrive(speed,rotation,true);
}


void Drivetrain::Stop(void)
{
    std::cout<<"Drivetrain: Stop!"<<std::endl;
    m_differentialDrive.TankDrive(0,0,false);
}

double Drivetrain::GetRightMotor(void)
{
    return -m_rightMotorFront.Get();
}

double Drivetrain::GetLeftMotor(void)
{
	return m_leftMotorFront.Get();
}

void Drivetrain::WriteFalconTemps(void)
{
    frc::SmartDashboard::PutNumber("FalconTemp LF", m_leftMotorFront.GetTemperature() );
    frc::SmartDashboard::PutNumber("FalconTemp LR", m_leftMotorBack.GetTemperature() );
    frc::SmartDashboard::PutNumber("FalconTemp RF", m_rightMotorFront.GetTemperature() );
    frc::SmartDashboard::PutNumber("FalconTemp RR", m_rightMotorBack.GetTemperature() );
}


//**************** ENCODERS *********************
int Drivetrain::GetLeftEncoder(void)
{
    return (m_leftMotorFront.GetSelectedSensorPosition(0)  - m_l1_enc_zero);
}

int Drivetrain::GetLeftEncoder2(void)
{
    return (m_leftMotorBack.GetSelectedSensorPosition(0) - m_l2_enc_zero);
}

int Drivetrain::GetRightEncoder(void)
{
    return -(m_rightMotorFront.GetSelectedSensorPosition(0) - m_r1_enc_zero);
}

int Drivetrain::GetRightEncoder2(void)
{
    return -(m_rightMotorBack.GetSelectedSensorPosition(0) - m_r2_enc_zero);
}

void Drivetrain::HardResetEncoders(void)
{

    //** WARNING ***
    //It takes several cycles to perform a hard reset on the Falcons
    //Do not use encoders immediately after a reset
    std::cout<< "Hard Encoder Reset" << std::endl;


    m_leftMotorFront.SetSelectedSensorPosition(0);
    m_leftMotorBack.SetSelectedSensorPosition(0);
    m_rightMotorFront.SetSelectedSensorPosition(0);
    m_rightMotorBack.SetSelectedSensorPosition(0);
    //
    m_l1_enc_zero = 0;
    m_l2_enc_zero = 0;
    m_r1_enc_zero = 0;
    m_r2_enc_zero = 0;
}



void Drivetrain::ResetEncoders(void)
{
    std::cout<< "Soft Encoder Reset" << std::endl;

    m_l1_enc_zero = m_leftMotorFront.GetSelectedSensorPosition(0);
    m_l2_enc_zero = m_leftMotorBack.GetSelectedSensorPosition(0);
    m_r1_enc_zero = m_rightMotorFront.GetSelectedSensorPosition(0);
    m_r2_enc_zero = m_rightMotorBack.GetSelectedSensorPosition(0);


}



//**************** AHRS (NavX) *********************
bool Drivetrain::IsGyroConnected(void)
{
	return m_ahrs.IsConnected();
}

double Drivetrain::GetGyroYaw(void)
{
    //Returns Relative Yaw:  -180 to +180
	return (double) m_ahrs.GetYaw();  
}

double Drivetrain::GetGyroAngle(void)
{
    //returns total accumulated angle -inf to +inf  (continuous through 360deg)
	return (double)m_ahrs.GetAngle();
}

double Drivetrain::GetGyroRate(void)
{
	return m_ahrs.GetRate();
}
//ed was here
void Drivetrain::ZeroGyro(void)
{
  	std::cout<<"ZeroGyro"<<std::endl;
	m_ahrs.ZeroYaw();
}





