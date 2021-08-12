#pragma once

#include <frc2/command/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "GamepadMap.h"
#include <frc2/Timer.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

#include "subsystems/LEDPanel.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/ControlPanel.h"
#include "subsystems/Shooter.h"
#include "subsystems/Limelight.h"
#include "subsystems/Climber.h"

//Auto
#include "commands/AutoDoNothing.h"
#include "commands/AutoJustShoot.h"

class RobotContainer 
{
 public:
  RobotContainer();


  // Our Code (good)

  frc2::Timer m_timer;
  frc::XboxController m_botDriver{0};
  frc::XboxController m_topOperator{1};
  LEDPanel            m_ledPanel;
  Drivetrain          m_drivetrain;
  Intake              m_intake;
  ControlPanel        m_controlPanel;
  Shooter             m_shooter;
  Limelight           m_limelight;
  Climber             m_climber;

  //Autonomous Setup
  frc2::Command* GetAutonomousCommand();
  frc::SendableChooser<frc2::Command*> m_chooser;

  //List Auto Commands here
  AutoDoNothing m_autoDoNothing{ &m_drivetrain };
  AutoJustShoot m_autoJustShoot{ &m_drivetrain, &m_shooter, &m_limelight };


 private:
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;


  //Buttons
  void ConfigureButtonBindings();
  frc2::JoystickButton m_btn_driver_A{&m_botDriver, GAMEPADMAP_BUTTON_A};
  frc2::JoystickButton m_btn_driver_B{&m_botDriver, GAMEPADMAP_BUTTON_B};
  frc2::JoystickButton m_btn_driver_X{&m_botDriver, GAMEPADMAP_BUTTON_X};
  frc2::JoystickButton m_btn_driver_Y{&m_botDriver, GAMEPADMAP_BUTTON_Y};



};
