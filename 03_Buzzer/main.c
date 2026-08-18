#include "stm32f10x.h"

// 【新增】加一个空的 SystemInit 函数，满足链接器要求
void SystemInit(void)
{
    // 暂时不做任何配置，蜂鸣器依然能响（只是单片机主频是 8MHz 而已）
}

int main(void)
{
    RCC->APB2ENR |= (1 << 3);          // 开启 GPIOB 时钟
    GPIOB->CRH &= ~(0xF << 16);        // 清空 PB12 配置
    GPIOB->CRH |= (0x3 << 16);         // 配置 PB12 推挽输出
    
    GPIOB->ODR |= (1 << 12);           // 初始状态关闭蜂鸣器

    while(1)
    {
        GPIOB->ODR &= ~(1 << 12);      // PB12 输出低电平 -> 蜂鸣器响
        for(int i = 0; i < 200000; i++); // 持续响一会儿
        
        GPIOB->ODR |= (1 << 12);       // PB12 输出高电平 -> 蜂鸣器停
        for(int i = 0; i < 200000; i++); // 停顿一会儿再响
    }
}