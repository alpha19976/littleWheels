/*����������Ԫ��*/

#include<stdio.h>
#include<stdio.h>
int GetWeekDay (int,int,int);//���µ�һ�����ڼ�
int GetMonthDay (int,int,int);//�����ж�����
void PrintMonthCalender (int,int);//��ӡ����
int CheckLeap (int);//�Ƿ�������


main()
{
	int year,month,startDay,days,yes_no;//�꣬�£����µ�һ�����ڼ��������ж����죬�Ƿ�������

	printf("input the year and month<YYYY-MM>:");
	scanf("%d-%d",&year,&month);
	printf("                     %d��-%d��\n",year,month);//��ӡ����YYYY-MM

    /*���ú���*/
	yes_no=CheckLeap ( year);
	startDay=GetWeekDay (year,month,yes_no);
	days=GetMonthDay (year,month,yes_no);//ֵ���ݺʹ���

	PrintMonthCalender (startDay,days);
    
    system("pause");
	return 0;
}

/*���� �Ƿ�������*/
int CheckLeap (int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)
		return 1;
	else
		return 0;
}

/*���µ�һ�����ڼ�*/
int GetWeekDay (int year,int month,int yes_no)
{
	int day,days1,days2;
	switch(month)//��switch�����������޵�����
	{
		  case 1:
			  days1=0;
			  break;
          case 2:
			  days1=31;
			  break;
		  case 3:
			  days1=59;
			  break;
		  case 4:
			  days1=90;
			  break;
		  case 5:
              days1=120;
			  break;
          case 6:
			  days1=151;
			  break;
          case 7:
			  days1=181;
			  break;
		  case 8:
			  days1=212;
			  break;
		  case 9:
			  days1=243;
			  break;
		  case 10:
              days1=273;
			  break;
          case 11:
			  days1=304;
			  break;
		  case 12:
              days1=334;
			  break;
	}
	if(yes_no==1&&month>2)//�Ƿ�������
	{
		days1=days1+1;
	}
	days2=(year-1)*365 + (year-1)/400 + (year-1)/4 - (year-1)/100 + days1 + 1; 
	day=days2%7;
	return day;
}

/*�����ж�����*/
int GetMonthDay (int year,int month,int yes_no)
{
	int days3;
	switch(month)//��switch�����������޵�����
	{
		  case 1:
			  days3=31;
			  break;
          case 2:
			  days3=28;
			  break;
		  case 3:
			  days3=31;
			  break;
		  case 4:
			  days3=30;
			  break;
		  case 5:
              days3=31;
			  break;
          case 6:
			  days3=30;
			  break;
          case 7:
			  days3=31;
			  break;
		  case 8:
			  days3=31;
			  break;
		  case 9:
			  days3=30;
			  break;
		  case 10:
              days3=31;
			  break;
          case 11:
			  days3=30;
			  break;
		  case 12:
              days3=31;
			  break;
	}
	if(yes_no==1&&month==2)//�Ƿ�������
	{
		days3=days3+1;
	}
	return days3;
}

/*��ӡ����*/
void PrintMonthCalender (int startDay,int days)
{
	int n1,n2;

    printf("Sun.    Mon.    Tue.    Wed.    Thu.    Fri.    Sat.    \n");//8λ�Ʊ�

	for(n1=1;n1<=startDay;n1++)//��ͷ��ո�
	{
		printf(" \t");
	}
	for(n2=1;n2<=days;n2++)//������
	{
		if((n2+startDay)%7==0)
		{
			printf("%d\n",n2);//�����պ���
		}
		else
		{
			printf("%d\t",n2);
		}
	}
}
/*
1��������ֵ����---�ṹ��˳��
2���Ʊ�---8λ
3��switch---�����������޵�����
4��N-Sͼ
5��ע��
6����ʽ
*/

	




	
	


