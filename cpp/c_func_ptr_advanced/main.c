
#include <stdio.h>

//�� ������ ����, ����, ����, ������ �Լ��� ����� ���α׷� ������ �ۼ��ϼ���.
//����Ÿ���� float�� �����ϼ���.
float DoAdditive(int tA, int tB);
float DoSubtract(int tA, int tB);
float DoMultiply(int tA, int tB);
float DoDivide(int tA, int tB);

int main()
{
	int tA = 3;
	int tB = 2;

	float tResult = 0.0f;
	
	int tCalcuType = 0;
	int tIsContinue = 0;

	float (*tpCalculate)(int, int) = NULL; //NULL�� �ʱ�ȭ�� �� �ϸ� ������ �����.

	while (1)
	{
		printf("Select Type of Calculate: (0: +, 1: -, 2: *, 3: /)\n");
		scanf_s("%d", &tCalcuType);
		getchar();
		
		//�Լ��� ���� ȣ��
		//����ġ ������ �̿��ϰ�, '�Լ�ȣ��'�� �ϼ���.
		/*
		switch (tCalcuType)
		{
		case 0:
		{
			tResult = DoAdditive(tA, tB);
			printf("Additive : %f\n", tResult); 
		}
		break;
		case 1:
		{
			tResult = DoSubtract(tA, tB);
			printf("Subtract : %f\n", tResult);
		}
		break;
		case 2:
		{
			tResult = DoMultiply(tA, tB);
			printf("Multiply : % f\n", tResult);
		}
		break;
		case 3:
		{
			tResult = DoDivide(tA, tB);
			printf("Divide : %f\n", tResult);
		}
		break;
		}
		*/

		//�Լ������͸� �̿��Ͽ� ����ȣ�� ���·� ���α׷� ������ �����ϼ���.
		//ȣ���� �Լ��� �����ϴ� �κа� �Լ� ȣ�� �κ��� �и��Ǿ���.
		//�̷��� �Ǹ� �� �� '������ ������ ����'�� ������ ���ɼ��� ��������.
		switch (tCalcuType)
		{
		case 0: 
		{
			tpCalculate = DoAdditive;
		}
		break;
		case 1:
		{
			tpCalculate = DoSubtract;
		}
		break;
		case 2:
		{
			tpCalculate = DoMultiply;
		}
		break;
		case 3:
		{
			tpCalculate = DoDivide;
		}
		break;
		}
		tResult = tpCalculate(tA, tB);
		printf("Calculate : %f\n", tResult);

		printf("Quit(9)?");
		//���ڿ� �Է� �Լ�
		scanf_s("%d", &tIsContinue);
			getchar();

		if (9 == tIsContinue)
		{
			break;
		}
	}


	return 0;
}

float DoAdditive(int tA, int tB)
{
	return (float)tA + (float)tB;;
}
float DoSubtract(int tA, int tB)
{
	return (float)tA - (float)tB;
}
float DoMultiply(int tA, int tB)
{
	return (float)tA * (float)tB;
}
float DoDivide(int tA, int tB)
{
	return (float)tA / (float)tB;
}