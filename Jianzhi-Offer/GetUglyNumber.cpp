//方法一：暴力方法，复杂度高


bool IsUgly(int number);
int GetUglyNumber(int index);

int main(int argc, char * argv[])
{
	int ugly;
	ugly=GetUglyNumber(1500);

	printf("%d", ugly);

	system("pause");
	return 0;
	
}


int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;

	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index)
	{
		number++;

		if (IsUgly(number))
			uglyFound++;
	}

	return number;
}

bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;

	return (number == 1) ? true : false;
}

//方法二：空间换时间

int Min(int number1, int number2, int number3);
int GetUglyNumber_Solution2(int index);

int main(int argc, char * argv[])
{
	int ugly;
	ugly=GetUglyNumber_Solution2(1500);

	printf("%d", ugly);

	system("pause");
	return 0;
	
}


int GetUglyNumber_Solution2(int index)
{
	if (index <= 0)
		return 0;

	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while (nextUglyIndex < index)
	{
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			++pMultiply5;

		++nextUglyIndex;
	}

	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}
