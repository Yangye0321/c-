#include<iostream>
#include<fstream>
#include"statement.h"
using namespace std;
int main()
{
	int num = 0;
	//cout << "������Ҫ�������ļ���������ʽΪXXX.dat��" << endl;
	const char* p = "f1.dat";
	num = get_num("num.dat");
	function(p, num);
	cin.get();
	return 0;
}