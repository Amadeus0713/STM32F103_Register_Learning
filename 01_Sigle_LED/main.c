#include "stm32f10x.h"

void SystemInit(void)
{
    // 占位函数，保证链接不报错
}

int main(void)
{
    RCC->APB2ENR |= (1 << 2);  // 开启 GPIOA 时钟
    GPIOA->CRL &= ~(0xF << 4); // 配置 PA1
    GPIOA->CRL |= (0x3 << 4);  // PA1 推挽输出

    while (1)
    {
        GPIOA->ODR &= ~(1 << 1); // PA1 亮 (低电平)
        for (int i = 0; i < 300000; i++)
            ;
        GPIOA->ODR |= (1 << 1); // PA1 灭 (高电平)
        for (int i = 0; i < 300000; i++)
            ;
    }
}