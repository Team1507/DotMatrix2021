#include "RobotContainer.h"

#include "frc/smartdashboard/SmartDashboard.h"
#include "frc2/command/PrintCommand.h"

//Buttons
#include"commands/CmdTest1.h"
#include "commands/GrpTest.h"
#include "commands/GrpDriveTest.h"
#include "commands/CmdDriveClearAll.h"



//Default Commands
#include "commands/CmdDriveWithGamepad.h"
#include "commands/CmdIntakeDefault.h"
#include "commands/CmdControlPanelDefult.h"



RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem)
{

  //Smartdashboard Buttons
  frc::SmartDashboard::PutData("TestCmd1",  new CmdTest1() );
  frc::SmartDashboard::PutData("TestGroup", new GrpTest()  );
  frc::SmartDashboard::PutData("GrpDriveTest", new GrpDriveTest(&m_drivetrain)  );
  frc::SmartDashboard::PutData("CmdDriveClearAll", new CmdDriveClearAll(&m_drivetrain)  );

  //Default Commands
  m_drivetrain.SetDefaultCommand( CmdDriveWithGamepad( &m_drivetrain, &m_botDriver)  );
  m_intake.SetDefaultCommand( CmdIntakeDefault( &m_intake, &m_topOperator ) );
  m_controlPanel.SetDefaultCommand( CmdControlPanelDefult( &m_controlPanel, &m_topOperator));

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
