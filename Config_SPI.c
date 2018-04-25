#include <c8051f020.h>
#include "Config_SPI.h"
#include "intrins.h"
#include "string.h"

//Define_port
sbit NSS=P3^7;

void Config_SPI(void){
	
	SPI0CFG=0x87; 
	SPI0CN=0x03;
	SPI0CKR=0x36; //pour avoir fSCK = 200 kHz
	SPIF=1;
}




	
char putcharSPI(char c, char csg_tempo) {
	while (csg_tempo != 0) //while tant que csg_tempo n'est pas arrivé a 0
		{
		if ((SPIF==1 )){
			NSS=0;
			SPIF=0;
			SPI0DAT = c;
		  while(TXBSY);
			NSS=1;
			return c; 
		}
		else{ //si drapeau pas pret a transmettre
			//	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
				csg_tempo-- ; //decrementation de csg_tempo
				
		}
	}
			
	return 0;
}

void test (void){
	int j;

	char chaineenvoyee[] = "Salut Nicolas";
	char chaine[30] = "$$";
	char octetFin[] ="@@";
	//putcharSPI('e',500);
	
	strcat(chaine,chaineenvoyee);
	strcat(chaine,octetFin);
	
	for (j=0;j<strlen(chaine);j++){
		putcharSPI(chaine[j],500);
}
}