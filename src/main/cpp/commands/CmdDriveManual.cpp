#include "Robot.h"
#include "commands/CmdDriveManual.h"

CmdDriveManual::CmdDriveManual(Drivetrain *drivetrain, double left_drive, double right_drive, double time) 
{
    m_left_drive = left_drive;
    m_right_drive = right_drive;
    m_time = time;


    m_ptrDrivetrain = drivetrain;
    AddRequirements({m_ptrDrivetrain});
}

// Called when the command is initially scheduled.
void CmdDriveManual::Initialize() 
{
    

    m_timer.Reset();
    m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void CmdDriveManual::Execute() 
{
    m_ptrDrivetrain->Drive(m_left_drive, m_right_drive);
}

// Called once the command ends or is interrupted.
void CmdDriveManual::End(bool interrupted) 
{
    m_ptrDrivetrain->Stop();
}

// Returns true when the command should end.
bool CmdDriveManual::IsFinished() 
{
    return m_timer.HasElapsed(units::second_t(m_time));
  
}
