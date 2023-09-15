#pragma once

#include "ProfileNode.h"



class Game {
public:
	Game() {
		this->arrCount = 0;
		this->proArr = new ProfileNode[1]();
		this->profilesF.open("profiles.csv");
		this->loadProfile();
	}

	~Game() {
		this->profilesF.close();
		this->profilesF.open("profiles.csv", std::fstream::out);		//Remove data in file

		for (int i = 0; i < arrCount; i++) {
			if (i == 0) {
				this->profilesF << this->proArr[i].getName() << "," << this->proArr[i].getPoints();
			}
			else {
				this->profilesF << "\n" << this->proArr[i].getName() << "," << this->proArr[i].getPoints();
			}
		}

		delete[] this->proArr;
		this->profilesF.close();
	}


	void loadProfile() {
		std::string line, name, temp;
		std::size_t commaPos;
		int points = 0;

		while (!this->profilesF.eof()) {
			std::getline(this->profilesF, line);

			commaPos = line.find(',');

			name = line.substr(0, commaPos);
			points = std::stoi(line.substr(commaPos+1));

			this->addProfile(name, points);
		}

	}

	void addProfile(std::string n, int p) {
		ProfileNode* tempArr = new ProfileNode[this->arrCount + 1]();


		for (int i = 0; i < this->arrCount; i++) {
			tempArr[i + 1].setName(this->proArr[i].getName());			//First element in tempArr will be empty for the new profile
			tempArr[i + 1].setPoints(this->proArr[i].getPoints());
		}

		tempArr[0].setName(n);
		tempArr[0].setPoints(p);
		this->arrCount++;
		delete[] this->proArr;
		this->proArr = tempArr;
	}

	bool checkProfile(std::string n) {
		for (int i = 0; i < this->arrCount; i++) {
			if (n == this->proArr[i].getName()) {
				return false;
			}
		}

		return true;
	}


	int updatePoints(std::string n, int newPoints) {
		for (int i = 0; i < this->arrCount; i++) {
			if (n == this->proArr[i].getName()) {
				this->proArr[i].incrementPoints(newPoints);
				return this->proArr[i].getPoints();
			}
		}
		return -1;
	}

private:
	std::fstream profilesF;
	ProfileNode* proArr;
	int arrCount;
};