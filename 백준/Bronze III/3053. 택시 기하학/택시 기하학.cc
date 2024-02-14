#include <iostream>
using namespace std;

int main() {
	double R;
	const double pi_v = 3.14159265358979323846264338327950288;
	const double texi_v = 2.0;
	cin >> R;
	printf("%.6lf\n", R * R * pi_v);
	printf("%.6lf\n", R * R * texi_v);
	return 0;
}