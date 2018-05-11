/*******************************************/
//文件名：USB.c
//隶属工程：
//作者：Binjie Tu
//创建时间：2010.07.06
//最后修改时间：
//描述：USB的相关操作
/*******************************************/

#include "USB.h"

// ==============================
// USB API中断
// 
// 
// ==============================
void  USB_API_TEST_ISR(void)  interrupt   17
{
   BYTE  INTVAL   =  Get_Interrupt_Source(); // Determine type of API interrupts
   if (INTVAL  &  USB_RESET)              // Bus Reset Event, go to Wait State
   {
      ;
   }

   if (INTVAL  &  DEVICE_OPEN)            // Device opened on host, go to Idle
   {
      ;
   }

   if (INTVAL  &  TX_COMPLETE)
   {
     ;
   }
   if (INTVAL  &  RX_COMPLETE)            // RX Complete, go to RX Setup or RX file state
   {
     Block_Read(USBRxBuf, 8);				// 收到上位机命令
	 ProcessID = PRO_HANDLE;				// 转到命令处理
	 IntSignal = TRUE;
   }
   if (INTVAL  &  DEVICE_CLOSE)           // Device closed, wait for re-open
   {
     ;
   }
   if (INTVAL  &  FIFO_PURGE)             // Fifo purged, go to Idle State
   {
     ;
   }
   
   

}



		// WriteStageLength = ((BytesToWrite - BytesWrote) > MAX_BLOCK_SIZE_WRITE)? MAX_BLOCK_SIZE_WRITE:(BytesToWrite - BytesWrote);
         // BytesWrote  += Block_Write((BYTE*)(ReadIndex), WriteStageLength);
         // ReadIndex += WriteStageLength;
		 
		// BytesRead   =  Block_Read(&Buffer,  3);      // Read Setup Message