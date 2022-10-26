
/*
	템플릿의 특수화


*/


#include <iostream>

using namespace std;

template<typename T>
class CRyuData
{
private:
	T mData;

public:
	//매개변수 있는 생성자
	CRyuData(T tData)
		:mData(tData) //초기화 목록
	{}

	T GetData()
	{
		return mData;
	}
	void SetData(T tData)
	{
		mData = tData;
	}

	//형변환 연산자 오버로드
	operator T()
	{
		return mData;
	}
};

//char* 에 대해서, 템플릿의 특수화를 하자
template<>					//<---여기는 비우고
class CRyuData<char*>		//<---여기는 타입을 명시했다.
{
private:
	char* mData;

public:
	//매개변수 있는 생성자
	CRyuData(char* tData)
	{
		//얖은 복사shallow copy가 아닌
		//깊은 복사deep copy를 수행해야 한다.

		int tLength = strlen(tData);
		mData = new char[tLength + 1];  //힙메모리 확보
		memset(mData, 0, tLength + 1);  //해당 메모리 클리어

		memcpy(mData, tData, tLength);  //메모리(값) 복사
	}
	~CRyuData()
	{
		if (nullptr != mData)
		{
			delete[] mData; //new ~[]형식으로 만들었으므로 delete[]로 삭제
			mData = nullptr;
		}
	}

	char* GetData()
	{
		return mData;
	}
	void SetData(char* tData)
	{
		mData = tData;
	}

	//형변환 연산자 오버로드
	operator char* ()
	{
		return mData;
	}
};



int main()
{
	CRyuData<int> tRyuData_0(777);
	//cout << tRyuData_0.GetData() << endl;
	cout << tRyuData_0 << endl;

	CRyuData<float> tRyuData_1(999.9f);
	cout << tRyuData_1 << endl;

	CRyuData<char*> tRyuData_2((char*)"Black Pink"); //c style문자열을 매개변수 값으로 설정
	cout << tRyuData_2 << endl;

	return 0;
}