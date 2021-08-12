// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoJustShoot.h"

#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveClearAll.h"
#include "Commands/CmdWaitStopped.h"

#include "commands/CmdCarouselSetPower.h"
#include "commands/CmdCarouselStop.h"
#include "commands/CmdShooterSetVelocity.h"
#include "commands/CmdShooterStop.h"
#include "commands/CmdFeederSetPower.h"
#include "commands/CmdFeederStop.h"
#include "commands/CmdRampExtend.h"
#include "commands/CmdRampRetract.h"

#include "commands/CmdDriveFwdGyroV2.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "commands/CmdDriveTurn2Limelight.h"



AutoJustShoot::AutoJustShoot(Drivetrain *drivetrain, Shooter *shooter, Limelight *limelight) 
{
  AddCommands(
    
    CmdDriveClearAll(drivetrain),
    CmdPrintAutoText("****** AUTO JUST SHOOT ******"),

    //Spool up shooter and get ready to shoot
    CmdCarouselSetPower(shooter, CAROUSEL_IDLE_POWER),
    CmdShooterSetVelocity(shooter, SHOOTER_IDLE_VELOCITY),
    

    //Back up off line
    CmdWaitStopped(drivetrain, 0.1),
    CmdDriveRevGyroV2( drivetrain, 0.2, 0.0, 18, true,true, 0.0),

    //Set shooter to shoot velocity and aim at target
    CmdShooterSetVelocity(shooter, SHOOTER_AUTO_LINE_VELOCITY),
    CmdWaitStopped(drivetrain, 2.0),
    
    //CmdDriveTurn2Limelight(drivetrain,limelight),      

    //so anyway, I started blastin'
    CmdCarouselSetPower(shooter, CAROUSEL_SHOOTING_POWER), 
    CmdFeederSetPower(shooter, FEEDER_SHOOTING_POWER), 
    CmdRampExtend(shooter),
    CmdWaitStopped(drivetrain, 3.0),

    //Stop shooter, feeder, retract ramp
    CmdFeederStop(shooter),    
    CmdRampRetract(shooter),
    CmdShooterStop(shooter),
    CmdCarouselSetPower(shooter, CAROUSEL_IDLE_POWER),


    //move off the line;
    CmdDriveFwdGyroV2( drivetrain, 0.4 , 0, 72 , true, true , 0.0 ) ,   //48+24=72



    //Clean up
    CmdPrintAutoText("AutoJustShoot Complete")

  );
}
