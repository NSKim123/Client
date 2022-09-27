
#include <stdio.h>

/*

	�Լ��� ����

	C���� '����ȭ ���α׷��� �з�����'���� ������� ���

	�׸��Ͽ�
		'����ȭ'�Ͽ� ����� �ڵ��� ���� ���ܵ��� '��ǰȭ'�Ͽ�
		�ش� ��ǰ��� ���α׷� ������ �����ϴ� ����� �߸��
		�̰��� ����ȭ ���α׷��� structured programming �̴�.
		( --> �Լ��� ����ü�� �̿��Ͽ� ���α׷� ������ �ۼ��ϴ� ��� )

		����ȭ ���α׷����� ��ǥ���� ������ '�Լ� function'�̴�.

		�߻�ȭ abstraction : ������ �׸���� ������� �̸��� ���̴� ����
		�Ϲ�ȭ generalization : ������ ���� ������ ������ �ϳ��� ��ǥ���� ��¡�� ���� �ٷ�� ����


	�Լ� : ��� ��ǰ
			y = ax +b ���������� ���Ӻ��� ������ �����
			���������� input�� ������ ���Ӻ����� output�� �����ȴ�
			<-- ��, �Է¿� ���� � ó���� �Ͽ� ����� ����� ��

	�Լ� : �ڵ�(�����)�� �߻�ȭ


		�Լ� ������ ���´� �̿� ����.

			����Ÿ�� �Լ��̸�(�Ű�����Ÿ�� �Ű������̸�, ...)
			{//function body
				//���ϴ� ��ɹ���

				return ȣ������ ������ ��;
			}

	�Լ������ 3�ܰ�
	    ���� : ( ȣ���� ���� )�Լ��� ���¸� �˷��ִ� ��
	    ���� : �Լ��� ���� ������ ����� ��
	    ȣ�� : �Լ��� �����ϴ� ��  <-- �Լ��̸����� �Ѵ�.


*/

//�Լ��� ����
int DoAddictive(int tA, int tB);
int DoSubtract(int tA, int tB);
int DoMultiply(int tA, int tB);
float DoDivide(float tA, float tB);

int main()
{

	int tA = 3;
	int tB = 2;

	int tResult = 0;


	//��Ģ����
	//+
	//DoAddictive
	tResult = DoAddictive(tA, tB);//tA + tB;
	printf("addictive : %d\n", tResult);

	//-
	//DoSubtract
	tResult = DoSubtract(tA, tB);//tA - tB;
	printf("subtract : %d\n", tResult);

	//*
	//DoMultiply
	tResult = DoMultiply(tA, tB);
	printf("multiply : %d\n", tResult);

	// /
	//DoDivide
	float tResult0 = 0.0f;
	tResult0 = DoDivide((float)tA, (float)tB);
	printf("division : %f\n", tResult0);
	
	
	
	return 0;
}

//�Լ��� ����
int DoAddictive(int tA, int tB) 
{
	int tResult = 0;
	tResult = tA + tB;

	return tResult;
}

int DoSubtract(int tA, int tB)
{
	int tResult = 0;
	tResult = tA - tB;

	return tResult;
}

int DoMultiply(int tA, int tB)
{
	int tResult = 0;
	tResult = tA * tB;

	return tResult;
}

float DoDivide(float tA, float tB)
{
	float tResult = 0;
	tResult = tA / tB;

	return tResult;
}