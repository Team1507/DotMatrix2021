
#pragma once

#include "subsystems/Drivetrain.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>


class CmdDriveFwdGyro
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriveFwdGyro> {
 public:
  CmdDriveFwdGyro(Drivetrain *drivetrain, double power, double heading, double distance, bool stop, double timeout);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
    Drivetrain *m_ptrDrivetrain;

    double m_power;
    double m_heading;
    double m_distance;
    bool m_stop;
    double m_timeout;
};
