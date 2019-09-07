#pragma once
#include <iostream>
#include <vector>
#include "Flight.h"
namespace AirlineReservationSystem
{
	class Database {

	public:
		void addFlight(Flight& flight);
	    Flight& getFlight(int flightNumber);
		std::vector<Flight>& getAllFlights();


	private:
		std::vector<Flight>mFlights;
	};
 }