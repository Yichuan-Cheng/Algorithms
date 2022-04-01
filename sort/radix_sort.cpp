#include<iostream>
#include<vector>
using namespace std;
/*
基数排序
*/
int maxbit(vector<int>& arr) //辅助函数，求数据的最大位数
{
    int maxData = arr[0];
    for (const auto i:arr)
    {
        if (maxData < i)
            maxData = i;
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        maxData /= 10;
        ++d;
    }
    return d;
}
void radix_sort(vector<int>& arr) //基数排序
{
    vector<vector<int>>last_arr(10, vector<int>());
    for (const auto& i : arr) {
        last_arr[i % 10].push_back(i);
    }
    vector<vector<int>>now_arr(10, vector<int>());
    int d = maxbit(arr);
    for (int i = 2; i <= d; i++){
        for (int j = 0; j < 10; j++) {
            for (const auto k : last_arr[j]) {
                int tmp = k;
                for (int ii = 1; ii < i; ii++) {
                    tmp /= 10;
                }
                now_arr[tmp % 10].push_back(k);
            }
        }
        for (int j = 0; j < 10; j++) {
            last_arr[j] = now_arr[j];
            now_arr[j].clear();
        }
    }
    arr.clear();
    for (int j = 0; j < 10; j++) {
        for (auto k : last_arr[j]) {
            arr.push_back(k);
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
    radix_sort(nums);
    if (flag == 0) reverse(nums.begin(), nums.end());
	for (const auto c : nums) cout << c <<endl;
}