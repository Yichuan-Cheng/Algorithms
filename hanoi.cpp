#include<iostream>
using namespace std;
/*
汉诺塔问题
使用递归
后一个值是前一个的2倍加一
*/

int hanoi(int x) {
	if (x == 1)return 1;
	return 2*(hanoi(x-1))+1;
}
int main(){
	int input_x;
	cout << "请输入x:        ";
	cin >> input_x;
	cout << hanoi(input_x) << endl;

}