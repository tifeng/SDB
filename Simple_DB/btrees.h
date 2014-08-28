/* btrees.h */ 
/* 
* ƽ���·����һ����Ҫ������ 
* �� 1970 ���� R. Bayer �� E. McCreight ������ 
*/ 
#define M 1 
/* B ���Ľף����Ǹ��ڵ��м�����С��Ŀ�� 
* ��Щ�˰ѽ׶���Ϊ�Ǹ��ڵ��������������Ŀ�� 
*/ 
typedef int typekey; 
typedef struct btnode {    /* B-Tree �ڵ� */ 
    int d;    /* �ڵ��м�����Ŀ */ 
    typekey k[2*M];    /* �� */ 
    int v[2*M];    /* ֵ */ 
    struct btnode *p[2*M+1];    /* ָ��������ָ�� */ 
}  *btree; 
/* 
* ÿ�������������е����еļ���С��������� 
* ÿ�������������е����еļ������ڵ���������� 
* Ҷ�ӽڵ��е�ÿ������û�������� 
*/ 

/* �� M ���� 1 ʱҲ��Ϊ 2-3 �� 
*    +----+----+ 
*    | k0 | k1 |                     
*  +-+----+----+--- 
*  | p0 | p1 | p2 | 
*  +----+----+----+ 
*/ 
extern int btree_disp; /* ����ʱ�ҵ��ļ��ڽڵ��е�λ�� */ 
extern int InsValue; /* ��Ҫ��ļ����Ӧ��ֵ */ 

extern btree search(typekey, btree&); 
extern btree insert(typekey,int,btree&); 
extern btree delete1(typekey,btree&); 
extern int height(btree); 
extern int count(btree); 
extern double payload(btree); 
extern btree deltree(btree&); 
/* end of btrees.h */ 