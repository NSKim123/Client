
#include <stdio.h>

/*

	(����)�迭 : ������ Ÿ���� ���ҵ��� (����������) �������� �޸� ��
	
*/

//�迭�� �Ű������� �ѱ�� ǥ���
void DoChangeElement(int tArray[], int tIndex, int tValue);

int main()
{
	int tArray[5] = {0,0,0,0,0};

	tArray[0] = 4;
	tArray[1] = 0;
	tArray[2] = 1;
	tArray[3] = 2;
	tArray[4] = 3;

	int ti = 0;
	for (ti = 0; ti < 5; ti++)
	{
		printf("%d\n", tArray[ti]);
	}

	printf("\n");


	//step_0
	/*
	
	tArray[0] = 777;

	for (ti = 0; ti < 5; ti++)
	{
		printf("%d\n", tArray[ti]);
	}
	
	*/

	//step_1
	//void DoChangeElement(int tArray[],int tIndex, int tValue);
	//�迭�� �̸��� �迭�� �����ּ��� ���� ��Ÿ����.
	//���⼭�� �迭�� �̸��� �Ѱ��ش�. (call by value �� �ƴϴ�.)
	DoChangeElement(tArray, 0, 777); 

	for (ti = 0; ti < 5; ti++)
	{
		printf("%d\n", tArray[ti]);
	}

	return 0;
}

void DoChangeElement(int tArray[], int tIndex, int tValue)
{
	tArray[tIndex] = tValue;
}