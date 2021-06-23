#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Intake.h"

class CmdSetIntake
    : public frc2::CommandHelper<frc2::CommandBase, CmdSetIntake> {
 public:
  CmdSetIntake(bool isRunning, Intake *intake);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
   bool m_isRunning;
   Intake *m_ptrIntake;
};
