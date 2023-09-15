#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>


using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;


class ProfileNode {
public:
	ProfileNode(std::string n, int p) {
		this->name = n;
		this->points = p;
	}

	ProfileNode() {
		this->name = "";
		this->points = 0;
	}

	std::string getName() {
		return this->name;
	}

	int getPoints() {
		return this->points;
	}

	void setPoints(int p) {
		this->points = p;
	}

	void setName(std::string n) {
		this->name = n;
	}

	void incrementPoints(int p) {
		this->points += p;
	}


private:
	std::string name;
	int points;
};