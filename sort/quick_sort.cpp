#include<iostream>
#include<vector>
using namespace std;
/*
��������
*/
int Paritition1(vector<int>& A, int low, int high) {
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

void quick_sort(vector<int>& A, int low, int high) //����ĸ����
{
    if (low < high) {
        int pivot = Paritition1(A, low, high);
        quick_sort(A, low, pivot - 1);
        quick_sort(A, pivot + 1, high);
    }
}

int main() {
    vector<int> nums;
    int input_x, flag;
    cout << "����������:        ";
    while (1) {
        cin >> input_x;
        nums.push_back(input_x);
        if (cin.get() == '\n')
            break;
    }
    cout << "�Ƿ�����:    ";
    cin >> flag;
    quick_sort(nums, 0, nums.size() - 1);
    if (flag == 0) reverse(nums.begin(), nums.end());
    for (const auto c : nums) cout << c << endl;
}