#ifndef _APP_H_
#define _APP_H_


/*
*----------------------------------------------------------------------------------------------------------------
*	MACROS
*-----------------------------------------------------------------------------------------------------------------
*/

//#define __FACTORY_CONFIGURATION__
#define MAX_NO_OF_TRUCKS	16

/*
*----------------------------------------------------------------------------------------------------------------
*	Enumerations
*-----------------------------------------------------------------------------------------------------------------
*/
typedef enum 
{
	OFF,
	ON
}INDICATOR_STATE;

typedef enum _ISSUE_TYPE
{
	NO_ISSUE,
	RAISED,
	RESOLVED
}ISSUE_TYPE;



typedef enum _APP_PARAM
{
	MAX_KEYPAD_ENTRIES = 3,
	MAX_ISSUES = 32,
	MAX_DEPARTMENTS = 5,
	MAX_LOG_ENTRIES = 6,
	LOG_BUFF_SIZE = MAX_KEYPAD_ENTRIES+1

}APP_PARAM;

typedef enum _LOGDATA
{
	HW_TMEOUT = 10,
	APP_TIMEOUT = 1000,
	TIMESTAMP_UPDATE_VALUE = (APP_TIMEOUT/HW_TMEOUT)
}LOGDATA;

typedef enum
{
	ISSUE_RESOLVED,
	ISSUE_RAISED,
	ISSUE_ACKNOWLEDGED,
	ISSUE_CRITICAL
}APP_STATE;

enum
{
	CMD_GET_STATUS = 0x80,
	CMD_GET_ADMIN_PASSWORD = 0x81,
	CMD_GET_LOGON_PASSWORD = 0x82,
	CMD_GET_BUZZER_TIMEOUT = 0x83,


	CMD_SET_ADMIN_PASSWORD = 0x91,
	CMD_SET_LOGON_PASSWORD = 0x92,
	CMD_SET_BUZZER_TIMEOUT = 0x93,


	CMD_PING = 0xA0,
	CMD_CLEAR_ISSUES = 0xA1,
	CMD_RESOLVE_ISSUE = 0xA2
};

typedef enum
{
	PICKING_START = 0,
	PICKING_END,
	STAGING_START,
	STAGING_END,
	LOADING_START,
	LOADING_END,
	MAX_STATES
}TRUCK_STATE;


extern void APP_init(void);
extern void APP_task(void);
BOOL APP_checkPassword(UINT8 *password);
void App_updateLog(far UINT8 *data);
BOOL APP_activityValid(UINT8 *buffer);

void APP_managePicking(UINT8 *buffer);
UINT8 APP_validatePicking(UINT8 *buffer);

void APP_manageStaging(UINT8 *buffer);
UINT8 APP_validateStaging(UINT8 *buffer);

void APP_manageLoading(UINT8 *buffer);
UINT8 APP_validateLoading(UINT8 *buffer);

#endif
