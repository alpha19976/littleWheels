/*5ѧ��4��Ŀ ƽ��*/ 
#include<stdio.h>
#include<stdlib.h>

main()
{
      int i,j;
      float total=0;
      struct student{ float a[5];};//�ṹ 
      struct student score[6];//���� 
      
      for(i=0;i<=4;i++)
      {
                       printf("\niput the score of student %d\n",i+1);
                       
                       for(j=0;j<=3;j++)//���� 
                       {
                                        scanf("%f",&score[i].a[j]);
                                        total+=score[i].a[j];
                       }
                       score[i].a[4]=total/4;//�����ƽ�� 
                       
                       total=0;
      }
      
      for(j=0;j<=4;j++)
      {
                       for(i=0;i<=4;i++)
                       {
                                        total+=score[i].a[j];
                       }
                       score[5].a[j]=total/5;//�����ƽ�� 
                       
                      total=0;
      }
      
      printf("the result is\n");
      
      printf("studentsname\tsubject1\tsubject2\tsubject3\tsubject4\tstudentEverage\n");
      
      for(i=0;i<=4;i++)
      {
                       printf("student%d\t",i+1);
                       for(j=0;j<=4;j++)
                       {
                                        printf("%f\t",score[i].a[j]);
                       }
                       printf("\n");
      }
      
      printf("subjectEverage\t",i+1);
      for(j=0;j<=4;j++)
      {
                       printf("%f\t",score[5].a[j]);
      }
      
      system("pause");
      
      return 0;                
                                        
                       
}                 

/*
1.tab���Ĺ���
2.�ṹ��β�ģ�
3.�ṹ���õ�����
*/ 



















