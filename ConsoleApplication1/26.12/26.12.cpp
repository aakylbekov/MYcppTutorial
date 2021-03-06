// 26.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//DZ 1 var  
//class City
//{
//public:
//	std::string country;
//	std::string name;
//	City(std::string country, std::string name) 
//	{
//	this->name =name;
//	this->country=country;
//	};
//	friend std::ostream & operator <<(std::ostream & stream, const City & city); 
//};
//std::ostream & operator <<(std::ostream & stream, City & city) {
//	return stream << city.country <<' '<< city.name<< std::endl;
//}
//int main()
//{
//	std::ofstream out("countries.txt");
//	std::vector<City> cities;
//
//	City city("KZ", "ALA");
//	cities.push_back(city);
//	City city1("KZ", "TSE");
//	cities.push_back(city1);
//	std::for_each(cities.begin(), cities.end(), [&out](City city) { out << city; });
//	system("pause");
//	return 0;
//}

//2 var
class City
{
public:
	std::string country;
	std::string name;
	City(std::string country, std::string name)
	{
		this->name = name;
		this->country = country;
	};
	friend std::ostream & operator <<(std::ostream & stream, const City & city);
	friend bool operator == (const City &a, const City &b);
};
bool operator == (const City &a, const City &b) {
	if (a.name != b.name) { return false; }
	else return true;
}
std::ostream & operator <<(std::ostream & stream, City & city) {
	return stream << city.country << ' ' << city.name << std::endl;
}
class Manager {
public:
	std::vector<City> cities;
	Manager() {
		City city("KZ", "ALA");
		cities.push_back(city);
		City city1("KZ", "TSE");
		cities.push_back(city1);
	}
	void writetoFile() {
		std::ofstream out("countries.txt");
		std::for_each(cities.begin(), cities.end(), [&out](City city) { 
			if (out.is_open()) {
				out << city;
			} });
		out.close();
	}
	void readfromFile() {
		std::ifstream in("countries.txt");
		if (in.is_open()) {
			while (in.eof()) {
				std::string s;
				std::getline(in, s);
				int position = s.find_first_of(' ');
				cities.push_back(
					City(
						std::string(s.begin(), s.begin() + position),
						std::string(s.begin() + position + 1, s.end())));
			}
		}
	}
	friend std::ostream & operator <<(std::ostream & stream, const Manager & manager);
	
	void findCity() { //finding of city
		std::string find;
	//	std::for_each(cities.begin(), cities.end(), [&country](City & city)	{if (country == city.country) {std::cout << city.name << std::endl;	}});
		std::cout << "Input City Name:" << std::endl;
		std::cin >> find;
		auto x = std::find_if(cities.begin(), cities.end(), [find] (City & city) {return find == city.name; });
		std::cout << x->country << std::endl;

	}
	void CitynameChange(){
		std::cout << "Input City Name to Change:" << std::endl;
		std::string h;
		std::cin >> h;
		City city("KZ", "ALA");
		City cirt("KZ", h);
		std::replace(cities.begin(), cities.end(), city, cirt);
	}
	void addNewCity(){
		std::cout << "Input City Name to add:" << std::endl;
		City city("KZ", "ALA");
	
	}
	void addNewCountry() {
	
	}
};

std::ostream & operator <<(std::ostream & stream, Manager & manager) {
	std::for_each(manager.cities.begin(), manager.cities.end(), [&stream](City & city) {
		stream << city.country<<' '<< city.name << std::endl;
	});
		return stream;
}

int main()
{
	Manager m;
	m.CitynameChange();
	std::cout << std::endl;
	m.writetoFile();
	m.readfromFile();
	std::cout << m;
	std::cout << m.cities.size();
	std::cout << std::endl;
	//m.findCity();
	std::cout << std::endl;
	

	system("pause");
	return 0;
}

