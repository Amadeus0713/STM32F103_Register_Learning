#include "stm32f10x.h"

// 【非常重要】Keil MDK5 编译必须要有这个空函数，否则会报 undefined symbol 错误
void SystemInit(void)
{
    // 这里什么都不写，只需要占位
}

int main(void)
{
    // 1. 开启 GPIOC 的时钟 (第 4 位)
    RCC->APB2ENR |= (1 << 4); // 等同于 RCC_APB2ENR_IOPCEN
    
    // 2. 配置 PC13 为推挽输出 (CRH 寄存器，PC13 对应 20~23 位)
    GPIOC->CRH &= ~(0xF << 20);    // 清空 PC13 配置
    GPIOC->CRH |= (0x3 << 20);     // 设置 PC13 为推挽输出
    
    while(1)
{
    GPIOC->ODR &= ~(1 << 13);  // 亮
    for(int i=0; i<500000; i++); // 用 CPU 空转做延时
    GPIOC->ODR |= (1 << 13);   // 灭
    for(int i=0; i<500000; i++);
}
}