#include<stdio.h>
#include<stdlib.h>
void GCD(int,int);

main()
{
	int n1,n2;

	printf("����������������\n");
	scanf("%d",&n1);
	scanf("%d",&n2);

	printf("���Լ���ǣ�\n");
	
	GCD(n1,n2);

    system("pause");
    
	return 0;
}


void GCD(int x,int y)
{
	if(x%y==0)
		printf("%d\n",y);
	else
		GCD(y,x%y);
}
