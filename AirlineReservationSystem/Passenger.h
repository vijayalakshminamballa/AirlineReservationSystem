#pragma once
#include <string>
namespace AirlineReservationSystem {
	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& firstname, const std::string& lastname, int idNumber, const std::string& gender,const std::string& birthday);

		void setFirstName(const std::string& firstname);
		const std::string& getFirstName()const;

		void setLastName(const std::string& lastname);
		const std::string& getLastName()const;

		void setGender(const std::string& gender);
		const std::string& getGender()const;

		void setBirthday(const std::string& birthday);
		const std::string& getBirthday()const;


		void setIdNumber(int idNumber);
		int getIdNumber()const;

		void setSeatNumber(int seatNumber);
		int getSeatNumber()const;

		
	 private:
		std::string mFirstName;
		std::string mLastName;
		std::string mGender;
		std::string mBirthday;
		int mIdNumber = -1;
		int mSeatNumber = -1;

	};

}
