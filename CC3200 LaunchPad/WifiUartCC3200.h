/*
 * WifiUartCC3200.h
 *
 *  Created on: 19 Nis 2018
 *      Author: Mahmud Sami Ünlü
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
#define WF_RQS_STRT  0x41
#define WF_RSP_CNTD  0x42
#define WF_RSP_DSTD  0x43
#define WF_RSP_UNEX  0x44
#define WF_RSP_IPOK  0x45
#define WF_RSP_IPER  0x46
#define WF_RSP_SCFL  0x47
#define WF_RSP_TXFL  0x48
#define WF_RSP_SCEX  0x49
#define WF_RSP_TCPR  0x4A
#define WF_RQS_INIO  0x4B
#define WF_RQS_TCPS  0x4C
#define WF_RSP_TCPS  0x4D
#define WF_RQS_RPMV_value  0x4E
#define WF_RSP_RPM0  0x4F
#define WF_RSP_SCDO  0x50
#define WF_RSP_CFGE  0x51
#define WF_RSP_CFGO  0x52
#define WF_RSP_WSER  0x53
#define WF_RSP_APER  0x54
#define WF_RSP_TPCE  0x55
#define WF_RSP_TPSE  0x56
#define WF_RSP_EXIT  0x57
#define WF_RSP_SNDA  0x58



/*
uint8   wifiUartInit();
void    wifiUartISOInýtOK();
uint8   wifiUartTCPStart();
void    wifiUartSendRPM(uint32 MeasuredRPM);
void    wifiUartSocketDone();
*/



#endif /* INCLUDE_WIFIUART_H_ */
