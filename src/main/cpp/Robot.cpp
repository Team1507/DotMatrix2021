#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit()
 {
    //*************************** INIT ******************************
    std::cout<<"RobotInit"<<std::endl;
    std::cout<<"FRC2021: Infinite Recharge ~~~DotMatrix~~~"<<std::endl;
    std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 
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
    m_container.m_topOperator.SetRumble(frc::GenericHID::kRightRumble,0);
    m_container.m_topOperator.SetRumble(frc::GenericHID::kLeftRumble,0);
 }

void Robot::DisabledPeriodic() 
{

}


void Robot::AutonomousInit() 
{
    std::cout<<"Auto Init"<<std::endl;
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) 
  {
    m_autonomousCommand->Schedule();
  }
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

    m_container.m_timer.Reset();
    m_container.m_timer.Start();
    m_container.m_topOperator.SetRumble(frc::GenericHID::kRightRumble,1.0);
    m_container.m_topOperator.SetRumble(frc::GenericHID::kLeftRumble,1.0);
}


void Robot::TeleopPeriodic()
 {

 }


void Robot::TestPeriodic() 
{

}

#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Robot>();
}
#endif

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

    frc::SmartDashboard::PutBoolean("TopAButton", (bool)m_container.m_topOperator.GetRawButton( GAMEPADMAP_BUTTON_A ) );
    frc::SmartDashboard::PutBoolean("TopBButton", (bool)m_container.m_topOperator.GetRawButton( GAMEPADMAP_BUTTON_B ) );
    frc::SmartDashboard::PutBoolean("TopXButton", (bool)m_container.m_topOperator.GetRawButton( GAMEPADMAP_BUTTON_X ) );
    frc::SmartDashboard::PutBoolean("TopYButton", (bool)m_container.m_topOperator.GetRawButton( GAMEPADMAP_BUTTON_Y ) );



}