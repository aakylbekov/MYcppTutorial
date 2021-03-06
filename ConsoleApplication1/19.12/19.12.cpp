// 19.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class A{
public:
	int value;
	A() {
		std::cout << "A()" << std::endl;
	}
	
	~A() {
		std::cout << "~A()" << std::endl;
	}
	int value;
	friend std::ostream & operator<<(std::ostream &, const A &);
	friend void operator>>(std::istream & stream, const A & a);
};
void auto_ptr() {
	std::auto_ptr<A> a(new A());
	a->value = 5;
	std::auto_ptr<A> b = a;
	std::cout << b->value << "\t" << std::endl;
}

void shared_ptr() {
	std::shared_ptr<int> x(new int(5));
	std::cout << x.use_count();
}
void use_count() {}



int main()
{
	auto_ptr();
	system("pause");
    return 0;
}

