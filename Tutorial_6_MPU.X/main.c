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

#define MPU6050_ADDRESS     0x68
#define MPU6050_SMPRT_DIV   0x19
#define MPU6050_CONFIG      0x1A
#define MPU6050_GYRO_CONFIG 0x1B
#define MPU6050_ACCEL_CONFIG    0x1C
#define MPU6050_SIGNAL_PATH_RESET   0x68
#define MPU6050_PWR_MGMT_1  0x6B
#define MPU6050_IN_ENABLE   0x38

#define MPU6050_ACCEL_XOUT_H    0x3B
#define MPU6050_ACCEL_XOUT_L    0x3C
#define MPU6050_ACCEL_YOUT_H    0x3D
#define MPU6050_ACCEL_YOUT_L    0x3E
#define MPU6050_ACCEL_ZOUT_H    0x3F
#define MPU6050_ACCEL_ZOUT_L    0x40

#define MPU6050_TEMP_OUT_H  0x41
#define MPU6050_TEMP_OUT_L  0x42

#define MPU6050_GYRO_XOUT_H 0x43
#define MPU6050_GYRO_XOUT_L 0x44
#define MPU6050_GYRO_YOUT_H 0x45
#define MPU6050_GYRO_YOUT_L 0x46
#define MPU6050_GYRO_ZOUT_H 0x47
#define MPU6050_GYRO_ZOUT_L 0x48

#define MPU6050_FIFO_EN     0x23
#define MPU6050_FIFO_COUNT_H    0x72
#define MPU6050_FIFO_COUNT_L    0x73
#define MPU6050_USER_CTRL   0x6A

#define MPU6050_ACCEL_LSB_0   16384
#define MPU6050_ACCEL_LSB_1   8192
#define MPU6050_ACCEL_LSB_2   4096
#define MPU6050_ACCEL_LSB_3   2048

#define MPU6050_GYRO_LSB_0  131
#define MPU6050_GYRO_LSB_1  65.5
#define MPU6050_GYRO_LSB_2  32.8
#define MPU6050_GYRO_LSB_3  16.4

typedef struct MPU_DATA{

    float ax;
    float ay;
    float az;
    float gx;
    float gy;
    float gz;
    float temp;
    float yaw;
    float pitch;
    float roll;

}mpu_data;

mpu_data myMpu;

void MPU_Initialization(void){
    
    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_PWR_MGMT_1,0x80);        //Reset
    __delay_ms(200);
    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_SIGNAL_PATH_RESET,0x07); //GYRO,ACCEL,TEMP RESET
    __delay_ms(200);

    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_PWR_MGMT_1,0x01);        //DLL + X GYRO CLOCK
    
    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_SMPRT_DIV,19);            //50 Hz
    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_CONFIG,0x06);             //Acc 1Khz, Gyro 1khz
    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_GYRO_CONFIG,0x00);        //+-250°/s
    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_ACCEL_CONFIG,0x00);       //+-2g

    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_USER_CTRL,0x04);     //FIFO RESET
    __delay_ms(20);
    
    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_FIFO_EN,0xF8);       //ACCEL,TEMP,GYRO FIFO ENABLE
    i2c_write1ByteRegister(MPU6050_ADDRESS,MPU6050_USER_CTRL,0x40);     //FIFO EN
    
}

void MPU_ReadFIFO(mpu_data* adata){

    uint8_t fifo_count[2] = {0,0};
    uint16_t fifo_counter = 0;
    uint8_t fifo_data[14];
    uint8_t sizePacket = 0;
    
    fifo_counter = i2c_read2ByteRegister(MPU6050_ADDRESS,MPU6050_FIFO_COUNT_H);
    sizePacket = fifo_counter / sizeof(fifo_data);
    
    //printf("%u\r\n",sizePacket);
    
    adata->ax = adata->ay = adata->az = 0;
    adata->temp = 0;
    adata->gx = adata->gy = adata->gz = 0;
    
    if(sizePacket > 0){

        for(uint8_t i=0;i<sizePacket;i++){
            
            i2c_readDataBlock(MPU6050_ADDRESS,0x74,&fifo_data,sizeof(fifo_data));

            adata->ax += ((float)((fifo_data[0] << 8)| fifo_data[1]) /  MPU6050_ACCEL_LSB_0);
            adata->ay += ((float)((fifo_data[2] << 8)| fifo_data[3]) /  MPU6050_ACCEL_LSB_0);
            adata->az += ((float)((fifo_data[4] << 8)| fifo_data[5]) /  MPU6050_ACCEL_LSB_0);

            adata->temp += (((((int16_t)fifo_data[6] << 8)| fifo_data[7])/340) + 36.53);

            adata->gx += ((((int16_t)fifo_data[8] << 8)| fifo_data[9]) /  MPU6050_GYRO_LSB_0);
            adata->gy += ((((int16_t)fifo_data[10] << 8)| fifo_data[11]) /  MPU6050_GYRO_LSB_0);
            adata->gz += ((((int16_t)fifo_data[12] << 8)| fifo_data[13]) /  MPU6050_GYRO_LSB_0);  
        
        } 
        
        adata->ax = adata->ax / sizePacket;
        adata->ay = adata->ay / sizePacket;
        adata->az = adata->az / sizePacket;
        adata->temp = adata->temp / sizePacket;
        adata->gx = adata->gx / sizePacket;
        adata->gy = adata->gy / sizePacket;
        adata->gz = adata->gz / sizePacket;
        
        adata->pitch = (atan2(adata->ax, sqrt(pow(adata->ay,2) + pow(adata->az,2))) * 57.295779) + (adata->gx * 0.1);
        adata->roll = (atan2(adata->ay,adata->az) * 57.295779) + (adata->gy * 0.1);
        
        adata->yaw = adata->yaw + (adata->gz * 0.1);
        
    }
    
}


/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros 

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    
    MPU_Initialization();
    
    printf("0x%X\r\n",i2c_read1ByteRegister(MPU6050_ADDRESS,0x75));
    
    while (1)
    {
        __delay_ms(100);
        MPU_ReadFIFO(&myMpu);
        printf("%0.1f\t%0.1f\t%0.1f\r\n",myMpu.pitch,myMpu.roll,myMpu.yaw);
        // Add your application code
    }
}
/**
 End of File
*/