#include "mmd.h"
#include "string.h"


rom const UINT8 FontTable5x7[][8]= {	// ASCII	DEC
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,		// space  	32
0x00,0x00,0x00,0x00,0x00,0x00,0x00,(0x00),		// space  	32
0x20,0x20,0x20,0x20,0x00,0x00,0x20,(0x00),		// !		33
0x50,0x50,0x50,0x00,0x00,0x00,0x00,(0x00),		// "		34
0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,(0x00),		// #		35
0x20,0x78,0xA0,0x70,0x28,0xF0,0x20,(0x00),		// $		36
0xC0,0xC8,0x10,0x20,0x40,0x98,0x18,(0x00),		// %		37
0x60,0x90,0xA0,0x40,0xA8,0x90,0x68,(0x00),		// &		38
0x60,0x20,0x40,0x00,0x00,0x00,0x00,(0x00),		// '		39
0x10,0x20,0x40,0x40,0x40,0x20,0x10,(0x00),		// (		40
0x40,0x20,0x10,0x10,0x10,0x20,0x40,(0x00),		// )		41
0x00,0x20,0xA8,0x70,0xA8,0x20,0x00,(0x00),		// *		42
0x00,0x20,0x20,0xF8,0x20,0x20,0x00,(0x00),		// +		43	
0x00,0x00,0x00,0x00,0x30,0x10,0x20,(0x00),		// ,		44
0x00,0x00,0x00,0x7C,0x00,0x00,0x00,(0x00),		// -		45
0x00,0x00,0x00,0x00,0x00,0x60,0x60,(0x00),		// .		46
0x00,0x08,0x10,0x20,0x40,0x80,0x00,(0x00),		// /		47
0x30,0x48,0x68,0x78,0x58,0x48,0x30,(0x00),		// 0		48
0x20,0x60,0xA0,0x20,0x20,0x20,0xF8,(0x00),		// 1		49
0x30,0x48,0x08,0x08,0x10,0x20,0x78,(0x00),		// 2		50
0x70,0x08,0x08,0x30,0x08,0x08,0x70,(0x00),		// 3		51
0x10,0x30,0x50,0x90,0xF8,0x10,0x10,(0x00),		// 4		52
0x78,0x40,0x40,0x70,0x08,0x08,0x70,(0x00),		// 5		53
0x30,0x48,0x40,0x70,0x48,0x48,0x30,(0x00),		// 6		54
0xF8,0x08,0x10,0x20,0x40,0x40,0x40,(0x00),		// 7		55
0x30,0x48,0x48,0x30,0x48,0x48,0x30,(0x00),		// 8		56
0x30,0x48,0x48,0x38,0x08,0x48,0x30,(0x00),		// 9		57
0x00,0x60,0x60,0x00,0x60,0x60,0x00,(0x00),		// :		58
0x00,0x60,0x60,0x00,0x60,0x20,0x40,(0x00),		// ;		59
0x08,0x10,0x20,0x40,0x20,0x10,0x08,(0x00),		// <		60
0x00,0x00,0xF8,0x00,0xF8,0x00,0x00,(0x00),		// =		61
0x40,0x20,0x10,0x08,0x10,0x20,0x40,(0x00),		// >		62
0x70,0x88,0x08,0x10,0x20,0x00,0x20,(0x00),		// ?		63	
0x70,0x88,0x08,0x68,0xA8,0xA8,0x70,(0x00),		// @		64
0x30,0x48,0x48,0x78,0x48,0x48,0x48, 0x00 ,		// A		65
0x70,0x48,0x48,0x70,0x48,0x48,0x70,(0x00),		// B		66
0x38,0x40,0x40,0x40,0x40,0x40,0x38,(0x00),		// C		67
0x70,0x48,0x48,0x48,0x48,0x48,0x70,(0x00),		// D		68	
0x78,0x40,0x40,0x70,0x40,0x40,0x78,(0x00),		// E		69
0x78,0x40,0x40,0x70,0x40,0x40,0x40,(0x00),		// F		70	
0x30,0x48,0x40,0x58,0x48,0x48,0x30,(0x00),		// G		71
0x48,0x48,0x48,0x78,0x48,0x48,0x48,(0x00),		// H		72
0x70,0x20,0x20,0x20,0x20,0x20,0x70,(0x00),		// I		73
0x70,0x20,0x20,0x20,0x20,0xA0,0x60,(0x00),		// J		74
0x48,0x50,0x60,0x40,0x60,0x50,0x48,(0x00),		// K		75
0x40,0x40,0x40,0x40,0x40,0x40,0x70,(0x00),		// L		76
0x88,0xD8,0xA8,0xA8,0x88,0x88,0x88,(0x00),		// M		77
0x48,0x48,0x68,0x78,0x58,0x48,0x48,(0x00),		// N		78
0x30,0x48,0x48,0x48,0x48,0x48,0x30,(0x00),		// 0		79	
0x70,0x48,0x48,0x70,0x40,0x40,0x40,(0x00),		// P		80
0x30,0x48,0x48,0x48,0x68,0x50,0x28,(0x00),		// Q		81
0x70,0x48,0x48,0x70,0x48,0x48,0x48,(0x00),		// R		82
0x30,0x48,0x40,0x30,0x08,0x48,0x30,(0x00),		// S		83
0xF8,0x20,0x20,0x20,0x20,0x20,0x20,(0x00),		// T		84
0x48,0x48,0x48,0x48,0x48,0x48,0x30,(0x00),		// U		85
0x88,0x88,0x88,0x88,0x88,0x50,0x20,(0x00),		// V		86
0x88,0x88,0x88,0xA8,0xA8,0xA8,0x50,(0x00),     	// W		87
0x48,0x48,0x48,0x30,0x48,0x48,0x48,(0x00),		// X		88
0x50,0x50,0x50,0x50,0x20,0x20,0x20,(0x00),		// Y		89
0x78,0x08,0x18,0x30,0x60,0x40,0x78,(0x00),		// Z		90
0x70,0x40,0x40,0x40,0x40,0x40,0x70,(0x00),		// [		91
0x88,0x50,0xF8,0x20,0xF8,0x20,0x20,(0x00),		// Y		92
0x70,0x10,0x10,0x10,0x10,0x10,0x70,(0x00),		// ]		93
0x20,0x50,0x88,0x00,0x00,0x00,0x00,(0x00),		// ^		94
0x00,0x00,0x00,0x00,0x00,0x00,0xF8,(0x00),		// _		95	
0x40,0x20,0x10,0x00,0x00,0x00,0x00,(0x00),     	// \		96
0x00,0x00,0x70,0x08,0x78,0x88,0x78,(0x00),		// a		97
0x80,0x80,0xB0,0xC8,0x88,0x88,0xF0,(0x00),		// b		98
0x00,0x00,0x70,0x80,0x80,0x88,0x70,(0x00),		// c		99
0x08,0x08,0x68,0x98,0x88,0x88,0x78,(0x00),		// d		100
0x00,0x00,0x70,0x88,0xF8,0x80,0x70,(0x00),		// e		101
0x30,0x48,0x40,0xE0,0x40,0x40,0x40,(0x00),		// f		102
0x00,0x78,0x88,0x88,0x78,0x08,0x70,(0x00),		// g		103
0x80,0x80,0xB0,0xC8,0x88,0x88,0x88,(0x00),		// h		104
0x20,0x00,0x60,0x20,0x20,0x20,0x70,(0x00),		// i		105
0x08,0x00,0x08,0x08,0x08,0x48,0x30,(0x00),		// j		106
0x40,0x40,0x48,0x50,0x60,0x50,0x48,(0x00),    	// k		107
0x60,0x20,0x20,0x20,0x20,0x20,0x70,(0x00),		// l		108
0x00,0x00,0xD0,0xA8,0xA8,0x88,0x88,(0x00),		// m		109
0x00,0x00,0xB0,0xC8,0x88,0x88,0x88,(0x00),		// n		110
0x00,0x00,0x70,0x88,0x88,0x88,0x70,(0x00),		// o		111
0x00,0x00,0xF0,0x88,0xF0,0x80,0x80,(0x00),		// p		112
0x00,0x00,0x68,0x98,0x78,0x08,0x08,(0x00),		// q		113
0x00,0x00,0xB0,0xC8,0x80,0x80,0x80,(0x00),		// r		114
0x00,0x00,0x70,0x80,0x70,0x08,0xF0,(0x00),		// s		115
0x40,0x40,0xE0,0x40,0x40,0x48,0x30,(0x00),		// t		116
0x00,0x00,0x88,0x88,0x88,0x98,0x68,(0x00),		// u		117
0x00,0x00,0x88,0x88,0x88,0x50,0x20,(0x00),		// v		118
0x00,0x00,0x88,0x88,0xA8,0xA8,0x50,(0x00),		// w		119
0x00,0x00,0x88,0x50,0x20,0x50,0x88,(0x00),		// x		120
0x00,0x00,0x88,0x88,0x78,0x08,0x70,(0x00),		// y		121
0x00,0x00,0xF8,0x10,0x20,0x40,0xF8,(0x00),		// z		122
0x10,0x20,0x20,0x40,0x20,0x20,0x10,(0x00),		// {		123
0x20,0x20,0x20,0x20,0x20,0x20,0x20,(0x00),		// |		124
0x20,0x10,0x10,0x08,0x10,0x10,0x20,(0x00),		// }		125
0x00,0x20,0x10,0xF8,0x10,0x20,0x00,(0x00),		// >		126
0x00,0x20,0x40,0xF8,0x40,0x20,0x00,(0x00),		// <		127
0x30,0x48,0x48,0x30,0x00,0x00,0x00,(0x00),		// dg		128
0x30,0x48,0x48,0x30,0x00,0x00,0x00,(0x00),		//			129
0x08,0x18,0x38,0x78,0x38,0x18,0x08,(0x00),		//			131
};




