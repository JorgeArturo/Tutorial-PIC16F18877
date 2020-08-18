/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F18877
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"


#define MOTORLEFT   0
#define MOTORRIGHT  1
#define WHEEL_DIAMETER 67
#define PPR 20
#define WHEEL_CIR   210
#define RESOLUTION_MMPP  11
#define MM_TO_PP(x) x/RESOLUTION_MMPP

#define LimitMaxMotorLeft 511
#define LimitMinMotorLeft 0
#define LimitMaxMotorRight 511
#define LimitMinMotorRight 0

#define RangeMotorLeft 300
#define RangeMotorRight 300

uint16_t buffer[4];
uint8_t data_buffer[8];
float pid_weights[3];

uint16_t EncoderOfMotorLeft = 0;
uint16_t EncoderOfMotorRight = 0;
uint32_t mean_pulses;

int16_t diff_count = 0;
int32_t outPID = 0;

int32_t pidleft = 0;
int32_t pidright = 0;
float m,y1,y2;

typedef struct PID_PARAMS{

    int time;
    float kp;
    float ki;
    float kd;
    float e;
    float le;
    float rp;
    float ri;
    float rd;
    
    float out;
    
    float ep;
    float pt;
    float ct;
    
}pid_params;

pid_params pid[1];


float gettime(void){

    return (float)TMR0_ReadTimer() * 0.001;
    

}

void switch_out(float In){

    y1 = (float)LimitMaxMotorLeft + In;
    y2 = (float)LimitMaxMotorRight - In;

    if(y1 >= LimitMaxMotorLeft) y1 =  LimitMaxMotorLeft;
    else if(y1 <= LimitMaxMotorLeft) y1 =  0;
    
    if(y2 >= LimitMaxMotorRight) y2 =  LimitMaxMotorRight;
    else if(y2 <= LimitMinMotorRight) y2 =  0;

    PWM1_LoadDutyValue((uint16_t)y1);
    PWM2_LoadDutyValue(0);
    PWM3_LoadDutyValue((uint16_t)y2);
    PWM4_LoadDutyValue(0);    

}

int32_t pid_compute(int16_t ap,int16_t spp,uint8_t tm){
    
    pid[tm].ct = gettime();
    pid[tm].ep = pid[tm].ct - pid[tm].pt;
    
    pid[tm].e = spp - ap;
     
    pid[tm].rp = pid[tm].kp *pid[tm].e;
    pid[tm].ri = pid[tm].ri + (pid[tm].e * pid[tm].ep);
    pid[tm].rd = (pid[tm].e - pid[tm].le) / pid[tm].ep;

    pid[tm].out = pid[tm].rp + (pid[tm].ki * pid[tm].ri) + (pid[tm].kd * pid[tm].rd);
    pid[tm].le = pid[tm].e;
    pid[tm].pt = pid[tm].ct;

    switch_out(pid[tm].out);
    
    return (int32_t)pid[tm].out;
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    PWM1_LoadDutyValue(0);
    PWM2_LoadDutyValue(0);
    PWM3_LoadDutyValue(0);
    PWM4_LoadDutyValue(0);

    __delay_ms(2000);
    
    pid[0].kp = 40;//40; 
    pid[0].ki = 0.95;//0.95;
    pid[0].kd = 0.015;//0.015;
    
    PWM1_LoadDutyValue(511);
    PWM2_LoadDutyValue(0);
    PWM3_LoadDutyValue(511);
    PWM4_LoadDutyValue(0);  
    
    printf("%u\r\n",MM_TO_PP(2000));
    
    while (1)
    {
        __delay_ms(100);
        
        diff_count = (int16_t)(EncoderOfMotorLeft - EncoderOfMotorRight);
        mean_pulses = (EncoderOfMotorLeft + EncoderOfMotorRight)/2;
        
        if(mean_pulses < MM_TO_PP(2000)){
    
            //outPID = pid_compute(diff_count,0,0);

            printf("%d,%d,%i,%i\r\n",EncoderOfMotorLeft,EncoderOfMotorRight,diff_count,outPID);
            
        }else{
        
            PWM1_LoadDutyValue(0);
            PWM2_LoadDutyValue(0);
            PWM3_LoadDutyValue(0);
            PWM4_LoadDutyValue(0);        
        
        }
        
        // Add your application code
    }
}
/**
 End of File
*/