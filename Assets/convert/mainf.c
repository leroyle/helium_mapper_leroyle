#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long double nb;
    long long ll;
    long long final;
    long long final1;
    printf("please enter the decimal number: ");
    //scanf("%d",&nb);
    int ret = scanf("%Le",&nb);
    char octal[100]="",hex[100]="", absol[100];
    //octal will hold the octal notation 
    // hex will hold the hexadecimal notation
    //sprintf(octal,"%#o",nb); //convert decimal to octal 

    long double retD;
    long double intD;

    // nb=nb * 100000;
    printf("input no cast: %Lf, \n",  nb);
    printf("input cast to long: %ld, \n", (long) nb);
    retD = modfl(nb, &intD);
    ll = (long) intD;
//    printf("whole: %Lf, dec: %Lf\n", intD,retD);
    printf("whole: %Lf\n", intD);
    printf("While long double to long %ld\n", (long) intD);
    if( ll < 0 )
    {
	ll *= -1;
        final = ~ll +1;
//        final1 = -1 * final;
        printf("less x %x\n",(unsigned int) final1);
    }
    else
    {
        final = ll;
    }

    
    printf("ll %lld \n",ll);

    // sprintf(hex,"%#Lf",nb); // convert decimal to hexadecimal 
    //sprintf(hex,"%lld",ll); // convert decimal to hexadecimal 
    //printf("converting %Lf to hexadecimal notation %s\n",nb,hex);

    printf("final %#X \n", (unsigned int) final);
    
    return 0;
}
