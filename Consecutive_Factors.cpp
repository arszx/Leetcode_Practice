#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

int main()
{
	int N;
//	N = scanf("%d",N);
	N=120;
	
	int max_factor=sqrt(N)+1,k=0;
        std::vector<int> factor;
	
	for(int i=2;i<=max_factor;++i)
	{
		while(N%i == 0)
		{
			factor[k++]=i;
			N/=i;
		}
	}
	int l=factor.size();
	std::vector<int> consecutive_factors;
	std::vector<int> output_factors;
	for (int i=2;i<=max_factor;++i)
	{
		for(int j=0;j<l;++j)
		{
			if(i%j==0)
			{
				if(i/j==1)
				{
					consecutive_factors.push_back(i);
					break;
				}
				factor[j]=factor[l-1];
				i/=j;
				l--;
			}
			else
				break;
		}
		
		if(consecutive_factors.size()>output_factors.size())
			output_factors=consecutive_factors;
	}
	
	printf("%d\n",output_factors.size());
	for(int i=0;i<output_factors.size();++i)
	{
		printf("%d\t",output_factors[i]);
	}
}
