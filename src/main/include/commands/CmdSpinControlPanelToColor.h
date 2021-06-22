#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ControlPanel.h"

class CmdSpinControlPanelToColor
    : public frc2::CommandHelper<frc2::CommandBase, CmdSpinControlPanelToColor> {
 public:
  CmdSpinControlPanelToColor( double wantedColor , ControlPanel *controlPanel);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  
  private:
  ControlPanel *m_ptrControlPanel;
  double m_color;
  double m_wantedColor;
  bool   m_onColor;
};
