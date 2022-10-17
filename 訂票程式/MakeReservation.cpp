// MakeReservation.cpp
// Member-function definitions for class MakeReservation.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "MakeReservation.h"     // MakeReservation class definition

extern int inputAnInteger( int begin, int end );
extern Date computeCurrentDate();

// MakeReservation constructor initializes base-class data members
MakeReservation::MakeReservation( ReservationDatabase &theReservationDatabase,
                                  AvailTableDatabase &theAvailTableDatabase )
   : reservationDatabase( theReservationDatabase ),
     availTableDatabase( theAvailTableDatabase )
{
}

// make reservation
void MakeReservation::execute()
{
   int numCustomers;
   do {
      cout << "\nEnter the number of customers (1 - 7, 10 - 12): ";
      numCustomers = inputAnInteger( 1, 12 );
   } while( numCustomers == 8 || numCustomers == 9 || numCustomers == -1 );

   Date currentDate = computeCurrentDate();

   Date date;
   chooseDate( date, currentDate, numCustomers );

   int timeCode;
   chooseTime( timeCode, date, numCustomers );

   cout << "\nEnter name: ";
   string name;
   cin >> name;

   cout << "\nEnter mobile number: ";
   string mobileNumber;
   cin >> mobileNumber;

   cout << "\nEnter email address: ";
   string email;
   cin >> email;

   cout << "\nEnter reservation password: ";
   string password;
   cin >> password;
   cin.ignore();

   string reservationNumber;
   for( int i = 0; i < 8; i++ )
      reservationNumber.push_back( rand() % 10 + '0' );

   Reservation newReservation( numCustomers, date, timeCode, name, mobileNumber,
                               email, password, reservationNumber );

   cout << setfill( ' ' ) << endl << setw( 11 ) << "Mobile No." << setw( 10 ) << "Name"
      << setw( 14 ) << "Date" << setw( 9 ) << "Time" << setw( 30 ) << "Email"
      << setw( 19 ) << "No of Customers" << setw( 12 ) << "Password"
      << setw( 19 ) << "Reservation No." << endl;

   newReservation.displayReservationInfo();

   reservationDatabase.pushBack( newReservation );

   cout << "\nReservation Completed.\n";

   availTableDatabase.decreaseAvailTables( numCustomers, date, timeCode );
}

// choose a date
void MakeReservation::chooseDate( Date &date, Date currentDate, int numCustomers )
{


}

// choose a time
void MakeReservation::chooseTime( int &timeCode, Date date, int numCustomers )
{


}