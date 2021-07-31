#include "Robot.h"
#include "commands/CmdWaitStopped.h"

CmdWaitStopped::CmdWaitStopped(Drivetrain *drivetrain, double time) 
{
    m_ptrDrivetrain = drivetrain;
    m_time = time;

    AddRequirements({m_ptrDrivetrain});
}

// Called when the command is initially scheduled.
void CmdWaitStopped::Initialize() 
{
    m_timer.Reset();
    m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void CmdWaitStopped::Execute() 
{
    //Continuously update drivertrain so we don't get MotorSaftey Errors
    m_ptrDrivetrain->Stop();
}

// Called once the command ends or is interrupted.
void CmdWaitStopped::End(bool interrupted) 
{
}

// Returns true when the command should end.
bool CmdWaitStopped::IsFinished() 
{
    return m_timer.HasElapsed(units::second_t(m_time));
}
