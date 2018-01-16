// ProjectQiuz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class Login {
public:
	std::string name; char male;
	int age;
	bool is_new_user = true;
	float rate = 0;
	Login(std::string name, int age, char male, bool is_new_user) {
		this->name = name;
		this->age = age;
		this->male = male;
		this->is_new_user = is_new_user;
	}
	Login() {}
	void setUser()
	{
		std::cout << "\n\t Input NAME: ";                    std::cin >> name;
		std::cout << "\n\t Input AGE: ";                     std::cin >> name;
		std::cout << "\n\t Input MAle - M or W: ";           std::cin >> name;
	 	is_new_user = false;
		rate = 0;
		system("cls");
	}
	std::string getUser() { return name;  }  //_getch();?
};

class Menu {
public:
	std::vector<Login> menu;
	Menu(){}
	Menu(){
	Login login("ALA");
	menu.push_back(login);
	}
	void writetoFile() {
		std::ofstream out("qiuz.txt");
		std::for_each(menu.begin(), menu.end(), [&out](Login login) {
			if (out.is_open()) {
				out << login;
			} });
		out.close();
	}
	void readfromFile() {
		std::ifstream in("qiuz.txt");
		if (in.is_open()) {
			while (in.eof()) {
				std::string s;
				std::getline(in, s);
				int position = s.find_first_of(' ');
				menu.push_back(
					Login(
						std::string(s.begin(), s.begin() + position),
						std::string(s.begin() + position + 1, s.end())));
			}
		}
	}
};
enum color { RED, GREEN, BLUE, WHITE };
void menu() {
	std::cout << std::setw(25);
	std::cout << "Choose one of the four:\n";
	std::cout << std::endl;
	
	std::cout << "1)  Mathematics\n" << "2)  Physics\n" << "3)  Biology\n" << "4)  Chemistry\n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1) {
		int choise;
		std::cout << std::endl;
		std::cin >> choise;
		switch (choise) {
		case 1:
			std::cout << "\t Mathematics\n";
			system("cls");
			std::cout << "\t 2+2-?\n";
			std::cout << "1)  4\n" << "2)  5\n" << "3)  3\n";
			std::cout << std::endl;
			std::cin >> choise;
			std::cout << std::endl;
			switch (choise) {
			case 1: 
				break;
			case 2:
			    break;
			case 3:
			 	break;
			}
		 	break;
		case 2:
			std::cout << "Physics\n";
			system("cls");
			std::cout << "\t 2+2-?\n";
			std::cout << "1)  4\n" << "2)  5\n" << "3)  3\n";
			std::cout << std::endl;
			std::cin >> choise;
			std::cout << std::endl;
			switch (choise) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;
		case 3:
			std::cout << "\tBiology\n";
			system("cls");
			std::cout << "\t 2+2-?\n";
			std::cout << "1)  4\n" << "2)  5\n" << "3)  3\n";
			std::cout << std::endl;
			std::cin >> choise;
			std::cout << std::endl;
			switch (choise) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;
		case 4:
			std::cout << "Chemistry\n";
			system("cls");
			std::cout << "\t 2+2-?\n";
			std::cout << "1)  4\n" << "2)  5\n" << "3)  3\n";
			std::cout << std::endl;
			std::cin >> choise;
			std::cout << std::endl;
			switch (choise) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;
		}
	}
	 
}
int main()
{
	
 menu();
	system("pause");
    return 0;
}

