#include<iostream>
#include<vector>
using namespace std;
/*
√∞≈›≈≈–Ú
*/

void bubble_sort(vector<int>& nums,bool ascending) {
	for (int i = 0; i < nums.size()-1; i++) {
		for (int j = 0; j < nums.size() - 1 - i; j++) {
			if (nums[j] < nums[j + 1]) {
				int tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j + 1] = tmp;
			}
		}
	}
	if (ascending == 1)reverse(nums.begin(),nums.end());
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
	bubble_sort(nums,flag);
	for (const auto c : nums) cout << c <<endl;
}