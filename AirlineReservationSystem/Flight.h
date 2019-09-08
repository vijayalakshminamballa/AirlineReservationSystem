#pragma once
#include<string>
#include<vector>
#include"Passenger.h"

namespace AirlineReservationSystem {
	class Flight
	{
	public:
		Flight() = default;
		Flight(const std::string& arrivalCity, const std::string& depatureCity, const std::string& duration,const std::string& depaturetime, const std::string& arrivaltime,int flightNumber,int totalSeats);

		void setArrivalCity(const std::string& arrivalCity);
		const std::string& getArrivalCity()const;

		void setDepatureCity(const std::string& depatureCity);
		const std::string& getDepatureCity()const;

		void setDuration(const std::string& duration);
		const std::string& getDuration()const;

		void setArrivalTime(const std::string& arrivaltime);
		const std::string& getArrivalTime()const;

		void setDepatureTime(const std::string& depaturetime);
		const std::string& getDepatureTime()const;

		void setFlightNumber(int flightNumber);
		int getFlightNumber()const;
        std::vector<int>& getAvailableSeats();
        std::vector<Passenger>& getPassengers();
        void display() const;
        void reserveSeat(Passenger& passenger);
      


	private:
		std::vector<Passenger> mPassengers;
		std::vector<int> mAvailableSeats;
		std::string mArrivalCity;
		std::string mDepatureCity;
		std::string mDuration;
		std::string mArrivalTime;
		std::string mDepatureTime;
		int mFlightNumber=-1;
	};
}
 