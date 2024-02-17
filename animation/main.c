#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<unistd.h> // Necessário para usar a função sleep


#define TECH_THEME 0

void loadingBar()
{
    int i;
    int size = 9;
    char* text = "test";
    for(i = 0; i < size; i++)
    {
        sleep(1);
        chline(i);
        cputsxy(0, 3, text);
    }
}

void verticalTextAnim(char* text, int duration)
{
    int i;
    char space = ' ';
    for(i = 1; i < duration; i++)
    {
        cputsxy(0, i, text);
        sleep(1);
        cputc(space);
        loadingBar();
    }
}

void setTheme(int theme)
{
    if (theme == TECH_THEME)
    {
        *(char*)0xD021 = 0; // BLACK COLOR
        *(char*)0xD020 = 6;
        textcolor(0x05);
    }
}

int main(void)
{   
    char* text = "Isso eh um teste.";
    clrscr();
    setTheme(TECH_THEME);
    //verticalTextAnim(text, 10);
    loadingBar();
    
    cgetc(); // Pause the system and not show 'ready.'
    return 0;
}