#include<iostream>
using namespace std;
/*
��ŵ������
ʹ�õݹ�
��һ��ֵ��ǰһ����2����һ
*/

int hanoi(int x) {
	if (x == 1)return 1;
	return 2*(hanoi(x-1))+1;
}
int main(){
	int input_x;
	cout << "������x:        ";
	cin >> input_x;
	cout << hanoi(input_x) << endl;

}