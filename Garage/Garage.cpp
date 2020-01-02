#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

int menuChoice;
bool garageCreated = false;

// =============================================
//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Numbers after 15 include background colors
void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// =============================================
// Gets user input and returns it as a string
string GetString()
{
	string temp;
	cin >> temp;

	for (int i = 0; i < temp.size(); i++)
	{
		temp[i] = toupper(temp[i]);
	}

	return temp;
}


// =============================================
// Checks user input and controls for bad inputs
int GetInt()
{
	int temp;
	cin >> temp;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		temp = 0;
	}

	return temp;
}

// =====================< CLASS >========================
// Vehicle abstract base class
// Contains basic information
// (Manufacturer(string), Color(string), Vehicle Type(string))
class Vehicle 
{
protected:
	int wheelCount = 0;
	string manufacturer;
	string color;
	string vehicleType;

public:
	
	Vehicle(string manufact, string color, string type) : manufacturer(manufact), color(color), vehicleType(type) {}

	virtual void Output() = 0;

	int GetWheelCount() { return wheelCount; }
	string GetManufacturer() { return manufacturer; }
	string GetColor() { return color; }
	string GetVehicleType() { return vehicleType; }

	virtual int GetSeatCount() = 0;
	virtual string GetNumberPlate() = 0;
	virtual bool GetDoubleDecker() = 0;
	virtual string GetWeightClass() = 0;
	virtual string GetType() = 0;
	virtual bool GetElectric() = 0;

	virtual ~Vehicle() {};
};

// =====================< CLASS >========================
// Car class
// Contains car-specific information
// (Number Plate(string a), Manufacturer(string c), Color(string b), Seat Count(int d))
class Car : public Vehicle
{
protected:
	int seatCount;
	string numberPlate;

public:
	Car(string plate, string manufact, string color, int seatCount) : numberPlate(plate), Vehicle(manufact, color, "Car"), seatCount(seatCount) { wheelCount = 4; }

	void Output()
	{
		cout << vehicleType << ": " << numberPlate << " is a " << color << " " << manufacturer << " with " << seatCount << " seats" << endl;
	}

	int GetSeatCount() { return seatCount; }
	string GetNumberPlate() { return numberPlate; }
	bool GetDoubleDecker() { return 0; };
	string GetWeightClass() { return ""; }
	string GetType() { return ""; }
	bool GetElectric() { return 0; }

	~Car() 
	{
		cout << "Car removed" << endl;
	}
};

// =====================< CLASS >========================
// Bus class
// Contains Bus-specific information
// (Number Plate(string a), Manufacturer(string c), Color(string b), Seat Count(int d), Double Decker(bool))   
class Bus : public Vehicle
{
protected:
	int seatCount;
	string numberPlate;
	bool doubleDecker;

public:
	Bus(string plate, string manufact, string color, int seatCount, bool doubleDecker) : numberPlate(plate), Vehicle(manufact, color, "Bus"), seatCount(seatCount), doubleDecker(doubleDecker) { wheelCount = 8; }

	void Output()
	{
		cout << vehicleType << ": " << numberPlate << " is a " << color << " " << manufacturer << " with " << seatCount << " seats and is ";
		if (doubleDecker == true)
		{
			cout << "a double decker" << endl;
		}
		else
		{
			cout << "not a double decker" << endl;
		}
	}

	int GetSeatCount() { return seatCount; }
	string GetNumberPlate() { return numberPlate; }
	bool GetDoubleDecker() { return doubleDecker; }
	string GetWeightClass() { return ""; }
	string GetType() { return ""; }
	bool GetElectric() { return 0; }

	~Bus()
	{
		cout << "Bus removed" << endl;
	}
};

// Truck class
// Contains Bus-specific information
// (Number Plate(string a), Manufacturer(string c), Color(string b), Seat Count(int d), Double Decker(bool))
class Truck : public Vehicle
{
protected:
	int seatCount;
	string numberPlate;
	string weightClass;

public:
	Truck(string plate, string manufact, string color, int seatCount, string weightClass) : numberPlate(plate), Vehicle(manufact, color, "Truck"), seatCount(seatCount), weightClass(weightClass) 
	{ 
		if (weightClass == "LIGHT")
		{
			wheelCount = 4;
		}
		else if (weightClass == "MEDIUM")
		{
			wheelCount = 6;
		}
		else if (weightClass == "HEAVY")
		{
			wheelCount = 8;
		}
	}

