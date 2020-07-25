/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F18877
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SRCLK aliases
#define SRCLK_TRIS                 TRISDbits.TRISD0
#define SRCLK_LAT                  LATDbits.LATD0
#define SRCLK_PORT                 PORTDbits.RD0
#define SRCLK_WPU                  WPUDbits.WPUD0
#define SRCLK_OD                   ODCONDbits.ODCD0
#define SRCLK_ANS                  ANSELDbits.ANSD0
#define SRCLK_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define SRCLK_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define SRCLK_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define SRCLK_GetValue()           PORTDbits.RD0
#define SRCLK_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define SRCLK_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define SRCLK_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define SRCLK_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define SRCLK_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define SRCLK_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define SRCLK_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define SRCLK_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set SER aliases
#define SER_TRIS                 TRISDbits.TRISD1
#define SER_LAT                  LATDbits.LATD1
#define SER_PORT                 PORTDbits.RD1
#define SER_WPU                  WPUDbits.WPUD1
#define SER_OD                   ODCONDbits.ODCD1
#define SER_ANS                  ANSELDbits.ANSD1
#define SER_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SER_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SER_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SER_GetValue()           PORTDbits.RD1
#define SER_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SER_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SER_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define SER_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define SER_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define SER_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define SER_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define SER_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set RCLK aliases
#define RCLK_TRIS                 TRISDbits.TRISD2
#define RCLK_LAT                  LATDbits.LATD2
#define RCLK_PORT                 PORTDbits.RD2
#define RCLK_WPU                  WPUDbits.WPUD2
#define RCLK_OD                   ODCONDbits.ODCD2
#define RCLK_ANS                  ANSELDbits.ANSD2
#define RCLK_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define RCLK_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define RCLK_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define RCLK_GetValue()           PORTDbits.RD2
#define RCLK_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define RCLK_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define RCLK_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define RCLK_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define RCLK_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define RCLK_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define RCLK_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define RCLK_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set IO_RD3 aliases
#define IO_RD3_TRIS                 TRISDbits.TRISD3
#define IO_RD3_LAT                  LATDbits.LATD3
#define IO_RD3_PORT                 PORTDbits.RD3
#define IO_RD3_WPU                  WPUDbits.WPUD3
#define IO_RD3_OD                   ODCONDbits.ODCD3
#define IO_RD3_ANS                  ANSELDbits.ANSD3
#define IO_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_GetValue()           PORTDbits.RD3
#define IO_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define IO_RD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define IO_RD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define IO_RD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define IO_RD3_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set D1 aliases
#define D1_TRIS                 TRISDbits.TRISD4
#define D1_LAT                  LATDbits.LATD4
#define D1_PORT                 PORTDbits.RD4
#define D1_WPU                  WPUDbits.WPUD4
#define D1_OD                   ODCONDbits.ODCD4
#define D1_ANS                  ANSELDbits.ANSD4
#define D1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define D1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define D1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define D1_GetValue()           PORTDbits.RD4
#define D1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define D1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define D1_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define D1_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define D1_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define D1_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define D1_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define D1_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set D2 aliases
#define D2_TRIS                 TRISDbits.TRISD5
#define D2_LAT                  LATDbits.LATD5
#define D2_PORT                 PORTDbits.RD5
#define D2_WPU                  WPUDbits.WPUD5
#define D2_OD                   ODCONDbits.ODCD5
#define D2_ANS                  ANSELDbits.ANSD5
#define D2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define D2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define D2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define D2_GetValue()           PORTDbits.RD5
#define D2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define D2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define D2_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define D2_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define D2_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define D2_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define D2_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define D2_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set D3 aliases
#define D3_TRIS                 TRISDbits.TRISD6
#define D3_LAT                  LATDbits.LATD6
#define D3_PORT                 PORTDbits.RD6
#define D3_WPU                  WPUDbits.WPUD6
#define D3_OD                   ODCONDbits.ODCD6
#define D3_ANS                  ANSELDbits.ANSD6
#define D3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define D3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define D3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define D3_GetValue()           PORTDbits.RD6
#define D3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define D3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define D3_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define D3_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define D3_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define D3_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define D3_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define D3_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISDbits.TRISD7
#define D4_LAT                  LATDbits.LATD7
#define D4_PORT                 PORTDbits.RD7
#define D4_WPU                  WPUDbits.WPUD7
#define D4_OD                   ODCONDbits.ODCD7
#define D4_ANS                  ANSELDbits.ANSD7
#define D4_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define D4_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define D4_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define D4_GetValue()           PORTDbits.RD7
#define D4_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define D4_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define D4_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define D4_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define D4_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define D4_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/