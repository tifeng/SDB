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
	//printf("读了一个long 之后：  %d\n",i);
	//rewind(f);
	//i=ftell(f);
	//printf("rewind  之后：  %d\n",i);
	fseek(f,8L,0);
	//i=ftell(f);
	//printf("对char 寻址之后：  %d\n",i);
	fread(&cc,sizeof(char),1,f);
	//i=ftell(f);
	//printf("读完char   之后：  %d\n",i);
	fseek(f,-5L,1);
	fread(&bb,sizeof(int),1,f);
	printf("%d\n",aa);
	printf("%d\n",bb);
	printf("%c\n",cc);
	//printf("SIZEOFint is %d\n",sizeof(int));


	fclose(f);
}