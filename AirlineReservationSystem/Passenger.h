#pragma once
#include <string>
namespace AirlineReservationSystem {
	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& firstname, const std::string& lastname, int idNumber);

		void setFirstName(const std::string& firstname);
		const std::string& getFirstName()const;

		void setLastName(const std::string& lastname);
		const std::string& getLastName()const;

		void setIdNumber(int idNumber);
		int getIdNumber()const;

		void setSeatNumber(int seatNumber);
		int getSeatNumber()const;

		
	 private:
		std::string mFirstName;
		std::string mLastName;
		int mIdNumber = -1;
		int mSeatNumber = -1;

	};

}
