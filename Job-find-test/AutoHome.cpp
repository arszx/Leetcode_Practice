//Count and Say

//Count and say,1,11,21,1211

class Solution
{
	private:
		string Count(string s)//计算下一个序列
		{
			string result;
			int i=0;
			int count;
			while(i<s.size())
			{
				count=1;
				char temp;
				if(s[i]==s[i+1])
				{
					while(s[i]==s[i+1])
					{
						count++;
						i++;
					}
					temp=count+'0';
					result=result+temp+s[i];
					i++;
				}
				else
				{
					temp='1';
					result=result+temp+s[i];
					i++;
				}
			}
			return result;
		}
	public:
		string CountAndSay(int n)
		{
			if(n==1)
				return "1";
			string s="1";
			while(--n)
			{
				s=Count(s);
			}
			return s;
		}
};
