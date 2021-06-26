// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveFwdEncoder.h"


CmdDriveFwdEncoder::CmdDriveFwdEncoder(Drivetrain *drivetrain, double power, double distance, bool stop, double timeout) 
{
  
  m_ptrDrivetrain = drivetrain;
  m_power    = power;
  m_distance = distance;
  m_stop     = stop;
  m_timeout  = timeout;

  AddRequirements({m_ptrDrivetrain});
}


void CmdDriveFwdEncoder::Initialize() 
{
  m_ptrDrivetrain->ResetEncoders();

  if( m_timeout > 0.0)
  {
    m_timer.Reset();
    m_timer.Start();
  }
}


void CmdDriveFwdEncoder::Execute() 
{
 	double l_dir = m_ptrDrivetrain->GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
	double r_dir = m_ptrDrivetrain->GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;
	double delta = l_dir - r_dir;

  const double kp    = 0.18; 

	m_ptrDrivetrain->Drive(m_power - delta*kp  ,  m_power + delta*kp ); 
}


void CmdDriveFwdEncoder::End(bool interrupted) 
{
  if(m_stop)
	{
		m_ptrDrivetrain->Stop();
	}
}


bool CmdDriveFwdEncoder::IsFinished() 
{

	double l_dir = m_ptrDrivetrain->GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
	double r_dir = m_ptrDrivetrain->GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;

	if(  (l_dir > m_distance) || (r_dir > m_distance)  )
	  return true;

	if ((m_timeout>0.0) && m_timer.HasElapsed( units::second_t(m_timeout) ) )
	{
		std::cout<<"CmdDriveFwdEncoder: Timeout"<<std::endl;
		return true;
	}

	return false;
}
