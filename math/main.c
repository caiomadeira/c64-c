/*

cl65 file_name.c -o file_name.prg

*/

#include<stdio.h>
#include<conio.h>
#include<time.h>

int main(void)
{
    int n1 = 29;
    int n2 = 45;
    int sum = n1 + n2;

    printf("%d + %d = %d", n1, n2, sum);
    return 0;
}

