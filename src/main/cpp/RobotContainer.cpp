#include "RobotContainer.h"

#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/CmdDriveWithGamepad.h"



RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem)
{



  //Smartdashboard Buttons
  //frc::SmartDashboard::PutData("TestCmd", new NewCommandTest("From Smartdashboard Button"));
  //frc::SmartDashboard::PutData("GrpDriveTest", new GrpDriveTest(&m_drivetrain));

  //Default Commands
  m_drivetrain.SetDefaultCommand( CmdDriveWithGamepad( &m_drivetrain, &m_botDriver)  );


  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  
  return &m_autonomousCommand;
}
