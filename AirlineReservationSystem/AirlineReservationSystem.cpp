// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "stdafx.h"
#include <iostream>
#include "Database.h"


using namespace AirlineReservationSystem;
using namespace std;


int displayMenu();
void  reserveASeat(Database& db);
void flightSchedule(Database& db);
void displayPassengerInfo(Database& db);
void displayFlightDetails(Database& db);
void userTicketInfomation(Database& db);
Flight& chooseFlight(Database& db);


int main()
{
	Database airlineDb;

	Flight flight1("Seattle", "Dubai", 1,60);
	Flight flight2("Newyork", "Hawaii", 2,70);
	Flight flight3("LasVegas", "Seattle", 3,80);
	Flight flight4("Portland", "Los Angeles", 4, 50);
	 
	airlineDb.addFlight(flight1);
	airlineDb.addFlight(flight2);
	airlineDb.addFlight(flight3);
	airlineDb.addFlight(flight4);

	while (true)
	{
		int selection = displayMenu();
		switch (selection)
		{
			case 0:
				return 0;
			case 1:
				reserveASeat(airlineDb);
				break;
			case 2:
				flightSchedule(airlineDb); 
				break;
			case 3:
				displayPassengerInfo(airlineDb);
				break;
			case 4:
				displayFlightDetails(airlineDb);
				break;
			case 5:
				userTicketInfomation(airlineDb);
				break;
			default:
				cerr << "Unknown command! Try Again!" << endl;
			break;
		}
	}
	return 0;
}

int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Airline Menu:" << endl;
	cout << "1.Reserve a Seat" << endl;
	cout << "2.Flight Schedule" << endl;
	cout << "3.Display Passenger Info" << endl;
	cout << "4.Flight Details" << endl;
	cout << "5.User Ticket Information" << endl;
	cout << "0. Quit" << endl;
	cout << endl;
	cin >> selection;
	cout << selection;
   
	return selection;
}

void flightSchedule(Database& db)
{
	vector<Flight>& Flights = db.getAllFlights();
	for (Flight& flight : Flights) {
		flight.display();
	}

}
Flight& chooseFlight(Database& db) {
	int flightId;
	cout << "Choose Flight Number " << endl;
	flightSchedule(db);
	cin >> flightId;
	Flight& flight = db.getFlight(flightId);
	return flight;
}

Passenger& getPassengerInfo()
{
	string firstName;
	string lastName;
	int Id;
	cout << "First Name:" << endl;
	cin >> firstName;
	cout << "Last Name:" << endl;
	cin >> lastName;
	cout << "Id Number" << endl;
	cin >> Id;

	Passenger* passenger = new Passenger(firstName, lastName, Id);
	return *passenger;


}
void reserveASeat(Database& db)
{
	int chosenSeat;
	int NumberOfSeats;

	Flight& flight = chooseFlight(db);
	cout << "Number of seats you want to reserve" << endl;
	cin >> NumberOfSeats;

	std::vector<int> availableSeats = flight.getAvailableSeats();
	for (int seat : availableSeats) {
		cout << seat << " ";
	}
	for (int i =0; i<NumberOfSeats; i++)
	{

		cout << endl << "Choose Your Seat " << endl;
		cin >> chosenSeat;
        Passenger& passenger = getPassengerInfo();
		passenger.setSeatNumber(chosenSeat);
		flight.reserveSeat(passenger);
	}
}

void displayPassengerInfo(Database& db) {

	Flight& flight = chooseFlight(db);

	vector<Passenger> passengers = flight.getPassengers();
	for (Passenger& passenger : passengers) {
		cout << "Passenger Information:" << endl;
		cout << "Seat Number: " << passenger.getSeatNumber() << endl;
		cout << "Name: " << passenger.getFirstName() << " " << passenger.getLastName() << endl;
		cout << "Flight Number: " << flight.getFlightNumber() << endl;
		cout << "Flight From: " << flight.getDepatureCity() << " To: " << flight.getArrivalCity() << endl;
		cout << endl;
	}
}
void userTicketInfomation(Database& db)
{
	Flight& flight = chooseFlight(db);

	int userId;
	cout << " Id number ";
	cin >> userId;

	vector<Passenger> passengers = flight.getPassengers();
	bool userFound = false;
	for (Passenger& passenger : passengers) {
		if (userId == passenger.getIdNumber()) {
			userFound = true;
			cout << "Passenger Information:" << endl;
			cout << "-------------------------" << endl;
			cout << "Name: " << passenger.getFirstName() << " " << passenger.getLastName() << endl;
			cout << "Flight Number: " << flight.getFlightNumber() << endl;
			cout << "Flight From: " << flight.getDepatureCity() << " to " << flight.getArrivalCity() << endl;
			cout << "Seat Number: " << passenger.getSeatNumber() << endl;
			cout << endl;
		}
	}
	if (userFound == false) {
		cout << "Passenger information not found." << endl;
	}
   }
		void displayFlightDetails(Database & db) {
			Flight& flight = chooseFlight(db);
			flight.display();
			vector<int> freeSeats = flight.getAvailableSeats();
			vector<Passenger> seatsBooked = flight.getPassengers();
			cout << "Number of seats left: " << freeSeats.size() << endl;
			cout << "Seats booked: " << seatsBooked.size() << endl;
         }





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
