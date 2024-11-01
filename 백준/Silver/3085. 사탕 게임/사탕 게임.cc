#include <iostream>
#include <algorithm>

enum RC {
	ROW = 0, COL = 1
};
int Candychecker(int  RorC, char candyboard[50][50], int xpos, int ypos, int size) {
	int maxcandynums = 0;
	int buf_candynums = 1;
	if (RorC == RC::ROW) {
		for (int i = 0; i < size- 1; i++) {
			if (candyboard[ypos][i] == candyboard[ypos][i + 1]) {
				buf_candynums++;
				if (maxcandynums < buf_candynums)
					maxcandynums = buf_candynums;
			}	
			else
				buf_candynums = 1;
		}
	}
	else {
		for (int i = 0; i < size - 1; i++) {
			if (candyboard[i][xpos] == candyboard[i + 1][xpos]) {
				buf_candynums++;
				if (maxcandynums < buf_candynums)
					maxcandynums = buf_candynums;
			}
			else
				buf_candynums = 1;
		}
	}
	return maxcandynums;
}

int main() {
	char candybd[50][50];
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) 
		std::cin >> candybd[i];
	int maxi = 0;
	for (int i = 0; i < N; i++) {
		if (maxi == N)
			break;
		for (int j = 0; j < N; j++) {
			if (maxi == N)
				break;
			if (j < N - 1) {
				std::swap(candybd[i][j], candybd[i][j + 1]);
				maxi = std::max(maxi, Candychecker(RC::ROW, candybd, j, i, N));
				maxi = std::max(maxi, Candychecker(RC::COL, candybd, j, i, N));
				maxi = std::max(maxi, Candychecker(RC::COL, candybd, j + 1, i, N));
				std::swap(candybd[i][j], candybd[i][j + 1]);
			}
			if (i < N - 1) {
				std::swap(candybd[i][j], candybd[i + 1][j]);
				maxi = std::max(maxi, Candychecker(RC::COL, candybd, j, i, N));
				maxi = std::max(maxi, Candychecker(RC::ROW, candybd, j, i, N));
				maxi = std::max(maxi, Candychecker(RC::ROW, candybd, j, i + 1, N));
				std::swap(candybd[i][j], candybd[i + 1][j]);
			}
		}
	}
	std::cout << maxi;
	return 0;
}