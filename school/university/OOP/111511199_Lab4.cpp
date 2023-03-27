#include <iostream>
#include <fstream>

using namespace std;

int query (int a, int b, int *pre_sum, int size) {
	if (a <= b) return pre_sum[b]-pre_sum[a-1];
	return pre_sum[size] - pre_sum[a-1] + pre_sum[b];
}

int main(int argc, char *argv[]) {
	ifstream input;
	input.open (argv[1]);

	int size, op;
	input >> size >> op;

	int *arr = new int[size+1];
	int *pre_sum = new int[size+1];

	pre_sum[0] = 0;
	for (int i = 1; i <= size; i++) {
		input >> arr[i];
		pre_sum[i] = pre_sum[i-1] + arr[i];
	}

	int mx_a, mx_b, mx_sum = -1;
	for (int i = 0; i < op; i++) {
		int a, b, temp;
		input >> a >> b;
		temp = query (a, b, pre_sum, size);
		if (temp > mx_sum) {
			mx_a = a, mx_b = b;
			mx_sum = temp;
		}
	}
	
	cout << "Max_range: (" << mx_a << "," << mx_b << "); Value: " << mx_sum << '\n';

	return 0;
}
