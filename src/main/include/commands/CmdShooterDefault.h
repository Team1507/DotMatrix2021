#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"
#include <frc/XboxController.h>
class CmdShooterDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdShooterDefault> {
 public:
  CmdShooterDefault(Shooter *shooter, frc::XboxController *operator_xbox);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  Shooter *m_ptrShooter;
  frc::XboxController *m_ptrOperatorXbox;
  int m_hood_angle;
};
