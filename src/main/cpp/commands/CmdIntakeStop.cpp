#include "commands/CmdIntakeStop.h"

CmdIntakeStop::CmdIntakeStop(Intake *intake) 
{
  m_ptrIntake = intake;

  //AddRequirements({m_ptrIntake});
}

void CmdIntakeStop::Initialize() 
{
    m_ptrIntake->IntakeStop();
}

void CmdIntakeStop::Execute() {}

void CmdIntakeStop::End(bool interrupted) {}

bool CmdIntakeStop::IsFinished() {
  return true;
}
