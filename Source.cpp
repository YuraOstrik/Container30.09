#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Car
{
public:
	string name;
	int year;
	double eng;
	double price;

	Car(string n, int y, double e, double p): 
		name(n),year(y),eng(e),price(p){}
	void Print() const
	{
		cout << "Name -> " << name
			<< " \tYear -> " << year
			<< " \tEng -> " << eng
			<< " \tPrice -> " << price << endl;
	}
};

struct SortName {
	bool operator()(const Car& car1, const Car& car2) const {
		return car1.name < car2.name;
	}
};

struct SortYear {
	bool operator()(const Car& car1, const Car& car2) const {
		return car1.year < car2.year;
	}
};


struct SortEng {
	bool operator()(const Car& car1, const Car& car2) const {
		return car1.eng < car2.eng;
	}
};
struct SortPrice {
	bool operator()(const Car& car1, const Car& car2) const {
		return car1.price < car2.price;
	}
};

struct FindName {
	string name;
	FindName(const string& n) : name(n){}
	bool operator()(const Car& car) const {
		return car.name == name;
	}
};


struct FindYear {
	int year;
	FindYear(int y) : year(y) {}
	bool operator()(const Car& car) const {
		return car.year == year;
	}
};


class Dealer {
private:
	vector<Car> cars;
public:
	void Add(const string& name, int year, double eng, double price)
	{
		Car newcar(name, year, eng, price);
		cars.push_back(newcar);
	}
	void Remove(string& name)
	{
		auto it = remove_if(cars.begin(), cars.end(), FindName(name));
		if (it != cars.end())
		{
			cars.erase(it, cars.end());
			cout << " Automobile has vanished - " << name << endl;

		}
		else {
			cout << "None automobibic" << endl;
		}
	}
	void Sort(const string& c) {
		if (c == "name") {
			sort(cars.begin(), cars.end(), SortName());
		}
		else if (c == "year") {
			sort(cars.begin(), cars.end(), SortYear());
		}
		else if (c == "engine") {
			sort(cars.begin(), cars.end(), SortEng());
		}
		else if (c == "price") {
			sort(cars.begin(), cars.end(), SortPrice());
		}
		else {
			cout << "-------.\n";
			return;
		}
		cout << "Sort by - " << c << ".\n";
	}
	void Display() const {
		for (const auto& car : cars)
		{
			car.Print();
		}
	}

	void Search(const string& name) const
	{
		auto it = find_if(cars.begin(), cars.end(), FindName(name));
		if (it != cars.end())
		{
			it->Print();
		}
		else {
			cout << "Nope]" << endl;
		}
	}
	
};

int main()
{
	Dealer dealer;

	dealer.Add("Toyota", 2024, 2.5, 30000);
	dealer.Add("Merc", 2000, 2.0, 20000);
	cout << "\t|My garage|" << endl;
	dealer.Display();
	dealer.Sort("name");
	dealer.Display();
}


























