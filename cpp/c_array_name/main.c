
#include <stdio.h>
/*

	(����)�迭 : ������ Ÿ���� ���ҵ��� (����������) �������� �޸� ��

	C��� �迭�� �̸����� ���캸��
*/


DoChangeElement(int tArray[], int tindex, int tValue);

int main()
{
	//step_0
	int tArray[5] = { 4, 0, 1, 2, 3 };

	int ti = 0;
	for (ti=0;ti<5;++ti)
	{
		printf("%d\n", tArray[ti]);
	}

	printf("\n");


	DoChangeElement(tArray, 0, 777); //'�迭�� �̸�'�� '�迭�� �����ּҰ�'�� ��Ÿ������ ������� �ִ�.

	for (ti = 0; ti < 5; ++ti)
	{
		printf("%d\n", tArray[ti]);
	}


	//step_1
	// ���� �迭�� ������ ���� ���ϱ�
	//sizeof ������ : �������� ũ�⸦ ����Ʈ ������ �˷��ش�.
	int tA = sizeof(tArray);
	int tB = sizeof(tArray[0]);

	printf("tA: %d\n", tA); //�迭���� sizeof�� �۵�, �迭�� �̸��� ������ �迭�� ��üũ�⸦ ����Ʈ ������ �˷��ش�.
	printf("tB: %d\n", tB); 
	
	int tArrayLength = tA / tB;

	printf("\n");

	//step_2
	int tArray_0[5] = {0};     //0���� �ʱ�ȭ�� ���� ǥ������� �����ϰ� �� ���� �ִ�.


	//step_3
	//���� �������� ������ �ڵ��̴�.
	printf("%p\n", &tArray_0);
	printf("%p\n", &tArray_0[0]);
	printf("%p\n", tArray_0); //�迭�� �̸��� �迭 ���� �ּ��� ���� ��Ÿ����.   <--  ��� �������� ������ ��� �ִ�.



	return 0;
}

// ù��° �Ű������� �迭Ÿ��(?)�̹Ƿ� �ּ��� ���� ���� �޴´�.
DoChangeElement(int tArray[], int tindex, int tValue)
{
	//�ε��� ���� �������� ��ü�� �迭�� �̸�(�����ּҰ�)�� �������� ��� ���Ҹ� �ǳʰ��� �����ϴ� ���̴�.
	tArray[tindex] = tValue;
}