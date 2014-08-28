#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"head.h"

//config message
 int columnNum;
 int keydis;
 char tablename[MAX_LENGHT];
 char columnName[MAX_COLUMN][MAX_LENGHT];
 int keytype[MAX_COLUMN];  //0 for int£¬2 double  3   char
 int indexdis;

//data message
int datanum;
char dbname[]={"D:\\simpleDb\\"};
 record arr[32];


void Initialize(){

	//columnNum=2;
	//keydis=0;
	//strcpy(tablename,"testSaveRecordFile");
	//for(int i=0;i<columnNum;i++) strcpy(columnName[i],"teacher");
	//for (int i=0;i<columnNum;i++) keytype[i]=i;
	//indexdis=0;

	//test InsertOneData
	clearOldData();
	strcpy(tablename,"testSaveRecordFile");
	for(int i=0;i<3;i++)
	{
		arr[i].dis=2;
		arr[i].v2='a';
	}
}

void clearOldData(){

	columnNum=-1;
	keydis=-1;
	strcpy(tablename,"\0");
	for(int i=0;i<columnNum;i++) strcpy(columnName[i],"\0");
	for (int i=0;i<columnNum;i++) keytype[i]=-1;
	indexdis=-1;
	for(int i=0;i<MAX_COLUMN;i++) {
		arr[i].dis=-1; 
		arr[i].v0=-1;
		arr[i].v1=-1;
		arr[i].v2='\0';
	}
	datanum=-1;
}

void analyzeSqlStatement(){

}






/*  in order to test the function "bool saveCatalogMessage()"
void testSave(){
	FILE * f;
	char path[100];
	strcpy(path,dbname);
	strcat(path,tablename);
	strcat(path,"_config.dat");
		if((f=fopen(path,"rb+"))==NULL)	
	{
		printf("failed");
	}
	char tb[32];
	int cn;
	int kd;
	int kt[32];
	char cname[32][32];
	fread(& tb,sizeof(char[32]),1,f);
	fread(&cn,sizeof(int),1,f);
	fread(&kd,sizeof(int),1,f);
	for (int i=0;i<columnNum;i++)
	{
		fread(cname[i],sizeof(char[MAX_LENGHT]),1,f);
	}
	for (int i=0;i<columnNum;i++)
		fread(&kt[i],sizeof(int),1,f);
	fclose(f);
	printf("tablename: %s\n",tb);
    printf("columnnum : %d\n",cn);
	printf("keydis : %d\n",kd);
	for (int i=0;i<cn;i++) printf("keytype %d\n",kt[i]);
	for (int i=0;i<cn;i++) printf("columnname : %s\n",cname[i]);
}
*/
void main()
{
	Initialize();

}