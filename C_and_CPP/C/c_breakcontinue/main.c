
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
			//�ݺ��߿� continue ������ ������,
			//�ݺ������ �ȿ� �Ʒ� ��ɹ����� ���������ʰ� �ǳʶپ�
			//�� ���� ������ ��ɹ� �ܰ踦 �����Ѵ�.
			//�ݺ�������� ���� ���ٷ� ����.
			continue;
		}
		printf("ti : %d\n", ti);
	}

	return 0;
}