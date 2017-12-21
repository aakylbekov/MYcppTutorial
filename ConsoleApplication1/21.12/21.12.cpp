// 21.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class A {
public:
	int value;
	A() {
		std::cout << "A()" << std::endl;
	}
	A(int x) : value(x) {}
	~A() {
		std::cout << "~A()" << std::endl;
	}
 
	friend std::ostream & operator<< (std::ostream &, const A &);
	friend void operator >>(std::istream & stream, const A & a);
};
std::ostream & operator<<(std::ostream & stream, const A & a)
{
	return stream << a.value;
}
void operator>>(std::istream & stream, const A & a) {
	stream >> a;
}
//void find() {
//	int arr[10] = { 1,2,5,9,4,6,7,8,0,3 };
//	/*int * p;
//
//	p = std::find (arr, arr + 10, 3);
//	if (p != arr + 10)
//		std::cout << "Element found in myints: " << *p << '\n';
//	else
//		std::cout << "Element not found in myints\n";	*/
//	
//	std::vector<A> myvector(arr, arr + 10);
//	std::vector<A>::iterator it;
//
//	it = find(myvector.begin(), myvector.end(),11);
//	if (it != myvector.end())
//		std::cout << "Element found in myvector: " << *it << '\n';
//	else
//		std::cout << "Element not found in myvector\n";
//
//}

class Finder {  //Functor 
public:
	Finder(int y) : x(y) {  }
	int x;
	bool operator() (const A & a) {
		return x == a.value;
	}
};

void lambda(){

std::vector<A> x = { A(1),A(2), A(3) };
std::for_each(x.begin(), x.end(), [](A a) {std::cout << a.value << "\t"; });
std::cout << std::endl;
int y;
std::cin >> y;
Finder f(y);
auto a = std::find_if(x.begin(), x.end(), f);
auto b = std::find_if(x.begin(), x.end(), [y](A & a) {return a.value == y; }); //Lambda
if (a != x.end()) {
	std::cout << *a << "\t" << *b << std::endl;
}
else std::cout << "not found" << std::endl;

}

int main()
{
 
 
		std::vector<int> f= { 1,2,3,4 };
		std::vector<int> b = { 3,5,4,2 };

		if (std::is_permutation(f.begin(), f.end(), b.begin()))
			std::cout << "f and b contain the same elements.\n";
		else std::cout << "f and b does not contain the same elements.\n";
 
	system("pause");
	return 0;
}
 

