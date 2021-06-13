#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "GamepadMap.h"
#include <frc2/Timer.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

#include "subsystems/LEDPanel.h"
#include "subsystems/Drivetrain.h"


class RobotContainer 
{
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();



  // Our Code (good)

  frc2::Timer m_timer;
  frc::XboxController m_botDriver{0};
  frc::XboxController m_topOperator{1};
  LEDPanel            m_ledPanel;
  Drivetrain          m_drivetrain;


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
