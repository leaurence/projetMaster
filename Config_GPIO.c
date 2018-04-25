#include <c8051f020.h>
#include "Config_Global.h"
#include "Config_GPIO.h"
#include "Config_SPI.h"


void Config_GPIO_Master(void){
	P0=0xff;
	XBR1=0x80;//sysclk routed to port pin
	P1=0x01;
	P1MDOUT|=0x01;
	P0MDOUT &=0xAA; //  P0.3(MISO) P0.5(NSS) en OD 
	P0MDOUT |=0x55; //P0.2(SCK) P0.4(MOSI) en PP
	XBR0 =0x06;//~0x71; // Activation UART et SPI
	XBR2 =0x44; // Activation UART1 et Crossbar
}

void Gestion_GPIO (void){
  Config_GPIO_Master();
}

