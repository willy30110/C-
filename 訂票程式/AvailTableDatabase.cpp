#include <iostream>
#include <fstream>
using namespace::std;

#include "AvailTableDatabase.h"

// tableTypes[ i ] is the table type for i customers
const int tableTypes[ 13 ] = { 0, 1, 1, 2, 2, 3, 4, 4, 0, 0, 5, 5, 5 };

extern Date computeCurrentDate();

// calls loadAvailTables(), removes outdated available table informations and
// adds new available table informations
AvailTableDatabase::AvailTableDatabase()
{
   loadAvailTables();



}

// call storeAvailTables
AvailTableDatabase::~AvailTableDatabase()
{
   storeAvailTables();
}

// increases the number of available tables by one on date and timeCode for corresponding table type
void AvailTableDatabase::increaseAvailTables( int numCustomers, Date date, int timeCode )
{
   int tableType = tableTypes[ numCustomers ];
   vector< AvailTable >::iterator it = getAvailTable( date );
   it->increaseAvailTables( timeCode, tableType );
}

// decreases the number of available tables by one on date and timeCode for corresponding table type
void AvailTableDatabase::decreaseAvailTables( int numCustomers, Date date, int timeCode )
{
   int tableType = tableTypes[ numCustomers ];
   vector< AvailTable >::iterator it = getAvailTable( date );
   it->decreaseAvailTables( timeCode, tableType );
}

// returns true if there are available tables on date for corresponding table type
bool AvailTableDatabase::availableTables( int numCustomers, Date date )
{


}

// returns true if there are available tables on date and timeCode for corresponding table type
bool AvailTableDatabase::availableTables( int numCustomers, Date date, int timeCode )
{


}

void AvailTableDatabase::loadAvailTables()
{


}

void AvailTableDatabase::storeAvailTables()
{


}

// returns an iterator that points to the AvailTable object containing specified date
vector< AvailTable >::iterator AvailTableDatabase::getAvailTable( Date date )
{


}