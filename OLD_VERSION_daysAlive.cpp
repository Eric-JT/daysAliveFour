#include <iostream>

using namespace std;

bool isLeapYear(int year)
{
/* Check if year is a leap year. Returns true or false */
  if (year % 400 == 0)
    return true;
  else if (year % 100 == 0)
    return false;
  else if (year % 4 == 0)
    return true;
  else
    return false;
}


int daysInMonth(int year, int month)
{
  /* Check how many days are in the month. Returns number of days */
  int days;
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
      if (isLeapYear(year))
        days = 29;
      else
        days = 28;
      break;
  }
  return days;
}


int* nextDay(int date[])
{
  /* Moves the current date up by one. Returns the date */
  if (date[2] < daysInMonth(date[0], date[1])){
      date[0] = date[0];
      date[1] = date[1];
      date[2] = ++date[2];
      return date;
    }
  else {
    if (date[1] == 12) {
      date[0] = ++date[0];
      date[1] = 1;
      date[2] = 1;
      return date;
    }
    else {
      date[0] = date[0];
      date[1] = ++date[1];
      date[2] = 1;
      return date;
    }
  }
}


bool isDateBefore(int dateOne[], int dateTwo[])
{
  /* Checks to make sure the birth date is before the current date. Returns true or false */
  if (dateOne[0] < dateTwo[0])
    return true;
  else if (dateOne[0] ==  dateTwo[0]){
    if (dateOne[1] < dateTwo[1]){
      return true;
    }
    else if (dateOne[1] == dateTwo[1]){
      return dateOne[2] < dateTwo[2];
    }
  }
  return false;
}


int daysBetweenDates(int dateOne[], int dateTwo[])
{
  /* Counts the number of days between dates. Returns the number of days */
  int days;
  while (isDateBefore(dateOne, dateTwo)){
    dateOne = nextDay(dateOne);
    days+=1;
  }
  return days;
}


int main()
{

  int dateOne[2];
  int dateTwo[2];

  /* Inputs */

  // Birth Date
  cout<<"Enter your birth year: ";
  cin>>dateOne[0];

  cout<<"Enter your birth month: ";
  cin>>dateOne[1];

  cout<<"Enter birth day: ";
  cin>>dateOne[2];

  // Current Date
  cout<<"Enter current year: ";
  cin>>dateTwo[0];

  cout<<"Enter curretn month: ";
  cin>>dateTwo[1];

  cout<<"Enter current day: ";
  cin>>dateTwo[2];


  int days = daysBetweenDates(dateOne, dateTwo);

  cout<<"number of days: "<<days<<endl;

  return 0;
}
