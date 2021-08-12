#include "subsystems/Climber.h"
#include "Robot.h"
#define LIGHTSABER_UP_MULTIPLIER   .5
#define LIGHTSABER_DOWN_MULTIPLIER .25

#define WINCH_POWER 0.1
#define REVERSE_WINCH_POWER 0.1

#include "subsystems/Climber.h"

Climber::Climber()
{
    m_isClimbActivated = false;
}

void Climber::Periodic() {}

void Climber::MoveLightsaber(double power)
{
    m_lightsaber.Set(power);
}

void Climber::SetClimbActivated()
{
    m_isClimbActivated = true;
}

void Climber::ClearClimbActivated()
{
    m_isClimbActivated = false;
}
void Climber::SetRightWinchMotor(double power)
{
    m_rightWinchMotor.Set(power);
}
void Climber::SetLeftWinchMotor(double power)
{
    m_leftWinchMotor.Set(power);
}
bool Climber::IsClimbActivated(void)
{
    return m_isClimbActivated;
}