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


#define LM45A_ADR   0x48
#define LM45A_TEMP  0x00

/*
0011 1111 -> 0
0000 0110 -> 1
0101 1011 -> 2
0100 1111 -> 3
0110 0110 -> 4
0110 1101 -> 5
0111 1101 -> 6
0000 0111 -> 7
0111 1111 -> 8
0110 1111 -> 9
0110 0011 ->°
0011 1001 ->C
 */
const uint8_t pattern[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x63,0x39};
uint8_t mask = 0;
uint8_t* buffer[4];
uint8_t number[4];

uint16_t cont = 0;

uint8_t lm45_buf[2];
int16_t lm45_temp;

void shift_data(uint8_t data){

    
    RCLK_SetHigh();
    for(uint8_t i=0;i<8;i++){
    
        PORTDbits.RD1 = (data << i) & 0x80?1:0;
        SRCLK_SetHigh();    //Clock
        SRCLK_SetLow();
        
    }

    RCLK_SetLow();
    
}


void converter_uint_to_array(uint16_t dataToConvert,uint8_t* buff){

    uint8_t mm,cc,dd,uu;
    
    PIE0bits.TMR0IE = 0;
    
    mm = (uint8_t)(dataToConvert / 1000);
    cc = (uint8_t)(dataToConvert / 100);
    cc = cc - ((uint8_t)(cc/10))*10;
    
    dd = (uint8_t)(dataToConvert / 10);
    dd = dd - ((uint8_t)(dd/10))*10;
    
    uu = dataToConvert - ((uint8_t)(dataToConvert/10))*10;  
    
    *buff++ = mm;
    *buff++ = cc;
    *buff++ = dd;
    *buff = uu;
    
    PIE0bits.TMR0IE = 1;
}

void converter_float_to_array(float dataToConvert,uint8_t* buff){

    uint16_t d1,d2,d3,d4,aux = 0;

    PIE0bits.TMR0IE = 0;

    if(dataToConvert>= 0.000 && dataToConvert < 10.00){
    
        d1 = (uint16_t)(dataToConvert);
        d2 = (uint16_t)((float)(dataToConvert - (float)d1));
        
        d3 = (uint16_t)dataToConvert*10;

        d3 = (uint16_t)(10*((float)(((float)dataToConvert*10) - (float)d3)));

        d4 = (uint16_t)dataToConvert*100;

        d4 = (uint16_t)(10*((float)(((float)dataToConvert*100) - (float)d4)));  
        printf("4 %u,%u,%u,%u\r\n",d1,d2,d3,d4);

    }else if(dataToConvert>= 10.00 && dataToConvert < 100.0){

        d1 = (uint16_t)(dataToConvert / 10);
        d1 = d1 - ((uint16_t)(d1/10))*10;
        d2 = (uint16_t)(dataToConvert - ((uint16_t)(dataToConvert/10))*10);
        
        d3 = (uint16_t)dataToConvert;
        d3 = (uint16_t)((float)((float)dataToConvert - (float)d3) * 10);
        
        d4 = (uint16_t)dataToConvert*10;
        d4 = (uint16_t)((float)((float)(dataToConvert*10) - (float)d3) * 10);   
        
        printf("2 %u,%u,%u,%u%\r\n",d1,d2,d3,d4);
    
    }
    
    

    *buff++ = (uint8_t)d1;
    *buff++ = (uint8_t)d2;
    *buff++ = (uint8_t)d3;
    *buff = (uint8_t)d4;   
        
    PIE0bits.TMR0IE = 1;
}


void convert_uint_to_TempArray(uint16_t dataToConvert,uint8_t* buff){

    uint8_t temp[4];
    
    converter_uint_to_array(dataToConvert,&temp);

    *buff++ = temp[2];
    *buff++ = temp[3];
    *buff++ = 10;
    *buff = 11;
    

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

    LATD = 0x00;
    
    number[0] = 0;
    number[1] = 0;
    number[2] = 0;
    number[3] = 0;
    
    buffer[0] = &number[0];
    buffer[1] = &number[1];
    buffer[2] = &number[2];
    buffer[3] = &number[3];
    

    while (1)
    {
        i2c_readDataBlock(LM45A_ADR,LM45A_TEMP,&lm45_buf,sizeof(lm45_buf));
        lm45_temp = (int16_t)lm45_buf[1] | ((int16_t)lm45_buf[0] << 8);
        lm45_temp = (lm45_temp>>5);
        lm45_temp = (uint16_t)((float)lm45_temp*0.125);
        
        //converter_float_to_array(0.123,&number);
        convert_uint_to_TempArray(lm45_temp,&number);
        __delay_ms(1000);
        // Add your application code
    }
}
/**
 End of File
*/