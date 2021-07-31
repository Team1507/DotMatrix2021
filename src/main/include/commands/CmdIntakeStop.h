#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Intake.h"

class CmdIntakeStop
    : public frc2::CommandHelper<frc2::CommandBase, CmdIntakeStop> {
 public:
  CmdIntakeStop(Intake *intake);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
   Intake *m_ptrIntake;
};
