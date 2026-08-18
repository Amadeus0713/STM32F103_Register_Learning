#include "stm32f10x.h" //包含寄存器定义

int main(void)
{
	// 1.打开GPIOC 在STM32F1中，GPIOC挂在APB2总线上
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	// 2.配置PC13为通用推挽输出
	// PC13在CRH寄存器中，对应bit20~bit23 引脚起始位 = （引脚编号 - 8）× 4 而每个引脚占用4位
	GPIOC->CRH &= ~(0xF << 20);
	GPIOC->CRH |= (0x3 << 20);
	//3.输出低电平，点亮LED
	GPIOC->ODR &= ~(1 << 13);
	
	while(1)
	{
				//程序停在这里，LED保存常亮
	}
	
}