typedef struct _BITPACK_TABLE
{
	UINT8 mask;
	UINT8 shiftCount;
	
}BITPACK_TABLE;

rom BITPACK_TABLE rightBitPackTable[COLUMNS_PER_SYMBOL+1]={
{0,0},{0x80,5},{0xC0,4},{0xE0,3},{0xF0,2},{0xF8,1}
};


rom BITPACK_TABLE leftBitPackTable[COLUMNS_PER_SYMBOL+1]={
{0,0},{0x08,4},{0x18,3},{0x38,2},{0x78,1},{0xF8,0}
};



typedef struct _MMD_Segment
{
	UINT8 id;
	UINT8 startAddress;
	UINT8 length;
	far UINT8 *symbolBuffer;
	UINT8 symbolCount;
	SCROLL_SPEED scrollSpeed;
	UINT8 speedCount;
	UINT8 curSymbolIndex;
	UINT8 switchBuffer;
	UINT8 shiftCount;
	UINT8 curShiftBuffer;
	UINT8 curDispBuffer;
	far UINT8 DispBuffer[2][ROWS_PER_SYMBOL][MMD_MAX_CHARS];
	far UINT8 DispDataBuffer[ROWS_PER_SYMBOL][MMD_MAX_CHARS];


}MMD_Segment;



