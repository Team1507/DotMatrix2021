// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GrpDriveTest.h"

#include "commands/CmdPrintAutoText.h"
#include <frc2/command/WaitCommand.h>

#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveManual.h"
#include "commands/CmdWaitStopped.h"
#include "commands/CmdDriveFwdEncoder.h"
#include "commands/CmdDriveRevEncoder.h"
#include "commands/CmdDriveFwdGyroV2.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "commands/CmdDriveTurn2Angle.h"

GrpDriveTest::GrpDriveTest(Drivetrain *drivetrain) 
{

  AddCommands(

    CmdPrintAutoText("Running GrpDriveTest"),
    CmdDriveClearAll(drivetrain),
    //frc2::WaitCommand( units::second_t(2.0)  ),


    //CmdDriveFwdEncoder(drivetrain, 0.0, 18, true, 2.0 ),


    // CmdDriveFwdEncoder(drivetrain, 0.5, 75,true,3.0),
    // CmdWaitStopped(drivetrain,1.0),
    // CmdDriveRevEncoder(drivetrain, 0.5, 75,true,3.0),

    // CmdDriveFwdGyroV2( drivetrain, 0.3, 0.0, 100, true,true, 0.0),
    // CmdWaitStopped(drivetrain,1.0),
    // CmdDriveRevGyroV2( drivetrain, 0.3, 0.0, 100, true,true, 0.0),

    CmdDriveFwdGyroV2( drivetrain, 0.3, 0.0, 100, true,true, 0.0 ),

    CmdDriveTurn2Angle(drivetrain, 0.3, 45.0 ),

    //*********************************************
    CmdPrintAutoText("GrpDriveTest Complete"),
    //STOP here for safety!
    CmdDriveManual(drivetrain, 0,0,0)

  );

}
