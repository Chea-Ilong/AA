#include <stdio.h>

int main()
{
    // TODO
    //  Input the number, the range min and the range max 
    //  Output "inside" if the number is in the range [min, max], "outside" otherwise
    int min,max,number;

    printf ("Input one number: ");
    scanf ("%d" ,&number);

    printf ("Enter the range min: ");
    scanf ("%d" ,&min);

    printf ("Enter the range max: ");
    scanf ("%d" ,&max);

    
    if ( number >= min && number <= max){
        printf ("%d is inside the range [%d, %d] ", number,min,max);
    }
    else{
          printf ("%d is outside the range [%d, %d] ", number,min,max);
    }
    
    return 0;
}
