#include<iostream>
#include<vector>
using namespace std;
/*
≤Â»Î≈≈–Ú
*/

void insertion_sort(vector<int>& arr,bool ascending) {
	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (key < arr[j])) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	if (ascending == 0)reverse(arr.begin(), arr.end());
}

int main(){
	vector<int> nums;
	int input_x,flag;
	cout << "«Î ‰»Î ˝◊È:        ";
	while (1) {
		cin >> input_x;
		nums.push_back(input_x);
		if (cin.get() == '\n')
			break;
	}
	cout << " «∑Ò…˝–Ú:    ";
	cin >> flag;
	selection_sort(nums,flag);
	for (const auto c : nums) cout << c <<endl;
}