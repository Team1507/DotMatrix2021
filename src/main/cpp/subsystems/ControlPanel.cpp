#include "subsystems/ControlPanel.h"
#include "Robot.h"

#define HOLD_POWER     0.1 
#define DEPLOY_POWER   0.6
#define RETRACT_POWER  0.25
#define TURBO_POWER_DEPLOY  0.9
#define TURBO_POWER_RETRACT 1.0

#define SPINNER_POWER   0.6

#define BOTTOM_STATE 0
#define GOING_UP     1
#define HOLDING_TOP  2
#define GOING_DOWN   3

ControlPanel::ControlPanel()
{
    m_isDeployed = false;
}

void ControlPanel::Periodic() {}

bool ControlPanel::GetIsDeployed()
{
    return m_isDeployed;
}


// void ControlPanel::InitDefaultCommand() {}


bool ControlPanel::isTopSwitchPress()
{
    return not m_topSwitch.Get(); 
}


bool ControlPanel::isBottomSwitchPress()
{
    return not m_bottomSwitch.Get();
}


void ControlPanel::TURBODeployControl()
{
    m_deployMotor.Set(TURBO_POWER_DEPLOY);
}


void ControlPanel::DeployControl()
{
    m_isDeployed = true;
    m_deployMotor.Set(DEPLOY_POWER);
}


void ControlPanel::TURBORetractControl()
{
    m_deployMotor.Set(-TURBO_POWER_RETRACT);
}


void ControlPanel::RetractControl()
{
    m_isDeployed = false;
    m_deployMotor.Set(-RETRACT_POWER);
}


void ControlPanel::HoldTopControl()
{
    m_deployMotor.Set(HOLD_POWER);
}

int ControlPanel::GetColor(){ 
    frc::Color color = m_ColorsensorV3.GetColor();
    double red = color.red;
    double blue = color.blue;
    double green = color.green;


    if(green > .47 && red < .21)
    {
        //the color is green
        return 1;
    }
    if(red > .4)
    {
        //the color is red
        return 2;
    }
    if(green > .5 && red > .27)
    {
        //the color is yellow
        return 3;
    }    
    if(blue > .3)
    {
        //the color is blue
        return 4;
    }
    //dosent see a color
    return 0;
}



void ControlPanel::StopControl()
{
    m_deployMotor.Set(0);
}


        
void ControlPanel::SpinControl(void)
{
    m_spinnerMotor.Set( -SPINNER_POWER );
}
void ControlPanel::StopSpinControl(void)
{
    m_spinnerMotor.Set( 0.0 );
}


int ControlPanel::GetSpinnerEncoder(void)
{
    return m_spinner_encoder.Get();
}
