#include<iostream>
#include<vector>
using namespace std;
/*
计数排序
*/

void counting_sort(vector<int>& arr) {
	int max_val = arr[0], min_val = arr[0];
	for (const auto& i : arr) {
		if (i > max_val)max_val = i;
		if (i < min_val)min_val = i;
	}
	vector<int>counter;
	for (int i = 0; i < max_val - min_val+1; i++) {
		counter.push_back(0);
	}
	for (const auto& i : arr) {
		counter[i - min_val]++;
	}
	arr.clear();
	for (int i = 0; i < max_val - min_val + 1; i++) {
		int tmp = counter[i];
		while (tmp > 0) {
			arr.push_back(i+min_val);
			tmp--;
		}
	}

}

int main(){
	vector<int> nums;
	int input_x,flag;
	cout << "请输入数组:        ";
	while (1) {
		cin >> input_x;
		nums.push_back(input_x);
		if (cin.get() == '\n')
			break;
	}
	cout << "是否升序:    ";
	cin >> flag;
	counting_sort(nums);
    if (flag == 0) reverse(nums.begin(), nums.end());
	for (const auto c : nums) cout << c <<endl;
}