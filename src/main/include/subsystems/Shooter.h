#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "Constants.h"
#include <frc/Solenoid.h>
#include <frc/Servo.h>

#define CAROUSEL_SHOOTING_POWER   0.6  
#define CAROUSEL_IDLE_POWER       0.3  
#define FEEDER_SHOOTING_POWER     1.0 
#define CAROUSEL_REVERSE_POWER    -0.5

//These are velocities in Falcon (units/100ms)/1000  <<==notice divided by 1000
                                                    //Changed back to original 
#define SHOOTER_AUTO_LINE_VELOCITY      19.5          ///19.5
#define SHOOTER_AUTO_TRENCH_VELOCITY    17          //17  

#define SHOOTER_LINE_VELOCITY           20          //20
#define SHOOTER_TRENCH_VELOCITY         17          //17 

#define SHOOTER_LOW_GOAL_VELOCITY       10          //10
#define SHOOTER_IDLE_VELOCITY           10           //10
#define SHOOTER_ZERO_VELOCITY           0

#define LINE_HOOD_ANGLE           129  
#define TRENCH_HOOD_ANGLE         111 
#define LOWGOAL_HOOD_ANGLE        50  
#define HOME_HOOD_ANGLE           40

class Shooter : public frc2::SubsystemBase {
 	public:
  		Shooter();
		void Periodic() override;

		void ShooterInit(void);
  		void SetShooterVelocity(double velocityRPM);
		void SetLeftShooterMotor(double power);
        double GetShooterVelocity(void);
        double GetLeftShooterPower();
        double GetRightShooterPower();
		double GetShooterRPM();
		bool   GetIsShooting();
		void SetisShooting(bool isShooting);
        void SetFeederVelocity(double velocityRPM);
        void SetFeederPower(double power);
        void ExtendRamp(void);
        void RetractRamp(void);
        void StopFeeder(void);
        void StopShooter(void);
        void SetCarouselPower(double percent);
        void SetCarouselIdlePower(void);
        void SetCarouselShootingPower(void);
        void CarouselStop(void);
        void SetHood(int angle);
        void WriteFalconTemps(void);

    private:
        TalonFX m_leftShooterMotor  {LEFT_SHOOTER_FALCON_ID};
        TalonFX m_rightShooterMotor {RIGHT_SHOOTER_FALCON_ID};
        //TalonSRX m_feederMotor      {FEEDER_CAN_ID};

        VictorSPX m_carouselMotor   {CAROUSEL_CAN_ID};
        VictorSPX m_feederMotor     {FEEDER_CAN_ID};
        
        frc::Solenoid m_shooterramp     {PCM_CAN_ID,PCM_RAMP_ID};
     
        bool m_isShooting;
        
        frc::Servo m_shooterHood {SHOOTER_HOOD_PORT};

        int m_hood_angle;

        double m_shooterRPM;
};
