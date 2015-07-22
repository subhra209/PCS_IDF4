#include "config.h"
#include "string.h"


typedef enum
{
	CMD_SYNC				= 0X80,
	CMD_REFERENCE			= 0X81,
	CMD_OPERATOR			= 0X82,
	CMD_PLAN_QUANTITY		= 0X83,
	CMD_ACTUAL				= 0X84,
	CMD_HOURLY_KE			= 0X85,
	CMD_SHIFT_KE			= 0X86
}CMD;

enum
{
	INPUT_KEY = 0
};

enum
{
	TURN_ON_GREEN_LAMP = 0,
	TURN_ON_RED_LAMP
};

typedef enum
{
	OPERATOR_INDEX_START		= 6,
	OPERATOR_INDEX_END			= 7,
	PLAN_QTY_INDEX_START		= 9,
	PLAN_QTY_INDEX_END			= 12,
	ACTUAL_QTY_START 			= 13,
	ACTUAL_QTY_END				= 16,
	HOURLY_KE_START				= 17,
	HOURLY_KE_END				= 21,
	SHIFT_KE_START				= 22,
	SHIFT_KE_END				= 26,
	RED_LED						= 30,
	GREEN_LED 					= 31			
}DD_SRC_DST;

void APP_init(void);
void APP_task(void);



