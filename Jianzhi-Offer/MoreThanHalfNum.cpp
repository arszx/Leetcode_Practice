//找出个数大于一半的数字
//解法一：

int MoreThanHalfNum(int* numbers, int length)
{
	if(CheckInvalidArray(numbers,length))
		return 0;
	
	int middle=length>>1;
	int start=0;
	int end=length-1;
	int index=Partition(numbers,length,strat,end);
	while(index!=middle)
	{
		if(index>middle)
		{
			end=index-1;
			index=Partition(numbers,length,start,end);
		}
		else
		{
			start=index+1；
			index=Partition(numbers,length,start,end);
		}
	}
	
	int result=numbers[middle];
	if(!CheckMoreThanHalf(numbers,length,result))
		result=0;
	
	return result;
}

bool g_bInputInvalid=false;

bool CheckInvalidArray(int* numbers,int length)
{
	g_bInputInvalid=false;
	if(numbers==NULL && length<=0)
		g_bInputInvalid=true;
	
	return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers,int length,int number)
{
	int times=0;
	for(int i=0;i<length;++i)
	{
		if(numbers[i]==number)
			times++;
	}
	
	bool isMoreThanHalf=true;
	if(times*2<=length)
	{
		g_bInputInvalid=true;
		isMoreThanHalf=false;
	}
	
	return isMoreThanHalf;
}

//解法二
int MoreThanHalfNum(int* numbers,int length)
{
	if(CheckInvalidArray(numbers,length))
		return 0;
	
	int result=numbers[0];
	int times=1;
	for(int i=1;i<length;++i)
	{
		if(times==0)
		{
			result=numbers[i];
			times=1;
		}
		else if(numbers[i]==result)
			times++;
		else
			times--;
	}
	if(!CheckMoreThanHalf(numbers,length,result))
		result=0;
	return result;
}







