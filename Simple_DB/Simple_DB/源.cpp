#include<stdio.h>
#include<stdlib.h>
int main(){
	long a=1000L,aa;
	int b=1001,bb;
	char c='a',cc;
	int i=0;
	FILE * f;
	f=fopen("D:\\a.dat","wb+");
	fwrite(&a,sizeof(long),1,f);
	fwrite(&b,sizeof(int),1,f);
	fwrite(&c,sizeof(char),1,f);
	fclose(f);
	f=fopen("D:\\a.dat","rb");
	fread(&aa,sizeof(long),1,f);
	
	//i=ftell(f);
	//printf("����һ��long ֮��  %d\n",i);
	//rewind(f);
	//i=ftell(f);
	//printf("rewind  ֮��  %d\n",i);
	fseek(f,8L,0);
	//i=ftell(f);
	//printf("��char Ѱַ֮��  %d\n",i);
	fread(&cc,sizeof(char),1,f);
	//i=ftell(f);
	//printf("����char   ֮��  %d\n",i);
	fseek(f,-5L,1);
	fread(&bb,sizeof(int),1,f);
	printf("%d\n",aa);
	printf("%d\n",bb);
	printf("%c\n",cc);
	//printf("SIZEOFint is %d\n",sizeof(int));


	fclose(f);
}