#include<iostream>
#include<vector>
using namespace std;
/*
ѡ������
*/

void selection_sort(vector<int>& arr,bool ascending) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] < arr[min])
				min = j;
		swap(arr[i], arr[min]);
	}
	if (ascending == 0)reverse(arr.begin(), arr.end());
}

int main(){
	vector<int> nums;
	int input_x,flag;
	cout << "����������:        ";
	while (1) {
		cin >> input_x;
		nums.push_back(input_x);
		if (cin.get() == '\n')
			break;
	}
	cout << "�Ƿ�����:    ";
	cin >> flag;
	selection_sort(nums,flag);
	for (const auto c : nums) cout << c <<endl;
}