void WriteDataToDisplay(UINT8 digit, UINT8 data);
void makeBitMap(UINT8 id , UINT8 row );


#pragma idata MMD_DATA
MMD_Segment mmdSegment[MMD_MAX_SEGMENTS]= {0};
#pragma udata


/*
*------------------------------------------------------------------------------
* static BOOL getBit(UINT8 data , UINT8 bitNo)
*
* Summary	: get a bit at specified position from a byte
*
* Input		: UINT8 data  - byte to get the bit 
*		      UINT8 bitNo - bit position
*
* Output	: None
*
*------------------------------------------------------------------------------
*/
static BOOL getBit(UINT8 data , UINT8 bitNo)
{
	BOOL bitValue = (data & ((UINT8) 1 << bitNo)) ? 1 : 0;
	return bitValue;
}

/*
*------------------------------------------------------------------------------
* static void setBit(UINT8 *data , UINT8 bitNo)
*
* Summary	: set a bit at specified position in  a byte
*
* Input		: UINT8 *data  - pointer to a byte to set the bit 
*		      UINT8 bitNo - bit position
*
* Output	: None
*
*------------------------------------------------------------------------------
*/
static void setBit(UINT8 *data , UINT8 bitNo)
{
	*data  |= ((UINT8)1 << bitNo);
	
}

/*
*------------------------------------------------------------------------------
* static void clearBit(UINT8 *data , UINT8 bitNo)
*
* Summary	: clear a bit at specified position in  a byte
*
* Input		: UINT8 *data  - pointer to a byte to clear the bit 
*		      UINT8 bitNo - bit position
*
* Output	: None
*
*------------------------------------------------------------------------------
*/
static void clearBit(UINT8 *data , UINT8 bitNo)
{
	*data &= ~ (((UINT8) 1 << bitNo));
}




