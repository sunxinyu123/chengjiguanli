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
    infile.close(); //关闭文件  
	printf("学生成绩读取成功\n\n");
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
	cout<<"请输入某门课成绩高者优化录取"<<"\n\n"<<"1.政治    2.英语    3.数学    4.专业课\n"<<endl;
	cin>>y;
	switch(y)
	{
		case 1:zz(n); break;
		case 2:yy(n); break;
		case 3:sx(n); break;
		case 4:zyk(n);break;
	}
	cout<<"\n"<<"成绩已按要求排序完成\n"<<endl;
}

void print(int m)
{
	int i=0;
	cout << "姓名" << "\t" << "政治" << "\t" << "英语"<< "\t" << "数学"<< "\t" << "专业课" << "\t" << "总分"<< "\t" << "排名" << endl;  
    for(i = 0; i < m; i++)  
    {  
        cout << stu[i].name << "\t" << stu[i].chengji.zhengzhi << "\t" << stu[i].chengji.yingyu << "\t" << stu[i].chengji.shuxue << "\t" << stu[i].chengji.zyeke << "\t" << stu[i].zhongfen << "\t" << i+1 << endl;  
    }  
}

int menu()  // 界面
{
	int num;
	printf("                   学生信息管理系统                     \n");
	printf("                                                        \n");
	printf("*********************系统功能菜单*************************       \n\n");
	printf("     *               1.读取学生信息               *     \n\n");
	printf("     *               2.录取规则配置               *     \n\n");
	printf("     *               3.成绩输出                   *     \n\n");
	printf("     *               4.退出系统                   *     \n\n");
	printf("请选择菜单编号:");
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