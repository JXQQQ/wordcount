#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "wc.c"
int main()
{
    char choice,path[200];
    while(1){
        printf("===�˵�===\n���롰c���������ļ��ַ�����\n���롰w���������ļ��ʻ�����\n���롰l���������ļ�������\n���롰a���������ļ�����/������/ע��������\n\n");
        printf("\n������������еĲ���:wc.exe-");
        scanf("%c",&choice);
        switch(choice){
    case 'c':
        printf("�������ļ�·����");
        scanf("%s",&path);
        printCount(path);
        printf("�����������\n");
        break;
    case 'w':
        printf("�������ļ�·����");
        scanf("%s",&path);
        printWord(path);
        printf("�����������");
        break;
    case 'l':
        printf("�������ļ�·����");
        scanf("%s",&path);
        printLine(path);
        printf("�����������");
        break;
    case 'a':
        printf("�������ļ�·����");
        scanf("%s",&path);
        printMore(path);
        printf("�����������");
        break;
    default:break;
        }
        getch();
        system("CLS");
    }
    return 0;
}
