
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
			{
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
	tResult = DoSubtract(tA, tB);//tA - tB;
	printf("subtract : %d\n", tResult);

	//*
	tResult = tA * tB;
	printf("multiply : %d\n", tResult);

	// /
	float tResult0 = 0.0f;
	tResult0 = (float)tA / (float)tB;
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