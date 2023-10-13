/*
Welcome to PA2!
Mason Menser - CPTS223
*/


#include "AVLTree.h"

int main() {
	std::vector<int> asc, dsc, random;
	for (int i = 1; i <= 100;) {
		asc.push_back(i);
		i += 2;
	}
	for (int i = 99; i >= 0;) {
		dsc.push_back(i);
		i -= 2;
	}
	random = asc;
	//auto rng = std::default_random_engine{};
	std::shuffle(random.begin(), random.end(), std::random_device());

	AVLTree<int> ascTree, dscTree, randTree;

	for (int i = 0; i < 50; i++) {
		ascTree.insert(asc[i]);
		dscTree.insert(dsc[i]);
		randTree.insert(random[i]);
	}

	std::cout << "Ascending Tree Height: " << ascTree.height() << "\nDescending Tree Height: " << dscTree.height() << "\nShuffled Tree Height: " << randTree.height() << endl << endl;

	std::cout << "Validation of ASCTree: " << ascTree.validate() << "\nValidation of DSCTree: " << dscTree.validate() << "\nValidation of SHUFFLETree: " << randTree.validate() << endl << endl;

	for (int i = 1; i < 100; i++) {
		if (i % 2 == 1 && (ascTree.contains(i) == 0 || dscTree.contains(i) == 0 || randTree.contains(i) == 0)) {		//If i is odd and still can't find value in tree
			std::cout << "My AVL implementation is wrong :(" << endl;
		}
	}
	std::cout << "AVL Tree sucessfully implemented." << endl;

	return 0;
}