#include<iostream>
#include<vector>
using namespace std;
/*
Ï£¶ûÅÅĞò
*/

void shell_sort(vector<int>& arr,bool ascending) {
	int h = arr.size() / 2;
	while (h >= 1) {
		for (int i = h; i < arr.size(); i++) {
			for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) {
				swap(arr[j], arr[j - h]);
			}
		}
		h = h / 2;
	}
	if (ascending == 0)reverse(arr.begin(), arr.end());
}

int main(){
	vector<int> nums;
	int input_x,flag;
	cout << "ÇëÊäÈëÊı×é:        ";
	while (1) {
		cin >> input_x;
		nums.push_back(input_x);
		if (cin.get() == '\n')
			break;
	}
	cout << "ÊÇ·ñÉıĞò:    ";
	cin >> flag;
	shell_sort(nums,flag);
	for (const auto c : nums) cout << c <<endl;
}