#pragma once

class Node {
public:

	Node(std::string n, std::string d) {
		this->name = n;
		this->description = d;
		this->next = nullptr;
	}

	Node() {
		this->name = "";
		this->description = "";
		this->next = nullptr;
	}



	Node* getNext() {
		return this->next;
	}

	std::string getName() {
		return this->name;
	}

	std::string getDescript() {
		return this->description;
	}

	void setNext(Node* nex) {
		this->next = nex;
	}

private:
	std::string name;
	std::string description;
	Node* next;
};