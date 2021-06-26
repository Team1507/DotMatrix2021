#include "commands/CmdShooterDefault.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "Constants.h"
#include "GamepadMap.h"
#define SHOOTER_kF_CONSTANT 0.0470          //Slightly highter than calculated 0.0467    
#define SHOOTER_kP_CONSTANT 0.00035  
CmdShooterDefault::CmdShooterDefault(Shooter *shooter, frc::XboxController *operator_xbox) 
{
    m_ptrShooter = shooter;
    m_ptrOperatorXbox = operator_xbox;

    m_hood_angle = HOME_HOOD_ANGLE;

    AddRequirements({m_ptrShooter});
}

void CmdShooterDefault::Initialize() {}

void CmdShooterDefault::Execute() 
{
    //trench is up on DPad
    //down is shooting in the low goal
    //left is shooting from the initian line
    int povAngle = m_ptrOperatorXbox->GetPOV(0);//POV 0, only one POV on gamepad
    
    static bool isPovCenter = false;
    
    if(povAngle == -1)
    {
        isPovCenter = true;
        //std::cout<<"nothing pressed"<<std::endl;
    }

    //this is to enable the shooting speed, after we have 5 balls
    if((povAngle == 0) && isPovCenter)
    {
        //SetShooterVelocity(SHOOTER_TRENCH_VELOCITY);
        double shootpower = frc::SmartDashboard::GetNumber("SHOOTER_TRENCH_VELOCITY", 0); 
        m_ptrShooter->SetShooterVelocity(shootpower);

        isPovCenter = false;
        std::cout<<"Shoot Trench "<<std::endl;
        //SetHood(0);//THE ZERO WILL CHANGE
        m_hood_angle = TRENCH_HOOD_ANGLE;
    }
    else if((povAngle == 180)&& isPovCenter)
    {
        //SetShooterVelocity(SHOOTER_LOW_GOAL_VELOCITY);
        double shootpower = frc::SmartDashboard::GetNumber("SHOOTER_LOW_GOAL_VELOCITY", 0); 
        m_ptrShooter->SetShooterVelocity(shootpower);
        isPovCenter = false;
        std::cout<<"Shoot low goal"<<std::endl;
        //SetHood(0);//THE ZERO WILL CHANGE
        m_hood_angle = LOWGOAL_HOOD_ANGLE;
    }
    else if((povAngle == 270) && isPovCenter)
    {
        //SetShooterVelocity(SHOOTER_LINE_VELOCITY);
        double shootpower = frc::SmartDashboard::GetNumber("SHOOTER_LINE_VELOCITY", 0); 
        m_ptrShooter->SetShooterVelocity(shootpower);
        isPovCenter = false;
        std::cout<<"Shoot line"<<std::endl;
        //SetHood(0);//THE ZERO WILL CHANGE
        m_hood_angle = LINE_HOOD_ANGLE;
    }
    
    //shooter button, right trigger, this is for after we aim
    bool m_isTriggerPressed = (m_ptrOperatorXbox->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG) >= 0.5);
    if (m_isTriggerPressed && !(m_ptrShooter->GetIsShooting()))
    {
        //shooter should already be at shooting speed
        m_ptrShooter->SetCarouselShootingPower();
        m_ptrShooter->SetFeederPower(FEEDER_SHOOTING_POWER);
        m_ptrShooter->ExtendRamp();
        std::cout<<"Shoot!"<<std::endl;
        //intake ?
        //deflector deployed for some reason?
        //feeder
        m_ptrShooter->SetisShooting(true);
    }
    else if(m_ptrShooter->GetIsShooting() && !m_isTriggerPressed)
    {
        //shooter at shooting speed still
        m_ptrShooter->SetCarouselIdlePower();
        m_ptrShooter->RetractRamp();
        m_ptrShooter->StopFeeder();
        m_ptrShooter->SetisShooting(false);
    }

    //*******   RESET  ******
    if(m_ptrOperatorXbox->GetRawButtonPressed(GAMEPADMAP_BUTTON_RBUMP))
    {
        //SetShooterVelocity(SHOOTER_IDLE_VELOCITY);
        double shootpower = frc::SmartDashboard::GetNumber("SHOOTER_IDLE_VELOCITY", 0); 
        m_ptrShooter->SetShooterVelocity(shootpower);
        m_ptrShooter->SetCarouselIdlePower();
        m_ptrShooter->StopFeeder();
        m_ptrShooter->RetractRamp();
        m_ptrShooter->SetHood(HOME_HOOD_ANGLE);
        m_hood_angle = HOME_HOOD_ANGLE;
        m_ptrShooter->SetisShooting(false);
        std::cout<<"Shoot Reset"<<std::endl;
    }


    ////*****  SET HOOD AFTER DPAD (after crossing under wheel-of-fortune)
    if(m_ptrOperatorXbox->GetRawButtonPressed(GAMEPADMAP_BUTTON_X))
    {
        m_ptrShooter->SetHood(m_hood_angle);
        std::cout<<"SetHood"<<std::endl;
    }


    //*******   REVERSE to Clear any jams
    bool isBumperPressed  = m_ptrOperatorXbox->GetRawButtonPressed(GAMEPADMAP_BUTTON_LBUMP);
    bool isBumperReleased = m_ptrOperatorXbox->GetRawButtonReleased(GAMEPADMAP_BUTTON_LBUMP);
    
    if(isBumperPressed)
    {
        m_ptrShooter->SetCarouselPower(-CAROUSEL_IDLE_POWER);
    }
    else if (isBumperReleased)
    {
        m_ptrShooter->SetCarouselPower(CAROUSEL_IDLE_POWER);
    }



    // //Driver Feedback LEDs
    // const double TOLRENCEZONE = 0.2;
    // double lmIsTarget = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tv", 0);
    // double lmAngle     = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", 0);  
    // double camera_offset = frc::SmartDashboard::GetNumber( "LimelightOffset", 0.0 );

    // double m_targetAngle = lmAngle + camera_offset;

    // if(((m_targetAngle <= TOLRENCEZONE) ) && ((m_targetAngle >= -TOLRENCEZONE))) 
    // {
    //     Robot::m_driverFeedback.UpdateTopLEDs(GREEN_rgb);
    // }
    // else if(lmIsTarget > 0.0)
    // {
    //     Robot::m_driverFeedback.UpdateTopLEDs(PURPLE_rgb);
    // }
    // else
    // {
    //     Robot::m_driverFeedback.UpdateTopLEDs(0,0,0);
    // }
    

    //Shooter Control
    if(m_ptrShooter->GetShooterRPM() == 0 )
    {
        //Free spin down to zero
        m_ptrShooter->SetLeftShooterMotor(0);
    }
    else
    {
        const double MAX_POS_ERROR = 1500;
        const double MAX_NEG_ERROR = -100;
        

        double curr_vel = m_ptrShooter->GetShooterVelocity();
        double curr_pow = m_ptrShooter->GetShooterPower();

        double v_error  = m_ptrShooter->GetShooterRPM()*1000 - curr_vel;

        if( v_error > MAX_POS_ERROR )   v_error = MAX_POS_ERROR;
        if( v_error < MAX_NEG_ERROR )   v_error = MAX_NEG_ERROR;   
        
        double shoot_power = (m_ptrShooter->GetShooterRPM() * SHOOTER_kF_CONSTANT) + ( v_error * SHOOTER_kP_CONSTANT );

        if( shoot_power < curr_pow ) shoot_power-= 0.01;    //Ramp down slowly to prevent belt slip

        if( shoot_power > 1.0 ) shoot_power = 1.0;
        if( shoot_power < 0.0 ) shoot_power = 0.0;

        m_ptrShooter->SetLeftShooterMotor(shoot_power);
    }
    


}


void CmdShooterDefault::End(bool interrupted) {}

bool CmdShooterDefault::IsFinished() {
  return false;
}