	void Output()
	{
		cout << weightClass << " " << vehicleType << ": " << numberPlate << " is a " << color << " " << manufacturer << " with " << seatCount << " seats" << endl;
	}

	int GetSeatCount() { return seatCount; }
	string GetNumberPlate() { return numberPlate; }
	bool GetDoubleDecker() { return 0; }
	string GetWeightClass() { return weightClass; }
	string GetType() { return ""; }
	bool GetElectric() { return 0; }

	~Truck()
	{
		cout << "Truck removed" << endl;
	}
};

// Motorcycle class
// Contains Bus-specific information
// (Number Plate(string a), Manufacturer(string c), Color(string b), Seat Count(int d), Double Decker(bool))
class Motorcycle : public Vehicle
{
protected:
	int seatCount;
	string numberPlate;
	string weightClass;
	string type;

public:
	Motorcycle(string plate, string manufact, string color, string weightClass, string type) : numberPlate(plate), Vehicle(manufact, color, "Motorcycle"), seatCount(1), weightClass(weightClass), type(type)
	{
		wheelCount = 2;
	}

	void Output()
	{
		cout << weightClass << " " << vehicleType << "(" << type << ")" << ": " << numberPlate << " is a " << color << " " << manufacturer << endl;
	}

	int GetSeatCount() { return seatCount; }
	string GetNumberPlate() { return numberPlate; }
	bool GetDoubleDecker() { return 0; }
	string GetWeightClass() { return weightClass; }
	string GetType() { return type; }
	bool GetElectric() { return 0; }

	~Motorcycle()
	{
		cout << "Motorcycle removed" << endl;
	}
};

// Motorcycle class
// Contains Bus-specific information
// (Number Plate(string a), Manufacturer(string c), Color(string b), Seat Count(int d), Double Decker(bool))
class Bike : public Vehicle
{
protected:
	int seatCount;
	string type;
	bool electric;

public:
	Bike(string manufact, string color, bool electric, string type) : Vehicle(manufact, color, "Bike"), seatCount(1), electric(electric), type(type)
	{
		wheelCount = 2;
	}

	void Output()
	{
		if (electric == true)
		{
			cout << "Electric ";
		}
		else
		{
			"Regular ";
		}
		cout << vehicleType << "(" << type << ")" << ": " << "is a " << color << " " << manufacturer << endl;
	}

	int GetSeatCount() { return seatCount; }
	string GetNumberPlate() { return ""; }
	bool GetDoubleDecker() { return 0; }
	string GetWeightClass() { return ""; }
	string GetType() { return type; }
	bool GetElectric() { return electric; }

	~Bike()
	{
		cout << "Motorcycle removed" << endl;
	}
};

// =====================< CLASS >========================
// Garage class
// Saves a vector with vehicle pointers
class Garage
{
protected:
	vector <Vehicle*> vehicleList;

public:
	Garage(int max)
	{
		vehicleList.resize(max);
	}

