#include "subsystems/Shooter.h"
#include "frc/smartdashboard/SmartDashboard.h"

#define SHOOTER_kF_CONSTANT 0.0470          //Slightly highter than calculated 0.0467    
#define SHOOTER_kP_CONSTANT 0.00035          

//#include "subsystems/DriverFeedback.h"

#define SHOOTER_PID_SLOT 0
Shooter::Shooter()
{
    m_isShooting = false;
    m_hood_angle = HOME_HOOD_ANGLE;
    m_shooterRPM = 0;
}

void Shooter::Periodic() {}

// Shooter::Shooter() : Subsystem("ShooterSubsystem") 
// {
//     m_isShooting = false;
//     m_hood_angle = HOME_HOOD_ANGLE;
//     m_shooterRPM = 0;
// } 


void Shooter::ShooterInit()
{
    frc::SmartDashboard::PutNumber("SHOOTER_LOW_GOAL_VELOCITY",10);
    frc::SmartDashboard::PutNumber("SHOOTER_LINE_VELOCITY",10);
    frc::SmartDashboard::PutNumber("SHOOTER_TRENCH_VELOCITY",10); //changed from 2000
    frc::SmartDashboard::PutNumber("SHOOTER_IDLE_VELOCITY",10);
    frc::SmartDashboard::PutNumber("CAROUSEL_SHOOTING_POWER",0.8);
    frc::SmartDashboard::PutNumber("FEEDER_POWER",0.8);
    std::cout << "Shooter Init" << std::endl;
    m_leftShooterMotor.ConfigFactoryDefault();
    m_rightShooterMotor.ConfigFactoryDefault();
    m_feederMotor.ConfigFactoryDefault();
    
    //everything will be written to "m_leftShooterMotor" for the shooter
    m_leftShooterMotor.SetNeutralMode(NeutralMode::Coast);
    m_rightShooterMotor.SetNeutralMode(NeutralMode::Coast);
    m_feederMotor.SetNeutralMode(NeutralMode::Coast);

    //encoder
    m_leftShooterMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
    m_rightShooterMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);

    // m_leftShooterMotor.ConfigNominalOutputForward(0,10);
    // m_leftShooterMotor.ConfigNominalOutputReverse(0,10);
    // m_leftShooterMotor.ConfigPeakOutputForward(1,10);
    // m_leftShooterMotor.ConfigPeakOutputReverse(0,10);

    // //PID constants
    // m_leftShooterMotor.ConfigNeutralDeadband(0.001);
    // m_leftShooterMotor.Config_kF(SHOOTER_PID_SLOT, SHOOTER_kF_CONSTANT, 10);    
    // m_leftShooterMotor.Config_kP(SHOOTER_PID_SLOT, SHOOTER_kP_CONSTANT, 10);    
 
    
    //right motor following and set inverted
    m_leftShooterMotor.SetInverted(true);
    m_rightShooterMotor.SetInverted(false);
    m_feederMotor.SetInverted(true);

    //set follow
    m_rightShooterMotor.Follow(m_leftShooterMotor);

    // //*********************************************************
    // //Shooter Setup TEMP CODE
    // frc::SmartDashboard::PutNumber("CAROUSEL_IDLE_POWER",       CAROUSEL_IDLE_POWER    );
    // frc::SmartDashboard::PutNumber("CAROUSEL_SHOOTING_POWER",   CAROUSEL_SHOOTING_POWER);
    // frc::SmartDashboard::PutNumber("FEEDER_POWER",              FEEDER_SHOOTING_POWER  );

    // frc::SmartDashboard::PutNumber("SHOOTER_IDLE_VELOCITY",     SHOOTER_IDLE_VELOCITY    );
    // frc::SmartDashboard::PutNumber("SHOOTER_TRENCH_VELOCITY",   SHOOTER_TRENCH_VELOCITY  );
    // frc::SmartDashboard::PutNumber("SHOOTER_LOW_GOAL_VELOCITY", SHOOTER_LOW_GOAL_VELOCITY);
    // frc::SmartDashboard::PutNumber("SHOOTER_LINE_VELOCITY",     SHOOTER_LINE_VELOCITY    );

    // //frc::SmartDashboard::PutNumber("SHOOTER Kf", 0);
    // //frc::SmartDashboard::PutNumber("SHOOTER Kp", 0);

    // SmartDashboard::PutNumber("INTAKE_POWER", 0.7);

}

