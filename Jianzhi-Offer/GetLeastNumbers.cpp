//找出输入n个整数中最小的k个数

//解法一：利用快排的Partition
void GetLeastNumbers(int* input, int n,int* output, int k)
{
	if(input==NULL || n<=0)
		return;
	
	int start=0;
	int end=n-1;
	int index=Partition(input,n,start,end);
	while(index!=k-1)
	{
		if(index>k-1)
		{
			end=k-2;
			index=Partition(input,n,start,end);
		}
		else
		{
			start=k;
			index=Partition(input,n,start,end);
		}
	}
	
	for(int i=0;i<k;++i)
		output[i]=input[i];
}

//解法二：利用堆，红黑树
typedef multiset<int, greater<int>>  intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data,intSet& leastNumbers, int k)
{
	leastNumbers.clear();
	
	if(k<1 || data.size()<k)
		return;
	
	vector<int>::const_iterator iter=data.begin();
	for(;iter!=data.end();++iter)
	{
		if((leastNumbers.size())<k)
			leastNumbers.insert(*iter);
		
		else
		{
			setIterator iterGreatest=leastNumbers.begin();
			
			if(*iter<*(leastNumbers.begin()))
			{
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
	
	
	
	
}

