
#include <iostream>
#include <queue>

using namespace std;

class CRectRyu
{
private:
	int mWidth = 0;
	int mHeight = 0;

public:
	CRectRyu(int tWidth, int tHeight)
		:mWidth(tWidth), mHeight(tHeight)
	{}
	//�ּ���, �������� ���ĵ� ����� ����.
	bool operator>(const CRectRyu& t) const
	{
		return mWidth * mHeight > t.mWidth * t.mHeight;
	}
	//�ִ���, �������� ���ĵ� ����� ����.
	bool operator<(const CRectRyu& t) const
	{
		return mWidth * mHeight < t.mWidth * t.mHeight;
	}

	void Display()
	{
		cout << "CRectRyu " << mWidth << "*" << mHeight << "=" << mWidth * mHeight << endl;
	}
};

//�ּ���, �������� ���ĵ� ����� ����.
typedef priority_queue<CRectRyu, vector<CRectRyu>, greater<CRectRyu>> CPriorityQGreater;  //greater : ��������  

typedef priority_queue<CRectRyu, vector<CRectRyu>, less<CRectRyu>> CPriorityQLess;

int main()
{
	CPriorityQGreater tPriorityQ_0;

	CRectRyu tRect_0(1, 5);
	CRectRyu tRect_1(7, 6);
	CRectRyu tRect_2(1, 2);
	CRectRyu tRect_3(8, 2);


	tPriorityQ_0.push(tRect_0);
	tPriorityQ_0.push(tRect_1);
	tPriorityQ_0.push(tRect_2);
	tPriorityQ_0.push(tRect_3);


	while (!tPriorityQ_0.empty())
	{
		CRectRyu tRect = tPriorityQ_0.top();
		tPriorityQ_0.pop();

		tRect.Display();
	}


	//

	CPriorityQLess tPriorityQ_1;

	tPriorityQ_1.push(tRect_0);
	tPriorityQ_1.push(tRect_1);
	tPriorityQ_1.push(tRect_2);
	tPriorityQ_1.push(tRect_3);

	return 0;
}