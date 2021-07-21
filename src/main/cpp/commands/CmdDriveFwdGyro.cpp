
#include "commands/CmdDriveFwdGyro.h"

CmdDriveFwdGyro::CmdDriveFwdGyro(Drivetrain *drivetrain, double power, double heading, double distance, bool stop, double timeout) 
{

    m_power    = power;
    m_heading  = heading;
    m_distance = distance;
    m_stop     = stop;
    m_timeout  = timeout;

    m_ptrDrivetrain = drivetrain;
    AddRequirements({m_ptrDrivetrain});
}

// Called when the command is initially scheduled.
void CmdDriveFwdGyro::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdDriveFwdGyro::Execute() {}

// Called once the command ends or is interrupted.
void CmdDriveFwdGyro::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveFwdGyro::IsFinished() {
  return false;
}
