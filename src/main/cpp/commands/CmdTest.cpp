
#include "commands/CmdTest.h"

CmdTest::CmdTest(Limelight *limelight) 
{
  m_limelight = limelight; 
}

void CmdTest::Initialize() 
{
  m_limelight->TogglePipeLine();
}

void CmdTest::Execute() {}

void CmdTest::End(bool interrupted) {}

bool CmdTest::IsFinished() {
  return true;
}
