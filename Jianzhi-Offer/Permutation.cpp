//字符串排列

void Permutation(char* pStr)
{
	if(pStr==NULL)
		return;
	
	Permutation(pStr,pStr);
}

void Permutation(char* pStr,char* pBegin)
{
	if(*pBegin=='\0')
	{
		printf("%s\n",pStr);
	}
	else
	{
		for(char* pCh=pBegin; *pCh!='\0';++pCh)
		{
			char temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;
			
			Permutation(pStr,Pbegin+1);
			
			temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;
		}
	}
}
