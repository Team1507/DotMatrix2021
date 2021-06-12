#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "GamepadMap.h"
#include <frc2/Timer.h>
#include <frc/XboxController.h>


class RobotContainer 
{
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();



  // Our Code (good)

  frc2::Timer m_timer;
  frc::XboxController m_topOperator{0};


 private:
  
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  void ConfigureButtonBindings();
};
