/*�ַ���reverse*/ 
#include<stdio.h>
#include<stdlib.h>

 void reverse(char *);

int main()
{
      char string[100];
      
      printf("�������ַ�����\n"); 
      gets(string);
      
      printf("���ú���ַ�����\n");
      reverse(string);
      
      system("pause");
      return 0;
}

void reverse(char *str) //�ݹ��ӡ 
{
     if(str[0]=='\0')
       return;
     else
     {
         reverse(&str[1]);
         putchar(str[0]);
     } 
}  
