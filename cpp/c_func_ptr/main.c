
#include <stdio.h>

/*

	�Լ� ������ 

		������ ���� : �ּҸ� ������ ������ ����
		
*/


int DoAdditive(int tA, int tB);

int main()
{
	int tA = 3;
	int tB = 2;
	int tResult = 0;

	//step_0
	//�Լ� �������� ���� : �Լ��� ���¸� ������ �����Ѵ�.
	int (*tpPtr)(int, int) = NULL;


	tpPtr = DoAdditive;


	//tResult = DoAdditive(tA, tB); //�Լ��� ȣ�� (����ȣ��)
	tResult = tpPtr(tA, tB);		//�Լ� �����͸� �̿��Ͽ� ����ȣ��
	
	printf("tResult : %d\n", tResult);


	//step_1
	//�Լ������Ϳ� typedef
	//typedef A B    typedef unsigned int RYU_INT

	//typedef�� �Լ��������� ���𱸹��� �Բ� ���ָ� �̸� �κ��� Ÿ��ó�� ��޵ȴ�.
	typedef int (*FuncPtrRyu)(int, int);
	
	FuncPtrRyu tpRyu; 
	tpRyu = DoAdditive;

	tResult = tpRyu(tA, tB);
	printf("tResult : %d\n", tResult);


	return 0;
}

int DoAdditive(int tA, int tB)
{
	int tResult = 0;

	tResult = tA + tB;

	return tResult;
}