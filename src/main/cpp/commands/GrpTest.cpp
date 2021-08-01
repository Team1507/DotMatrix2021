// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GrpTest.h"
#include "commands/CmdDriveManual.h"
#include "commands/CmdPrintAutoText.h"
#include <frc2/command/WaitCommand.h>

#include "commands/CmdRampExtend.h"
#include "commands/CmdRampRetract.h"
#include "commands/CmdCarouselSetPower.h"
#include "commands/CmdCarouselStop.h"
#include "commands/CmdFeederSetPower.h"
#include "commands/CmdFeederStop.h"
#include "commands/CmdShooterSetVelocity.h"
#include "commands/CmdShooterStop.h"
#include "commands/CmdIntakeStart.h"
#include "commands/CmdIntakeStop.h"


GrpTest::GrpTest(Drivetrain *drivetrain, Shooter *shooter, Intake *intake) 
{

  AddCommands(

    CmdPrintAutoText("Running GrpTest"),

    //frc2::WaitCommand( units::second_t(2.0)  ),
    //CmdPrintAutoText(" ON!"),
    //frc2::WaitCommand( units::second_t(2.0)  ),
    //CmdPrintAutoText("OFF"),

    frc2::WaitCommand( units::second_t(1.0)  ),

    CmdRampExtend(shooter),
    frc2::WaitCommand( 2.0_s ),
    CmdRampRetract(shooter),
    
    
    frc2::WaitCommand( 1.0_s ),


    CmdIntakeStart(intake),
    frc2::WaitCommand( 2.0_s ),
    CmdIntakeStop(intake),



    frc2::WaitCommand( 1.0_s ),


/* 
    CmdCarouselSetPower(shooter, CAROUSEL_SHOOTING_POWER ),
    frc2::WaitCommand( 2.0_s ),
    CmdCarouselStop(shooter),


    frc2::WaitCommand( 1.0_s ),


    CmdFeederSetPower(shooter, FEEDER_SHOOTING_POWER ),
    frc2::WaitCommand( 2.0_s ),
    CmdFeederStop(shooter),


    frc2::WaitCommand( 1.0_s ),

    CmdShooterSetVelocity(shooter, SHOOTER_IDLE_VELOCITY),
    frc2::WaitCommand( 2.0_s ),
    CmdShooterStop(shooter),

     */

    
    //************************************
    CmdPrintAutoText("GrpTest Complete")

  );

}
