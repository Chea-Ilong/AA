#include <stdio.h>

int main()
{
    // TODO

    //  Enter the first person date of birth (year/month/day)
    //  Enter the second person date of birth (year/month/day)
    
    //  Depending on the 2 dates of birth, print either:
    //  - The first person is the youngest
    //  - The second person is the youngest
    //  - Both persons have the same age
    
    int person1_year, person1_month,person1_day;
    int person2_year, person2_month,person2_day;

    printf ("Enter the first person date of birth (year/month/day): ");
    scanf ("%d %d %d" ,&person1_year, &person1_month,&person1_day);

    printf ("Enter the second person date of birth (year/month/day): ");
    scanf ("%d %d %d" ,&person2_year, &person2_month,&person2_day);
    

    if (person1_year > person2_year || (person1_year == person2_year && person1_month > person2_month) || (person1_year == person2_year && person1_month == person2_month && person1_day > person2_day))
    {
        printf("\nThe first person is the youngest.\n");
    }
    else if (person2_year > person1_year || (person2_year == person1_year && person2_month > person1_month) || (person2_year == person1_year && person2_month == person1_month && person2_day > person1_day))
    {
        printf("\nThe second person is the youngest.\n");
    }
    else
    {
        printf("\nBoth persons have the same age.\n");
    }
    
 
    return 0;
}
