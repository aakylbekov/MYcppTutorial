// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void Open() {
	ifstream t("sample.txt");
	string str;
	if (!t.is_open()) {
		while (getline(t, str)) {
			cin >> str;
		}
	}
	t.close();
}

int main()
{
	ofstream o("sample.txt");
	string s;

	while (_getch() != 27) {
		while (getline(cin, s)) {
			o << s;
		}
	}
	o.close();
	system("pause");
	return 0;
}

