// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdPrintAutoText.h"


CmdPrintAutoText::CmdPrintAutoText(std::string text) 
{
  m_text = text;
}

void CmdPrintAutoText::Initialize() 
{  
  std::cout << m_text << std::endl; 
}
