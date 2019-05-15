//把数组排列成最小的数

//mn拼接时可能超出int，所以算作大数问题

const int g_MaxNumberLength=10;

char* g_StrCombine1=new char[g_MaxNumberLength * 2+1];
char* g_StrCombine2=new char[g_MaxNumberLength * 2+1];

void PrintMinNumber(int* numbers, int length)
{
	if(numbers==NULL || length<=0)
		return;
	
	char** strNumbers=(char**)(new int[length]);
	for(int i=0;i<length;++i)
	{
		strNumbers[i]=new char[g_MaxNumberLength+1];
		sprintf(strNumbers[i],"%d",numbers[i]);
	}
	
	qsort(strNumbers,length,sizeof(char*),compare);
	
	for(int i=0;i<length;++i)
		printf("%s",strNumbers[i]);
	printf("\n");
	
	for(int i=0;i<length;++i)
		delete[] strNumbers[i];
	delete[] strNumbers;
}

int compare(const void* strNumber1,const void* strNumber2)
{
	strcpy(g_StrCombine1,*(const char**)strNumber1);
	strcat(g_StrCombine1,*(const char**)strNumber2);
	
	strcpy(g_StrCombine2,*(const char**)strNumber2);
	strcat(g_StrCombine2,*(const char**)strNumber1);
	
	return strcmp(g_StrCombine1,g_strCombine2);
}