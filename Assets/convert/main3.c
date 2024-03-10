
// 2's compliment calculator:  https://www.exploringbinary.com/twos-complement-converter/

// binary to hex calculator: https://www.rapidtables.com/convert/number/binary-to-hex.html

// -400.99556 converts to 0XFD9C211C
//  400.99556 to  0X263DEE4 



#include <stdio.h>
#include <stdlib.h>

int main()
{
    double nb;
    // long long ll;
     long twosComp;
    long final;
    long nbAsLong;

    printf("please enter the decimal number: ");
    int ret = scanf("%le",&nb);
    // int ret = scanf("%ld",&nb);

    // remove decimal
    nb=nb * 100000;

    // printf("input no cast: %Lf, \n",  nb);
    // printf("input no cast: %f, \n",  nb);
    // printf("input cast to long: %ld, \n", (long) nb);

    printf("input to 2s comp converter: %ld, \n", (long) nb);
    
    twosComp = (long) nb;

    if( twosComp < 0 )
    {
	twosComp *= -1;
        final = ~twosComp +1;
    }
    else
    {
        final = twosComp;
    }

    printf("2s Comp x %X\n",(unsigned int) final);
    

    nbAsLong = (long) nb;

    printf("nb cast long  %lX \n",  nbAsLong);
    printf("nb cast to unsigned int as hex %#X \n", (unsigned int) nb);

    printf("nbAsLong %#X \n", (unsigned int) nbAsLong);
    
    return 0;
}