	// =============================================
	// Adds a vehicle to garage vector, fills first empty spot
	void AddVehicle(string vehicle)
	{
		bool found = false;
		for (size_t i = 0; i < vehicleList.size(); i++)
		{
			if (vehicleList[i] == 0)
			{
				if (vehicle == "Car")
				{
					string a;
					string b;
					string c;
					int d;
					cout << "Parking spot nr." << i + 1 << " vacant." << endl;
					cout << "Number plate: "; a = GetString();
					cout << "Manufacturer: "; b = GetString();
					cout << "Color: "; c = GetString();
					cout << "Number of seats: "; d = GetInt();

					Vehicle* temp = new Car(a, b, c, d);
					vehicleList[i] = temp;
					cout << "Added Car" << endl;

					found = true;
					break;
				}

				else if (vehicle == "Bus")
				{
					string a;
					string b;
					string c;
					int d;
					bool e;
					cout << "Parking spot nr." << i + 1 << " vacant." << endl;
					cout << "Number plate: "; a = GetString();
					cout << "Manufacturer: "; b = GetString();
					cout << "Color: "; c = GetString();
					cout << "Number of seats: "; d = GetInt();
					cout << "Double decker? (1 = Yes, 0 = No): "; cin >> e;

					Vehicle* temp = new Bus(a, b, c, d, e);
					vehicleList[i] = temp;
					cout << "Added Bus" << endl;

					found = true;
					break;
				}

				else if (vehicle == "Truck")
				{
					string a;
					string b;
					string c;
					int d;
					string e;
					cout << "Parking spot nr." << i + 1 << " vacant." << endl;
					cout << "Number plate: "; a = GetString();
					cout << "Manufacturer: "; b = GetString();
					cout << "Color: "; c = GetString();
					cout << "Number of seats: "; d = GetInt();
					cout << "Weight Class (Heavy, Medium, Light): "; e = GetString();

					Vehicle* temp = new Truck(a, b, c, d, e);
					vehicleList[i] = temp;
					cout << "Added Truck" << endl;

					found = true;
					break;
				}
				else if (vehicle == "Motorcycle")
				{
					string a;
					string b;
					string c;
					string e;
					string f;
					cout << "Parking spot nr." << i + 1 << " vacant." << endl;
					cout << "Number plate: "; a = GetString();
					cout << "Manufacturer: "; b = GetString();
					cout << "Color: "; c = GetString();
					cout << "Weight Class ('Heavy', 'Medium', 'Light'): "; e = GetString();
					cout << "Motorcycle type (Off-Road, Street, Racing, etc.): "; f = GetString();

					Vehicle* temp = new Motorcycle(a, b, c, e, f);
					vehicleList[i] = temp;
					cout << "Added Motorcycle" << endl;

					found = true;
					break;
				}
				else if (vehicle == "Bike")
				{
					string b;
					string c;
					bool e;
					string f;
					cout << "Parking spot nr." << i + 1 << " vacant." << endl;
					cout << "Manufacturer: "; b = GetString();
					cout << "Color: "; c = GetString();
					cout << "Electrically powered? (1 = Yes, 0 = No): "; cin >> e;
					cout << "Bike type (Off-Road, Street, Racing, etc.): "; f = GetString();

					Vehicle* temp = new Bike(b, c, e, f);
					vehicleList[i] = temp;
					cout << "Added Bike" << endl;

					found = true;
					break;
				}
			}
		}
		if (found == false)
		{
			cout << "Garage full." << endl;
		}
	}

	// =============================================
	// Removes a vehicle from garage vector, clears chosen spot
	void RemoveVehicle()
	{
		int temp;
		cout << "Select parking spot to clear: ";
		cin >> temp;
		temp -= 1;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			temp = 100;
		}

		if (temp >= 0 && temp < vehicleList.size())
		{
			delete vehicleList[temp];
			vehicleList[temp] = 0;
		}

