#include <algorithm>
#include <iostream>
using namespace std;

// Function to check if a year is a leap year
bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

/**
 * Validate a given date
 * @param year, month, day : the date
 * @return true if the date is valid, false otherwise
 */
bool isValidDate(int year, int month, int day)
{
    // TODO
    // The year shall be a positive number
    // The month shall be a number between 1 and 12
    // The day shall be a number between 1 and the max days
    int max;
    if (month == 2 && isLeapYear(year))
    {
        max = 29;
    }
    else if (month == 2)
    {
        max = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        max = 30;
    }
    else
    {
        max = 31;
    }

    return (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= max);
}

/**
 * Compare 2 dates (date1 and date2)
 * @param year1, month1, day1 : date 1
 * @param year2, month2, day2 : date 2
 * @return
 *      -1 if date1 < date2
 *      0 if they are the same
 *      1 if date1 > date2
 */
int compare(int year1, int month1, int day1, int year2, int month2, int day2)
{
    // TODO
    if (year1 > year2)
    {
        return 1;
    }
    else if (year1 < year2)
    {
        return -1;
    }
    else
    {

        if (month1 > month2)
        {
            return 1;
        }
        else if (month1 < month2)
        {
            return -1;
        }
        else
        {
            if (day1 > day2)
            {
                return 1;
            }
            else if (day1 < day2)
            {
                return -1;
            }
            else if (day1 == day2)
            {
                return 0;
            }
        }
    }
}

int main()
{
    // 1- Input the dates
    int year1, month1, day1;
    cout << "Enter the first person's date of birth (year/month/day): ";
    cin >> year1 >> month1 >> day1;

    int year2, month2, day2;
    cout << "Enter the second person's date of birth (year/month/day): ";
    cin >> year2 >> month2 >> day2;

    // 2- Validate the dates (BONUS)
    // TODO
    if (isValidDate(year1, month1, day1))
    {
        cout << "Person 1 date of birth is valid" << endl;
    }
    else
    {
        cout << "Person 1 date of birth is invalid" << endl;
    }
    if (isValidDate(year2, month2, day2))
    {
        cout << "Person 2 date of birth is valid" << endl;
    }
    else
    {
        cout << "Person 2 date of birth is invalid" << endl;
    }

    // 3- Compare the dates
    // TODO
    if ((isValidDate(year1, month1, day1)) && (isValidDate(year2, month2, day2)))
    {
        if (compare(year1, month1, day1, year2, month2, day2) == -1)
        {
            cout << " Person1 is older than person2";
        }
        else if (compare(year1, month1, day1, year2, month2, day2) == 1)
        {
            cout << " Person2 is older than person1";
        }
        else
        {
            cout << " Person1 and Person2 are the same age";
        }
    }
    else
    {
        cout << "None comparable because not valid date";
    }
    return 0;
}
