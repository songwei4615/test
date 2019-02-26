#include "Init.h"
 
 int main(void)
 {	
	u8 t=0;	  
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  	 	//初始化与LED连接的硬件接口
	KEY_Init();          	//初始化与按键连接的硬件接口
	LED0=0;					//点亮LED
	while(1)
	{
//		delay_ms(500);
//		GPIO_ResetBits(GPIOA,GPIO_Pin_8);
//		delay_ms(500);
//		GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		t=KEY_Scan(0);		//得到键值
		switch(t)
		{				 
			case KEY0_PRES:
				LED0=!LED0;
				break;
			case KEY1_PRES:
				LED1=!LED1;
				break;
			case WKUP_PRES:				
				LED0=!LED0;
				LED1=!LED1;
				break;
			default:
				delay_ms(10);	
		} 
	}
 }

