/*ħ��--ÿ�л�ÿ�еĺͶ����*/
#include<stdio.h>
#include<stdlib.h> 

main()
{
	int n,m,i,j,si=0,sj=0;
	int a [16][16]={0};//�������� 
	
    printf("enter n(��1��15����һ����):");
	
	scanf("%d",&n);

	i=1;
	j=n/2 + 1;

	a [i][j]=1;//1�ĸ�ֵ 

	for(m=2;m<=n*n;m++)
	{
		si=i;
		sj=j;//����i,j��ֵ�������ٴ�ʹ�� 

		if(i==1&&j==n)//1��n�� 
		{
			i=2;
		}
		else
		{
			if(i==1)//1�� 
				i=n;
			else
				i--;
			if(j==n)//n�� 
				j=1;
			else
				j++;
		}
		if(a[i][j]==0)//�ж��Ƿ��ǿ�λ 
			a[i][j]=m;
		else
		{
			i=si+1;
		    j=sj;
			a[i][j]=m;
		}

	
	}
		
	for(i=1;i<=n;i++)//��ӡ 
	{   
		for(j=1;j<=n;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
		
	}
    system("pause");
    return 0;
}














































































