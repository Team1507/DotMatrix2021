#include "commands/CmdSpinControlPanelToColor.h"
#include "frc/smartdashboard/SmartDashboard.h"
CmdSpinControlPanelToColor::CmdSpinControlPanelToColor(double wantedColor, ControlPanel *controlPanel) 
{
  m_wantedColor = wantedColor;
  m_ptrControlPanel = controlPanel;

  AddRequirements({m_ptrControlPanel});
}

void CmdSpinControlPanelToColor::Initialize() 
{
  m_ptrControlPanel->SpinControl();
  m_onColor = false;
}

void CmdSpinControlPanelToColor::Execute() 
{
  m_color = m_ptrControlPanel->GetColor();

  if (m_color == m_wantedColor)
  {
      m_onColor = true;
  }
  std::cout<<m_onColor<<std::endl;
}

void CmdSpinControlPanelToColor::End(bool interrupted) 
{
  m_ptrControlPanel->StopSpinControl();
}

bool CmdSpinControlPanelToColor::IsFinished() 
{
  return m_onColor;
}
