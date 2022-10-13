
#include <stdio.h>

/*

	�Լ��� �Ű������� �ѱ�� �⺻����� call by value �̴�.


	�� ������ swap ��ȯ

*/

// void : �ƹ��͵� �������� �ʴ´�.
void DoSwap(int tA, int tB);

int main()
{
	//step_0
	/*
	int tA = 3;
	int tB = 2;


	//before
	printf("tA: %d\n", tA);
	printf("tB: %d\n", tB);

	//�� ������ �� ��ȯ
	int tTemp = 0;  //�ӽ������� ���� �������� ������ �ϳ� �ʿ��ϴ�.

	tTemp = tA;
	tA = tB;
	tB = tTemp;

	//after
	printf("tA: %d\n", tA);
	printf("tB: %d\n", tB);
	*/

	

	//step_1
	int tA = 3;
	int tB = 2;


	//before
	printf("tA: %d\n", tA);
	printf("tB: %d\n", tB);


	//void DoSwap
	DoSwap(tA, tB);  //���� tA,tB�� call by value�� �ް�, DoSwap�� ������ �Ű����� tA�� tB�� ������Ƿ� swap�� ���Ͼ��.

	

	//after
	printf("tA: %d\n", tA);
	printf("tB: %d\n", tB);

	return 0;
}

//call(pass) by value
void DoSwap(int tA, int tB)
{
	int tTemp = 0;

	tTemp = tA;
	tA = tB;
	tB = tTemp;
}