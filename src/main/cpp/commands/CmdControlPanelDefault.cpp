#include "commands/CmdControlPanelDefault.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "GamepadMap.h"
#define BOTTOM_STATE 0
#define GOING_UP     1
#define HOLDING_TOP  2
#define GOING_DOWN   3

CmdControlPanelDefault::CmdControlPanelDefault( ControlPanel *controlPanel, frc::XboxController *operator_xbox) 
{
  m_ptrControlPanel = controlPanel;
  m_ptrOperatorXbox = operator_xbox;
  
  AddRequirements({m_ptrControlPanel});
}

void CmdControlPanelDefault::Initialize() {}

void CmdControlPanelDefault::Execute() 
{

  static int movementState = 0;

  bool botLS    = m_ptrControlPanel->isBottomSwitchPress();
  bool topLS    = m_ptrControlPanel->isTopSwitchPress();

   bool isDeploy = m_ptrOperatorXbox->GetRawAxis(GAMEPADMAP_AXIS_R_Y) < -0.5;
   bool isSpin   = m_ptrOperatorXbox->GetRawButton(GAMEPADMAP_BUTTON_A);

  frc::SmartDashboard::PutNumber("CtrlPanel State", movementState);
    
  //Spinner Deploy State Machine   
  switch (movementState)
  {
  case BOTTOM_STATE:  //this state brings it back to the bottom
      if(isDeploy)
      {
          movementState = GOING_UP;//start moving up
      }
       break;
  
  case GOING_UP:
      if(botLS) 
      {
          m_ptrControlPanel->TURBODeployControl();
      }
      else if(topLS)
      {
          movementState = HOLDING_TOP;
      }        
      else if(!botLS)
      {
          m_ptrControlPanel->DeployControl();
      }

      if(!isDeploy) 
      {
          movementState = GOING_DOWN;
      }
      break;
  case HOLDING_TOP:
      if(!topLS) 
      {
          movementState = GOING_UP;
      }
      if(!isDeploy) 
      {
          movementState = GOING_DOWN;
      }
      m_ptrControlPanel->HoldTopControl();
      break;
  case GOING_DOWN:
      if(topLS)
      {
          m_ptrControlPanel->TURBORetractControl();
      }
      else if(botLS)
      {
          movementState = BOTTOM_STATE;
      }        
      else if(!topLS)
      {
          m_ptrControlPanel->RetractControl();
      }

      if(isDeploy) 
      {
          movementState = GOING_UP;
      }
      break;
  default:
      std::cout<<"SOS!!!!!"<<std::endl;
      break;
  }


  //Spinner State Machine
  //More smarts need to go here.
  //if( (movementState == HOLDING_TOP) && isSpin )
  static bool spinFlag = false;
  if( (movementState == HOLDING_TOP) && isSpin && !spinFlag)
  {
      m_ptrControlPanel->SpinControl();
      spinFlag = true;
  }
  else if(spinFlag && !isSpin)
  {
      m_ptrControlPanel->StopSpinControl();
      spinFlag = false;
  }


  frc::SmartDashboard::PutNumber("Spinner Encoder", m_ptrControlPanel->GetSpinnerEncoder()  );
  frc::SmartDashboard::PutNumber("Spinner Color", m_ptrControlPanel->GetColor()  );
}

void CmdControlPanelDefault::End(bool interrupted) {}

bool CmdControlPanelDefault::IsFinished() {
  return false;
}
