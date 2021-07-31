// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveRevGyroV2.h"

CmdDriveRevGyroV2::CmdDriveRevGyroV2(Drivetrain *drivetrain,double power, double heading, double distance, bool ramp, bool stop, double timeout) 
{
    m_ptrDrivetrain = drivetrain;
  	m_power    = (-1.0) * power;		//Reverse = negative power
	m_heading  = heading;
  	m_distance = (-1.0) * distance;     //Reverse = Negative distance
    m_stop     = stop;
    m_timeout  = timeout;

    m_ramp = ramp;
    m_base = 0;

    AddRequirements({m_ptrDrivetrain});

}

void CmdDriveRevGyroV2::Initialize() 
{

    m_ptrDrivetrain->ResetEncoders();
        
    m_base = -0.1;	//Initial Power

    if( m_timeout > 0.0)
    {
        m_timer.Reset();
        m_timer.Start();
    }

}

void CmdDriveRevGyroV2::Execute() 
{

    //Ramp base power
    if( m_ramp )
        m_base += (m_power - m_base) * Drivetrain::RAMP_FACTOR;
    else
        m_base = m_power;
    


    //Don't use GetGyroYaw; if we try to drive on -181 heading, yaw freaks out and goes positive
    double errorAngle = m_ptrDrivetrain->GetGyroAngle() - m_heading;
    double kp = 0.002; //was 0.05, then 0.04

    m_ptrDrivetrain->Drive(m_base - errorAngle*kp  ,  m_base + errorAngle*kp ); 
}

void CmdDriveRevGyroV2::End(bool interrupted) 
{

    if(m_stop)
    {
        m_ptrDrivetrain->Stop();
    }
}

bool CmdDriveRevGyroV2::IsFinished() 
{
    double l_dir = m_ptrDrivetrain->GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
    double r_dir = m_ptrDrivetrain->GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;

    if(  (l_dir <= m_distance) || (r_dir <= m_distance)  )
        return true;

    if ((m_timeout>0.0) && m_timer.HasElapsed( units::second_t(m_timeout) ) )
    {
        std::cout<<"CmdDriveRevGyroV2: Timeout"<<std::endl;
        return true;
    }

    return false;
}
