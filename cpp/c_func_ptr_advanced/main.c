
#include <stdio.h>

//두 정수의 덧셈, 뺄셈, 곱셈, 나눗셈 함수를 만들어 프로그램 구조를 작성하세요.
//리턴타입을 float로 통일하세요.
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

	float (*tpCalculate)(int, int) = NULL; //NULL로 초기화를 안 하면 오류가 생긴다.

	while (1)
	{
		printf("Select Type of Calculate: (0: +, 1: -, 2: *, 3: /)\n");
		scanf_s("%d", &tCalcuType);
		getchar();
		
		//함수를 직접 호출
		//스위치 구문을 이용하고, '함수호출'을 하세요.
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

		//함수포인터를 이용하여 간접호출 형태로 프로그램 구조를 변경하세요.
		//호출할 함수를 결정하는 부분과 함수 호출 부분이 분리되었다.
		//이렇게 되면 좀 더 '유연한 형태의 구조'로 변형할 가능성이 높아진다.
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
		//문자열 입력 함수
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