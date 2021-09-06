/*
Requirements
1) There should be multiple floors in parking lot
2) There should be multiple gates in the parking lot
3) There should be a parking attendant at each gate
4) The entry gate should process parking ticket
5) The exit gate should process payment on hourly basis
6) The parking lot should have parking facility for different types of vehicles
7) There should be a display board at each floor showing the details of vacant spots available on the floor.
*/

//Base Class Creation
class ParkingLot{
	vector<ParkingFloor> parkingFloors;
	vector<Entrances> entrances;
	vector<Exit> exits;
	
	//meta infro
	Address address;
	string parkingLotName;
	
public:
	bool isParkingSpaceAvailableForVehicle(Vechicle vehicle);
	bool updateParkingAttendant(ParkingAttendant parkingAttendant,int gateId);
};

//Defining all the complex objects created in base class
class ParkingFloor{
	int levelId;
	bool isFull;
	
	vector<ParkingSpaces> parkingSpaces;
	ParkingDisplayBoard parkingDisplayBoard;
}
	
	//exploiting the "is-a relationship" between gate class and entrance,exit classes with the help of inheritance.
class Gate{
protected:
	int gateId;
	ParkingAttendant parkingAttendant;
}

class Entrance: protected Gate{
public:
	ParkingTicket getParkingTicket(Vehicle vehicle);
}

class Exit: protected Gate{
public:
	ParkingTicket payForParking(ParkingTicket parkingTicket, PaymentType paymentType);
}

class ParkingSpace{
	int spaceId;
	bool isFree;
	double costPerHour;
	Vehicle vehicle;
	ParkingSpaceType parkingSpaceType;
}

