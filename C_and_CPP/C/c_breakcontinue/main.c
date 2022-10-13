
#include <stdio.h>

int main()
{
	int ti = 0;
	for (ti = 0 ; ti<5 ; ++ti)
	{
		printf("ti : %d\n", ti);
	}


	printf("\n");


	for (ti = 0; ti < 5; ti++)
	{
		if (3 == ti)
		{
			break;
		}
		printf("ti : %d\n", ti);
	}


	printf("\n");


	for (ti = 0; ti < 5; ++ti)
	{
		if (3 == ti)
		{
			//반복중에 continue 구문을 만나면,
			//반복제어구조 안에 아래 명령문들은 실행하지않고 건너뛰어
			//그 다음 실행할 명령문 단계를 실행한다.
			//반복제어구조의 가장 윗줄로 간다.
			continue;
		}
		printf("ti : %d\n", ti);
	}

	return 0;
}