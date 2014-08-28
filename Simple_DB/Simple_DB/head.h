
const int MAX_LENGHT=32;
const int MAX_COLUMN=32;

typedef int typekey; 
//config message
extern int columnNum;
extern int keydis;
extern char tablename[MAX_LENGHT];
extern char columnName[MAX_COLUMN][MAX_LENGHT];
extern int keytype[MAX_COLUMN];  //0 for int£¬2 double  3   char
extern int indexdis;

//data message
extern int datanum;
extern char dbname[];

typedef struct node{
	int dis;
	int v0;
	double v1;
	char v2;
} record;

extern record arr[32];

//-------------Interpreter.cpp-------------//
void clearOldData();
void analyzeSqlStatement();

//-------------RecordManager.cpp---------//
bool BuildRecordFile();
bool appendDataIntoFile();
int getOffSet(int num);

//-------------API.cpp----------------------//
bool InsertSQL();
bool deleteSQL();
bool searchSQL();
bool createIndexSQL();

//-------------IndexManager.cpp---------//
void InsertIntoBTree(typekey key,int offset);

