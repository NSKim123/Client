
/*
	���ø��� Ư��ȭ


*/


#include <iostream>

using namespace std;

template<typename T>
class CRyuData
{
private:
	T mData;

public:
	//�Ű����� �ִ� ������
	CRyuData(T tData)
		:mData(tData) //�ʱ�ȭ ���
	{}

	T GetData()
	{
		return mData;
	}
	void SetData(T tData)
	{
		mData = tData;
	}

	//����ȯ ������ �����ε�
	operator T()
	{
		return mData;
	}
};

//char* �� ���ؼ�, ���ø��� Ư��ȭ�� ����
template<>					//<---����� ����
class CRyuData<char*>		//<---����� Ÿ���� ����ߴ�.
{
private:
	char* mData;

public:
	//�Ű����� �ִ� ������
	CRyuData(char* tData)
	{
		//�A�� ����shallow copy�� �ƴ�
		//���� ����deep copy�� �����ؾ� �Ѵ�.

		int tLength = strlen(tData);
		mData = new char[tLength + 1];  //���޸� Ȯ��
		memset(mData, 0, tLength + 1);  //�ش� �޸� Ŭ����

		memcpy(mData, tData, tLength);  //�޸�(��) ����
	}
	~CRyuData()
	{
		if (nullptr != mData)
		{
			delete[] mData; //new ~[]�������� ��������Ƿ� delete[]�� ����
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

	//����ȯ ������ �����ε�
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

	CRyuData<char*> tRyuData_2((char*)"Black Pink"); //c style���ڿ��� �Ű����� ������ ����
	cout << tRyuData_2 << endl;

	return 0;
}