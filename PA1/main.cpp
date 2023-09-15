/*
Mason Menser PA1

ADVANTAGES/DISADVANTAGES LINKED LIST
One advantage of using a linked list here is the fast operation of adding a command to the front of the list. You only need to update the head node which can
be done in O(1) time. Further, it's very easy to delete and add memory in linked lists. This game requires you to be able to remove and add commands at ease,
and linked lists have dynamic sizing so it's much easier to delete/add elements in a linked list than an array.

One disadvantages of using a linked list here is the lack of random access to its elements. My method for getting multiple different random commands was more
inefficent compared to if we used an array here, because a temporary node had to be updated to the next node for each random number. Meaning if I was trying to 
get to the 17th node in the list, I had to preform 17 operations of temp = temp.next(). If we used an array here, I could simply put temp[17] and continue from there.



ADVANTAGES/DISADVANTAGES ARRAY
One disadvantage of using an array in this scenairo is the need to manually dynamically allocate new memory for each new element in the array. If we instead
used a vector, we could simply add an element each time and we wouldn't need to track the amount of elements already in the container. 

One advantage of using an array here is that we can access any element in the array with time complexity O(1). If we used a linked list instead to store
profiles, we would have to iterate through the entire list to find a profile near the end of the list. With an array, you can use the operator []
to return the reference of any element in the array.


*/
#include "List.h"
#include "Game.h"

std::chrono::milliseconds timespan(5000); 



int main(void) {
	Game game;
	List<std::string, std::string> cList;

	srand((unsigned)time(NULL));

	bool loadedP = false;
	int option = 0, loadedPoints = 0, qAmount = 0, pointsUpdate = 0;
	std::string username;

	while (option != 6) {
		loadedP = false;
		std::cout << "Please enter a number from an option.\n";
		std::cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit" << endl;

		std::cin >> option;

		switch (option) {
		case 1:
			std::cout << "To play the game you must enter a username. This username can be new (points start at 0) or can be loaded from past users (points start at current value). " << endl;
			std::cout << "From there, enter the amount of questions you want to be quizzed on. You will be given that number of questions and three options to choose from." << endl;
			std::cout << "Enter the correct answer and you will recieve a point. Wrong answer, you lose a point. You score will be updated at the end of the game. Have fun!" << endl;
			break;
		case 3:

			std::cout << "Please enter a loaded profile username." << endl;
			std::cin >> username;
			loadedPoints = game.checkProfile(username);

			while (loadedPoints == -1) {
				std::cout << "Username does not exist. Please enter again." << endl;
				std::cin >> username;
				loadedPoints = game.checkProfile(username);
			}

			std::cout << "Username: " << username << "\nPoints: " << loadedPoints << endl;
			std::cout << "Entering game" << endl;
			std::this_thread::sleep_for(timespan);
			option = 2;
			loadedP = true;
		case 2:
			if (!loadedP) {
				std::cout << "Game selected! Please enter your username." << endl;
				std::cin >> username;

				while (!game.checkProfile(username)) {
					std::cout << "Invalid username. Please enter a unique username." << endl;
					std::cin >> username;
				}
				std::cout << "Username accepted!" << endl;
				game.addProfile(username, 0);
			}
			

			std::cout << "Please enter the amount of questions you would like to be quizzed on." << endl;
			std::cin >> qAmount;

			pointsUpdate = cList.generateQuiz(qAmount);
			pointsUpdate = game.updatePoints(username, pointsUpdate);
			std::cout << "New Score: " << pointsUpdate << endl;


			break;
		case 4:
			cList.addCommand();
			break;
		case 5:
			cList.removeCommand();
			break;
		case 6:

			break;
		}
	}


	return 0;
}