// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GrpDriveTest.h"

#include "commands/CmdPrintAutoText.h"
#include <frc2/command/WaitCommand.h>

#include "commands/CmdDriveFwdEncoder.h"


GrpDriveTest::GrpDriveTest(Drivetrain *drivetrain) 
{

  AddCommands(

    CmdPrintAutoText("Running GrpDriveTest"),

 
    CmdDriveFwdEncoder(drivetrain, 0.0, 18, true, 2.0 ),


    //frc2::WaitCommand( units::second_t(2.0)  ),

    CmdPrintAutoText("GrpDriveTest Complete")

    //Should have a STOP here for safety!



  );

}
