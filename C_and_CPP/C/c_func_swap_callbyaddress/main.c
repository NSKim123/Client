
#include <stdio.h> //��������̶�� �θ�

void DoSwap(int tA, int tB);

void DoSwapPtr(int* tpA, int* tpB);

int main()
{
	//step_0
	//�� ������ ���� ��ȯ

	/*
	int tA = 3;
	int tB = 2;

	//��ȯ ��ƾ
	int tTemp = 0;
	tTemp = tA;
	tA = tB;
	tB = tTemp;

	printf("tA: %d, tB: %d\n", tA, tB);

	//void DoSwap(int tA, int tB) ������ (callbyvalue ������ ������ �Ű������� swap �Ǵ� ���̰� ���� main�Լ��� ���������� swap ���� ����)
	DoSwap(tA, tB);

	printf("tA: %d, tB: %d\n", tA, tB);
	*/

	//step_1
	int tA = 3;
	int tB = 2;

	//��ȯ ��ƾ
	DoSwapPtr(&tA, &tB);

	printf("tA: %d, tB: %d\n", tA, tB);


	return 0;
}

void DoSwap(int tA, int tB)
{
	int tTemp = 0;
	tTemp = tA;
	tA = tB;
	tB = tTemp; 
}
//call by address(pointer)
void DoSwapPtr(int* tpA, int* tpB)
{
	int tTemp = 0;
	tTemp = *tpA;
	*tpA = *tpB;
	*tpB = tTemp;
}
