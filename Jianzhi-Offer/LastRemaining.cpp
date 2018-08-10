//圆圈中最后剩下的数字

int LastRemaining(unsigned int n, unsigned int m)
{
	if(n<1 || m<1)
		return -1;
	
	unsigned int i=0;
	
	list<int> number;
	for(i=0; i<n; ++i)
		number.push_back(i);
	
	list<int>::iterator current=number.begin();
	while(number.size()>1)
	{
		for(int i=1; i<m; ++i)
		{
			current++;
			if(current==number.end())
				current=number.begin();
		}
		
		list<int>::iterator next=++current;
		if(next==number.end())
			next=number.begin();
		
		--current;
		number.erase(current);
		current=next;
	}
	
	return *(current);
}
