//翻转单词顺序&左旋转字符串
void Reverse(char* pBegin, char* pEnd)
{
	if(pBegin==NULL || pEnd==NULL)
		return;
	
	while(pBegin!=pEnd)
	{
		char temp=*pEnd;
		*pEnd=*pBegin;
		*pBegin=temp;
		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if(pData==NULL)
		return NULL;
	
	char* pBegin=pData;
	char* pEnd=pData;
	while(*pData!='\0')
		pEnd++;
	pEnd--;
	
	Reverse(pBegin,pEnd);
	
	pBegin=pEnd=pData;
	while(pBegin!='\0')
	{
		if(*pBegin==' ')
		{
			pBegin++;
			pEnd++;
		}
		else if(*pEnd==' ' || *pEnd=='\0')
		{
			Reverse(pBegin,--pEnd);
			pBegin=++pEnd;
		}
		else
			pEnd++;
	}
	return pData;
}

//左旋转字符串
char* LeftRotateString(char* pStr, int n)
{
	if(pStr!=NULL)
	{
		int nLength=static_cast<int>(strlen(pStr));
		if(nLength>0 && n>0 && n<nLength)
		{
			char* pFirstStart=pStr;
			char* pFirstEnd=pStr+n-1;
			char* pSencondStart=pStr+n;
			char* pSecondEnd=pStr+nLength-1;
			
			Reverse(pFirstStart,pFirstEnd);
			Reverse(pSencondStart,pSecondEnd);
			Reverse(pFirstStart,pSecondEnd);
		}
	}
	return pStr;
}

