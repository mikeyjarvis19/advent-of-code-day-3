#include <vector>
#include <fstream>
#include <iostream>
#include <string>

void part_1() {
	std::vector <std::vector<char>> all_rows;
	std::ifstream fileContents("input.txt");
	std::string rowString;
	while (std::getline(fileContents, rowString)) {
		std::vector<char> row(rowString.begin(), rowString.end());
		all_rows.push_back(row);
	}
	auto numberOfRows = all_rows.size();
	auto requiredCharWidth = (numberOfRows * 3) + 1;
	auto rowWidth = all_rows[0].size();
	auto numberOfTimesToRepeatRows = requiredCharWidth/ rowWidth;
	for (int i = 0; i < all_rows.size(); i++) {
		auto originalRow = all_rows[i];
		for (int j = 0; j < numberOfTimesToRepeatRows; j++) {
			for (int k = 0; k < originalRow.size(); k++) {
				all_rows[i].push_back(originalRow[k]);
			}
		}
	}
	auto x = 0;
	auto openSquare = '.';
	auto tree = '#';
	auto treeMiss = 'O';
	auto treeHit = 'X';
	for (int y = 0; y < all_rows.size(); y++) {
		auto characterAtPosition = all_rows[y][x];
		if (characterAtPosition == openSquare){
			all_rows[y][x] = treeMiss;
		}
		else if (characterAtPosition == tree) {
			all_rows[y][x] = treeHit;
		}
		x = x + 3;
	}
	auto treeHitCount = 0;
	auto rowsChecked = 0;
	auto charactersChecked = 0;
	for (int r = 0; r < all_rows.size(); r++) {
		for (int c = 0; c < requiredCharWidth; c++) {
			if (all_rows[r][c] == treeHit) {
				//std::cout << "all_rows [r][c]: " << all_rows[r][c] << " ,tree: " << tree << "\n";
				treeHitCount = treeHitCount + 1; 
			}
			charactersChecked++;
		}
		rowsChecked++;
		int h = 1;
	}
	std::cout << "Rows checked: " << rowsChecked << "\n";
	std::cout << "Characters checked: " << charactersChecked << "\n";
	std::cout << "Trees hit: " << treeHitCount << "\n";
	int i = 1;
}

int main() {
	part_1();
	//part_2();
}