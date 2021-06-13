#include "RobotContainer.h"

#include "frc/smartdashboard/SmartDashboard.h"
#include "frc2/command/PrintCommand.h"

//Buttons
#include"commands/CmdTest1.h"
#include "commands/GrpTest.h"


//Default Commands
#include "commands/CmdDriveWithGamepad.h"



RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem)
{

  //Smartdashboard Buttons
  frc::SmartDashboard::PutData("TestCmd1",  new CmdTest1() );
  frc::SmartDashboard::PutData("TestGroup", new GrpTest()  );



  //Default Commands
  m_drivetrain.SetDefaultCommand( CmdDriveWithGamepad( &m_drivetrain, &m_botDriver)  );


  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
  m_btn_driver_A.WhenPressed(  frc2::PrintCommand("A button was pressed")  );

  m_btn_driver_B.WhenPressed(  frc2::PrintCommand("B button was pressed")  ).WhenReleased(  frc2::PrintCommand("B button was Released")  );



}


frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  
  return &m_autonomousCommand;
}
