// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Limelight.h"

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include "frc/smartdashboard/SmartDashboard.h"
#include <math.h>

const double PI = 3.14159;

Limelight::Limelight() 
{
    //m_ptrTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
}

void Limelight::Periodic() {}

void Limelight::LimelightInit(void) 
{
    frc::SmartDashboard::PutNumber( "LimelightOffset", -1.5 );
}

bool Limelight::IsTarget(void)
{
    return (bool)nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tv", 0);
//  return (bool)m_ptrTable->GetNumber("tv", 0);
}

double Limelight::GetHOffset(void)
{
    return nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", 0);
//  return m_ptrTable->GetNumber("tx", 0);
}

double Limelight::GetDistance(void)
{
    //139
    const double a1 = 19.3;//68.4;
    const double h1 = 24;
    const double h2 = 103.50;
    double a2 = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);
    return (h2-h1)/tan((a1+a2)*(PI/180));//
    
}

double Limelight::GetVAngle(void)
{
    return nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);
}
void Limelight::TogglePipeLine(void)
{
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 1);
}