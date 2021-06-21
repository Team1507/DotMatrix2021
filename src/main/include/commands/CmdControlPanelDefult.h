#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ControlPanel.h"

#include <frc/XboxController.h>

class CmdControlPanelDefult
    : public frc2::CommandHelper<frc2::CommandBase, CmdControlPanelDefult> {
 public:
  CmdControlPanelDefult( ControlPanel *controlPanel, frc::XboxController *operator_xbox);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  ControlPanel        *m_ptrControlPanel;
  frc::XboxController *m_ptrOperatorXbox;
};
