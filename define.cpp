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
	cout << "�ѻָ���������" << endl;
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
	cout << "����ɱ�������" << endl;
}
void set_file(const char* filename, int n)
{
	ofstream outfile(filename, ios::trunc);
	string a;
	if (n == 0)
	{
		cout << "�����ȫ������" << endl;
	}
	else
	{
		cout << "��������Ҫ�洢��" << n << "�����ݣ�" << endl;
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
	//	cerr << "���ļ�����!" << endl;
	//}
	cout << "����Ϊ�洢��" << n << "������" << endl;
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
	cout << "������Ҫ��ӵ�" << n << "������" << endl;
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
		cout << "��ǰ��" << num << "������" << endl
			<< "��ѡ��Ҫִ�еĹ���" << endl
			<< "1.����д������\n2.�������\n3.��ȡ����\n4.��������\n5.�ָ������ݵ�����" << endl
			<< "����0��������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "������Ҫ��������ݸ�����" << endl;
			cin >> n;
			set_file(p, n);
			num = n;
			break;
		}
		case 2:
		{
			cout << "������Ҫ��ӵ����ݸ�����" << endl;
			cin >> n;
			add_file(p, n);
			num += n;
			break;
		}
		case 3:
		{
			if (num == 0)
			{
				cout << "��ǰ�ļ�������" << endl;
			}
			else
			{
				cout << "������Ҫ��ȡ�����ݸ�����" << endl;
				cin >> n;
				if (n > num)
				{
					cerr << "��ȡ���ݴ�����������������" << endl;
					cerr << "�����벻����" << num << "����" << endl;
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
			//cout << "=======���ܽ�����=======" << endl;
			break;
		}
		case 0:
			break;
		default:cout << "������0-5֮�����" << endl;
		}
		cout << endl;
	}
	cout << "����������ļ�f1.dat����" << num << "������" << endl;
	set_num("num.dat", num);
}