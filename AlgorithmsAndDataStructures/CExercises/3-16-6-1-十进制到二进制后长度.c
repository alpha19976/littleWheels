#include<stdio.h>
#include<stdlib.h>

int f(int,int);

main()
{
	int m,n;
	int num[20]={0};//�������� 

	printf("������Ҫ���������ĸ���\n");
    
    scanf("%d",&m);

	printf("������������:\n");

	for(n=1;n<=m;n++)//���� 
	{
		scanf("%d",&num[n-1]);
	}
		
	printf("ת����ĳ�����:\n");
		
	for(n=1;n<=m;n++)//���ú�������ӡ��� 
		{
			int a=1;

			printf("%5d",f(num[n-1],a));
		}
		system("pause");
		return 0;
}


int f(int num,int i)//��λ���ĵݹ麯�� 
{
	if(num/2==0)
		return 1;
	else
		return (1+f(num/2,i++));
}
