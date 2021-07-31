// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveTurn2Angle.h"

CmdDriveTurn2Angle::CmdDriveTurn2Angle(Drivetrain *drivetrain, double power, double angle ) 
{
  m_ptrDrivetrain = drivetrain;
  m_power = power;
  m_angle = angle;

  
  AddRequirements({m_ptrDrivetrain});
}

void CmdDriveTurn2Angle::Initialize() 
{
	m_calcAngle   = m_ptrDrivetrain->GetGyroAngle() + m_angle;	//Calculate degrees to turn
	m_isRightTurn = m_angle > 0;								                //Right turn if angle positive    
}

void CmdDriveTurn2Angle::Execute() 
{
	if( m_isRightTurn )
	{
		//Right turn.  Drive LEFT motor hard
		m_ptrDrivetrain->Drive(m_power, -0.05);
	}
	else
	{
		//Left turn.  Drive RIGHT motor hard
		m_ptrDrivetrain->Drive(-0.05, m_power);
	}
}

void CmdDriveTurn2Angle::End(bool interrupted) 
{
	m_ptrDrivetrain->Stop();  
}

bool CmdDriveTurn2Angle::IsFinished() 
{
	if( m_isRightTurn )
	{
		//Right turn: Done when Yaw becomes greater than calc angle
		if( m_ptrDrivetrain->GetGyroAngle() >= m_calcAngle)
		{
			return true;
		}
	}
	else
	{
		//Left Turn:  Done when Yaw becomes less than calc angle
		if( m_ptrDrivetrain->GetGyroAngle() <= m_calcAngle)
		{
			return true;
		}
	}
  return false;
}
