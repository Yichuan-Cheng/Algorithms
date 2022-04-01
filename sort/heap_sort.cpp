#include<iostream>
#include<vector>
using namespace std;
/*
∂—≈≈–Ú
*/
void max_heapify(vector<int>& arr, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { 
        if (son + 1 <= end && arr[son] < arr[son + 1]) 
            son++;
        if (arr[dad] > arr[son]) 
            return;
        else { 
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(vector<int>& arr, int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);

    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
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
    heap_sort(nums,nums.size());
    if (flag == 0) reverse(nums.begin(), nums.end());
	for (const auto c : nums) cout << c <<endl;
}