/*��ĸ����*/
#include<stdio.h>
#include<stdlib.h>
void tongji(char [],int);
void printResult(char,int);//����ԭ�� 

int main()
{
    char str[51]; 
    int i=0;
    
    printf("�����ַ������ԡ�#����������\n");
    gets(str);
    
    while(str[i]!='#')
    {
               if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')//��ȥ��ĸ���ַ� 
               {
                 tongji(str,i);//���� 
               }
               i++;
    }
    
    printf("\n");
    system("pause");
    return 0;
}
/*��������*/        
void tongji(char str[],int i)
{
     int k=i+1,j=1;
     char ch;
     
     while(str[k]!='#')
    {
                       if(str[k]==str[i])
                       {
                                          j++;
                                          str[k]='0';
                       }
                       k++;
    }
    ch=str[i];
    printResult(ch,j);//��ӡ 
}
/*��ӡ*/ 
void printResult(char ch,int j)
{
           printf("\n%d��%c",j,ch);
} 
                        
                       
                      
               
               
                                                                           
    
     
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
