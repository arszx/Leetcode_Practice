
//coding by zx，要进一步调试审核；
bool IsPopOrder(const int * pPush,const int * pPop,int nLength)
{
	
	stack<int> stackData;
	
	while(pPush!=null && pPop!=null) //问题：还有可能pPop先用完；
	{
		if(pPop->value==stackData.top())
		{
			stackData.pop();
			pPop=pPop->next;
			nLength--;
		}
			
		else
		{
			stackData.push(pPush->value);
			pPush=pPush->next;
		}	
	}
	if(nLength==0)
		return true;
	else
		return false;
}

//标准答案
bool IsPopOrder(const int * pPush,const int * pPop,int nLength)
{
	bool bPossible=false;
	
	if(pPush!=NULL && pPop!=NULL && nLength>0)
	{
		const int * pNextPush=pPush;
		const int * pNextPop=pPop;
		
		std::stack<int>stackData;
		
		while(pNextPop-pPop<nLength)
		{
			while(stackData.empty() || stackData.top()!=*pNextPop)
			{
				if(pNextPush-pPush==nLength)
					break;
				
				stackData.push(*pNextPush);
				pNextPush++;
			}
			
			if(stackData.top()!=*pNextPop)
				break;
			
			stackData.pop();
			pNextPop;
		}
		
		if(stackData.empty() && pNextPop-pPop==nLength)
			bPossible=true;
	}
	return bPossible;
}