void MMD_init()
{
	UINT8 i,j,k;
	for( i = 0; i < MMD_MAX_SEGMENTS ; i++)
	{
		mmdSegment[i].id = i+1;
		mmdSegment[i].startAddress = 0;
		mmdSegment[i].symbolBuffer = 0;
		mmdSegment[i].symbolCount = 0;		
		mmdSegment[i].scrollSpeed = SCROLL_SPEED_NONE;
		mmdSegment[i].switchBuffer = 0;
		mmdSegment[i].shiftCount = 0;
		mmdSegment[i].speedCount = 0;
		mmdSegment[i].curShiftBuffer = 0;
		mmdSegment[i].curDispBuffer = 0;
		mmdSegment[i].curSymbolIndex = 0;
		mmdSegment[i].length = 0;
		
		j= ROWS_PER_SYMBOL*MMD_MAX_CHARS;
		memset((void*)mmdSegment[i].DispDataBuffer,0,j);
		memset((void*)mmdSegment[i].DispBuffer[0],0,j);
		memset((void*)mmdSegment[i].DispBuffer[1],0,j);
	}

}


BOOL MMD_configSegment( UINT8 id,  MMD_Config *config )
{

	UINT8 i,j,k;
	INT8 curSymbolIndex,curSymbol;
	MMD_Config *tmp;		//temp pointer to help in copying config info

	if( id >= MMD_MAX_SEGMENTS					//check for allowable data
		|| config->startAddress >= MMD_MAX_ADDRESS
		|| config->symbolBuffer == 0)

	{
		return FALSE;
	}

	tmp = (MMD_Config*) &mmdSegment[id].startAddress;	//cast to config structure
	*tmp = *config;									//copy 
	
	mmdSegment[id].speedCount = mmdSegment[id].scrollSpeed;
	i = ROWS_PER_SYMBOL * MMD_MAX_CHARS;
	memset((UINT8*)mmdSegment[id].DispDataBuffer,0,i);
	memset((UINT8*)mmdSegment[id].DispBuffer[0],0,i);
	memset((UINT8*)mmdSegment[id].DispBuffer[1],0,i);

	if( mmdSegment[id].scrollSpeed == SCROLL_SPEED_NONE)
	{
		mmdSegment[id].curSymbolIndex = 0;
		for( i = 0; i < mmdSegment[id].length ; i++)
		{
			
			curSymbol = mmdSegment[id].symbolBuffer[mmdSegment[id].curSymbolIndex++]-32;
			if( (curSymbol < 0) || (curSymbol > 0x63 ))
				curSymbol = 0;
			if(mmdSegment[id].curSymbolIndex >= mmdSegment[id].symbolCount)
				mmdSegment[id].curSymbolIndex = 0;

			for( j = 0; j < ROWS_PER_SYMBOL ; j++)
			{	


				mmdSegment[id].DispDataBuffer[j][i] = (FontTable5x7[curSymbol ][j]);
				mmdSegment[id].DispBuffer[0][j][i] = mmdSegment[id].DispDataBuffer[j][i];
				mmdSegment[id].DispBuffer[1][j][i] = mmdSegment[id].DispDataBuffer[j][i];
			}
			
		}
	}
	else
	{
		mmdSegment[id].curSymbolIndex = 0;
		for( i = 0; i < mmdSegment[id].length ; i++)
		{
			curSymbol = mmdSegment[id].symbolBuffer[mmdSegment[id].curSymbolIndex++]-32;
	        if( (curSymbol < 0) || (curSymbol > 0x63 ))
				curSymbol = 0;
			if(mmdSegment[id].curSymbolIndex >= mmdSegment[id].symbolCount)
				mmdSegment[id].curSymbolIndex = 0;
			for( j = 0; j < ROWS_PER_SYMBOL ; j++)
			{	

				mmdSegment[id].DispDataBuffer[j][i] = (FontTable5x7[curSymbol ][j]) ;
				mmdSegment[id].DispBuffer[0][j][i] = mmdSegment[id].DispDataBuffer[j][i];
				mmdSegment[id].DispBuffer[1][j][i] = mmdSegment[id].DispDataBuffer[j][i];
			}
			
		}
	}
	mmdSegment[id].curSymbolIndex = 0;
	return TRUE;
}

void MMD_setScrollSpeed( UINT8 id , SCROLL_SPEED speed )
{
	
	mmdSegment[id].scrollSpeed = speed;
	mmdSegment[id].speedCount = speed;

}	


void MMD_changeSymbol( UINT8 segmentID , UINT8 symbolID)
{
	UINT8 j;
	UINT8 curSymbol ;

	curSymbol = mmdSegment[segmentID].symbolBuffer[symbolID]-32;

	for( j = 0; j < ROWS_PER_SYMBOL ; j++)
	{	

		mmdSegment[segmentID].DispDataBuffer[j][symbolID] = (FontTable5x7[curSymbol ][j]) ;
		mmdSegment[segmentID].DispBuffer[0][j][symbolID] = mmdSegment[0].DispDataBuffer[j][symbolID];
		mmdSegment[segmentID].DispBuffer[1][j][symbolID] = mmdSegment[0].DispDataBuffer[j][symbolID];
	}
}

