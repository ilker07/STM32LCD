

#include "delay.h"


static __IO uint32_t DelayCounter;
static __IO uint32_t DelayCounter2;


void SysTick_Handler(void) {
   DelayCounter++;
	DelayCounter2++;
}


void delay_init(void) {
   
   SysTick->LOAD = (uint32_t)(SystemCoreClock / (1000UL - 1UL));

  
   NVIC_SetPriority(SysTick_IRQn,(1 << __NVIC_PRIO_BITS) - 1);

  
   SysTick->VAL = 0UL;

   
   SysTick->CTRL = (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk);
}


void delay_ms(uint32_t ms) {
  
   SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

  
   DelayCounter = 0;
   while (DelayCounter < ms);

  
   SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void delay_msdiger(float ms) {
  
   SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

  
   DelayCounter2 = 0;
   while (DelayCounter2 < ms);

  
   SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}




