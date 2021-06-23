#include "commands/CmdSetIntake.h"

CmdSetIntake::CmdSetIntake(bool isRunning, Intake *intake) 
{
  m_ptrIntake = intake;
  m_isRunning = isRunning;
  AddRequirements({m_ptrIntake});
}

void CmdSetIntake::Initialize() 
{
    if(m_isRunning)
    {
        m_ptrIntake->IntakeForward();
    }
    else if(!m_isRunning)
    {
        m_ptrIntake->IntakeStop();
    }
}

void CmdSetIntake::Execute() {}

void CmdSetIntake::End(bool interrupted) {}

bool CmdSetIntake::IsFinished() {
  return true;
}
