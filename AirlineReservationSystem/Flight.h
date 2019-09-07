#pragma once
#include<string>
#include<vector>
#include"Passenger.h"

namespace AirlineReservationSystem {
	class Flight
	{
	public:
		Flight() = default;
		Flight(const std::string& arrivalCity, const std::string& depatureCity, int flightNumber,int totalSeats);

		void setArrivalCity(const std::string& arrivalCity);
		const std::string& getArrivalCity()const;

		void setDepatureCity(const std::string& depatureCity);
		const std::string& getDepatureCity()const;

		void setFlightNumber(int flightNumber);
		int getFlightNumber()const;

		 std::vector<int>& getAvailableSeats();

		 std::vector<Passenger>& getPassengers();

		void display() const;

		//vector<int>& getAvailableSeats();

		//void setAvailableSeats(const std::vector<int>& availableSeats);
	   // std::vector<int>& getAvailableSeats()const;

		void reserveSeat(Passenger& passenger);
       // std::vector<Passenger>& getPassengers() const;



	private:
		std::vector<Passenger> mPassengers;
		std::vector<int> mAvailableSeats;
		std::string mArrivalCity;
		std::string mDepatureCity;
		int mFlightNumber=-1;
	};
}
