// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdIntakeDefault.h"
#include "GamepadMap.h"
#include "frc/smartdashboard/SmartDashboard.h"

CmdIntakeDefault::CmdIntakeDefault(Intake *intake, frc::XboxController *operator_xbox) 
{

  m_ptrIntake       = intake;
  m_ptrOperatorXbox = operator_xbox;
  m_isIntaking      = false;


  //SetName("Intake");
  AddRequirements({m_ptrIntake});

}


void CmdIntakeDefault::Initialize() 
{
  frc::SmartDashboard::PutNumber("INTAKE_POWER", 0.7);
}


void CmdIntakeDefault::Execute() 
{
    
    bool isTriggerPressed = m_ptrOperatorXbox->GetRawAxis(  GAMEPADMAP_AXIS_L_TRIG) >= .5;
    bool isBumperPressed  = m_ptrOperatorXbox->GetRawButton(GAMEPADMAP_BUTTON_LBUMP);   

    if( isTriggerPressed && !m_isIntaking )
    {
        m_ptrIntake->IntakeForward();
        m_isIntaking = true;
    }
    else if( isBumperPressed && !m_isIntaking )
    {
        m_ptrIntake->IntakeBackward();
        m_isIntaking = true;
    }
    else if( m_isIntaking )
    {
        m_ptrIntake->IntakeStop();
        m_isIntaking = false;
    }
}


void CmdIntakeDefault::End(bool interrupted) 
{

}


bool CmdIntakeDefault::IsFinished() 
{
  return false;
}