		else
		{
			cout << "Parking spot not found." << endl;
		}
	}

	// =============================================
	// Clears garage completely and forces user to create a new garage overriding it
	void DestroyAndExit()
	{
		for (size_t i = 0; i < vehicleList.size(); i++)
		{
			if (vehicleList[i] != 0)
			{
				delete vehicleList[i];
				vehicleList[i] = 0;
			}
		}
		cout << "Welcome, \nBefore you get started you need to create a garage." << endl;
		cout << "Enter 1 - 10 parking spots in your garage. \nEnter '100' to quit application." << endl << endl;
		garageCreated = false;
	}

	// =============================================
	// Prints types of vehicles and their number
	void PrintVehicles()
	{
		int carC = 0;
		int busC = 0;
		int truckC = 0;
		int motorcycleC = 0;
		int bikeC = 0;

		for (size_t i = 0; i < vehicleList.size(); i++)
		{
			if (vehicleList[i] != 0)
			{
				if (vehicleList[i]->GetVehicleType() == "Car")
				{
					carC++;
				}
				if (vehicleList[i]->GetVehicleType() == "Bus")
				{
					busC++;
				}
				if (vehicleList[i]->GetVehicleType() == "Truck")
				{
					truckC++;
				}
				if (vehicleList[i]->GetVehicleType() == "Motorcycle")
				{
					motorcycleC++;
				}
				if (vehicleList[i]->GetVehicleType() == "Bike")
				{
					bikeC++;
				}
			}
		}
		cout << carC << "\t" << "Cars\n" << busC << "\t" << "Buses\n" << truckC << "\t" << "Trucks\n" << motorcycleC << "\t" << "Motorcycles\n" << bikeC << "\t" << "Bikes" << endl;
	}

	// =============================================
	// Prints entire vector
	void PrintList()
	{
		int c = 0;

		for (size_t i = 0; i < vehicleList.size(); i++)
		{
			if (vehicleList[i] != 0)
			{
				Color(11);
				cout << "Parking spot " << i+1 << ": ";
				vehicleList[i]->Output();
				c++;
				Color(7);
			}
			else
			{
				Color(3);
				cout << "Parking spot " << i+1 << ": " << "Vacant" << endl;
			}
		}
		Color(3);
		cout << "(" << c << " vehicles in garage)" << endl;
		Color(7);
	}

	// =============================================
	// Searches though vector to find matching color
	void SearchForColor(string searchInput)
	{
		bool found = false;
		for (size_t i = 0; i < vehicleList.size(); i++)
		{
			if (vehicleList[i] != 0)
			{
				if (vehicleList[i]->GetColor() == searchInput)
				{
					if (found == false)
					{
						Color(11);
						cout << "Matching vehicles:" << endl;
					}
					Color(11);
					cout << "At parking spot " << i + 1 << ": ";
					vehicleList[i]->Output();
					Color(7);
					found = true;
				}
			}
		}
		if (found == false)
		{
			Color(3);
			cout << "No matching vehicles found." << endl;
			Color(7);
		}
	}

	// =============================================
	// Searches though vector to find matching wheel count
	void SearchForWheelCount(int searchInput)
	{
		bool found = false;
		for (size_t i = 0; i < vehicleList.size(); i++)
		{
			if (vehicleList[i] != 0)
			{
				if (vehicleList[i]->GetWheelCount() == searchInput)
				{
					if (found == false)
					{
						Color(11);
						cout << "Matching vehicles:" << endl;
					}
					Color(11);
					cout << "At parking spot " << i + 1 << ": ";
					vehicleList[i]->Output();
					Color(7);
					found = true;
				}
			}
		}
		if (found == false)
		{
			Color(3);
			cout << "No matching vehicles found." << endl;
			Color(7);
		}
	}

	// =============================================
	// Searches though vector to find matching manufacturer
	void SearchForManufacturer(string searchInput)
	{
		bool found = false;
		for (size_t i = 0; i < vehicleList.size(); i++)
		{

			if (vehicleList[i] != 0)
			{
				if (vehicleList[i]->GetManufacturer() == searchInput)
				{
					if (found == false)
					{
						Color(11);
						cout << "Matching vehicles:" << endl;
					}
					Color(11);
					cout << "At parking spot " << i + 1 << ": ";
					vehicleList[i]->Output();
					Color(7);
					found = true;
				}
			}
		}
		if (found == false)
		{
			Color(3);
			cout << "No matching vehicles found." << endl;
			Color(7);
		}
	}

	// =============================================
	// Searches though vector to find matching seat count
	void SearchForSeatCount(int searchInput)
	{
		bool found = false;
		for (size_t i = 0; i < vehicleList.size(); i++)
		{
			if (vehicleList[i] != 0)
			{
				if (vehicleList[i]->GetSeatCount() == searchInput)
				{
					if (found == false)
					{
						Color(11);
						cout << "Matching vehicles:" << endl;
					}
					Color(11);
					cout << "At parking spot " << i + 1 << ": ";
					vehicleList[i]->Output();
					Color(7);
					found = true;
				}
			}
		}
		if (found == false)
		{
			Color(3);
			cout << "No matching vehicles found." << endl;
			Color(7);
		}
	}

	// =============================================
	// Searches though vector to find matching number plate
	void SearchForNumberPlate(string searchInput)
	{
		bool found = false;
		for (size_t i = 0; i < vehicleList.size(); i++)
		{
			if (vehicleList[i] != 0)
			{
				if (vehicleList[i]->GetNumberPlate() == searchInput)
				{
					if (found == false)
					{
						Color(11);
						cout << "Matching vehicles:" << endl;
					}
					Color(11);
					cout << "At parking spot " << i + 1 << ": ";
					vehicleList[i]->Output();
					Color(7);
					found = true;
				}
			}
		}
		if (found == false)
		{
			Color(3);
			cout << "No matching vehicles found." << endl;
			Color(7);
		}
	}
};



