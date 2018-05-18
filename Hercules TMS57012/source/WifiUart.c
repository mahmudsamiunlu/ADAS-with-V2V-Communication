/*
 * WifiUart.c
 *
 *  Created on: 18 Nis 2018
 *      Author: mahmu
 *              WF_RQS_STRT
                WF_RSP_CNTD
                WF_RSP_DSTD
                WF_RSP_UNEX
                WF_RSP_IPOK
                WF_RSP_IPER
                WF_RSP_SCFL
                WF_RSP_TXFL
                WF_RSP_SCEX
                WF_RSP_TCPR
                WF_RQS_INIO
                WF_RQS_TCPS
                WF_RSP_TCPS
                WF_RQS_RPMV_value
                WF_RSP_RPM0
                WF_RSP_SCDO
                WF_RSP_CFGE
                WF_RSP_CFGO
                WF_RSP_WSER
                WF_RSP_APER
                WF_RSP_TPCE
                WF_RSP_TPSE
                WF_RSP_EXIT
                WF_RSP_SNDA
 */
//#include "reg_sci.h"
#include "sci.h"
#include "sys_vim.h"
#include "math.h"
#include "WifiUart.h"

uint8 WF_RQS_STRT=0x41U;
uint8 WF_RSP_CNTD =0x42U;
uint8 WF_RSP_DSTD =0x43U;
uint8 WF_RSP_UNEX =0x44U;
uint8 WF_RSP_IPOK =0x45U;
uint8 WF_RSP_IPER =0x46U;
uint8 WF_RSP_SCFL =0x47U;
uint8 WF_RSP_TXFL =0x48U;
uint8 WF_RSP_SCEX =0x49U;
uint8 WF_RSP_TCPR =0x4AU;
uint8 WF_RQS_INIO =0x4BU;
uint8 WF_RQS_TCPS =0x4CU;
uint8 WF_RSP_TCPS =0x4DU;
uint8 WF_RQS_RPMV_value =0x4EU;
uint8 WF_RSP_RPM0 =0x4FU;
uint8 WF_RSP_SCDO =0x50U;
uint8 WF_RSP_CFGE =0x51U;
uint8 WF_RSP_CFGO =0x52U;
uint8 WF_RSP_WSER =0x53U;
uint8 WF_RSP_APER =0x54U;
uint8 WF_RSP_TPCE =0x55U;
uint8 WF_RSP_TPSE =0x56U;
uint8 WF_RSP_EXIT =0x57U;
uint8 WF_RSP_SNDA =0x58U;

uint8   wifiUartInit()
{
  uint8 Ready=4;
  uint8 WifiUartBuffer[WifiBufferSize]={0};
  sciSendByte(sciREG,WF_RQS_STRT);
  delay(100);

    sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);
       if (WifiUartBuffer[0]==WF_RSP_CFGO)
           Ready--;

    sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);
    if (WifiUartBuffer[0]==WF_RSP_CNTD)
        Ready--;

        sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);
    if (WifiUartBuffer[0]==WF_RSP_IPOK)
        Ready--;

    sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);
        if (WifiUartBuffer[0]==WF_RSP_TCPR)
            Ready--;


       return Ready;
}

void    wifiUartISOInýtOK()
{
    sciSendByte(sciREG,WF_RQS_INIO);
    delay (1000);

}

uint8   wifiUartTCPStart()
{
    uint8 Ready=1;
    uint8 WifiUartBuffer[WifiBufferSize]={0};

    sciSendByte(sciREG,WF_RQS_TCPS);

    sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);

       if (WifiUartBuffer[0]==WF_RSP_TCPS)
           Ready=0;
       else
           Ready=1;

       return Ready;
}

void    wifiUartSendRPM(uint8 * adrMeasuredRPM)
{
    uint8 Ready=0;
    uint8 ByteMeasuredRPM[2]={0};
    uint8 WifiUartBuffer[WifiBufferSize]={0};
    ByteMeasuredRPM[0] = *adrMeasuredRPM;         //MSB FIRST
    adrMeasuredRPM++;
    ByteMeasuredRPM[1] = *adrMeasuredRPM;                              //     0xFFF7E400U
    sciSendByte(sciREG,WF_RQS_RPMV_value);
    sciSendByte(sciREG,ByteMeasuredRPM[0]);
    sciSendByte(sciREG,ByteMeasuredRPM[1]);

       sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);
       if (WifiUartBuffer[0]==WF_RSP_RPM0)
                 Ready=1;
}
void wifiUartSocketDone()
{
    sciSendByte(sciREG,WF_RSP_SCDO);


}

