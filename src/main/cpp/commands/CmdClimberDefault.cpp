#define LIGHTSABER_UP_MULTIPLIER   .5
#define LIGHTSABER_DOWN_MULTIPLIER .25
#define WINCH_POWER 1.0
#define REVERSE_WINCH_POWER 0.4
#include "commands/CmdClimberDefault.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "GamepadMap.h"

CmdClimberDefault::CmdClimberDefault( Climber *climber, frc::XboxController *operator_xbox, frc::XboxController *driver_xbox) 
{
  m_ptrClimber = climber;
  m_ptrOperatorXbox = operator_xbox;
  m_ptrDriverXbox = driver_xbox;
  AddRequirements({m_ptrClimber});
}

void CmdClimberDefault::Initialize() {}

void CmdClimberDefault::Execute() 
{ 
  if(m_ptrDriverXbox->GetRawButton(GAMEPADMAP_BUTTON_Y) && !m_ptrClimber->IsClimbActivated())
  {
    m_ptrClimber->SetClimbActivated();
  }
  else if(!m_ptrDriverXbox->GetRawButton(GAMEPADMAP_BUTTON_Y) && m_ptrClimber->IsClimbActivated())
  {
    m_ptrClimber->ClearClimbActivated();
  }
  double gamepadAxis = ((m_ptrOperatorXbox->GetRawAxis(GAMEPADMAP_AXIS_L_Y)) );
    double climberPower = 0;
    static bool isIdle = true;    //flag to prevent 0-spam

    //if pressed up, assign power upwards with up multiplier, if pressed downward use downward multiplier
    climberPower = (gamepadAxis < 0)? (gamepadAxis*LIGHTSABER_UP_MULTIPLIER) : (gamepadAxis*LIGHTSABER_DOWN_MULTIPLIER);
    
    if(m_ptrOperatorXbox->GetRawButton(GAMEPADMAP_BUTTON_Y)  && m_ptrClimber->IsClimbActivated() )
    {
        m_ptrClimber->MoveLightsaber(climberPower);
        isIdle = false;
    }
    else if(!isIdle)
    {
        isIdle = true;
        m_ptrClimber->MoveLightsaber(0.0);
    }

    //**************
    //Climb Motor
    //bool driverClimb = Robot::m_oi.GetDriverGamepad()->GetRawButton(GAMEPADMAP_BUTTON_START);
    bool operatorClimb = m_ptrOperatorXbox->GetRawButton(GAMEPADMAP_BUTTON_START);
    bool reverseOperatorClimb = m_ptrOperatorXbox->GetRawButton(GAMEPADMAP_BUTTON_BACK);  

    if(operatorClimb && m_ptrClimber->IsClimbActivated()) //&& driverClimb)
    {
        m_ptrClimber->SetLeftWinchMotor(WINCH_POWER);
        m_ptrClimber->SetRightWinchMotor(WINCH_POWER);
    }
    else if( reverseOperatorClimb && m_ptrClimber->IsClimbActivated() )
    {
        m_ptrClimber->SetLeftWinchMotor(-REVERSE_WINCH_POWER);
        m_ptrClimber->SetRightWinchMotor(-REVERSE_WINCH_POWER);
    }
    else
    {   
        m_ptrClimber->SetLeftWinchMotor(0.0);
        m_ptrClimber->SetRightWinchMotor(0.0);
    }


    //SmartDashboard
    frc::SmartDashboard::PutBoolean("ClimbEnabled", m_ptrClimber->IsClimbActivated() ); 
}

void CmdClimberDefault::End(bool interrupted) {}

bool CmdClimberDefault::IsFinished() {
  return false;
}
