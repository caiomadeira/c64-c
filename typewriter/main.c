#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>

char* text = "This is a typerwriter effect";
size_t text_len = 0;
size_t i = 0;

int main(void)
{
    clrscr();
    bgcolor(COLOR_BLACK);
    text_len = strlen(text);

/*
=============================================================
    WARNING: Uma limitação do cc65 é que voce nao pode
    declarar a variavel já dentro da condição do for:

    for (size_int i = 0; i < count; i++)

    Deve-se declara-la antes separadamente e depois chama-la
=============================================================
*/
    for (i = 0; i < text_len; i++)
    {
        textcolor(i); // Rainbow effect loop through colors addrs;
        cputc(text[i]);
        if (text[i] != ' ') 
        {
            sleep(3);
        } else {
            sleep(1);
        }
    }

    cgetc();
    clrscr();

    return  0;
}