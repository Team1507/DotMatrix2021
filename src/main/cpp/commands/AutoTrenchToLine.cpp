
#include "commands/AutoTrenchToLine.h"

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

#include "commands/CmdIntakeStart.h"



AutoTrenchToLine::AutoTrenchToLine(Drivetrain *drivetrain, Shooter *shooter, Limelight *limelight, Intake *intake) 
{
  AddCommands(
    
    CmdDriveClearAll(drivetrain),
    CmdPrintAutoText("****** AUTO TRENCH TO LINE ******"),

    //Start up Intake/Shooter/Carousel
    CmdIntakeStart(intake),
    //Hood Code here
    CmdShooterSetVelocity(shooter, SHOOTER_IDLE_VELOCITY),
    CmdCarouselSetPower(shooter, CAROUSEL_IDLE_POWER),


    //Drive back
    CmdDriveRevGyroV2( drivetrain, 0.4, 0.0, 132, true, true, 0.0),
    CmdWaitStopped(drivetrain, 0.1),

    //Drive Fwd
    CmdDriveFwdGyroV2(drivetrain, .4, -7.0, 25, true, false, 0.0),
    
    
    //Spin up the shooter
    CmdShooterSetVelocity(shooter, SHOOTER_LINE_VELOCITY),

    CmdDriveFwdGyroV2(drivetrain, .4, -90.0, 72, false, false, 0.0),


    //Turn Toward Target
    CmdDriveFwdGyroV2(drivetrain,.4, 25.0, 60, false, false, 0.0),
    CmdDriveFwdGyroV2(drivetrain,.4, 0, 2, false, true, 0.0),

    CmdWaitStopped(drivetrain, 3.0),
    CmdDriveTurn2Limelight(drivetrain, limelight),

    //shoot
    CmdCarouselSetPower(shooter, CAROUSEL_SHOOTING_POWER),
    CmdFeederSetPower(shooter, FEEDER_SHOOTING_POWER),

    CmdRampExtend(shooter),

    //shooting time
    CmdWaitStopped(drivetrain, 4.0),


    //stop everything
    CmdRampRetract(shooter),
    CmdFeederStop(shooter),
    CmdShooterStop(shooter),
    //hood code here
    CmdCarouselSetPower(shooter, CAROUSEL_IDLE_POWER),




    //Clean up
    CmdPrintAutoText("AutoTrenchToLine Complete")

  );
}
