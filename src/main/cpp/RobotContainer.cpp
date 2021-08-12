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
#include "commands/CmdControlPanelDefault.h"
#include "commands/CmdShooterDefault.h"
#include "commands/CmdClimberDefault.h"



RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem)
{

  //Smartdashboard Button
  frc::SmartDashboard::PutData("TestCmd1",  new CmdTest1() );
  frc::SmartDashboard::PutData("TestGroup", new GrpTest(&m_drivetrain,&m_shooter,&m_intake)  );
  frc::SmartDashboard::PutData("GrpDriveTest", new GrpDriveTest(&m_drivetrain)  );
  frc::SmartDashboard::PutData("CmdDriveClearAll", new CmdDriveClearAll(&m_drivetrain)  );


  //Default Commands
  m_drivetrain.SetDefaultCommand(   CmdDriveWithGamepad( &m_drivetrain, &m_botDriver)  );
  m_intake.SetDefaultCommand(       CmdIntakeDefault( &m_intake, &m_topOperator ) );
  m_controlPanel.SetDefaultCommand( CmdControlPanelDefault( &m_controlPanel, &m_topOperator));
  m_shooter.SetDefaultCommand(      CmdShooterDefault( &m_shooter, &m_topOperator ));
  m_climber.SetDefaultCommand( CmdClimberDefault(&m_climber, &m_topOperator,&m_botDriver));

  //Auto
  m_chooser.SetDefaultOption("Auto Do Nothing",  &m_autoDoNothing );
  m_chooser.AddOption("Auto Just Shoot", &m_autoJustShoot );

  // Put the chooser on the dashboard
  frc::SmartDashboard::PutData(&m_chooser);

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
  m_btn_driver_A.WhenPressed(  frc2::PrintCommand("A button was pressed")  );

  m_btn_driver_B.WhenPressed(  frc2::PrintCommand("B button was pressed")  ).WhenReleased(  frc2::PrintCommand("B button was Released")  );



}


frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  return m_chooser.GetSelected();
  //return &m_autonomousCommand;
}
