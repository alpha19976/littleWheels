#include<stdio.h>
#include<stdlib.h>

int main()
{
    int array[15]={0},i,length=1,longest=0;
    
    printf("�������������룺\n"); 
    scanf("%d",&array[0]);
    
    for(i=1;i<=14;i++)
    {
                       scanf("%d",&array[i]);
                       
                       if(array[i]!=array[i-1]||i==14)
                       {
                            if(i==14)
                            length++;
                            
                            if(longest<length)
                               longest=length;
                               length=1;
                       }     
                       else{
                                               length++;
                       }
                       
    }
    printf("ƽ̨�ĳ���Ϊ��%d",longest);
    
    system("pause");
    return 0;
} 
                                               
                      
                       
