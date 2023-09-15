#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <chrono>
#include <thread>

#include "Node.h"


using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;


template <class T, class Q>
class List {
public:

	List() {
		this->head = nullptr;
		this->tail = nullptr;

		
		this->commands.open("commands.csv");
		std::string line;

		while (!this->commands.eof()) {
			std::getline(this->commands, line);
			std::size_t commaPos = line.find(',');

			this->insertFront(line.substr(0, commaPos), line.substr(commaPos + 1, line.length() - (commaPos + 1)));
			this->nodeCount++;
		}


	}

	~List() {
		int count = 0;
		this->commands.close();
		this->commands.open("commands.csv", std::fstream::out);		//Remove data in file

		Node* temp = new Node();
		temp = this->head;
		
		while (temp != nullptr) {
			if (count != 0) {
				this->commands << "\n" << temp->getName() << "," << temp->getDescript();
			}
			else {
				this->commands << temp->getName() << "," << temp->getDescript();		//Dont add a newline if it's the first line 
			}
			count++;
			temp = temp->getNext();
		}

		//delete this;
	}


	int generateQuiz(int qAmount) {
		std::vector<Node*> chosenNode;
		bool uniqueCom = true, alreadyZero = false;

		Node* temp = new Node();
		
		int ran = 0, ran1 = 0, points = 0, choice = 0, rightAnswer = 0;
		
		for (int i = 0; i < qAmount; i++) {
			temp = this->head;
			ran = rand() % this->nodeCount;
			for (int j = 0; j < ran; j++) {
				temp = temp->getNext();
			}

			for (int k = 0; k < chosenNode.size(); k++) {
				if (temp->getName() == chosenNode.at(k)->getName()) {				
					i--;	
					uniqueCom = false;
				}
			}
			
			if (uniqueCom) {
				chosenNode.push_back(temp); 
			}

		}		//This block of code gets the (# of needed question) nodes, now we need to get two random descriptions and print them out to user


		std::vector<std::string> descriptVector;
		
		for (int i = 0; i < qAmount; i++) {
			temp = this->head;
			descriptVector.push_back(chosenNode.at(i)->getDescript());

			std::cout << "Define what the '" << chosenNode.at(i)->getName() << "' command does. Enter a number." << endl;

			for (int j = 0; j < 2; j++) {
				temp = this->head;
				ran = rand() % (this->nodeCount);
				for (int k = 0; k < ran; k++) {
					temp = temp->getNext();
				}
				descriptVector.push_back(temp->getDescript());
			}	//This for loop adds two random descriptions into descriptVector
			

			for (int k = 0; k < 3; k++) {
				ran1 = rand() % descriptVector.size();

				std::cout << k + 1 << ". " << descriptVector.at(ran1) << endl;
				if (descriptVector.at(ran1) == chosenNode.at(i)->getDescript()) {
					rightAnswer = k + 1;
				}
				descriptVector.erase(descriptVector.begin() + ran1);
			}

			std::cin >> choice;
			if (choice == rightAnswer) {
				std::cout << "Correct! You gained a point!" << endl;
				points++;
			}
			else {
				std::cout << "Incorrect! Minus one point." << endl;
				points--;
			}

			descriptVector.clear();
		}

		return points;
	}


	void addCommand() {
		std::string name, descript, finalD;


		std::cout << "Please enter your new command name." << endl;
		std::cin >> name;

		while (!checkCommand(name)) {
			std::cout << "Command name already exists. Please enter a valid command name or enter 'quit' to return to the menu." << endl;
			std::cin >> name;
			if (name == "quit") {
				return;
			}
		}

		std::cout << "Command name accepted. Please enter your new description." << endl;
		std::getline(cin, descript);
		std::getline(cin, descript);

		while (!checkCommand(descript)) {
			std::cout << "Command description already exists. Please enter a valid command descripton or 'quit' to return to the menu." << endl;
			std::getline(cin, descript);
			if (descript == "quit") {
				return;
			}
		}

		finalD = "\"" + descript + "\"";

		this->insertFront(name, finalD);
		this->nodeCount++;
		std::cout << "Command added sucessfully. Returning to menu." << endl;

	}

	void removeCommand() {
		int count = 0;
		std::string name;
		std::cout << "Please enter the name of the command you wish to remove." << endl;
		std::getline(cin, name);
		std::getline(cin, name);
	
		while (checkCommand(name)) {		//Check whether checkCommand returns true which means is a unique name in linked list and thus cant be removed
			std::cout << "Command not found. Enter a valid command name or type 'quit'." << endl;
			std::getline(cin, name);
			if (name == "quit") {
				std::cout << "Returning to menu." << endl;
				return;
			}
		}

		Node* locateNode = new Node();
		Node* prevNode = new Node();
		locateNode = this->head;
		prevNode = this->head;

		while (locateNode->getName() != name) {
			locateNode = locateNode->getNext();
			if (count != 0) {						//Lag updating the prev node by 1 so once the locateNode locates the targeted node, the prev node is one behind 
				prevNode = prevNode->getNext();
			}
			count++;
		}

		prevNode->setNext(locateNode->getNext());
		delete locateNode;

		std::cout << "Command removed sucessfully. Returning to menu." << endl;
	}

	bool checkCommand(T str) {			//Checks string against both name and descript in linked list
		Node* temp = new Node();
		temp = this->head;

		while (temp != nullptr) {
			if (str == temp->getName() || str == temp->getDescript()) {
				return false;
			}
			temp = temp->getNext();
		}

		return true;
	}

	/*
	void goThru() {
		Node* temp = new Node();
		temp = this->head;

		while (temp != nullptr) {
			std::cout << temp->getDescript() << endl;
			temp = temp->getNext();
		}

		delete temp;
	}
	*/

	void insertFront(T name, Q descript) {
		Node* temp = new Node(name, descript);

		if (this->head == nullptr) {
			this->head = temp;
			this->tail = temp;
		}
		else {
			temp->setNext(this->head);
			this->head = temp;
		}

	}

private:
	Node* head;
	Node* tail;
	int nodeCount;
	std::fstream commands;
};