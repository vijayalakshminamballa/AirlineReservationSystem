#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Flight.h"

using namespace std;
namespace AirlineReservationSystem
{
	Flight::Flight(const std::string& arrivalCity, const std::string& depatureCity, int flightNumber,int totalSeats):mArrivalCity(arrivalCity),mDepatureCity(depatureCity),
		mFlightNumber(flightNumber)
	{
		for (int i = 1; i <= totalSeats; i++) {
			mAvailableSeats.push_back(i);
		}

	}
	void Flight::setArrivalCity(const std::string& arrivalCity)
	{
		mArrivalCity = arrivalCity;
	}
	const std::string& Flight::getArrivalCity() const
	{
		return mArrivalCity;
	}
	void Flight::setDepatureCity(const std::string& depatureCity)
	{
		mDepatureCity = depatureCity;
	}
	const std::string& Flight::getDepatureCity() const
	{
		return mDepatureCity;
	}

	void Flight::setFlightNumber(int flightNumber)
	{
		mFlightNumber = flightNumber;
	}
	int Flight::getFlightNumber() const
	{
		return mFlightNumber;
	}
    std::vector<int>& Flight::getAvailableSeats() {
		return mAvailableSeats;
	}
	
	void Flight::reserveSeat(Passenger& passenger) {
		mPassengers.push_back(passenger);
		int seatNumber = passenger.getSeatNumber();
		mAvailableSeats.erase(std::remove(mAvailableSeats.begin(), mAvailableSeats.end(), seatNumber), mAvailableSeats.end());
	}
	   std::vector<Passenger>& Flight::getPassengers() {
		return mPassengers;
	}
	void Flight::display() const
	{
		cout << "Flight Number: "<<getFlightNumber() << "  travels from  " << getDepatureCity() << "  to  " << getArrivalCity() << endl;
	}

}
