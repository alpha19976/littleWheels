/*�����ֽ�*/ 
#include<stdio.h>
#include<stdlib.h>

void divide(int,int,int);//����ԭ�� 

int main()
{
	int n1,n2,m;
	/*���뷶Χ*/ 
	printf("�����뷶Χ(from,to)\n:");
	scanf("%d",&n1);
	scanf("%d",&n2);
    
    printf("�����ֽ���Ϊ��\n");
    /*���õݹ麯�������ֽ��ӡ*/ 
	for(m=n1;m<=n2;m++)
	{
		divide(m,2,0);
		printf("\n");
        
	}
    
    system("pause");
	return 0;
}

/*����*/ 
void divide(int num,int a,int i)
{
		if(num%a==0)
		{

				i++;
				if(i>1)
				{
					printf("*%d",a);//�ڶ������ϵ������� 
				}
				else
                {
			        printf("%d=%d",num,a);//��һ�������� 
				}
       
                divide(num/a,a,i);//�ݹ� 
		}
		else
		{
            if(num!=1)
            {
                        a++;
			  divide(num,a,i);//������a++��//�ݹ� 
            }
            /*else
              {
                                //printf(".");
                                //return;
              }û��*/              
		}
}



 
