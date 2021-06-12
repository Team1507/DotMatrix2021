// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

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


    // m_leftMotorFront.SetStatusFramePeriod(StatusFrame::Status_2_Feedback0_,2,10 );
    // m_rightMotorFront.SetStatusFramePeriod(StatusFrame::Status_2_Feedback0_,2,10);
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



