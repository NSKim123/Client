
#include <stdio.h>
#include <stdlib.h> //malloc, free


/*

	�޸��� �����Ҵ�� ����

	void* malloc( size_t size ) 

	�־��� �Ű����� ���ڸ�ŭ '����Ʈ' ������ �޸𸮸� ��������(�����߿�, dynamic, runtime) �Ҵ�(Ȯ��)�ϰ� �ش� �޸��� '�ּ�'�� ��ȯ�Ѵ�.


	free   �־��� ������ ������ ����(�ּҰ� ���� �޸𸮿� ����)�Ͽ�, �����Ҵ�� �޸𸮸� ����(�޸𸮼���������)�Ѵ�. 

	�̰��� ǥ�� '�Լ�' �̴�.

	�޸��� �����Ҵ�� ������ ����� �����Ѵ�.
	�̷��� �Ҵ�� �޸𸮴� '��'�޸��� ��ġ�ϰ� �ȴ�.

	stack frame vs Dynamaic Memory Allocation
*/

int main()
{
	//step_0
	//���� �޸𸮴� �������α׷����� ����ϴ� ũ�Ⱑ �ü���� ���� �������ִ�.
	//�׷���, �Ը� ū �������α׷��� ���ø��� ����Ͽ� ����� �Ϳ��� �Ѱ谡 �ִ�.
	//char tArray[1000100];
	//char tArray[9000100];   ���ÿ����÷ο�

	//step_1
	char* tpA = NULL;
	tpA = (char*)malloc(sizeof(char) * 9000100); //���޸� �����Ҵ�
		  //malloc �Լ��� void Ÿ���̹Ƿ� char*�� ����ȯ �ؾ��Ѵ�.

	if (NULL != tpA) //�� üũ
	{
		//�����Ҵ��� �޸� ����
		free(tpA);
		tpA = NULL;
	}



	//step_2
	//���޸𸮿� int Ÿ���� ������ 1�� �����
	//���� 777�� ��������

	int* tpB = NULL;
	tpB = (int*)malloc(sizeof(int) * 1); 
	
	if (NULL != tpB)
	{
		*tpB = 777; //��������

		printf("%d\n", *tpB);
	}

	if (NULL != tpB) 
	{
		free(tpB);
		tpB = NULL;
	}

	return 0;
}