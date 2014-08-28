#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"head.h"

bool BuildRecordFile(){
	FILE * f;
	char path[100];
	strcpy(path,dbname);
	strcat(path,tablename);
	strcat(path,"_record.dat");
	if((f=fopen(path,"wb+"))==NULL)	
	{
		printf("open file failed");
		return 0;
	}
	datanum=0;
	fwrite(&datanum,sizeof(int),1,f);
	fclose(f);
	return 1;
}

bool appendDataIntoFile(){
	FILE * f;
	char path[100];
	strcpy(path,dbname);
	strcat(path,tablename);
	strcat(path,"_record.dat");
	if((f=fopen(path,"r+"))==NULL)	
	{
		printf("open file failed");
		return 0;
	}
	fread(&datanum,sizeof(int),1,f);
	printf("datanum: %d\n",&datanum);
	rewind(f);
	fwrite(&(++datanum),sizeof(int),1,f);
	fclose(f);
	f=fopen(path,"a");
	for(int i=0;i<MAX_COLUMN;i++)
	{
		if(arr[i].dis==-1) break;
		switch (arr[i].dis)
		{
	     	case 0: fwrite(&arr[i].v0,sizeof(int),1,f); break;
			case 1: fwrite(&arr[i].v1,sizeof(double),1,f);break;
			case 2: fwrite(&arr[i].v2,sizeof(char),1,f);break;
		default:
			break;
		}
	}
	fclose(f);
	if(indexdis>=0) 
	{
		int key=arr[indexdis].v0;//暂时规定索引只能建立在类型为int的列上
		int offset=getOffSet(datanum);
		InsertIntoBTree(key,offset);
	}
	return 1;
}

int getOffSet(int num)
{
	int sum=sizeof(int);
	int OneData=0;
	for (int i=0;i<columnNum;i++) 
	{
		switch (keytype[i])
		{
		case 0: OneData+=sizeof(int);break;
		case 1: OneData+=sizeof(double);break;
		case 2: OneData+=sizeof(char);break;
		default:
			break;
		}
	}
	sum+=OneData*(num-1);
	return sum;
}