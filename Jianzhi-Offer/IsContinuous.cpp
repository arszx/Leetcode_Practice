bool IsContinuous(int* number, int length)
{
	if(number==NULL || length<1)
		return false;
	
	qsort(numbers,length,sizeof(int), compare);
	
	int numberOfZero=0;
	int numberOfGap=0;
	
	//统计数组中0的个数
	for(int i=0;i<length && number[i]==0;++i)
		++numberOfZero;
	
	//统计数组中的间隙数目
	int small=numberOfZero;
	int big=small+1;
	while(big<length)
	{
		//两个数相等，有对子，不可能是顺子
		if(number[small]==number[big])
			return false;
		
		numberOfGap +=number[big]-number[small]-1;
		small=big;
		++big;
	}
	
	return (numberOfGap>numberOfZero) ? false : true;
}

int compare(const void* arg1, const void *arg2)
{
	return *(int*)arg1-*(int*)arg2;
}
