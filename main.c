#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "lcd.h"





uint8_t boyut=0;
uint8_t sutun=1;
uint8_t satir=1;




char kelime[]="il";

//B portunda RS ve EN pinlerini tanimla RW toprak.B0 ve B1.
//A portunda 4 pini al.A7,A6,A5,A4
int main()
{
	
	delay_init();
	
	portAyarlari();
	
	
  lcd_basla();
	
	GPIOB->CRH=0;
	GPIOB->CRH =0x22000000;
	
	
	
	boyut=kelimeBoyut(kelime);
	
	

	while(1)
	{
		
		if(boyut+sutun<=17)
		{
			
		lcdHucreyeGit(satir,sutun);
		lcd_yaz(kelime);
		delay_ms(1000);
		lcd_komut_yolla(0x01);
		sutun=sutun+boyut;
			
		}
		else
		{
		
		sutun=1;
		if(satir==1)
			satir=2;
		else if (satir==2)
			satir=1;

		
			
		}
		
		
	
	  
		
	}
	
}

















