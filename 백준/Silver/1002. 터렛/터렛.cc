#include <iostream>
using namespace std;

int main() {
	int T;
	unsigned int dot_distance;
	unsigned int x_distance, y_distance;
	unsigned int R_distance;
	unsigned int Rm_distance;
	int turret[2][3];
	cin >> T;
	while (T--) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++)
				cin >> turret[i][j];
		}
		x_distance = (turret[0][0] - turret[1][0]) * (turret[0][0] - turret[1][0]);
		y_distance = (turret[0][1] - turret[1][1]) * (turret[0][1] - turret[1][1]);
		dot_distance = x_distance + y_distance;
		R_distance = (turret[0][2] + turret[1][2]) * (turret[0][2] + turret[1][2]);
		if (dot_distance > R_distance) {
			printf("0\n");
		}
		else if (dot_distance < R_distance) {
			Rm_distance = (turret[0][2] - turret[1][2]) * (turret[0][2] - turret[1][2]);
			if (dot_distance > 0) {
				if (Rm_distance < dot_distance)
					printf("2\n");
				else if (Rm_distance > dot_distance)
					printf("0\n");
				else
					printf("1\n");
			}
			else {
				if (turret[0][2] == turret[1][2])
					printf("-1\n");
				else
					printf("0\n");
			}
		}
		else {
			printf("1\n");
		}
	}
	return 0;
}