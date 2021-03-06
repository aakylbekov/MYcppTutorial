
#include "stdafx.h"
class Login {
public:
	Login() {}
	std::string name;
	std::string male;
	int age;
	bool is_new_user = true;
	float rate = 0;
	Login(std::string name, std::string male) {
		this->name = name;
		this->male = male;
		//this->is_new_user = is_new_user;
	}
	virtual void setUser()
	{	};
	std::string getUser() { return name; }  //_getch();?
	friend std::ostream & operator <<(std::ostream & stream, const Login & login);
	friend bool operator == (const Login &a, const Login &b);
};
std::ostream & operator <<(std::ostream & stream, Login & login) {
	return stream << login.name << ' ' << login.male << std::endl;
}
bool operator==(const Login & a, const Login & b)
{
	return false;
}

class Manager {
public:
	std::vector<Login> menu;
	Manager() {
		Login login("name", "male");
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

	friend std::ostream & operator <<(std::ostream & stream, const Manager & menu);
};

class Menu : public Login {
public:
	Menu() {}
	void setUser() {
		std::cout << "\n\t Input NAME: ";                    std::cin >> name;
		//std::cout << "\n\t Input AGE: ";                     std::cin >> age;
		std::cout << "\n\t Input MAle - M or W: ";           std::cin >> male;
		is_new_user = false;
		rate = 0;
		system("cls");
	}
	void quiz() {
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
					system("cls");
					std::cout << "\t sqrt of 4 - ?\n";
					std::cout << "1)  3\n" << "2)  2\n" << "3)  6\n";
					std::cout << std::endl;
					std::cin >> choise;
					std::cout << std::endl;
					switch (choise) {
					case 1:
						system("cls");
						std::cout << "\t (a+b)^2- ?\n";
						std::cout << "1)  a^2+b^2\n" << "2)  a+b+a+b\n" << "3)  (a^2+2ab+b^2)\n";
						std::cout << std::endl;
						std::cin >> choise;
						std::cout << std::endl;
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
					}
				}
				Manager m;
				m.writetoFile();
				m.readfromFile();
			}
		}
};
int main()
{
	Menu menu;
	menu.setUser();
	menu.quiz();
	system("pause");
	return 0;
}