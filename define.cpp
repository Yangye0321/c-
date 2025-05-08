#include<iostream>
#include<fstream>
#include"statement.h"
using namespace std;
int cw_b(const char*filename,const char*filename_num)
{
	int num;
	ifstream infile1("backups_num.dat");
	infile1 >> num;
	infile1.close();
	string t;
	ifstream infile2("backups.dat");
	ofstream outfile1(filename);
	for (int i = 0; i < num; i++)
	{
		infile2 >> t;
		outfile1 << t << " ";
	}
	infile2.close();
	outfile1.close();
	ofstream outfile2(filename_num);
	outfile2 << num;
	outfile2.close();
	cout << "已恢复备份内容" << endl;
	return num;
}
void backups_file(const char* filename, int num)
{
	ifstream infile(filename);
	string t;
	ofstream outfile("backups.dat", ios::trunc | ios::out);
	ofstream outfile_num("backups_num.dat", ios::trunc | ios::out);
	outfile_num << num;
	outfile_num.close();
	for (int i = 0; i < num; i++)
	{
		infile >> t;
		outfile << t << " ";
	}
	outfile.close();
	cout << "已完成备份任务" << endl;
}
void set_file(const char* filename, int n)
{
	ofstream outfile(filename, ios::trunc);
	string a;
	if (n == 0)
	{
		cout << "已清除全部数据" << endl;
	}
	else
	{
		cout << "请输入你要存储的" << n << "个数据：" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		outfile << a << " ";
	}
	outfile.close();
}

void show_file(const char* filename, int n)
{
	string a;
	ifstream infile(filename);
	//if (!infile)
	//{
	//	cerr << "打开文件错误!" << endl;
	//}
	cout << "以下为存储的" << n << "个数：" << endl;
	for (int i = 0; i < n; i++)
	{
		infile >> a;
		cout << a << " ";
	}
	cout << endl;
	infile.close();
}

void add_file(const char* filename, int n)
{
	string a;
	ofstream outfile(filename, ios::app);
	cout << "请输入要添加的" << n << "个数：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		outfile << a << " ";
	}
	outfile.close();
}

int get_num(const char* filename)
{
	int num;
	ifstream infile("num.dat");
	if (!infile)
	{
		ifstream infile("num.dat", ios::out | ios::trunc);
		num = 0;
	}
	else
	{
		infile >> num;
		infile.close();
	}
	return num;
}

void set_num(const char* filename, int num)
{
	ofstream outfile("num.dat");
	outfile << num;
	outfile.close();
}
void function(const char* p, int num)
{
	int n;
	int choice = 1;
	while (choice)
	{
		cout << "当前共" << num << "个数据" << endl
			<< "请选择要执行的功能" << endl
			<< "1.重新写入数据\n2.添加数据\n3.读取数据\n4.备份数据\n5.恢复到备份的数据" << endl
			<< "输入0结束程序。" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入要输入的数据个数：" << endl;
			cin >> n;
			set_file(p, n);
			num = n;
			break;
		}
		case 2:
		{
			cout << "请输入要添加的数据个数：" << endl;
			cin >> n;
			add_file(p, n);
			num += n;
			break;
		}
		case 3:
		{
			if (num == 0)
			{
				cout << "当前文件无数据" << endl;
			}
			else
			{
				cout << "请输入要读取的数据个数：" << endl;
				cin >> n;
				if (n > num)
				{
					cerr << "读取数据大于总数据量，错误！" << endl;
					cerr << "请输入不大于" << num << "的数" << endl;
				}
				else
				{
					show_file(p, n);
				}
			}
			break;
		}
		case 4:
		{
			backups_file(p, num);
			break;
		}
		case 5:
		{
			num=cw_b(p, "num.dat");
			//cout << "=======功能建设中=======" << endl;
			break;
		}
		case 0:
			break;
		default:cout << "请输入0-5之间的数" << endl;
		}
		cout << endl;
	}
	cout << "程序结束，文件f1.dat中有" << num << "个数据" << endl;
	set_num("num.dat", num);
}