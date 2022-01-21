#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit()
 {
    //*************************** INIT ******************************
    std::cout<<"RobotInit"<<std::endl;
    std::cout<<"FRC2021: Infinite Recharge code port"<<std::endl;
    std::cout<<"          ~~~ DotMatrix ~~~"<<std::endl;
    std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 

  //Julia was here

    m_container.m_ledPanel.SetAllLEDColor(255,255,0);  //Yellow
    m_container.m_drivetrain.InitFalcons();
    m_container.m_drivetrain.Stop();
    m_container.m_drivetrain.HardResetEncoders();
    m_container.m_drivetrain.ZeroGyro(); 
    m_container.m_drivetrain.ResetOdometry();
    m_container.m_shooter.ShooterInit();
    m_container.m_limelight.LimelightInit();
 }


void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();
  WriteToSmartDashboard();
}


void Robot::DisabledInit()
 {
    std::cout<<"Disabled Init"<<std::endl;
    m_container.m_timer.Stop();
    //m_container.m_topOperator.SetRumble(frc::GenericHID::kRightRumble,0);
    //m_container.m_topOperator.SetRumble(frc::GenericHID::kLeftRumble,0);
 }

void Robot::DisabledPeriodic() 
{

  m_container.m_ledPanel.LedPanelPeriodic();

}


void Robot::AutonomousInit() 
{
  std::cout<<"Auto Init"<<std::endl;
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) 
  {
    m_autonomousCommand->Schedule();
  }


  CheckAlliance();

}

void Robot::AutonomousPeriodic() 
{

}

void Robot::TeleopInit()
{
  std::cout<<"Teleop Init"<<std::endl;
  if (m_autonomousCommand != nullptr) 
  {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }

  CheckAlliance();

  m_container.m_timer.Reset();
  m_container.m_timer.Start();
  //m_container.m_topOperator.SetRumble(frc::GenericHID::kRightRumble,1.0);
  //m_container.m_topOperator.SetRumble(frc::GenericHID::kLeftRumble,1.0);
}


void Robot::TeleopPeriodic()
 {

 }



void Robot::CheckAlliance( void )
{

  //Set Panel LEDs
  if( m_ds.GetAlliance() == frc::DriverStation::kRed)
  {
      m_container.m_ledPanel.SetAllLEDColor(255, 0, 0);
  }
  else if(m_ds.GetAlliance() == frc::DriverStation::kBlue)
  {
      m_container.m_ledPanel.SetAllLEDColor(0,0,255);
  }
  else
  {
      m_container.m_ledPanel.SetAllLEDColor(255,255,0);
  }



}


