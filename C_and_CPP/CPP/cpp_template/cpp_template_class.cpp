#include <iostream>

using namespace std;

//템플릿 클래스

/*
class CRyrData
{
public:
	int mData = 0;
};

class CRyrDataFloat
{
public:
	float mData = 0.0f;
};

class CRyrDataDouble
{
public:
	double mData = 0.0;
};
*/

template<typename T>
class CRyuData
{
public:
	T mData;
};

int main()
{
	CRyuData<int> tRyuData;
	tRyuData.mData = 777;
	cout << tRyuData.mData << endl;

	CRyuData<float> tRyuDataFloat;
	tRyuDataFloat.mData = 777.7f;
	cout << tRyuDataFloat.mData << endl;

	CRyuData<double> tRyuDataDouble;
	tRyuDataDouble.mData = 777.9;
	cout << tRyuDataDouble.mData << endl;

	return 0;
}