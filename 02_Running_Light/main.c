#include "stm32f10x.h"

void SystemInit(void)
{
    // 占位函数，保证链接不报错
}

int main(void)
{
    RCC->APB2ENR |= (1 << 2) | (1 << 3); // 开启 GPIOA 和 GPIOB 时钟

    // 配置 PA1, PA2, PA3, PA5, PA6
    GPIOA->CRL |= (0x3 << 4) | (0x3 << 8) | (0x3 << 12) | (0x3 << 20) | (0x3 << 24);
    // 配置 PB0
    GPIOB->CRL |= (0x3 << 0);

    while (1)
    {
        // 每步都先熄灭所有灯
        GPIOA->ODR |= (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);
        GPIOB->ODR |= (1 << 0);

        GPIOA->ODR &= ~(1 << 1); // PA1 亮
        for (int i = 0; i < 300000; i++)
            ;

        GPIOA->ODR |= (1 << 1);
        GPIOA->ODR &= ~(1 << 2); // PA2 亮
        for (int i = 0; i < 300000; i++)
            ;

        GPIOA->ODR |= (1 << 2);
        GPIOA->ODR &= ~(1 << 3); // PA3 亮
        for (int i = 0; i < 300000; i++)
            ;

        GPIOA->ODR |= (1 << 3);
        GPIOA->ODR &= ~(1 << 5); // PA5 亮
        for (int i = 0; i < 300000; i++)
            ;

        GPIOA->ODR |= (1 << 5);
        GPIOA->ODR &= ~(1 << 6); // PA6 亮
        for (int i = 0; i < 300000; i++)
            ;

        GPIOA->ODR |= (1 << 6);
        GPIOB->ODR &= ~(1 << 0); // PB0 亮
        for (int i = 0; i < 300000; i++)
            ;
    }
}