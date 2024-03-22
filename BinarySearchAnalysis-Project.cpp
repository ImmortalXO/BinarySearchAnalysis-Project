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
	int N = 1000000;
	double SumRBS = 0.0;
	double SumIBS = 0.0;
	double SumSeqS = 0.0;
	
	for (int count = 0; count < 10; ++count) {
		vector<int> nums;
		mt19937 rng(random_device{}());
		uniform_int_distribution<int> distribution(1, 100);

		for (int i = 0; i < N; ++i) {
			nums.push_back(distribution(rng));
		}

		sort(nums.begin(), nums.end());

		int target = distribution(rng);

		// Recursive Binary Search Time
		auto start_time_rbs = chrono::high_resolution_clock::now();
		int rec_search = recursiveBinarySearch(nums, target, 0, nums.size() - 1);
		auto end_time_rbs = chrono::high_resolution_clock::now();
		auto duration_rbs = chrono::duration_cast<chrono::microseconds>(end_time_rbs - start_time_rbs).count();
		SumRBS += static_cast<double>(duration_rbs);

		// Sequential Search Time
		auto start_time_seq = chrono::high_resolution_clock::now();
		int seq_search = sequentialSearch(nums, target);
		auto end_time_seq = chrono::high_resolution_clock::now();
		auto duration_seq = chrono::duration_cast<chrono::microseconds>(end_time_seq - start_time_seq).count();
		SumSeqS += static_cast<double>(duration_seq);

		// Iterative Binary Search Time
		auto start_time_ibs = chrono::high_resolution_clock::now();
		int it_search = iterativeBinarySearch(nums, target);
		auto end_time_ibs = chrono::high_resolution_clock::now();
		auto duration_ibs = chrono::duration_cast<chrono::microseconds>(end_time_ibs - start_time_ibs).count();
		SumIBS += static_cast<double>(duration_ibs);
	}

	cout << "Average Running Time for Recursive Binary Search in microseconds is: " << SumRBS/10 << endl;
	cout << "Average Running Time for Iterative Binary Search in microseconds is: " << SumIBS/10 << endl;
	cout << "Average Running Time for Sequential Search in microseconds is: " << SumSeqS/10 << endl;

	return 0;
}