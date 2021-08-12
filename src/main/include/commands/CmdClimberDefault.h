#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Climber.h"
#include <frc/XboxController.h>
class CmdClimberDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdClimberDefault> {
 public:
  CmdClimberDefault( Climber *climber, frc::XboxController *operator_xbox, frc::XboxController *driver_xbox);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  Climber               *m_ptrClimber;
  frc::XboxController   *m_ptrOperatorXbox;
  frc::XboxController   *m_ptrDriverXbox;
};
