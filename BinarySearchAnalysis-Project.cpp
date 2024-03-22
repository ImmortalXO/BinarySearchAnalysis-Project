#include <iostream>
#include <vector>
#include <random>

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

	vector<int> nums = { 2, 64, 32, 22, 51, 43, 88, 11, 9, 75 };

	sort(nums.begin(), nums.end());

	cout << "List of integers:" << endl;
	for (int num : nums) {
		cout << num << " ";
	}
	cout << "\n" << endl;

	int target = 64;
	int target2 = 10;

	// Recursive Binary Search
	cout << "Recursive Binary Search:" << endl;
	int result = recursiveBinarySearch(nums, target, 0, nums.size() - 1);
	cout << target << " found at index: " << result << endl;

	int result2 = recursiveBinarySearch(nums, target2, 0, nums.size() - 1);
	cout << target2 << " was not found, return value is: " << result2 << endl;

	cout << "\n" << endl;

	// Iterative Binary Search
	cout << "Iterative Binary Search:" << endl;
	int result3 = iterativeBinarySearch(nums, target);
	cout << target << " found at index: " << result3 << endl;

	int result4 = iterativeBinarySearch(nums, target2);
	cout << target2 << " was not found, return value is: " << result4 << endl;

	cout << "\n" << endl;

	// Sequential Search
	cout << "Sequential Search:" << endl;
	int result5 = sequentialSearch(nums, target);
	cout << target << " found at index: " << result5 << endl;

	int result6 = sequentialSearch(nums, target2);
	cout << target2 << " was not found, return value is: " << result6 << endl;

	cout << "\n" << endl;

	return 0;
}