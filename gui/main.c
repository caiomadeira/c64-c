/*

Referencia: https://cc65.github.io/doc/funcref.html

*/


#include<stdio.h>
#include<conio.h>
#include<c64.h>
#include<peekpoke.h>

unsigned char textc = 0;
unsigned char backgroundc = 0;
unsigned char borderc = 0;

/*

Memory setup register = D018

Esse endereço é usado para dizer ao 'VIC 2'(?) qual
character (caractere) (conjunto de caracteres) ler da ROM, bem, qual local ler, basicamente, 
é o que controla quais CHARS aparecem na tela

*/

int main(void)
{
    // Clear and set colors
    clrscr();
    //backgroundc = bgcolor(COLOR_BLACK);
    //borderc = bordercolor(COLOR_RED); // BACKGROUND COMMODORE 64 COLOR

    // Point directly to the address relative to background color
    *(char*)0XD021 = 3; // Background color (only bits #0-#3).
    *(char*)0xD020 = 5; // Border color (only bits #0-#3).
    //*(char*)0xD022 = 0; // Extra background color #1 (only bits #0-#3).


    textc = textcolor(COLOR_BLACK);

    printf(":::::::::: WELCOME ::::::::::\n\n");
    printf("SCRL LOCK - FOR DIGIT IN KEYBOARD.\n");
    printf("CTRL + SHIFT - ENABLE/DISABLE UPPER/LOWER CASE.\n");

    // Wait for user to press a key and clear the screen
    cgetc();
    clrscr();

    // Reset to default colors
    textcolor(textc);
    bordercolor(borderc);
    bgcolor(backgroundc);

    /* 
    
    Usar funções disponibilizadas pelas libs ao inves
    de transformações diretamente na memória fazem com que
    o programa tenha funções compativeis entre diferentes sistemas.
    Por exemplo, ao mudar a cor de fundo no commodore 64, ele mudará
    no Atari também, mas apenas porque o a função externa do header
    file 'textcolor(COLOR_SEILA)' possui ja setup para outros sistemas.

    Se usarmos a mudança direta pelo endereço, ele fica especifico ao
    sistema que estamos programando, mas, ainda sim, podemos criar uma lógica
    para tratar em outros sistemas.
    */

    // Reset character set
    //*(char*)0xD018 = 0x14;

    // POKE (function) - Write a byte to memory
    // declaration POKE (unsigned addr, unsigned char val)
    POKE(0xD018, 0x14); // Mesma coisa que fazer *(char*)0xD018 = 0x14;

    // Control characters (https://www.c64-wiki.com/wiki/control_character) - muda a cor para laranja
    printf("\x81"); 


    printf("Program finished.");

    return 0;
}