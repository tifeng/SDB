#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"
#include"btrees.h"

struct listnode{
	char tableName[MAX_LENGHT];
	char columnName[MAX_LENGHT];
	btree t;
};

static listnode BtreeList[MAX_COLUMN];


void BtreeInitialize()
{
	for(int i=0;i<MAX_COLUMN;i++)
	{
		strcpy(BtreeList[i].tableName,'\0');
		strcpy(BtreeList[i].columnName,'\0');
		BtreeList[i].t=new btnode;
	}

}
void InsertIntoBTree(typekey key,int offset)
{
	for( int i=0;i<MAX_COLUMN;i++) 
	{
		if( strcmp(BtreeList[i].tableName,'\0')==0 
			&& strcmp(BtreeList[i].columnName,'\0')==0)
		{
			printf("Error:Btree t not found!\n");
			return;
		}
		if( strcmp(BtreeList[i].tableName,tablename)==0 
			&& strcmp(BtreeList[i].columnName,columnName[indexdis])==0)
		{
			BtreeList[i].t=insert(key,offset,BtreeList[i].t);
		}
	}
}