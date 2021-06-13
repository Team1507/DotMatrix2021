// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GrpTest.h"

#include "commands/CmdPrintAutoText.h"
#include <frc2/command/WaitCommand.h>


GrpTest::GrpTest() 
{

  AddCommands(

    CmdPrintAutoText("Running GrpTest"),

    frc2::WaitCommand( units::second_t(2.0)  ),

    CmdPrintAutoText(" ON!"),

    frc2::WaitCommand( units::second_t(2.0)  ),

    CmdPrintAutoText("OFF"),

    CmdPrintAutoText("GrpTest Complete")


  );

}
