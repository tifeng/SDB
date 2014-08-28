#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"head.h"
bool saveCatalogMessage(){//需要输入tablename
	FILE * f;
	char path[100];
	strcpy(path,dbname);
	strcat(path,tablename);
	strcat(path,"_config.dat");
	if((f=fopen(path,"wb+"))==NULL)	
	{
		printf("open file failed");
		return 0;
	}
	fwrite(tablename,sizeof(char[MAX_LENGHT]),1,f);//写入表名
	fwrite(&columnNum,sizeof(int),1,f);//列数
	fwrite(&keydis,sizeof(int),1,f);//主键所在列数
	for(int i=0;i<columnNum;i++)//写入列名称
		fwrite(columnName[i],sizeof(char[MAX_LENGHT]),1,f);
	for(int i=0;i<columnNum;i++)//写入列的数据类型
		fwrite(&keytype[i],sizeof(int),1,f);
	fwrite(&indexdis,sizeof(int),1,f);
	fclose(f);
	BuildRecordFile();
	return 1;
}