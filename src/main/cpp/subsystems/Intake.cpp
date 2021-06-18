// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

#define INTAKE_PERCENT .7 //can change


Intake::Intake()
{
    //Constructor


}

// This method will be called once per scheduler run
void Intake::Periodic() {}



void Intake::IntakeBackward()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, -INTAKE_PERCENT);
}


void Intake::IntakeStop()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);  
}


void Intake::IntakeForward()
{
    //temp code to read off the smart dashboard
    //double percent = -(frc::SmartDashboard::GetNumber("INTAKE_POWER", 0));
    const double poop = 0.5;

    m_intakeMotor.Set(ControlMode::PercentOutput, poop);   
}


void Intake::IntakeForward(double power)
{
    m_intakeMotor.Set(ControlMode::PercentOutput, power);   
}