void Robot::WriteToSmartDashboard(void)
{

    //Timers
    frc::SmartDashboard::PutNumber("FPGATime1", (double)m_container.m_timer.GetFPGATimestamp() );
    frc::SmartDashboard::PutNumber("Timer",     (double)m_container.m_timer.Get() );
    frc::SmartDashboard::PutNumber("MatchTime", (double)m_container.m_timer.GetMatchTime() );

    //Joystick Test
    frc::SmartDashboard::PutNumber("TopLeftXAxis",  (double)m_container.m_topOperator.GetRawAxis( GAMEPADMAP_AXIS_L_X ) ); 
    frc::SmartDashboard::PutNumber("TopLeftYAxis",  (double)m_container.m_topOperator.GetRawAxis( GAMEPADMAP_AXIS_L_Y ) );
    frc::SmartDashboard::PutNumber("TopRightXAxis", (double)m_container.m_topOperator.GetRawAxis( GAMEPADMAP_AXIS_R_X ) );
    frc::SmartDashboard::PutNumber("TopRightYAxis", (double)m_container.m_topOperator.GetRawAxis( GAMEPADMAP_AXIS_R_Y ) );

    // frc::SmartDashboard::PutBoolean("TopAButton", (bool)m_container.m_topOperator.GetRawButton( GAMEPADMAP_BUTTON_A ) );
    // frc::SmartDashboard::PutBoolean("TopBButton", (bool)m_container.m_topOperator.GetRawButton( GAMEPADMAP_BUTTON_B ) );
    // frc::SmartDashboard::PutBoolean("TopXButton", (bool)m_container.m_topOperator.GetRawButton( GAMEPADMAP_BUTTON_X ) );
    // frc::SmartDashboard::PutBoolean("TopYButton", (bool)m_container.m_topOperator.GetRawButton( GAMEPADMAP_BUTTON_Y ) );


    // frc::SmartDashboard::PutNumber("BotLeftXAxis",  (double)m_container.m_botDriver.GetRawAxis( GAMEPADMAP_AXIS_L_X ) ); 
    // frc::SmartDashboard::PutNumber("BotLeftYAxis",  (double)m_container.m_botDriver.GetRawAxis( GAMEPADMAP_AXIS_L_Y ) );
    // frc::SmartDashboard::PutNumber("BotRightXAxis", (double)m_container.m_botDriver.GetRawAxis( GAMEPADMAP_AXIS_R_X ) );
    // frc::SmartDashboard::PutNumber("BotRightYAxis", (double)m_container.m_botDriver.GetRawAxis( GAMEPADMAP_AXIS_R_Y ) );

    // frc::SmartDashboard::PutBoolean("BotAButton", (bool)m_container.m_botDriver.GetRawButton( GAMEPADMAP_BUTTON_A ) );
    // frc::SmartDashboard::PutBoolean("BotBButton", (bool)m_container.m_botDriver.GetRawButton( GAMEPADMAP_BUTTON_B ) );
    // frc::SmartDashboard::PutBoolean("BotXButton", (bool)m_container.m_botDriver.GetRawButton( GAMEPADMAP_BUTTON_X ) );
    // frc::SmartDashboard::PutBoolean("BotYButton", (bool)m_container.m_botDriver.GetRawButton( GAMEPADMAP_BUTTON_Y ) );


    //Nax-X
	  frc::SmartDashboard::PutBoolean("navx_IsConn", m_container.m_drivetrain.IsGyroConnected() );
	  frc::SmartDashboard::PutNumber("navx_Yaw",     m_container.m_drivetrain.GetGyroYaw()      );
   	frc::SmartDashboard::PutNumber("navx_Angle",   m_container.m_drivetrain.GetGyroAngle()    );

    //Odometry
    frc::SmartDashboard::PutNumber("Curr_X",    m_container.m_drivetrain.GetOdometryX() );
    frc::SmartDashboard::PutNumber("Curr_Y",    m_container.m_drivetrain.GetOdometryY() );
    frc::SmartDashboard::PutNumber("Curr_Vel",  m_container.m_drivetrain.GetOdometryVel() );
   	frc::SmartDashboard::PutNumber("Curr_Head", m_container.m_drivetrain.GetOdometryHeading() );

    //Motors
    frc::SmartDashboard::PutNumber("L_Motor",  m_container.m_drivetrain.GetLeftMotor()  );
    frc::SmartDashboard::PutNumber("R_Motor",  m_container.m_drivetrain.GetRightMotor()  );

    frc::SmartDashboard::PutNumber("LeftEnc",  m_container.m_drivetrain.GetLeftEncoder());
//  frc::SmartDashboard::PutNumber("LeftEnc2", m_container.m_drivetrain.GetLeftEncoder2());
    frc::SmartDashboard::PutNumber("RightEnc", m_container.m_drivetrain.GetRightEncoder());  
//  frc::SmartDashboard::PutNumber("RightEnc2",m_container.m_drivetrain.GetRightEncoder2());

  //
    frc::SmartDashboard::PutNumber("HOffset" , m_container.m_limelight.GetHOffset() );
    frc::SmartDashboard::PutNumber("Distance", m_container.m_limelight.GetDistance());
    frc::SmartDashboard::PutNumber("VAngle"  , m_container.m_limelight.GetVAngle()  );
    m_container.m_drivetrain.WriteFalconTemps();
    m_container.m_shooter.WriteFalconTemps();

}





//*********************************************************

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Robot>();
}
#endif

