#include <stdio.h>
#include <stdlib.h>
#include "head.h"
void printCount(char path[]){//计算文件字符数
    FILE *fp;
    fp=fopen(path,"r");
    if(fp==NULL){//读取文件为空时，结束程序
        printf("读取文件失败\n");
        return ;
    }
    int count=0;
    char read=fgetc(fp);//打开文件后读取字符
    while(read!=EOF){
        count++;//每读取一个字符，字符数+1
        read=fgetc(fp);
        }
    printf("文件字符数为：%d \n",count);//打印数据
    fclose(fp);
    return ;
    }
void printWord(char path[]){//计算文件词汇数
    FILE *fp;
    fp=fopen(path,"r");//打开文件
    if(fp==NULL){
        printf("读取文件失败\n");
        return ;
    }
    int count=0;
    int blank=0;//balnk=1是光标位于单词中，blank=0时光标位于单词间隔处
    char read=fgetc(fp);
    while(read!=EOF){
        if((read>='a'&&read<='z')||(read>='A'&&read<='Z')||(read>='0'&&read<='9')){
            if(blank==0) count++,blank=1;//当blank0变1时，词汇数+1
        }else blank=0;
        read=fgetc(fp);
    }
    printf("文件词数为：%d \n",count);//输出数据
    fclose(fp);
    return ;
}
void printLine(char path[]){//计算行数
    FILE *fp;
    fp=fopen(path,"r");//读取文件
    if(fp==NULL){
        printf("读取文件失败\n");
        return ;
    }
    int count=1;//初始值为1
    char read=fgetc(fp);
    while(read!=EOF){
        if(read=='\n') count++;//读取到'\n'时行数+1
        read=fgetc(fp);
    }
    printf("文件行数为：%d \n",count);//输出数据
    fclose(fp);
    return ;
}
void printMore(char path[]){//计算空行、代码行、注释行数
    FILE *fp;
    fp=fopen(path,"r");
    if(fp==NULL){
        printf("读取文件失败\n");
        return ;
    }
    int ept=0,ch=0,count=0,codeline=0,noteline=0,note=0,flag=0;//ch可视符号数，count字符数,ept空行数,codeline代码行,noteline注释行;flag=0时该行无注释;note=1时表示前一个符号为'/'
    char read=fgetc(fp);
    while(1){
        if(read=='\n'||read==EOF){//判断一行的结束
            if(count==0&&ch<=1) ept++;//当字符数都是空格且有小于一个可视字符时，空行+1
            else if(count>0) codeline++;
            ch=0;count=0,note=0,flag=0;//在下一行重置变量
        }
        else if(read=='{'||read=='}') {
            if(ch==1) count++;
            ch++;
        }//一行中的可视字符数
        else if(read!=' ') count++;
        if(note==1&&read!='/') note=0;//计算注释行数,'/'非连续时重置flag为0
        if(read=='/'&&flag==0){
            if(note==0) note++;
            if(note==1) flag=1,noteline++;//'/'连续时flag为1且注释行+1
        }
        if(read==EOF) break;
        read=fgetc(fp);
    }
    printf("文件空行数为：%d \n",ept);
    printf("文件代码行数为：%d \n",codeline);
    printf("文件注释行数为：%d \n",noteline);
    fclose(fp);
    return ;
}
