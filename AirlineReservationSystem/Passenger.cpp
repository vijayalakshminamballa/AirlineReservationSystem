#include "stdafx.h"
#include "Passenger.h"
#include <string>

using namespace std;
namespace AirlineReservationSystem {
	Passenger::Passenger(const std::string& firstname, const std::string& lastname, int idNumber) :mFirstName(firstname),mLastName(lastname),mIdNumber(idNumber)
	{}
	void Passenger::setFirstName(const std::string& firstname)
	{
		mFirstName = firstname;
	}
	const string& Passenger::getFirstName() const
	{
		return mFirstName;
	}
	void Passenger::setLastName(const std::string& lastname)
	{
		mLastName = lastname;
	}
	const string& Passenger::getLastName() const
	{
		return mLastName;
	}
	void Passenger::setIdNumber(int idNumber)
	{
		mIdNumber = idNumber;
	}
	int Passenger::getIdNumber() const
	{
		return mIdNumber;
	}
	void Passenger::setSeatNumber(int seatNumber)
	{
		mSeatNumber = seatNumber; 
	}
	int Passenger::getSeatNumber() const
	{
		return mSeatNumber;
	}
}