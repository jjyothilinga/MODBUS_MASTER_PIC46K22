
/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/
#include "config.h"
#include "board.h"
#include "timer.h"
#include "modbusMaster.h"
#include "app.h"
#include "string.h"
#include "eep.h"



//#define SIMULATION

/*
*------------------------------------------------------------------------------
* modbus 
*------------------------------------------------------------------------------
*/

//////////////////// Port information ///////////////////
#define baud 9600
#define timeout 1000
#define polling 200 // the scan rate
#define retry_count 10

// The total amount of available memory on the master to store data
#define TOTAL_NO_OF_REGISTERS 1

// This is the easiest way to create new packets
// Add as many as you want. TOTAL_NO_OF_PACKETS
// is automatically updated.
enum
{
  PACKET1,
  //PACKET2,
  TOTAL_NO_OF_PACKETS // leave this last entry
};

// Create an array of Packets to be configured
Packet packets[TOTAL_NO_OF_PACKETS];

// Masters register array
//unsigned int regs[TOTAL_NO_OF_REGISTERS];
unsigned int regs[] = "012345678";

UINT8 buffer[] = "01234567";


/*
*------------------------------------------------------------------------------
* void APP-init(void)
*------------------------------------------------------------------------------
*/

void APP_init(void)
{

 	// Initialize each packet
//	MB_construct(&packets[PACKET1], SLAVE_ID, PRESET_MULTIPLE_REGISTERS, 
//								STARTING_ADDRESS, 1, buffer);	
 	 MB_construct(&packets[PACKET1], 1, READ_COIL_STATUS, STARTING_ADDRESS, 1, buffer);	

	
	//modbus master initialization
	MB_init(BAUD_RATE, TIMEOUT, POLLING, RETRY_COUNT, packets, TOTAL_NO_OF_PACKETS, regs);

}




/*
*------------------------------------------------------------------------------
* void APP-task(void)
*------------------------------------------------------------------------------
*/
void APP_task(void)
{
					
	MB_task();

}









