// project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Question {
public:
	string content;
	string variants[4];
	string right;
};

class Quiz {
public:
	vector<Question> questions;
	void retrieveQuestions() {
		ifstream in("questions.txt");
		if (in.is_open()) {
			string s;
			while (!in.eof()) {
				getline(in, s);
				Question q;
				q.content = s;
				for (int i = 0; i < 4; ++i) {
					getline(in, s);
					q.variants[i] = s;
				}
				getline(in, s);
				q.right = s;
				questions.push_back(q);
			}
		}
	}
};
int main() {
	Quiz quiz;
	quiz.retrieveQuestions();
	system("pause");
	return 0;
}