void MMD_clearSegment(UINT8 id)
{
	UINT8 size;

		mmdSegment[id].startAddress = 0;
		mmdSegment[id].symbolBuffer = 0;
		mmdSegment[id].symbolCount = 0;		
		mmdSegment[id].scrollSpeed = SCROLL_SPEED_NONE;
		mmdSegment[id].switchBuffer = 0;
		mmdSegment[id].shiftCount = 0;
		mmdSegment[id].speedCount = 0;
		mmdSegment[id].curShiftBuffer = 0;
		mmdSegment[id].curDispBuffer = 0;
		mmdSegment[id].curSymbolIndex = 0;
		mmdSegment[id].length = 0;

		size = ROWS_PER_SYMBOL*MMD_MAX_CHARS;
		
		memset((UINT8*)mmdSegment[id].DispDataBuffer,0,size);
		memset((UINT8*)mmdSegment[id].DispBuffer[0],0,size);
		memset((UINT8*)mmdSegment[id].DispBuffer[1],0,size);

	
}
void MMD_task(void)
{
	UINT8 i , j , k;
	UINT8 curSymbol,curRowData;

	for( i = 0; i < MMD_MAX_SEGMENTS ; i++)
	{
		if( mmdSegment[i].scrollSpeed != SCROLL_SPEED_NONE)
		{
			--mmdSegment[i].speedCount;
			if( mmdSegment[i].speedCount > 0)	
				continue;
		}
		mmdSegment[i].speedCount = mmdSegment[i].scrollSpeed;

		DISABLE_TMR1_INTERRUPT();
		if( mmdSegment[i].switchBuffer == 0 )
		{
			mmdSegment[i].curShiftBuffer = ( mmdSegment[i].curDispBuffer == 0 )? 1 : 0;
				
		}
		if(mmdSegment[i].switchBuffer == 1 )
		{
			ENABLE_TMR1_INTERRUPT();
		 	continue;
		}
	
		ENABLE_TMR1_INTERRUPT();
	

		if( mmdSegment[i].scrollSpeed == SCROLL_SPEED_NONE)
		{/*
			for( j = 0; j < ROWS_PER_SYMBOL; j++)
			{
				for( k = 0; k < mmdSegment[i].length; k++)
				{
					mmdSegment[i].DispBuffer[mmdSegment[i].curShiftBuffer][j][k] = mmdSegment[i].DispDataBuffer[j][k];
				}
			}
		*/
		}
		else
		{
			
			for( j = 0; j < ROWS_PER_SYMBOL; j++)
			{
				for( k = 1; k < mmdSegment[i].length; k++)
				{
					mmdSegment[i].DispDataBuffer[j][k-1] <<= 1;
					
					if( getBit(mmdSegment[i].DispDataBuffer[j][k],7) == 1 )
						setBit(&mmdSegment[i].DispDataBuffer[j][k-1] , 8-COLUMNS_PER_CHARACTER);
					else
						clearBit(&mmdSegment[i].DispDataBuffer[j][k-1],8-COLUMNS_PER_CHARACTER);
					mmdSegment[i].DispBuffer[mmdSegment[i].curShiftBuffer][j][k-1] = mmdSegment[i].DispDataBuffer[j][k-1];
				}
					
				mmdSegment[i].DispDataBuffer[j][k-1] <<= 1;
				curSymbol = mmdSegment[i].symbolBuffer[mmdSegment[i].curSymbolIndex]-32;
				 if( (curSymbol < 0) || (curSymbol > 0x63 ))
					curSymbol = 0;	
				curRowData	 = FontTable5x7[curSymbol][j];
				if( getBit(curRowData,7-mmdSegment[i].shiftCount) == 1 )
				{
					setBit(&(mmdSegment[i].DispDataBuffer[j][k-1]) , 8-COLUMNS_PER_CHARACTER);
				}
				else
				{
					clearBit(&(mmdSegment[i].DispDataBuffer[j][k-1]),8-COLUMNS_PER_CHARACTER);
				}

				mmdSegment[i].DispBuffer[mmdSegment[i].curShiftBuffer][j][k-1] = mmdSegment[i].DispDataBuffer[j][k-1];
			}
			++mmdSegment[i].shiftCount;

			if( mmdSegment[i].shiftCount >= COLUMNS_PER_CHARACTER)
			{
				mmdSegment[i].curSymbolIndex++;
				if( mmdSegment[i].curSymbolIndex >= mmdSegment[i].symbolCount)
				{
					mmdSegment[i].curSymbolIndex = 0;
				}
				
				mmdSegment[i].shiftCount = 0;
				
			}
			
		}

		DISABLE_TMR1_INTERRUPT();
		mmdSegment[i].switchBuffer = 1;
		ENABLE_TMR1_INTERRUPT();
	}

}				

