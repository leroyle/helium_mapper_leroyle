
// 2's compliment calculator:  https://www.exploringbinary.com/twos-complement-converter/

// binary to hex calculator: https://www.rapidtables.com/convert/number/binary-to-hex.html

// -400.99556 converts to 0XFD9C211C


#include <stdio.h>
#include <stdlib.h>

int main()
{
    double nb;
    // long long ll;
    long ll;
    long final;

    printf("please enter the decimal number: ");
    int ret = scanf("%le",&nb);
    // int ret = scanf("%ld",&nb);

    // remove decimal
    nb=nb * 100000;

    // printf("input no cast: %Lf, \n",  nb);
    printf("input no cast: %f, \n",  nb);
    printf("input cast to long: %ld, \n", (long) nb);
    
    ll = (long) nb;

    if( ll < 0 )
    {
	ll *= -1;
        final = ~ll +1;
    }
    else
    {
        final = ll;
    }

    printf("less x %x\n",(unsigned int) final);
    
    // printf("ll %lld \n",ll);
    printf("ll %ld \n",ll);

    final = nb;

    printf("long long final %ld \n",  final);
    printf("final %#X \n", (unsigned int) final);
    
    return 0;
}
