/* Sender 0.2 @ CCC 2011 Germany
 * Develop by 0xCC
 * */
#include "funk/nrf24l01p.h"
#include "funk/mesh.h"
#include "basic/basic.h"
#include "basic/config.h"
#include "lcd/lcd.h"
#include "lcd/print.h"
#include "usetable.h"

void _mesh_sendloop(void);
void _init(void);

/* tx_msg MAX <= 20 */
char tx_msg[20];

/*Main Loop*/
void ram(void)
{
	char inputed[20];
    for(int i=0; i<20; i++) 
		inputed[i] = 0;
    input("Write msg:",inputed,' ','}',20);
    strcpy(tx_msg, inputed);
    while(getInputRaw() != BTN_UP)
    {       
        lcdClear();
		lcdPrintln("");
		lcdPrintln("Sender 0.2");
		lcdPrintln("---------------");
		lcdPrintln(tx_msg);        
		lcdPrintln("");        
		lcdPrintln("Press UP Exit");
		lcdPrintln("");
		lcdPrintln("_______________");
		lcdPrintln("Sending...");
		lcdRefresh();
        _mesh_sendloop();
    }
}

/*Mesh Send*/
void _mesh_sendloop(void)
{
    MPKT * mpkt= meshGetMessage('A');
    MO_TIME_set(mpkt->pkt,getSeconds()+3600);
    strcpy((char*)MO_BODY(mpkt->pkt), &tx_msg[0]);
    getInputWaitTimeout(2000);
}
