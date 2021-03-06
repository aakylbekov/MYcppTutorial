// 25.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//class Singleton
//{
//public:
//	
//	static Singleton & getInstance()
//	{
//	 
//		static Singleton Instance;
//		return Instance;
//	}
//private:
//	Singleton() {}
//	Singleton(const Singleton& ) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//};

class Subject;
class Observer;

class Subject {
public:
	double currency;
    std::vector<Observer> observers;
	void add(Observer & observer) {
		observers.push_back(observer);
	}
	void remove(int id) {
		observers.erase(observers.begin() + id);
	}
	void notify() {
		for (auto x: observers) {
			x.update();
		}
	}

};
class Observer {
	double currency;
	Subject *subject;
public:
	void update() {
		this->currency = subject->currency;
	}

};
int main()
{
	//auto x = Singleton::getInstance;
 
	system("pause");
	return 0;

}

