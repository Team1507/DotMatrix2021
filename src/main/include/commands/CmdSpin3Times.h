#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ControlPanel.h"
class CmdSpin3Times
    : public frc2::CommandHelper<frc2::CommandBase, CmdSpin3Times> {
 public:
  CmdSpin3Times(ControlPanel *controlpanel);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  ControlPanel *m_ptrControlPanel;
  bool   m_isGreen;
  bool   m_isYellow;
  bool   m_isRed;
  bool   m_isBlue;
  double m_spins;
  double m_color;
  int m_numberGreenTruecounts;
  int m_numberGreenFalsecounts;
  int m_numberRedTruecounts;
  int m_numberRedFalsecounts;
  int m_numberYellowTruecounts;
  int m_numberYellowFalsecounts;
  int m_numberBlueTruecounts;
  int m_numberBlueFalsecounts;
};