UINT8 iSRState = 0;
void MMD_refreshDisplay(void)
{
	UINT8 dataByte,addr;
	UINT8 i,j;

	MMD_CONTROL = 0;	//disable the display

	Delay10us(1);

	

	for( i = 0 ; i < MMD_MAX_SEGMENTS ; i++)
	{
		
		for( j = 0 ; j < mmdSegment[i].length ; j++)
		{
			dataByte = mmdSegment[i].DispBuffer[mmdSegment[i].curDispBuffer][iSRState][j];

			addr = mmdSegment[i].startAddress + j;					//set the address

			if( addr >=64 )	//workaround for PCB flaw 
			{				//- pins 39 & 40 are interchanged in 10 pin connector 
				addr +=128;
			}

			//DISPLAY_CONTROL = DISPLAY_DISABLE;

			DIGIT_PORT = addr;
			DATA_PORT = ~dataByte;
			DISPLAY_CONTROL = DISPLAY_ENABLE;	//enable the display					
			Delay10us(1);
			DISPLAY_CONTROL = DISPLAY_DISABLE;	//disable the display					


		}
	}

	switch( iSRState )
	{
		case 0:
				DIGIT_SEL_A	 = 0;
				DIGIT_SEL_B	 = 0;
				DIGIT_SEL_C	 = 0;
			break;
		case 1:
				DIGIT_SEL_A	 = 1;
				DIGIT_SEL_B	 = 0;
				DIGIT_SEL_C	 = 0;
			break;

		case 2:
				DIGIT_SEL_A	 = 0;
				DIGIT_SEL_B	 = 1;
				DIGIT_SEL_C	 = 0;
			break;

		case 3:
				DIGIT_SEL_A	 = 1;
				DIGIT_SEL_B	 = 1;
				DIGIT_SEL_C	 = 0;

			break;
		case 4:
				DIGIT_SEL_A	 = 0;
				DIGIT_SEL_B	 = 0;
				DIGIT_SEL_C	 = 1;
			break;

		case 5:
				DIGIT_SEL_A	 = 1;
				DIGIT_SEL_B	 = 0;
				DIGIT_SEL_C	 = 1;
			break;

		case 6:
				DIGIT_SEL_A	 = 0;
				DIGIT_SEL_B	 = 1;
				DIGIT_SEL_C	 = 1;
			break;


		default:
				iSRState = 0;
			break;
	}

	MMD_CONTROL = 1;
	iSRState++;
	if( iSRState >= ROWS_PER_SYMBOL )
	{
		iSRState = 0;

#ifndef __MMD_STATIC__

		for( i = 0 ; i < MMD_MAX_SEGMENTS ; i++)
		{
			if( mmdSegment[i].switchBuffer == 1 )
			{
				mmdSegment[i].curDispBuffer = (mmdSegment[i].curDispBuffer == 0) ?1 : 0 ;
				mmdSegment[i].switchBuffer = 0;
			}
		}
#endif
	}
}



	



/*
*------------------------------------------------------------------------------
* void WriteDataToDisplay(UINT8 digit, UINT8 data)
*
* Summary	: Write one byte data on the bus
*
* Input		: UINT8 digit - digit number to write the data
*			  UINT8 dataByte - data byte for the digit
*
* Output	: None
*------------------------------------------------------------------------------
*/
void WriteDataToDisplay(UINT8 digit, UINT8 data)
{
	if( digit >=64 )
	{
		digit+=128;
	}
	DISPLAY_CONTROL = DISPLAY_DISABLE;	//disable the display
	DIGIT_PORT = digit;					//set the address
	DATA_PORT = data;					// write data
	DISPLAY_CONTROL = DISPLAY_ENABLE;	//enable the display
	Delay10us(10);						//delay for the data to stabilize
	DISPLAY_CONTROL = DISPLAY_DISABLE;	//disable it again

}


