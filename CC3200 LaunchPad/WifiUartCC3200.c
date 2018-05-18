/*
 * WifiUartCC3200.h
 *
 *  Created on: 19 Nis 2018
 *      Author: Mahmud Sami Ünlü
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

#include "WifiUartCC3200.h"

/*
uint8   wifiUartInit()
{
  uint8 Ready=0;
  uint8 WifiUartBuffer[WifiBufferSize]={0};
    sciSend(sciREG,WifiBufferSize,WF_RQS_STRT);

    sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);

    if (WifiUartBuffer[0]==WF_RSP_CNTD[0])
        Ready=1;

        sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);

    if (WifiUartBuffer[0]==WF_RSP_IPOK[0])
        Ready++;
        sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);

        if (WifiUartBuffer[0]==WF_RSP_TCPR[0])
            Ready++;

       return Ready;
}

void    wifiUartISOInýtOK()
{
    sciSend(sciREG,WifiBufferSize,WF_RQS_INIO);

}

uint8   wifiUartTCPStart()
{
    uint8 Ready=0;
    uint8 WifiUartBuffer[WifiBufferSize]={0};

    sciSend(sciREG,WifiBufferSize,WF_RQS_TCPS);

    sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);

       if (WifiUartBuffer[0]==WF_RSP_TCPS[0])
           Ready=1;
       else
           Ready=0;

       return Ready;
}

void    wifiUartSendRPM(uint32 MeasuredRPM)
{
    uint8 Ready=0;
    uint8 ByteMeasuredRPM[2]={0};
    uint8 WifiUartBuffer[WifiBufferSize]={0};
    ByteMeasuredRPM[0] = MeasuredRPM & 0x000000FFU;
    ByteMeasuredRPM[1] = MeasuredRPM & 0x0000FF00U;                              //     0xFFF7E400U
       sciSend(sciREG,WifiBufferSize,WF_RQS_RPMV_value);
       sciSend(sciREG,WifiBufferSize+1,ByteMeasuredRPM);

       sciReceive(sciREG,WifiBufferSize,WifiUartBuffer);
       if (WifiUartBuffer[0]==WF_RSP_RPM0[0])
                 Ready=1;
}
void wifiUartSocketDone()
{
    sciSend(sciREG,WifiBufferSize,WF_RSP_SCDO);


}
 */
