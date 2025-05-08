#include<iostream>
#include<fstream>
#include"statement.h"
using namespace std;
int main()
{
	int num = 0;
	//cout << "请输入要操作的文件名：（格式为XXX.dat）" << endl;
	const char* p = "f1.dat";
	num = get_num("num.dat");
	function(p, num);
	cin.get();
	return 0;
}