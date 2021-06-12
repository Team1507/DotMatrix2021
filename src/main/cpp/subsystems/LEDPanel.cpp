// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LEDPanel.h"

LEDPanel::LEDPanel()
{
    //Setup Leds
    m_led.SetLength(kLEDLength);
    m_led.SetData(m_ledBuffer);
    m_led.Start();

    m_index = 0;
    m_count = 0;
}

// This method will be called once per scheduler run
void LEDPanel::Periodic() 
{
    
}

//Manual Periodic
void LEDPanel::LedPanelPeriodic() 
{
    //20ms = 50 tick/sec
    if( m_count++ > 1 )
    {
        m_count = 0;
        ClearBuffer();
        SetOneLEDColor(m_index++,255,255,0);    //Yellow

        if( m_index >= kLEDLength)
        {
            m_index=0;
        }

        SetOneLEDColor(m_index,255,255,0);    //Yellow

    }
}





void LEDPanel::SetAllLEDColor(int r, int g, int b)
{
    for(int i = 0; i < kLEDLength; i++)
    {
        m_ledBuffer[i].SetRGB( r, g, b);
    }
    m_led.SetData(m_ledBuffer);
}

void LEDPanel::SetOneLEDColor(int LEDNum, int r, int g, int b)
{
    if(LEDNum < kLEDLength)
    {
        m_ledBuffer[LEDNum].SetRGB( r, g, b);
        m_led.SetData(m_ledBuffer);
    }
}


void LEDPanel::ClearBuffer( void )
{
    for(int i = 0; i < kLEDLength; i++)
    {
        m_ledBuffer[i].SetRGB(0,0,0);
    }

}
