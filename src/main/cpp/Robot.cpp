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

WPI_TalonFX m_leftMotorFront  { LEFTDRIVE_FRONT_CAN_ID };
WPI_TalonFX m_leftMotorBack   { LEFTDRIVE_BACK_CAN_ID  };
WPI_TalonFX m_rightMotorFront { RIGHTDRIVE_FRONT_CAN_ID };
WPI_TalonFX m_rightMotorBack  { RIGHTDRIVE_BACK_CAN_ID };

frc::XboxController m_botDriver{0};

frc::DifferentialDrive m_differentialDrive{ m_leftMotorFront, m_rightMotorFront };


class Poop : public frc::TimedRobot {
  void RobotInit() override {std::cout<<"Pain train here we come"<<std::endl;}
  void RobotPeriodic() override{}
  void DisabledInit() override{}
  void DisabledPeriodic() override{}
  void TeleopInit() override{}
  void TeleopPeriodic() override{}
};



#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Poop>();
}
#endif



// const double DEADBAND           = 0.05;
//   	const double MAX_DRIVE_POWER    = 0.85;

// 	double yL = m_ptrDriverXbox->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
// 	double xL = m_ptrDriverXbox->GetRawAxis(GAMEPADMAP_AXIS_L_X);
// 	double yR = m_ptrDriverXbox->GetRawAxis(GAMEPADMAP_AXIS_R_Y);
// 	double xR = m_ptrDriverXbox->GetRawAxis(GAMEPADMAP_AXIS_R_X); 

// 	//double tL = m_driver_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_TRIG);
// 	//double tR = m_driver_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG);

// 	//Control DeadBand
// 	if (fabs(yL)<= DEADBAND) yL = 0;
// 	if (fabs(xL)<= DEADBAND) xL = 0;
// 	if (fabs(yR)<= DEADBAND) yR = 0;
// 	if (fabs(xR)<= DEADBAND) xR = 0;

// 	//Subtract off deadband
// 	if (fabs(yL)>= DEADBAND) yL +=  (yL>0)? -DEADBAND : +DEADBAND;
// 	if (fabs(xL)>= DEADBAND) xL +=  (xL>0)? -DEADBAND : +DEADBAND;
// 	if (fabs(yR)>= DEADBAND) yR +=  (yR>0)? -DEADBAND : +DEADBAND;
// 	if (fabs(xR)>= DEADBAND) xR +=  (xR>0)? -DEADBAND : +DEADBAND;


//     //Test Drive
// 	yL *= MAX_DRIVE_POWER;	
// 	yR *= MAX_DRIVE_POWER;	

//   m_ptrDrivetrain->ArcadeDrive( -yL, xR );