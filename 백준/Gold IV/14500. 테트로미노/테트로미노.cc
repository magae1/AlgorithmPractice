#include <iostream>

int blocksnum[500][500];
int SumofSqure(int bs[500][500], int rowlens, int collens) {
	int biggestsum = 0;
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j] + bs[i][j + 1] + bs[i + 1][j] + bs[i + 1][j + 1];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	return biggestsum;
}
int SumofMak(int bs[500][500], int rowlens, int collens) {
	int biggestsum = 0;
	for (int i = 0; i < collens - 3; i++) {
		for (int j = 0; j < rowlens; j++) {
			int sum = bs[i][j] + bs[i + 1][j] + bs[i + 2][j] + bs[i + 3][j];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens; i++) {
		for (int j = 0; j < rowlens - 3; j++) {
			int sum = bs[i][j] + bs[i][j + 1] + bs[i][j + 2] + bs[i][j + 3];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	return biggestsum;
}
int SumofL(int bs[500][500], int rowlens, int collens) {
	int biggestsum = 0;
	for (int i = 0; i < collens - 2; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j] + bs[i][j + 1] + bs[i + 1][j] + bs[i + 2][j];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 2; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j] + bs[i][j + 1] + bs[i + 1][j + 1] + bs[i + 2][j + 1];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 2; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j] + bs[i + 1][j] + bs[i + 2][j] + bs[i + 2][j + 1];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 2; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j + 1] + bs[i + 1][j + 1] + bs[i + 2][j + 1] + bs[i + 2][j];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 2; j++) {
			int sum = bs[i][j] + bs[i][j + 1] + bs[i][j + 2] + bs[i + 1][j];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 2; j++) {
			int sum = bs[i][j] + bs[i][j + 1] + bs[i][j + 2] + bs[i + 1][j + 2];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 2; j++) {
			int sum = bs[i][j] + bs[i + 1][j] + bs[i + 1][j + 1] + bs[i + 1][j + 2];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 2; j++) {
			int sum = bs[i][j + 2] + bs[i + 1][j] + bs[i + 1][j + 1] + bs[i + 1][j + 2];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	return biggestsum;
}
int SumofS(int bs[500][500], int rowlens, int collens) {
	int biggestsum = 0;
	for (int i = 0; i < collens - 2; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j] + bs[i + 1][j] + bs[i + 1][j + 1] + bs[i + 2][j + 1];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 2; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j + 1] + bs[i + 1][j + 1] + bs[i + 1][j] + bs[i + 2][j];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 2; j++) {
			int sum = bs[i][j] + bs[i][j + 1] + bs[i + 1][j + 1] + bs[i + 1][j + 2];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 2; j++) {
			int sum = bs[i + 1][j] + bs[i + 1][j + 1] + bs[i][j + 1] + bs[i][j + 2];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	return biggestsum;
}
int SumofF(int bs[500][500], int rowlens, int collens) {
	int biggestsum = 0;
	for (int i = 0; i < collens - 2; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j] + bs[i + 1][j] + bs[i + 1][j + 1] + bs[i + 2][j];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 2; i++) {
		for (int j = 0; j < rowlens - 1; j++) {
			int sum = bs[i][j + 1] + bs[i + 1][j + 1] + bs[i + 1][j] + bs[i + 2][j + 1];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 2; j++) {
			int sum = bs[i][j + 1] + bs[i + 1][j] + bs[i + 1][j + 1] + bs[i + 1][j + 2];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	for (int i = 0; i < collens - 1; i++) {
		for (int j = 0; j < rowlens - 2; j++) {
			int sum = bs[i][j] + bs[i][j + 1] + bs[i][j + 2] + bs[i + 1][j + 1];
			if (biggestsum < sum)
				biggestsum = sum;
		}
	}
	return biggestsum;
}
int main() {
		int N, M;
		std::cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				std::cin >> blocksnum[i][j];
		}
		int a[5];
		a[0] = SumofSqure(blocksnum, M, N);
		a[1] = SumofMak(blocksnum, M, N);
		a[2] = SumofL(blocksnum, M, N);
		a[3] = SumofS(blocksnum, M, N);
		a[4] = SumofF(blocksnum, M, N);

		int result = 0;
		for (int i = 0; i < 5; i++) {
			if (a[i] > result)
				result = a[i];
		}
		std::cout << result << '\n';


	return 0;
}