/*������*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void matchNumber(int, int);
void start(void);//����ԭ��

main()
{
    printf("Here is a number between 1 and 1000.\n");
    printf("Can you guss my number?\n");
    
    start();//���ÿ�ʼ����
}

/*���������*/
void start(void)
{   
	int num,count;//�����,����

	srand(time(NULL));//���������

	num=rand()%1000 + 1;//�޶���Χ
    
    printf("Please type your first guss.\n");

	count=1;

    matchNumber(num,count);//�����жϺ���
	
}

/*�ж��Ƿ�match*/
void matchNumber(int num,int count)
{
	int guss_num;
	char ch;

    scanf("%d",&guss_num);
        
	    //�¶�
		if(guss_num==num)
		{
			if(count<10)     //����10��
			{
				printf("Excellent!You guss it! \n ");
				printf("Either you know the secret or you got lucky!\n");

            }
			else
			{
				if(count==10)//10��
				{
					printf("Ahah!You know the secret!\n");
					printf("You guss the number!\n");
				}
				else        //����10��
				{
					printf("You guss the number!\n");
					printf("You should be able to do better.\n");
				}
			}
			    //���¿�ʼ��Ϸ��
                printf("Do you want to try again?(y/n)");

				getchar();//�жϺ���
				scanf("%c",&ch);
				
                if(ch=='y')
				{
                   start();//�ص�start()
				}
				
		}
		//�´�
		else
		{
			if(guss_num<num)//ƫС
			{
				printf("Too low .Try again.\n");
				
				
			}
			else            //ƫ��
			{
				printf("Too high .Try again.\n");
			}
			
			count=count++;//�ƴ���
			num=num;

			matchNumber(num,count);//����match�ٲ�һ��
			
			
			
		}
		
	
}

