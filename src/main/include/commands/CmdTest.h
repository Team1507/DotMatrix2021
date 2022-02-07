#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Limelight.h"

class CmdTest
    : public frc2::CommandHelper<frc2::CommandBase, CmdTest> {
 public:
  CmdTest(Limelight *limelight);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  Limelight *m_limelight;
};
