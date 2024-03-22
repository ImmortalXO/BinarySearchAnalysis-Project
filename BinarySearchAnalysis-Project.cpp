#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int recursiveBinarySearch(const vector<int>& arr, int targ, int low, int high) {
	if (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == targ) {
			return mid;
		}
		else if (arr[mid] < targ) {
			return recursiveBinarySearch(arr, targ, mid + 1, high);
		}
		else {
			return recursiveBinarySearch(arr, targ, low, mid - 1);
		}
	}
	else {
		return -1;
	}
}

int iterativeBinarySearch(const vector<int>& arr, int targ) {
	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == targ) {
			return mid;
		}
		else if (arr[mid] < targ) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int sequentialSearch(vector<int>& arr, int targ) {
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == targ) {
			return i;
		}
	}
	return -1;
}

int main() {
	int N = 5000;
	int SumRBS = 0;
	int SumIBS = 0;
	int SumSeqS = 0;

	int count = 0;
	while (count < 10) {

		vector<int> nums;

		mt19937 rng(random_device{}());

		uniform_int_distribution<int> distribution(1, 100);

		for (int i = 0; i < 10; ++i) {
			nums.push_back(distribution(rng));
		}

		sort(nums.begin(), nums.end());

		int target = distribution(rng);

		auto start_time = chrono::high_resolution_clock::now();

		auto end_time = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

		int result = recursiveBinarySearch(nums, target, 0, nums.size() - 1);

		cout << "Execution time: " << duration << endl;

		count++;
	}

	return 0;
}