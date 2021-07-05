#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/drive/DifferentialDrive.h>
#include "ctre/Phoenix.h"

#include <frc/TimedRobot.h>
#include <frc2/command/button/JoystickButton.h>

#include <frc2/command/Command.h>

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>


#define LEFTDRIVE_FRONT_CAN_ID  1
#define LEFTDRIVE_BACK_CAN_ID   2
#define RIGHTDRIVE_FRONT_CAN_ID 3
#define RIGHTDRIVE_BACK_CAN_ID  4 

#define MAX_DRIVE  0.85
#define DEADZONE 0.05

WPI_TalonFX m_leftMotorFront  { LEFTDRIVE_FRONT_CAN_ID };
WPI_TalonFX m_leftMotorBack   { LEFTDRIVE_BACK_CAN_ID  };
WPI_TalonFX m_rightMotorFront { RIGHTDRIVE_FRONT_CAN_ID };
WPI_TalonFX m_rightMotorBack  { RIGHTDRIVE_BACK_CAN_ID };

frc::XboxController m_botDriver{0};

frc::DifferentialDrive m_differentialDrive{ m_leftMotorFront, m_rightMotorFront };


class Poop : public frc::TimedRobot {
  void RobotInit() override {std::cout<<"Pain train here we come"<<std::endl;}
  void RobotPeriodic() override{}
  void DisabledInit() override
  {
    m_differentialDrive.ArcadeDrive( 0, 0);
  }
  void DisabledPeriodic() override{}
  void TeleopInit() override{}
  void TeleopPeriodic() override
  {
    // Deal with it B)
    double yL = m_botDriver.GetRawAxis(1);
    double xL = m_botDriver.GetRawAxis(0);
    double yR = m_botDriver.GetRawAxis(5);
    double xR = m_botDriver.GetRawAxis(4); 

    //double tL = m_driver_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_TRIG);
    //double tR = m_driver_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG);

    //Control DEADZONE
    if (fabs(yL)<= DEADZONE) yL = 0;
    if (fabs(xL)<= DEADZONE) xL = 0;
    if (fabs(yR)<= DEADZONE) yR = 0;
    if (fabs(xR)<= DEADZONE) xR = 0;

    //Subtract off DEADZONE
    if (fabs(yL)>= DEADZONE) yL +=  (yL>0)? -DEADZONE : +DEADZONE;
    if (fabs(xL)>= DEADZONE) xL +=  (xL>0)? -DEADZONE : +DEADZONE;
    if (fabs(yR)>= DEADZONE) yR +=  (yR>0)? -DEADZONE : +DEADZONE;
    if (fabs(xR)>= DEADZONE) xR +=  (xR>0)? -DEADZONE : +DEADZONE;


      //Test Drive
    yL *= MAX_DRIVE;	
    yR *= MAX_DRIVE;	

    m_differentialDrive.ArcadeDrive( -yL, xR );

  }
};


#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Poop>();
}
#endif

