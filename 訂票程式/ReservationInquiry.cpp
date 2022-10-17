#include <iostream>
using namespace::std;

#include "ReservationInquiry.h"

extern int inputAnInteger( int begin, int end );

ReservationInquiry::ReservationInquiry( ReservationDatabase &theReservationDatabase,
                                        AvailTableDatabase &theAvailTableDatabase )
   : reservationDatabase( theReservationDatabase ),
     availTableDatabase( theAvailTableDatabase )
{
}

// reservation inquiry
void ReservationInquiry::execute()
{
   if( reservationDatabase.empty() )
   {
      cout << "\nNo reservations!\n";
      return;
   }



}