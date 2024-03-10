#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nb;
    printf("please enter the decimal number: ");
    scanf("%d",&nb);
    char octal[100]="",hex[100]="", absol[100];
    //octal will hold the octal notation 
    // hex will hold the hexadecimal notation
    //sprintf(octal,"%#o",nb); //convert decimal to octal 
     nb = nb*10000;
     sprintf(hex,"%#X",nb); // convert decimal to hexadecimal 

    // show the result 
    printf("converting %d to hexadecimal notation %s\n",nb,hex);
//    printf("converting %d to octal notation %s\n",nb,octal);

    return 0;
}
