// 20.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//bool compare(int u, int y) {
//	return u > y;
//}
class comparator {
public:
	bool operator() (int u, int y) {
		return u < y;
	}
};
void vector(){
int arr[10] = { 1,2,5,9,4,6,7,8,0,3 };
std::vector<int> x(arr, arr + 10);
//std::sort(x.begin(), x.end(), std::greater<int>());
//std::sort(x.begin(), x.end(), compare);
std::sort(x.begin(), x.end(), comparator());
auto it = x.begin();
for (; it != x.end(); ++it) {
	std::cout << *it << '\t';
}
std::cout << std::endl;
}
void list() {
	int arr[10] = { 1,2,5,9,4,6,7,8,0,3 };
	std::list<int> y(arr, arr + 10);
	y.sort();
	//std::sort(y.begin(), y.end());
	std::list<int>::iterator it1 = y.begin();
	for (; it1 != y.end();++it1) {
		std::cout << *it1 << '\t';
	}
	std::cout << std::endl;

}
void map() {
	std::map<std::string, int> dictionary;
	dictionary.emplace(std::make_pair<std::string, int>("123", 1));
	std::cout << dictionary.at("123") << std::endl;
	auto it2 = dictionary.begin();
	for (; it2 != dictionary.end(); ++it2) {
		std::cout << it2->first << '\t' << it2->second << std::endl;
	}
	std::cout << std::endl;
}

void vect2() {
	int arr[10] = { 1,2,5,9,4,6,7,8,0,3 };
	std::vector<int> x(arr, arr + 10);
	std::sort( x.begin(), x.end(), [](int x, int y) {return x < y; });
	//std::sort(x.begin(), x.end(), compare);
	std::sort(x.begin(), x.end(), comparator());
	auto it = x.begin();
	for (; it != x.end(); ++it) {
		std::cout << *it << '\t';
	}
	std::cout << std::endl;
}


int main()
{

	//map();
	std::cout<<std::endl;
	//vector();
//	lym();
	std::cout << std::endl;
	//list();
	system ("pause");
    return 0;
}

