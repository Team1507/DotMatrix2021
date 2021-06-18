#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "Constants.h"
#include <frc/DigitalInput.h>
#include <rev/ColorSensorV3.h>
#include <frc/Encoder.h> 

class ControlPanel : public frc2::SubsystemBase {
 public:
  ControlPanel();

  void Periodic() override;
  bool isTopSwitchPress( void );
  bool isBottomSwitchPress( void );
  bool GetIsDeployed( void );
  void DeployControl(void);
  void RetractControl(void);
  void TURBODeployControl(void);
  void TURBORetractControl(void);
  void StopControl(void);   
  void HoldTopControl(void);
  int GetColor(void); //return type not determined (most likely 1 red, 2 green etc...)
        
  void SpinControl(void);
  void StopSpinControl(void);

  int GetSpinnerEncoder(void);

 private:
bool m_isDeployed;

frc::DigitalInput m_bottomSwitch{1};
frc::DigitalInput m_topSwitch{0};
frc::Encoder      m_spinner_encoder{2, 3, false, frc::Encoder::k4X};

//servo
WPI_VictorSPX m_deployMotor{CP_DEPLOY_CAN_ID};
WPI_VictorSPX m_spinnerMotor{CP_SPINNER_CAN_ID};
        
//Color Sensor
rev::ColorSensorV3 m_ColorsensorV3{frc::I2C::Port::kOnboard};

};
