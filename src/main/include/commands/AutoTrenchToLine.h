// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Limelight.h"
#include "subsystems/Intake.h"


class AutoTrenchToLine
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTrenchToLine> {
 public:
  AutoTrenchToLine(Drivetrain *drivetrain, Shooter *shooter, Limelight *limelight, Intake *intake);
};
