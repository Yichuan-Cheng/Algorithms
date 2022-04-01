#include<iostream>
#include<vector>
using namespace std;
/*
快速排序
*/
int Paritition1(vector<int>&A, int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(vector<int>& A, int low, int high) //快排母函数
{
    if (low < high) {
        int pivot = Paritition1(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}
void merge_sort(vector<int>& Array, int front,int end) {
    if (front >= end-1) return;
    int mid = (front + end) / 2;
    merge_sort(Array, front,mid);
    merge_sort(Array, mid,end);
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid);
    vector<int> RightSubArray(Array.begin() + mid, Array.begin() + end);
    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
    for (int i = front; i <end; i++) {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
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
    merge_sort(nums,0,nums.size());
    if (flag == 0) reverse(nums.begin(), nums.end());
	for (const auto c : nums) cout << c <<endl;
}