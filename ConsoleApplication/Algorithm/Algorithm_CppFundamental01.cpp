#include <iostream>
#include <map>

typedef void(*FuncType)(int);

void Test(int i)
{
	printf("%s %d\r\n", __FUNCTION__, i);
}

class KTest
{
public:
	void Test(int i)
	{
		printf("%s %d\r\n", __FUNCTION__, i);
	}
private:
	int m_iIntData = 0;
};

class KCompare
{
public:
	int operator()(int left_, int right_) const
	{
		return left_ < right_;
	}
};

int CompFunc(int left_, int right_)
{
	return left_ < right_;
}

auto CompFunc2(int left_, int right_) -> int
{
	return left_ < right_;
}

template<typename T>
void CompareTest(int a, int b, T predicate_)
{
	//const bool bCompResult = predicate_.operator()(a, b);
	const bool bCompResult = predicate_(a, b);
	printf("CompareTest result = %d\r\n", bCompResult);
}

int main()
{
	FuncType fp = Test;
	fp(3);

	typedef void (KTest::*MemFuncType)(int);
	MemFuncType mfp = &KTest::Test;

	KTest t;
	(t.*mfp)(9);

	CompareTest(2, 3, KCompare());
	CompareTest(2, 3, CompFunc);
	CompareTest(2, 3, CompFunc2);
	auto firstLambda = [](int a, int b)->int{return a < b; };
	CompareTest(2, 3, firstLambda);
}
