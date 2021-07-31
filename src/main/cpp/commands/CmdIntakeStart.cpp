#include "commands/CmdIntakeStart.h"

CmdIntakeStart::CmdIntakeStart(Intake *intake) 
{
  m_ptrIntake = intake;

  //AddRequirements({m_ptrIntake});
}

void CmdIntakeStart::Initialize() 
{
  m_ptrIntake->IntakeForward();
}

void CmdIntakeStart::Execute() {}

void CmdIntakeStart::End(bool interrupted) {}

bool CmdIntakeStart::IsFinished() {
  return true;
}
