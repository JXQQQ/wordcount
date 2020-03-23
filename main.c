#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "wc.c"
int main()
{
    char choice,path[200];
    while(1){
        printf("===菜单===\n输入“c”：计算文件字符数；\n输入“w”，计算文件词汇数；\n输入“l”：计算文件行数；\n输入“a”：计算文件空行/代码行/注释行数；\n\n");
        printf("\n请输入您想进行的操作:wc.exe-");
        scanf("%c",&choice);
        switch(choice){
    case 'c':
        printf("请输入文件路径：");
        scanf("%s",&path);
        printCount(path);
        printf("按任意键返回\n");
        break;
    case 'w':
        printf("请输入文件路径：");
        scanf("%s",&path);
        printWord(path);
        printf("按任意键返回");
        break;
    case 'l':
        printf("请输入文件路径：");
        scanf("%s",&path);
        printLine(path);
        printf("按任意键返回");
        break;
    case 'a':
        printf("请输入文件路径：");
        scanf("%s",&path);
        printMore(path);
        printf("按任意键返回");
        break;
    default:break;
        }
        getch();
        system("CLS");
    }
    return 0;
}
