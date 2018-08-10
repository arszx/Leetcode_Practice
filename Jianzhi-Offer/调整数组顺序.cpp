///////////调整数组顺序（双指针）奇偶数////////////////////
void ReorderOddEven(int * pData,unsigned int length)
{
	if(pDAta==NULL || length==0)
		return;
	
	int *pBegin=pData;
	int *pEnd=pData+length-1;
	
	while(pBegin<pEnd)
	{
		//向后移动pBegin，直到它指向偶数
		while(pBegin<pEnd && (*pBegin &0x1)!=0)
			pBegin++;
		
		//向前移动pEnd,直到它指向奇数
		while(pBegin<pEnd && (pEnd & 0x1)==0)
			pEnd++;
		
		if(pBegin<pEnd)
		{
			int temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}

//调整数组顺序，框架
void Reorder(int *pData,unsigned int length,bool (*func)(int))
{
	if(pData==NULL || length==0)
		return;
	
	int *pBegin=pData;
	int *pEnd=pData+length-1;
	
	while(pBegin<pEnd)
	{
		while(pBegin<pEnd && !func(*pBegin))
			pBegin++;
		
		while(pBegin<pEnd && func(*pEnd))
			pEnd--;
		
		if(pBegin<pEnd)
		{
			int temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}

bool isEven(int n)
{
	return(n&1)==0;
}

void ReorderOddEven(int *pData,unsigned int length)
{
	Reorder(pData,length,isEven);
}
