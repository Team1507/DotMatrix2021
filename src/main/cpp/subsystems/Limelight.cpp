// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Limelight.h"

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>


Limelight::Limelight() 
{
    //m_ptrTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
}

void Limelight::Periodic() {}

void Limelight::LimelightInit(void) {}

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

