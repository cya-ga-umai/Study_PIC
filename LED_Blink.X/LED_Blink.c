/* 
 * File:   LED_Blink.c
 * Author: cya-ga-umai
 *
 * Created on 2015/02/21, 22:09
 */

#include <stdlib.h>
#include <xc.h>

/* コンフィギュレーション
 * （Window->PIC Memory Views->Configuration Bitsより設定可能）
 */
// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

#define _XTAL_FREQ 8000000  /* クロック周波数は8MHz */
/*
 * 
 */
int main(void) {
    /* 初期設定 */
    OSCCON = 0x70;  /* クロック周波数は8MHz */
    TRISC = 0x00;   /* すべてのRCポートを出力に */
    ANSELC = 0x00;  /* すべてのRCポートをデジタル出力に */
    PORTC = 0x00;
    LATC = 0x00;
    
    while(1){
        LATCbits.LATC2 = 0;     /* LED点灯 */
        //PORTCbits.RC3 = 0;    /* PORTxにビットをセットしてもLATxにセットされる */
        __delay_ms(500);
        LATCbits.LATC2 = 1;     /* LED消灯 */
        //PORTCbits.RC3 = 1;
        __delay_ms(500);
    }
    return (EXIT_SUCCESS);
}

