#include "stdafx.h"
#include "Passenger.h"
#include <string>

using namespace std;
namespace AirlineReservationSystem {
	Passenger::Passenger(const std::string& firstname, const std::string& lastname, int idNumber, const std::string& gender,const std::string& birthday)
		:mFirstName(firstname),mLastName(lastname),mIdNumber(idNumber),mGender(gender),mBirthday(birthday)
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
	void Passenger::setGender(const std::string& gender)
	{
		mGender = gender;
	}
	const string& Passenger::getGender() const
	{
		return mGender;
	}
	void Passenger::setBirthday(const std::string& birthday)
	{
		mBirthday = birthday;
	}
	const string& Passenger::getBirthday() const
	{
		return mBirthday;
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