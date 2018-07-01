#include <iostream>

struct birthDate
{
    int birthYear;
    int birthMonth;
    int birthDay;
};

struct currentDate
{
    int year;
    int month;
    int day;
};

bool isDateBefore( birthDate &usersBirthDate, currentDate &date );
bool isLeapYear( int year );
int daysInMonth( int year, int month );
birthDate nextDay( birthDate &usersBirthDate );
int daysBetweenDates( birthDate &usersBirthDate, currentDate &date );
void getBirthDate( birthDate &usersBirthDate );
void getCurrentDate( currentDate &date );

int main()
{
    birthDate usersBirthDate;
    currentDate date;

    getBirthDate( usersBirthDate );
    getCurrentDate( date );

    std::cout << "Days alive: " << daysBetweenDates( usersBirthDate, date ) << std::endl;

    return 0;
}

bool isDateBefore( birthDate &usersBirthDate, currentDate &date  )
{

    
/* Checks if dates are valid. Returns True or False */
    if (usersBirthDate.birthYear < date.year){
      return true;
    }
    else if (usersBirthDate.birthYear ==  date.year){
        if (usersBirthDate.birthMonth < date.month){
            return true;
        }
        else if (usersBirthDate.birthMonth == date.month){
            if ( usersBirthDate.birthDay < date.day ){
               return true;
            }
        }
    }
    return false;
}

bool isLeapYear( int year )
{
    /* Check if the year is a Leap Year. Input an integer. Returns True or False */
    if (year % 400 == 0) {
      return true;
    }
    else if (year % 100 == 0){
      return false;
    }
    else if (year % 4 == 0){
      return true;
    }
    else{
      return false;
    }
}

int daysInMonth(int year, int month)
{
    /* Input year and month, Returns the amount of days in the given month */
    int days = 0;
    switch (month) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        days = 31;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        days = 30;
        break;
      case 2:
        if( isLeapYear( year ) ){
          days = 29;
        }
        else {
          days = 28;
        }
        break;
    }
    return days;
}

birthDate nextDay( birthDate &usersBirthDate )
{
    /* The counter. Moves the date to the next day by one number. returns the new date */
    if ( usersBirthDate.birthDay < daysInMonth( usersBirthDate.birthYear, usersBirthDate.birthMonth ) ){
      usersBirthDate.birthYear = usersBirthDate.birthYear;
      usersBirthDate.birthMonth = usersBirthDate.birthMonth;
      usersBirthDate.birthDay = ++usersBirthDate.birthDay;
      return usersBirthDate;
    }
    else {
      if ( usersBirthDate.birthMonth == 12) {
        usersBirthDate.birthYear = ++usersBirthDate.birthYear;
        usersBirthDate.birthMonth = 1;
        usersBirthDate.birthDay = 1;
        return usersBirthDate;
      }
      else {
        usersBirthDate.birthYear = usersBirthDate.birthYear;
        usersBirthDate.birthMonth = ++usersBirthDate.birthMonth;
        usersBirthDate.birthDay = 1;
        return usersBirthDate;
      }
    }
}

int daysBetweenDates( birthDate &usersBirthDate, currentDate &date )
{
    /* Counts the days between dates. Returns the number of days */
    int days = 0;
    while ( isDateBefore( usersBirthDate, date ) ){
        usersBirthDate = nextDay( usersBirthDate );
        days+=1;
    }
    return days;
}

void getBirthDate( birthDate &usersBirthDate )
{
    // 10749 days alive bewteen 1989 1 24 and 2018 5 30
    std::cout << "\nEnter Birth year: ";
    std::cin >> usersBirthDate.birthYear;
    std::cout << "\nEnter Birth month ( 1-12 ): ";
    std::cin >> usersBirthDate.birthMonth;
    std::cout << "\nEnter Birth day: ";
    std::cin >> usersBirthDate.birthDay;
}

void getCurrentDate( currentDate &date )
{
    std::cout << "\nEnter current year: ";
    std::cin >> date.year;
    std::cout << "\nEnter current month ( 1-12 ): ";
    std::cin >> date.month;
    std::cout << "\nEnter current day: ";
    std::cin >> date.day;
}