

#pragma once

#include <frc2/Timer.h>
#include "subsystems/Drivetrain.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdDriveManual
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriveManual> {
 public:
  CmdDriveManual(Drivetrain *drivetrain, double left_drive, double right_drive, double time);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
      Drivetrain *m_ptrDrivetrain; 

      double m_left_drive;
      double m_right_drive;
      double m_time;

      frc2::Timer m_timer;
};
