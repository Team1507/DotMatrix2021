#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem)
{

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  
  return &m_autonomousCommand;
}
