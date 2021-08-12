#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <Constants.h>

class Climber : public frc2::SubsystemBase {
 public:
  Climber();

  void Periodic() override;
  void MoveLightsaber(double power);
  void SetClimbActivated(void);
  void ClearClimbActivated(void);
  void SetRightWinchMotor(double power);
  void SetLeftWinchMotor(double power);
  bool IsClimbActivated(void);
 private:
    WPI_VictorSPX m_leftWinchMotor {LEFT_WINCH_CAN_ID};
    WPI_VictorSPX m_rightWinchMotor{RIGHT_WINCH_CAN_ID};
    WPI_VictorSPX m_lightsaber {LIGHTSABER_CAN_ID};
    bool m_isClimbActivated;
};
