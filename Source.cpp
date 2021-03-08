#include <vector>
#include <fstream>
#include <iostream>
#include <string>

int countTreesHit(int moveRight, int moveDown) {
	std::vector <std::vector<char>> all_rows;
	std::ifstream fileContents("input.txt");
	std::string rowString;
	while (std::getline(fileContents, rowString)) {
		std::vector<char> row(rowString.begin(), rowString.end());
		all_rows.push_back(row);
	}
	auto numberOfRows = all_rows.size();
	auto requiredCharWidth = (numberOfRows * moveRight) + 1;
	auto rowWidth = all_rows[0].size();
	auto numberOfTimesToRepeatRows = requiredCharWidth / rowWidth;
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
	for (int y = 0; y < all_rows.size(); y+=moveDown) {
		auto characterAtPosition = all_rows[y][x];
		if (characterAtPosition == openSquare) {
			all_rows[y][x] = treeMiss;
		}
		else if (characterAtPosition == tree) {
			all_rows[y][x] = treeHit;
		}
		x += moveRight;
	}
	auto treeHitCount = 0;
	auto rowsChecked = 0;
	auto charactersChecked = 0;
	for (int r = 0; r < all_rows.size(); r++) {
		for (int c = 0; c < requiredCharWidth; c++) {
			if (all_rows[r][c] == treeHit) {
				treeHitCount = treeHitCount + 1;
			}
			charactersChecked++;
		}
		rowsChecked++;
	}
	return treeHitCount;
}

void part_1() {
	auto part1hitcount = countTreesHit(3, 1);
	std::cout << "Part 1 hits: " << part1hitcount << "\n";
}

void part_2() {
	auto slope1count = countTreesHit(1, 1);
	auto slope2count = countTreesHit(3, 1);
	auto slope3count = countTreesHit(5, 1);
	auto slope4count = countTreesHit(7, 1);
	auto slope5count = countTreesHit(1, 2);
	auto finalAnswer = slope1count * slope2count * slope3count * slope4count * slope5count;
	std::cout << "Part 2 answer: " << finalAnswer << "\n";
}

int main() {
	part_1();
	part_2();
}