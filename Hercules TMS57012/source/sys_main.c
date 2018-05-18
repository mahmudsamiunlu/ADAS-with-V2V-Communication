/** @file sys_main.c 
*   @brief Application main file
*   @date 07-July-2017
*   @version 04.07.00
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2016 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "sys_common.h"

/* USER CODE BEGIN (1) */
#include "WifiUart.h"
#include "sci.h"
#include "system.h"
#include "het.h"
#include "gio.h"
#include "rti.h"



/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
#define D_SIZE 1
#define reqest_SIZE 6
#define respond_RPM_SIZE 8
#define respond_SPEED_SIZE 7
#define wifiUartBuffer 11
#define USER_LED_B 0x04
#define USER_LED_A 0x02
// WF_RSP_CNTD

 uint8 tx_data[D_SIZE]= {0x33};
 uint32 BaudRate= 10;

 uint8 syncData[4]={0};
 uint8 WifiUart[wifiUartBuffer]={0};
 uint8 requestRPM[reqest_SIZE]={0x68, 0x6a, 0xf1, 0x01, 0x0c, 0xd0};
 uint8 requestSPEED[reqest_SIZE]={0x68, 0x6a, 0xf1, 0x01, 0x0d, 0xd1};
 uint8 respondRPM[respond_RPM_SIZE]={0};
 uint8 respondSPEED[respond_SPEED_SIZE]={0};
 uint32 obdRPM[2]={0};
 uint16 obdSPEED=0;
 uint32 ready= 0;
 void delay(uint32 time);
 void measureRPM(uint8 *RPM);

/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */
   // gioSetDirection(hetPORT1, 0xFFFFFFFF);

    // __delay_cycles(100000); //2ms
  //  __delay_cycles(500000); //10ms
   // __delay_cycles(500000); //10ms
   // __delay_cycles(500000); //10ms
   // __delay_cycles(500000); //10ms
   // __delay_cycles(500000); //10ms

 //   delay(50);
 //   gioSetPort(hetPORT1, gioGetPort(hetPORT1) ^ 0x00000001);
 //   delay(50);
 //   gioSetPort(hetPORT1, gioGetPort(hetPORT1) ^ 0x00000001);
 //   delay(50);
  //  gioSetPort(hetPORT1, gioGetPort(hetPORT1) ^ 0x00000001);
  //  delay(50);
  //  gioSetPort(hetPORT1, gioGetPort(hetPORT1) ^ 0x00000001);

   // sciSetBaudrate(scilinREG, 0x0A);
   // sciInit_initBaud_Comm(initBaud);                                                //sami
    //void sciSetFunctional(sciBASE_t *sci, uint32 port)            bunu dene

    rtiInit();
    gioSetDirection(hetPORT1,0x0U);// (~PIN_HET_15)
    gioInit();
    gioSetDirection(gioPORTB,USER_LED_B|USER_LED_A);// (~PIN_HET_15)

 /* Enable RTI Compare 0 interrupt notification */
   // rtiEnableNotification(rtiNOTIFICATION_COMPARE0);
   // _enable_IRQ();
 /* Start RTI Counter Block 0 */
    sciInit();

    while (gioGetBit(hetPORT1, PIN_HET_15)){}
    delay(1);


    //sciSend(scilinREG,D_SIZE,tx_data);
    uint8 init = 0x33U;
 //   delay(100);
   // rxDISABLE();
    sciSendByte(scilinREG,init);
    WaitFiveBaudInit(scilinREG);
   // sciSend(scilinREG,D_SIZE,tx_data);


   // while(sciIsTxReady(scilinREG));

   delay(2020);
   gioSetPort(gioPORTB, USER_LED_B);

   // delay(5);
    sciInit_initBaud_Comm(Comm);
   // sciEnableLoopback(scilinREG, Analog_Lbk);
    //sami
   // while(!(sciIsTxReady(scilinREG)==0));
//    delay(1);
//    tx_data[0] = 'U';
//      sciSend(scilinREG,D_SIZE,tx_data);
   // sciReceive(sciBASE_t *sci, uint32 length, uint8 * data)
    sciReceive(scilinREG,3,syncData);
    //  syncData[0] = sciReceiveByte(scilinREG);
    //  syncData[1] = sciReceiveByte(scilinREG);
    //  syncData[2] = sciReceiveByte(scilinREG);
    rxDISABLE();
      delay(30);
    tx_data[0] = 0xF7U;
    sciSend(scilinREG,D_SIZE,tx_data);
    delay(20);
    rxENABLE();
    delay(10);
     syncData[3] = sciReceiveByte(scilinREG);
    delay(100);
    gioSetPort(gioPORTB, USER_LED_B);
    wifiUartInit();
    delay(10);
    wifiUartISOInýtOK();

    while (wifiUartTCPStart()) {}

//    sciSendFiveMSDelayed(scilinREG,reqest_SIZE,requestRPM);
//    delay(40);
//    sciReceive(scilinREG,respond_RPM_SIZE,respondRPM);
//    uint16 calcuatedRPM= (respondRPM[5]*256 + respondRPM[6])/4;
    uint8 tRPM[2];
    measureRPM(tRPM);
    wifiUartSendRPM(tRPM);
    delay(50);
    measureRPM(tRPM);
    wifiUartSendRPM(tRPM);

  //  wifiUartSocketDone();
    while(1)
    {

    }
/* USER CODE END */

    return 0;
}


/* USER CODE BEGIN (4) */
/* void delaySum(uint32 time)
{
    uint32 i=0;
    uint32 w=0;
    for(i=0; i<time; i++)
    {
      //  for (w = 0; w < 15000; w++);
         __delay_cycles(45000); //1ms
    }

}
*/
void delay(uint32 mSTime)
{
    rtiStartCounter(rtiCOUNTER_BLOCK0);
    uint32 tick=rtiGetCurrentTick(rtiCOMPARE0);
    while(mSTime>(rtiGetCurrentTick(rtiCOMPARE0)-tick)) {}

     //uint32 CurrentTick= rtiGetCurrentTick(rtiCOMPARE0)-tick;
     rtiStopCounter(rtiCOUNTER_BLOCK0);
}
void measureRPM(uint8 *RPM)
{
    rxDISABLE();
    delay(100);
        sciSendFiveMSDelayed(scilinREG,reqest_SIZE,requestRPM);
        delay(50);
        rxENABLE();
        sciReceive(scilinREG,respond_RPM_SIZE,respondRPM);
        RPM[0]=respondRPM[5];
        RPM[1]=respondRPM[6];
        // obdRPM= (respondRPM[5]*256 + respondRPM[6])/4;
        //return (respondRPM[5]*256 + respondRPM[6])/4;
}
/* USER CODE END */
