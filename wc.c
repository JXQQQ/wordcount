#include <stdio.h>
#include <stdlib.h>
#include "head.h"
void printCount(char path[]){//�����ļ��ַ���
    FILE *fp;
    fp=fopen(path,"r");
    if(fp==NULL){//��ȡ�ļ�Ϊ��ʱ����������
        printf("��ȡ�ļ�ʧ��\n");
        return ;
    }
    int count=0;
    char read=fgetc(fp);//���ļ����ȡ�ַ�
    while(read!=EOF){
        count++;//ÿ��ȡһ���ַ����ַ���+1
        read=fgetc(fp);
        }
    printf("�ļ��ַ���Ϊ��%d \n",count);//��ӡ����
    fclose(fp);
    return ;
    }
void printWord(char path[]){//�����ļ��ʻ���
    FILE *fp;
    fp=fopen(path,"r");//���ļ�
    if(fp==NULL){
        printf("��ȡ�ļ�ʧ��\n");
        return ;
    }
    int count=0;
    int blank=0;//balnk=1�ǹ��λ�ڵ����У�blank=0ʱ���λ�ڵ��ʼ����
    char read=fgetc(fp);
    while(read!=EOF){
        if((read>='a'&&read<='z')||(read>='A'&&read<='Z')||(read>='0'&&read<='9')){
            if(blank==0) count++,blank=1;//��blank0��1ʱ���ʻ���+1
        }else blank=0;
        read=fgetc(fp);
    }
    printf("�ļ�����Ϊ��%d \n",count);//�������
    fclose(fp);
    return ;
}
void printLine(char path[]){//��������
    FILE *fp;
    fp=fopen(path,"r");//��ȡ�ļ�
    if(fp==NULL){
        printf("��ȡ�ļ�ʧ��\n");
        return ;
    }
    int count=1;//��ʼֵΪ1
    char read=fgetc(fp);
    while(read!=EOF){
        if(read=='\n') count++;//��ȡ��'\n'ʱ����+1
        read=fgetc(fp);
    }
    printf("�ļ�����Ϊ��%d \n",count);//�������
    fclose(fp);
    return ;
}
void printMore(char path[]){//������С������С�ע������
    FILE *fp;
    fp=fopen(path,"r");
    if(fp==NULL){
        printf("��ȡ�ļ�ʧ��\n");
        return ;
    }
    int ept=0,ch=0,count=0,codeline=0,noteline=0,note=0,flag=0;//ch���ӷ�������count�ַ���,ept������,codeline������,notelineע����;flag=0ʱ������ע��;note=1ʱ��ʾǰһ������Ϊ'/'
    char read=fgetc(fp);
    while(1){
        if(read=='\n'||read==EOF){//�ж�һ�еĽ���
            if(count==0&&ch<=1) ept++;//���ַ������ǿո�����С��һ�������ַ�ʱ������+1
            else if(count>0) codeline++;
            ch=0;count=0,note=0,flag=0;//����һ�����ñ���
        }
        else if(read=='{'||read=='}') {
            if(ch==1) count++;
            ch++;
        }//һ���еĿ����ַ���
        else if(read!=' ') count++;
        if(note==1&&read!='/') note=0;//����ע������,'/'������ʱ����flagΪ0
        if(read=='/'&&flag==0){
            if(note==0) note++;
            if(note==1) flag=1,noteline++;//'/'����ʱflagΪ1��ע����+1
        }
        if(read==EOF) break;
        read=fgetc(fp);
    }
    printf("�ļ�������Ϊ��%d \n",ept);
    printf("�ļ���������Ϊ��%d \n",codeline);
    printf("�ļ�ע������Ϊ��%d \n",noteline);
    fclose(fp);
    return ;
}
