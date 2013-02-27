#include <stm32f4xx_conf.h>


int main (void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	GPIOD->MODER = (1 << 26);

	while (1)
	{
		GPIOD->ODR ^= (1 << 13);
	}
}
