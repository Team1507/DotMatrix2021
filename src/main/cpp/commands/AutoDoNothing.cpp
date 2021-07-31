// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoDoNothing.h"

#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveClearAll.h"

AutoDoNothing::AutoDoNothing(Drivetrain *drivetrain)
{
  AddCommands(

    //Auto Setup 
    CmdPrintAutoText("****** AutoDoNothing ******"),
    CmdDriveClearAll(drivetrain),

    //Auto Commands here




    //Clean up
    CmdPrintAutoText("AutoDoNothing Complete")

  );

}
