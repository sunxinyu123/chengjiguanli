#include <iostream>  
#include <fstream>  
#include <string>  
#include <stdio.h>

using namespace std;  

struct fenshu
{
	int zhengzhi;
	int yingyu;
	int shuxue;
	int zyeke;
};

struct student  
{  
    char name[10];  
    fenshu chengji;
	int zhongfen;
	int paiming;
}stu[150]; 
int duqu()  
{  
    int i = 0, stuNum = 0;  
  
    ifstream infile("xscj.txt",ios::in);   
    while(!infile.eof())  
    {  
		infile >> stu[i].name >> stu[i].chengji.zhengzhi >> stu[i].chengji.yingyu >> stu[i].chengji.shuxue >> stu[i].chengji.zyeke >> stu[i].zhongfen;  
        i++;  
        stuNum++;  
    }  
    infile.close(); //�ر��ļ�  
	printf("ѧ���ɼ���ȡ�ɹ�\n\n");
    return stuNum;
   
}

void zz(int z)
{
	int i;
	student x;
	for(i=0;i<z-1;i++)
	{
		if(stu[i].zhongfen==stu[i+1].zhongfen)
		{
			if(stu[i].chengji.zhengzhi<stu[i+1].chengji.zhengzhi)
			{
				x=stu[i];
				stu[i]=stu[i+1];
				stu[i+1]=x;
			}
		}
	}
}

void yy(int z)
{
	int i;
	student x;
	for(i=0;i<z-1;i++)
	{
		if(stu[i].zhongfen==stu[i+1].zhongfen)
		{
			if(stu[i].chengji.yingyu<stu[i+1].chengji.yingyu)
			{
				x=stu[i];
				stu[i]=stu[i+1];
				stu[i+1]=x;
			}
		}
	}
}

void sx(int z)
{
	int i;
	student x;
	for(i=0;i<z-1;i++)
	{
		if(stu[i].zhongfen==stu[i+1].zhongfen)
		{
			if(stu[i].chengji.shuxue<stu[i+1].chengji.shuxue)
			{
				x=stu[i];
				stu[i]=stu[i+1];
				stu[i+1]=x;
			}
		}
	}
}

void zyk(int z)
{
	int i;
	student x;
	for(i=0;i<z-1;i++)
	{
		if(stu[i].zhongfen==stu[i+1].zhongfen)
		{
			if(stu[i].chengji.zyeke<stu[i+1].chengji.zyeke)
			{
				x=stu[i];
				stu[i]=stu[i+1];
				stu[i+1]=x;
			}
		}
	}
}

void paixu(int n)
{
	int i,j,y;
	student x;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(stu[j].zhongfen<stu[j+1].zhongfen)
			{
				x=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=x;
			}
		}
	}
	cout<<"������ĳ�ſγɼ������Ż�¼ȡ"<<"\n\n"<<"1.����    2.Ӣ��    3.��ѧ    4.רҵ��\n"<<endl;
	cin>>y;
	switch(y)
	{
		case 1:zz(n); break;
		case 2:yy(n); break;
		case 3:sx(n); break;
		case 4:zyk(n);break;
	}
	cout<<"\n"<<"�ɼ��Ѱ�Ҫ���������\n"<<endl;
}

void print(int m)
{
	int i=0;
	cout << "����" << "\t" << "����" << "\t" << "Ӣ��"<< "\t" << "��ѧ"<< "\t" << "רҵ��" << "\t" << "�ܷ�"<< "\t" << "����" << endl;  
    for(i = 0; i < m; i++)  
    {  
        cout << stu[i].name << "\t" << stu[i].chengji.zhengzhi << "\t" << stu[i].chengji.yingyu << "\t" << stu[i].chengji.shuxue << "\t" << stu[i].chengji.zyeke << "\t" << stu[i].zhongfen << "\t" << i+1 << endl;  
    }  
}

int menu()  // ����
{
	int num;
	printf("                   ѧ����Ϣ����ϵͳ                     \n");
	printf("                                                        \n");
	printf("*********************ϵͳ���ܲ˵�*************************       \n\n");
	printf("     *               1.��ȡѧ����Ϣ               *     \n\n");
	printf("     *               2.¼ȡ��������               *     \n\n");
	printf("     *               3.�ɼ����                   *     \n\n");
	printf("     *               4.�˳�ϵͳ                   *     \n\n");
	printf("��ѡ��˵����:");
	cin>>num;
	cout<<endl;
	return num;
}
int main()
{
	int a=0,b=0;
	while(1)
	{
		a=menu();
		if(a==4)
			break;
		switch (a)
		{
			case 1:b=duqu(); break;
			case 2:paixu(b); break;
			case 3:print(b); break;
		}
	}
	system("pause");
	return 0;
}