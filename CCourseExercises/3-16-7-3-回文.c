/*�ж��Ƿ��ǻ����ַ���*/
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    int i=0,j,k=0;
    char string[20];
    
    printf("�������ַ���:\n");
    gets(string);
    /*�ַ�����ͳ��*/ 
    while(string[i]!='\0')
    {
                          i++; 
    }
    /*�ж��Ƿ�Գ�*/ 
    for(j=0;j<=(i-1)/2;j++)
    {
                           if(string[j]!=string[i-1-j])
                           {
                                                       k++;
                           }
    }
    /*��ӡ���*/ 
    if(k==0)
    {
            printf("\n�ǻ����ַ�����");
    }
    else
    {
            printf("\n���ǻ����ַ�����");
    }
         
    system("pause");
    return 0;
}
































 