int main()
{
	int searchInputInt;
	string searchInput;

	bool running = true;
	bool searchMenu = true;

	cout << "Welcome, \nBefore you get started you need to create a garage." << endl;
	cout << "Enter 1 - 10 parking spots in your garage. \nEnter '100' to quit application." << endl << endl;

	// Garage creating manu
	while (running == true)
	{
		cout << "Number of parking spots: ";
		int parkingSpots = GetInt();
		
		if (parkingSpots <= 10 && parkingSpots > 0)
		{
			Garage garage(parkingSpots);
			garageCreated = true;
			cout << "Garage successsfully created." << endl;

			// Main menu
			while (garageCreated == true)
			{
				Color(15);
				cout << "\nEnter [1]: To Add Vehicle." << endl
				<< "Enter [2]: To Remove Vehicle." << endl
				<< "Enter [3]: To List Parked Vehicles." << endl
				<< "Enter [4]: To Search for Vehicles." << endl
				<< "Enter [5]: To List Number of Vehicles of Each Type." << endl
				<< "Enter [6]: To Destroy and Exit Current Garage, Then Create new Garage" << endl;
				
				Color(7);
				menuChoice = GetInt();
				switch (menuChoice)
				{
				case 1:
					cout << "\nEnter [1]: To Add Car." << endl
					<< "Enter [2]: To Add Bus." << endl
					<< "Enter [3]: To Add Truck." << endl
					<< "Enter [4]: To Add Motorcycle." << endl
					<< "Enter [5]: To Add Bike." << endl;

					menuChoice = GetInt();
					switch (menuChoice)
					{
					case 1:
						garage.AddVehicle("Car");
						break;
					case 2:
						garage.AddVehicle("Bus");
						break;
					case 3:
						garage.AddVehicle("Truck");
						break;
					case 4:
						garage.AddVehicle("Motorcycle");
						break;
					case 5:
						garage.AddVehicle("Bike");
						break;
					default:
						break;
					}
					break;

				case 2:
					garage.RemoveVehicle();
					break;

				case 3:
					garage.PrintList();
					break;

				case 4:
					searchMenu = true;
					while (searchMenu == true)
					{
						Color(15);
						cout << "\nEnter [1]: To Find all with Chosen Color." << endl
						<< "Enter [2]: To Find all with Chosen Number of Wheels." << endl
						<< "Enter [3]: To Find all by Chosen Manufacturer." << endl
						<< "Enter [4]: To Find all with Chosen Number of Seats." << endl
						<< "Enter [5]: To Find specific vehicle." << endl
						<< "Enter [6]: Return to Main Menu." << endl;
						Color(7);
						menuChoice = GetInt();
						switch (menuChoice)
						{
						case 1:
							cout << "Color: ";
							searchInput = GetString();
							garage.SearchForColor(searchInput);
							break;

						case 2:
							cout << "Wheel count: ";
							searchInputInt = GetInt();
							garage.SearchForWheelCount(searchInputInt);
							break;

						case 3:
							cout << "Manufacturer: ";
							searchInput = GetString();
							garage.SearchForManufacturer(searchInput);
							break;

						case 4:
							cout << "Number of seats: ";
							searchInputInt = GetInt();
							garage.SearchForSeatCount(searchInputInt);
							break;

						case 5:
							cout << "Registration plate: ";
							searchInput = GetString();
							garage.SearchForNumberPlate(searchInput);
							break;

						case 6:
							searchMenu = false;
							break;

						default:
							cout << "Invalid choice." << endl << endl;
							break;
						}
					}
					break;

				case 5:
					garage.PrintVehicles();
					break;

				case 6:
					garage.DestroyAndExit();
					break;

				default:
					cout << "Invalid choice." << endl << endl;
					break;
				}
			}
		}

		else if (parkingSpots == 100)
		{
			running = false;
		}

		else
		{
			cout << "Failed to create garage." << endl;
		}
	}
}