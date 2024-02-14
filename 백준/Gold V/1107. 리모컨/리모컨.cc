#include <iostream>
#include <algorithm>
#include <cmath>
bool enablenum[10];

int Tennel(int n) {
	if (n == 0) {
		if (enablenum[0])
			return 0;
		else
			return 1;
	}
	int times = 0;
	while (n > 0) {
		if (enablenum[n % 10])
			return 0;
		n = n / 10;
		times++;
	}
	return times;
}

int main() {
	int N, M, chan;
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> chan;
		enablenum[chan] = true;
	}
	int channelshiftnum = std::abs(N - 100);
	for (int startchannelnum = 0; startchannelnum <= 1000000; startchannelnum++) {
		int tp = Tennel(startchannelnum);
		if (tp == 0)
			continue;
		tp = tp + std::abs(startchannelnum - N);
		channelshiftnum = std::min(channelshiftnum, tp);
	}
	std::cout << channelshiftnum;
	return 0;
}