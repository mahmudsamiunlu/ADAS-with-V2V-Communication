/*
 * WifiUart.h
 *
 *  Created on: 18 Nis 2018
 *      Author: mahmu
 */
        /*
                WF_RQS_STRT
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

#ifndef INCLUDE_WIFIUART_H_
#define INCLUDE_WIFIUART_H_

#ifdef __cplusplus
extern "C" {
#endif

#define WifiBufferSize 1U




uint8   wifiUartInit();
void    wifiUartISOInýtOK();
uint8   wifiUartTCPStart();
void    wifiUartSendRPM(uint8 * adrMeasuredRPM);
void    wifiUartSocketDone();




#endif /* INCLUDE_WIFIUART_H_ */
