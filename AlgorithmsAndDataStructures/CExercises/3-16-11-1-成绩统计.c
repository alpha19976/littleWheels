/*�ɼ�ͳ��*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct inf* Getinput();//��������ѧ����Ϣ��ŵ�����
void Getcount(int [],struct inf*);//ͳ�Ƹ�����������
void Getprint(int []);//���ͳ�ƽ��
void Getfree(struct inf*);//�ͷ�����

struct inf{
	char *name;
	int number;
	float grade;
	struct inf *nextptr;
};//���ѧ����Ϣ�ṹ
main()
{
	int shu[5]={0};//��Ÿ������ε�����
    struct inf *headptr;//�����ͷ���
	
	printf("����������ѧ����������ѧ�ţ��ɼ�:\n");
    headptr=Getinput();//��������ѧ����Ϣ��ŵ�����Ȼ����������ͷ���
	Getcount(shu,headptr);//ͳ�Ƹ�����������
	Getprint(shu);//���ͳ�ƽ��
	Getfree(headptr);//��������
}
struct inf* Getinput()//��������ѧ����Ϣ��ŵ�����Ȼ����������ͷ���
{
    int i,j,num;//ѧ��
	char str[20]={0};//��ʱ���ѧ��������
	struct inf *headptr=NULL,*countptr=NULL,*lastptr=NULL;
    float gra;//�ɼ�    
    scanf("%s",str);//��������������str��
	for (i=0;str[0]!='#';i++)//��������
	{
		
		countptr=(struct inf*)malloc(sizeof(struct inf));//Ϊÿһ����������ڴ�ռ�
		if(countptr!=NULL)
		{
			countptr->name=(char *)malloc(sizeof(strlen(str)));//Ϊ���������ڴ�ռ�
			for (j=0;j<=strlen(str)-1;j++)//������str�е����ִ���countptr->name
                (countptr->name)[j]=str[j];
			scanf("%d",&num);//����ѧ��
            countptr->number=num;
			scanf("%f",&gra);//�������
            countptr->grade=gra;  
		}
		if (headptr==NULL)
		{
			headptr=countptr;
			lastptr=countptr;
		}
		else
		{
			lastptr->nextptr=countptr;
			lastptr=countptr;
		}
        scanf("%s",str);
	}
    lastptr->nextptr=NULL;
	return headptr;
}
/*ͳ�Ƹ�����������*/
void Getcount(int shu[],struct inf*headptr)
{
	struct inf*countptr;
    countptr=headptr;
	
	while (countptr!=NULL)
	{
		if (countptr->grade<60.0)
			shu[0]++;
		else
		{
			if ((countptr->grade>=60.0)&&(countptr->grade<70.0))
				shu[1]++;
			else{
				if ((countptr->grade>=70.0)&&(countptr->grade<80.0))
                    shu[2]++;
				else{
					if ((countptr->grade>=80.0)&&(countptr->grade<90.0))
						shu[3]++;
					else
						shu[4]++;
				}
			}
		}
		countptr=countptr->nextptr;//����һ�����
	}//����ÿ�����������ķ����Σ�������Ӧ������
}
/*���ͳ�ƽ��*/
void Getprint(int shu[])
{
	int i;
	printf("%d���µ�ѧ������:%d\n",60,shu[0]);
	for (i=0;i<=2;i++)
	{
		printf("%d��%d֮�������:%d\n",60+i*10,60+(i+1)*10,shu[i+1]);
	}
	printf("%d���ϵ�����:%d\n",90,shu[4]);
}
/*�ͷ�����*/
void Getfree(struct inf*headptr)
{
    struct inf* countptr;
	while (headptr!=NULL)
	{
	    countptr=headptr;
	    headptr=headptr->nextptr;
	    free(countptr->name);//���ͷ�Ϊ����������ڴ�ռ�
        countptr->name=NULL;
	    free(countptr);//�ͷ�Ϊ���������ڴ�ռ�
	}
}
