//最大子序列和

//解法一：从头开始计算和

int FindGreatestSumOfSubArray(int* pData, int nLength)
{
	if((pData==NULL) || (nLength<=0))
	{	g_InvalidInput=true;
		return 0;
	}
	
	g_InvalidInput=false;
	
	int nCurSum=0;
	int nGreatestSum=0x80000000;
	
	for(int i=0;i<nLength;++i)
	{
		if(nCurSum<=0)
			nCurSum=pData[i];
		else
			nCurSum+=pData[i];
		
		if(nCurSum>nGreatestSum)
			nGreatestSum=nCurSum;
	}
	
	return nGreatestSum;
}

//动态规划法
//f(i)=pData[i]  i=0或者f(i-1)<=0
//f(i)=f(i-1)+pData[i]  i!=0并且f(i-1)>0
