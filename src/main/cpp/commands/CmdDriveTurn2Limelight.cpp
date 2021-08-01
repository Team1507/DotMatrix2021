// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveTurn2Limelight.h"


#define TOLRENCEZONE 0.5               //was 0.17
#define TIMEOUT      3.0

CmdDriveTurn2Limelight::CmdDriveTurn2Limelight(Drivetrain *drivetrain, Limelight *limelight) 
{
    m_Kp = 0.0015;
    m_minPower = 0.125;

    m_ptrDrivetrain = drivetrain;
    m_ptrLimelight  = limelight;
    AddRequirements({m_ptrDrivetrain});
}

void CmdDriveTurn2Limelight::Initialize() 
{

    std::cout<< "CmdDriveTurn2Limelight Init" << std::endl;

    double camera_offset = 0.0;   //frc::SmartDashboard::GetNumber( "LimelightOffset", 0.0 );

    bool isTarget = m_ptrLimelight->IsTarget();


    if( isTarget )
    {
        m_targetAngle = m_ptrDrivetrain->GetGyroYaw() + m_ptrLimelight->GetHOffset();  
        m_targetAngle += camera_offset;
    }
    else
    {
        std::cout<< "   *** No Target" << std::endl;
        m_targetAngle = m_ptrDrivetrain->GetGyroYaw();   //Target is at whatever angle we are at
    }
    

    std::cout<<"   CURR ANGLE "   << m_ptrDrivetrain->GetGyroYaw();
    std::cout<<"   TARGET ANGLE " << m_targetAngle<<std::endl;


    //Init Timeout Timer
    m_timer.Reset();
    m_timer.Start();
}

void CmdDriveTurn2Limelight::Execute() 
{
    double error = m_targetAngle - m_ptrDrivetrain->GetGyroYaw();
    double leftDrive = 0;
    double rightDrive = 0;
    
    if(error > TOLRENCEZONE)
    {
        // right turn
        leftDrive  = -((m_Kp * error) + m_minPower);
        rightDrive =  ((m_Kp * error) + m_minPower);
    }
    else if(error < -TOLRENCEZONE)
    {
        // left turn
        leftDrive  = -((m_Kp * error) - m_minPower);
        rightDrive =  ((m_Kp * error) - m_minPower);
    }
    else
    {
        //Right on target 
        leftDrive  = 0;
        rightDrive = 0;
    }
    m_ptrDrivetrain->Drive( -leftDrive, -rightDrive );
}

void CmdDriveTurn2Limelight::End(bool interrupted) 
{
    std::cout<< "CmdDriveTurn2Limelight Ended!" << std::endl;
    m_ptrDrivetrain->Drive(0,0);
}

bool CmdDriveTurn2Limelight::IsFinished() 
{
    double curr_yaw = m_ptrDrivetrain->GetGyroYaw();
     
    if(((m_targetAngle - TOLRENCEZONE) <= curr_yaw) && ((m_targetAngle + TOLRENCEZONE) >= curr_yaw)) 
    {
        std::cout<<"Finished, CMDTURN2LIMELIGHT: "<<m_targetAngle - curr_yaw<<std::endl;
        return true;
    }

    if( m_timer.HasElapsed( units::second_t(TIMEOUT) ) )
    {
        std::cout<< "CmdDriveTurn2Limelight TIMEOUT!!!!" << std::endl;
        return true;
    }

    return false;
}
