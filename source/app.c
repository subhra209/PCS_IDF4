#include "app.h"
#include "typedefs.h"
#include "mb.h"
#include "mmd.h"
#include "linearkeypad.h"
#include "digit_driver.h"
#include "rtc_driver.h"
#include "string.h"
#include "stdlib.h"

/*---------------------------------------------------------------
*
*---------------------------------------------------------------*/
#define REG_INPUT_START 1
#define REG_INPUT_NREGS 17

enum
{

	INACTIVE,
	ACTIVE,
	TRANSITION
};

// APP Structure
typedef struct _APP
{
	//used to store the application data
	UINT8 mbData[25]; 



	// used to store individual data's
	UINT8 refrence[20];
	UINT8 hourlyKE[5];
	UINT8 shiftKE[4];

	//used to switch on status lamps ( green and red )
	BOOL status;
	
	//mb data received flag
	BOOL dataReceived;

	UINT8 state;

		

}APP;

/*---------------------------------------------------------------
* Global variables
*---------------------------------------------------------------*/
#pragma idata APP_DATA
APP app = {{0},0};
MMD_Config mmdConfig = {0}; 
#pragma idata


//ss,mm,HH,day,date,month,year
UINT8 writeTimeDateBuffer[] = {0X00, 0X00, 0X15, 0X01, 0x20, 0X07, 0X15};
UINT8 message[7] = "READY ";

/*---------------------------------------------------------------
* Private functions
*---------------------------------------------------------------*/
void handleMBData( void );
void updateActual( void );
void calculateTargetHrlyRate( void );
void calculateActualHrlyRate( void );
void getCurrentTime( void );
void updateTargetHrlyRate( void );
void updateActualHrlyRate( void );
#ifdef RTC_TEST
void displayRTCData( void );
#endif
/*---------------------------------------------------------------
* void APP_init(void)
*---------------------------------------------------------------*/


void APP_init(void)
{
	UINT8 i;

	
#ifdef RTC_TEST
	WriteRtcTimeAndDate(writeTimeDateBuffer);
	displayRTCData();	
#endif



	//Turn OFF green lamp 
	DDR_loadDigit( GREEN_LED, 10 );
	DelayMs(1);	

	//Turn OFF red lamp
	DDR_loadDigit( RED_LED, 10 );
	DelayMs(1);	


	app.state = INACTIVE;
}


/*---------------------------------------------------------------
* void APP_task(void)app
*---------------------------------------------------------------*/
void APP_task(void)
{


UINT16 temp;
	
#ifdef RTC_TEST
	displayRTCData();
	
#else
	handleMBData();

	switch(app.state)
	{
		case INACTIVE:	
			return;


		case ACTIVE:


		app.hourlyKE[3] = '\0';
		temp = atoi(app.hourlyKE);	

		if( temp >= 45 )
			app.status = TURN_ON_GREEN_LAMP ;
		else 
			app.status =TURN_ON_RED_LAMP;

		if ( (app.status == TURN_ON_RED_LAMP) )
		{
			//Turn OFF green lamp 
			DDR_loadDigit( GREEN_LED, 10 );
			DelayMs(1);	
		
			//Turn ON red lamp
			DDR_loadDigit( RED_LED, 8 );
			DelayMs(1);	

		}
		else if ( (app.status == TURN_ON_GREEN_LAMP) )
		{
			//Turn ON green lamp 
			DDR_loadDigit( GREEN_LED, 8 );
			DelayMs(1);	
		
			//Turn OFF red lamp
			DDR_loadDigit( RED_LED, 10 );
			DelayMs(1);	
	
		
		}
		break;
	}


#endif




}


/*---------------------------------------------------------------
* modbus callback
*---------------------------------------------------------------*/

eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{

    eMBErrorCode    eStatus = MB_ENOERR;

    int             iRegIndex;
/*
    if( ( usAddress >= REG_INPUT_START )
        && ( usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS ) )
    {
        iRegIndex = ( int )( usAddress - usRegInputStart );
        while( usNRegs > 0         {
            *pucRegBuffer++ =
                ( unsigned char )( usRegInputBuf[iRegIndex] >> 8 );
            *pucRegBuffer++ =
                ( unsigned char )( usRegInputBuf[iRegIndex] & 0xFF );
            iRegIndex++;
            usNRegs--;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
 
*/
    return eStatus;

}

eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs,
                 eMBRegisterMode eMode )
{

	UINT8	starting_add = usAddress;
	UINT8	no_regs		 = usNRegs * 2;
	eMBErrorCode    eStatus = MB_ENOERR;
	UINT8 i = 0;
	UINT8 test[10] = "IDEONICS ";

	switch(eMode)
	{
	case MB_REG_WRITE:

    
	while( no_regs > 0)
	{

		app.mbData[i++] = * pucRegBuffer++;

		starting_add++;
		no_regs	--;
	}
	app.mbData[i] = '\0';
	app.dataReceived = TRUE;
    break;

 	case MB_REG_READ: 

	while(no_regs > 0)
	{

			* pucRegBuffer++ =	'A';
			* pucRegBuffer++ =	'B';		
			
			* pucRegBuffer++ = 'C';
			* pucRegBuffer++ = 'D';

		starting_add++;
		no_regs	--;	
	}
   	 break;
	}

	return eStatus;
  }


eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
               eMBRegisterMode eMode )
{
    return MB_ENOREG;
}

eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    return MB_ENOREG;
}


/*---------------------------------------------------------------
* void handleMBData( void )
*---------------------------------------------------------------*/

void handleMBData( void )
{
	UINT8 command = 0;
	UINT8 i, j = 0;


	if ( app.dataReceived == TRUE )
	{
		command = app.mbData[0];

		switch ( command )
		{
			case CMD_SYNC:
				MMD_clearSegment(0);
				mmdConfig.startAddress = 0;
				mmdConfig.length = 6;
				mmdConfig.symbolCount = strlen(message);
				mmdConfig.symbolBuffer = message;
				mmdConfig.scrollSpeed = SCROLL_SPEED_NONE;	
				MMD_configSegment( 0 , &mmdConfig );

				for(i = OPERATOR_INDEX_START ; i <=GREEN_LED  ; i++)
				{
					DDR_loadDigit( i, 10 );
					DelayMs(1);					
				}

			break;

			case CMD_REFERENCE:
				strcpy(app.refrence , app.mbData+1);

				MMD_clearSegment(0);
				mmdConfig.startAddress = 0;
				mmdConfig.length = 6;
				mmdConfig.symbolCount = strlen(app.refrence);
				mmdConfig.symbolBuffer = app.refrence;
				mmdConfig.scrollSpeed = SCROLL_SPEED_LOW;	
				MMD_configSegment( 0 , &mmdConfig );


			break;

			case CMD_OPERATOR:
			
			for ( i = OPERATOR_INDEX_START, j = 0; i <= OPERATOR_INDEX_END; i++, j++ )
			{
				DDR_loadDigit( i, app.mbData[2-j] - '0' );
				DelayMs(1);
			} 			
			break;

			case CMD_PLAN_QUANTITY:

			for ( i = PLAN_QTY_INDEX_START, j = 0; i <= PLAN_QTY_INDEX_END; i++, j++ )
			{
				DDR_loadDigit( i, app.mbData[j+1] - '0' );
				DelayMs(1);
			} 

	//		app.state = ACTIVE;
			
			break;

			case CMD_ACTUAL:

			for ( i = ACTUAL_QTY_START; i <= ACTUAL_QTY_END; i++, j++ )
			{
				DDR_loadDigit( i, app.mbData[j+1] - '0' );
				DelayMs(1);
			} 

			break;

			case CMD_HOURLY_KE:

			strcpy(app.hourlyKE , app.mbData+1);

			for ( i = HOURLY_KE_START; i <= HOURLY_KE_END; i++, j++ )
			{
				DDR_loadDigit( i, app.mbData[j+1] - '0' );
				DelayMs(1);
			} 

			app.state = ACTIVE;
			break;


			case CMD_SHIFT_KE:

			for ( i = SHIFT_KE_START; i <= SHIFT_KE_END; i++, j++ )
			{
				DDR_loadDigit( i, app.mbData[j+1] - '0' );
				DelayMs(1);
			} 


			break;

			default:
			break;
		}
		
		app.dataReceived = 0;


	}

}

/*---------------------------------------------------------------
* void displayRTCData( void )
*---------------------------------------------------------------*/

void displayRTCData( void )
{
	UINT8 i, j = 0;
	UINT8 RTCData[6];
	UINT8 displayBuffer[4];
	static UINT8 count = 0;
	count++;

	ReadRtcTimeAndDate(RTCData);

	if ( count >= 100 )
	{
		for(i = 0; i < 7; i++)			
		{
			WriteUSART(RTCData[i]) ;  //store time and date 
			DelayMs(20);
		}
		count = 0;
	}


			
	displayBuffer[0] = (RTCData[1] & 0X0F) + '0';        //Minute LSB
	displayBuffer[1] = ((RTCData[1] & 0XF0) >> 4) + '0'; //Minute MSB

	displayBuffer[2] = (RTCData[2] & 0X0F) + '0';		//Hour LSB
	displayBuffer[3] = ((RTCData[2] & 0XF0) >> 4) + '0'; //Hour MSB 

	for ( i = ACTUAL_QTY_START; i <= ACTUAL_QTY_END; i++, j++ )
	{
		DDR_loadDigit( i, displayBuffer[3 - j] - '0' );
		DelayMs(1);
	} 
}