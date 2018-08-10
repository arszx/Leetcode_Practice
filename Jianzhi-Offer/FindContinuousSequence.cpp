void FindContinuousSequence(int sum)
{
	if(sum<3)
		return;
	
	int small=1;
	int big=2;
	int middle=(1+sum)/2;
	int curSum=small+big;
	
	while(small<middle)
	{
		if(curSum==sum)
			PrintContinuousSequence(small,big);
		
		while(curSum>sum && small<middle)
		{
			curSum-=small;
			small++;
			
			if(curSum==sum)
				PrintContinuousSequence(small,big);
		}
		
		big++;
		curSum+=big;
	}
}

void PrintContinuousSequence(int small,int big)
{
	for(int i=small;i<=big;++i)
		printf("%d",i);
	printf("\n");
}

//核心思想是对上下界进行处理，通过前一个序列的结果来进行下一个序列的处理。
