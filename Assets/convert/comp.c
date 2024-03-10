
https://www.allmath.com/ones-complement.php  // calculator
// ones compliment

main()
{


// dec -9675237
// 1. abs valu
// 2. ones complement
// 3. add 1
 x = 0x93A1E5

}


int main()
{
    int nb;
    printf("please enter the decimal number: ");
    scanf("%d",&nb);
    char octal[100]="",hex[100]="";
    //octal will hold the octal notation 
    //hex will hold the hexadecimal notation
    sprintf(octal,"%#o",nb); //convert decimal to octal 
    sprintf(hex,"%#X",nb); // convert decimal to hexadecimal 

    // show the result 
    printf("converting %d to hexadecimal notation %s\n",nb,hex);
    printf("converting %d to octal notation %s\n",nb,octal);

    return 0;
}
