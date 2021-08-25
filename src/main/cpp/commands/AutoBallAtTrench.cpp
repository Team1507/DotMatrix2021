
#include "commands/AutoBallAtTrench.h"

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
#include "commands/CmdDriveTurn2Angle.h"

#include "commands/CmdIntakeStart.h"



AutoBallAtTrench::AutoBallAtTrench(Drivetrain *drivetrain, Shooter *shooter, Limelight *limelight, Intake *intake) 
{
  AddCommands(
    CmdPrintAutoText("AUTO BALL AT TRENCH"),
    CmdDriveClearAll(drivetrain),
    
    //Start up Intake/Shooter/Carousel
    CmdIntakeStart(intake),
    //Hood Code here
    CmdShooterSetVelocity(shooter, SHOOTER_TRENCH_VELOCITY),
    CmdCarouselSetPower(shooter, CAROUSEL_IDLE_POWER),


    //Drive back
    CmdDriveRevGyroV2( drivetrain, 0.4, 0.0, 132, true, true, 0.0),
    CmdWaitStopped(drivetrain, 0.1),

    //Drive Fwd
    CmdDriveFwdGyroV2(drivetrain, .4, -5.0, 28, true, true, 0.0),
    
    //Turn Toward Target
    CmdDriveTurn2Angle(drivetrain,.15,-10),
    CmdWaitStopped(drivetrain,4.0),
    CmdDriveTurn2Limelight(drivetrain, limelight),

    //shoot
    CmdCarouselSetPower(shooter, CAROUSEL_SHOOTING_POWER),
    CmdFeederSetPower(shooter, FEEDER_SHOOTING_POWER),

    CmdRampExtend(shooter),
    //shooting time
    CmdWaitStopped(drivetrain, 5.0),


    //stop everything
    CmdRampRetract(shooter),
    CmdFeederStop(shooter),
    CmdShooterStop(shooter),
    //hood code here
    CmdCarouselSetPower(shooter, CAROUSEL_IDLE_POWER),




    //Clean up
    CmdPrintAutoText("Auto Ball AT TRENCH Complete")

  );
}