void Shooter::SetShooterVelocity(double velocityRPM)
{
    //**** NOTE ***  THIS IS SHOOTER POWER FOR NOW, not velocity
    //m_leftShooterMotor.Set(ControlMode::PercentOutput, velocityRPM );
    std::cout<<"Here!!! " << velocityRPM << std::endl;
    m_shooterRPM = velocityRPM;

//    // rpm --> ticks per 100ms, 2048 ticks/revolution, 600 revs/ 100ms

//     double ticks_100ms = velocityRPM * 2098 / 600;

//    //m_leftShooterMotor.Set(ControlMode::Velocity, velocityRPM * 4096 / 600);
//    //m_leftShooterMotor.Set(ControlMode::Velocity, tempV * 4096 / 600); //targetVelocity is in ticks/100ms

//    m_leftShooterMotor.Set(ControlMode::Velocity, ticks_100ms ); 
}

void Shooter::SetLeftShooterMotor(double power)
{

    //*** KRIS DISABLED SHOOTER HERE***
    m_leftShooterMotor.Set(ControlMode::PercentOutput, power );
}

double Shooter::GetShooterVelocity()
{
    return m_leftShooterMotor.GetSelectedSensorVelocity(SHOOTER_PID_SLOT);
}

double Shooter::GetLeftShooterPower()
{
    return m_leftShooterMotor.GetMotorOutputPercent();
}
double Shooter::GetRightShooterPower()
{
    return m_rightShooterMotor.GetMotorOutputPercent();
}
double Shooter::GetShooterRPM()
{
    return m_shooterRPM;
}
bool Shooter::GetIsShooting()
{
    return m_isShooting;
}
void Shooter::SetisShooting(bool isShooting)
{
    m_isShooting = isShooting;
}
void Shooter::SetFeederVelocity(double velocityRPM)
{
    //No Encoder, Use SetFeederPower instead.
    // double tempV = SmartDashboard::GetNumber("FEEDER_VELOCITY", 0);
    // //m_feederMotor.Set(ControlMode::Velocity ,tempV * 4096 / 600);
    // //m_feederMotor.Set(ControlMode::Velocity ,velocityRPM * 4096 / 600);
    // m_feederMotor.Set(ControlMode::PercentOutput ,tempV);
}
void Shooter::SetFeederPower(double power)
{
    double tempP = frc::SmartDashboard::GetNumber("FEEDER_POWER", 0);
    m_feederMotor.Set(ControlMode::PercentOutput ,tempP);
}

void Shooter::ExtendRamp()
{
    m_shooterramp.Set(true);
}


void Shooter::RetractRamp()
{
    m_shooterramp.Set(false);
}


void Shooter::StopFeeder()
{
    m_feederMotor.Set(ControlMode::PercentOutput, 0);
}


void Shooter::StopShooter()
{
    //m_leftShooterMotor.Set(ControlMode::PercentOutput, 0);
    m_shooterRPM = 0;
}


void Shooter::SetCarouselPower(double percent)
{
    // double tempP = SmartDashboard::GetNumber("CAROUSEL_POWER", 0);
    // m_carouselMotor.Set(ControlMode::PercentOutput, tempP);
    m_carouselMotor.Set(ControlMode::PercentOutput, percent);
}


void Shooter::SetCarouselIdlePower(void)
{
    double tempVar = frc::SmartDashboard::GetNumber("CAROUSEL_IDLE_POWER", 0.0);
    SetCarouselPower(tempVar);
}


void Shooter::SetCarouselShootingPower(void)
{
    double tempVar = frc::SmartDashboard::GetNumber("CAROUSEL_SHOOTING_POWER", 0.0);
    SetCarouselPower(tempVar);
}


void Shooter::CarouselStop()
{
    m_carouselMotor.Set(ControlMode::PercentOutput, 0);   
}


void Shooter::SetHood(int angle)
{
    //max 142, min 40
    m_shooterHood.SetAngle(angle);
    std::cout<<"HOOD ANGLE: "<<angle<<std::endl;
}

void Shooter::WriteFalconTemps(void)
{
    frc::SmartDashboard::PutNumber("Left Shooter Power",m_leftShooterMotor.GetMotorOutputPercent());
    frc::SmartDashboard::PutNumber("Right Shooter Power",m_rightShooterMotor.GetMotorOutputPercent());
    frc::SmartDashboard::PutNumber("FalconTemp LSM", m_leftShooterMotor.GetTemperature() );
    frc::SmartDashboard::PutNumber("FalconTemp RSM", m_rightShooterMotor.GetTemperature() );
}