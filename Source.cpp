/*
Program name: ClassDateExceptions.cpp
Programmer: Tyler Davies
Date: 11-8-21
Version: 1.0
Description: This program contains a class called Date, which stores a date in three integers:
             month, day, and year. It prints the date in three different formats (Ex: 12/25/2015; 
             December 25, 2015; and 25 December 2015). The main function implements and tests
             the class and its object's member functions.
*/

#include<iostream>
using namespace std;

//The Date class has three private data member integers that hold the month, day, and year. The
//public member functions set the private members and print the date in three different formats.
class Date
{
private:
    int month, day, year;
public:
    class InvalidDay      //Exception Class
        {};
    class InvalidMonth    //Exception Class
        {};
    Date(int, int, int);
    void setMonth(int num);
    void setDay(int num);
    void setYear(int num)
        { year = num; }
    void printMonthName() const;
    void printNumberFormat() const;
    void printFullFormat() const;
    void printDayMonthYear() const;
};

//The Date constructor has three default arguments. It passes the values given to it to the member
//functions setting the values for month, day, and year; this ensures valid values were entered.
Date::Date(int num1 = 1, int num2 = 1, int num3 = 2022)
{
    setMonth(num1);
    setDay(num2);
    setYear(num3);
}

//The setMonth function sets the month based on the value passed to it. An InvalidMonth exception
//class object is created and thrown when an invalid month (< 1 or > 12) is passed to the class.
void Date::setMonth(int num)
{
    try
    {
        if (num < 1 || num > 12)
            throw InvalidMonth();
        month = num;
    }
    catch (Date::InvalidMonth)
    {
        cout << "Error: invalid entry for month. \nThe date will not be updated!\n";
    }
}

//The setDay function sets the day based on the value passed to it. An InvalidDay exception class
//object is created and thrown when an invalid day (< 1 or > 31) is passed to the class.
void Date::setDay(int num)
{
    try
    {
        if (num < 1 || num > 31)
            throw InvalidDay();
        day = num;
    }
    catch (Date::InvalidDay)
    {
        cout << "Error: invalid entry for day. \nThe date will not be updated!\n";
    }
}

//The printMonthName function outputs a string based on the value stored in month.
void Date::printMonthName() const
{
    if (month == 1)
        cout << "January";
    else if (month == 2)
        cout << "February";
    else if (month == 3)
        cout << "March";
    else if (month == 4)
        cout << "April";
    else if (month == 5)
        cout << "May";
    else if (month == 6)
        cout << "June";
    else if (month == 7)
        cout << "July";
    else if (month == 8)
        cout << "August";
    else if (month == 9)
        cout << "September";
    else if (month == 10)
        cout << "October";
    else if (month == 11)
        cout << "November";
    else
        cout << "December";
}

//The printNumberFormat function outputs the date in the following format: 12/25/2015
void Date::printNumberFormat() const
{
    cout << month << '\/' << day << '\/' << year << endl;
}

//The printFullFormat function outputs the date in the following format: December 25, 2015
void Date::printFullFormat() const
{
    printMonthName();
    cout << ' ' << day << ", " << year << endl;
}

//The printDayMonthYear function outputs the date in the following format: 25 December 2015
void Date::printDayMonthYear() const
{
    cout << day << ' ';
    printMonthName();
    cout << ' ' << year << endl;
}

//The main function acts as a driver program, implementing and testing the class and its object's
//member functions.
int main()
{
    Date date(11, 8, 2021);
    cout << "Date object has been initialized with today's date (November 8, 2021).\n\n";

    cout << "Attempting to update day with an invalid number (50).\n";
    date.setDay(50);
    
    cout << "\nOutputting the date in number format (##\/##\/####):\n";
    date.printNumberFormat();

    cout << "\nAttempting to update month with an invalid number (-50).\n";
    date.setMonth(-50);

    cout << "\nOutputting the date in full format (Month ##, ####):\n";
    date.printFullFormat();

    cout << "\nUpdating date to December 31, 2021 using setDay(31) and setMonth(12).\n";
    date.setDay(31);
    date.setMonth(12);

    cout << "\nOutputting the date in day month year format (## Month ####):\n";
    date.printDayMonthYear();

    exit(0);
}