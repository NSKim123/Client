
#include <stdio.h>

/*


	���ȣ��
	�ڱ��ڽ��� ȣ���Ѵ�.

	'��ü ����'�� ���� '�κб���'��
	��ü������ ���ԵǾ� �ִٸ�
	�̰��� ���ȣ��� ���� �� �ִ�.

*/

unsigned int DoFactorial(unsigned int tN);

int main()
{
	int tA = 4;
	int tResult = 0;
	tResult = DoFactorial(tA);

	printf("4!�� �����: %d\n", tResult);

	return 0;
}

//�Լ��� ���ǰ� ������ �ʾ������� �ұ��ϰ�
//�ش� �Լ��� ȣ���ϰ� �ִ�.
/*
�̰��� ������ ������ �Լ��� ���ǵ� �޸𸮿� �ֱ� �����̴�.
�Լ� ȣ���� �Լ��� �̸����� �ϴµ�
�Լ��� �̸��� �ּҸ� ��Ÿ����.
��, �Լ�ȣ���� �ϸ� �ش� �Լ��� ���Ǻ��� ���ۺκ����� ���� ��ɹ��� �����Ѵ�.
*/

/*
 
	���ȣ���� ����
	i)�Լ� ȣ�� ����� ���( �ӵ��� ������ )
	ii)���� ���� �÷ο� stack over flow : ���� �޸𸮰� ���ڶ� ���� �ִ�.

	���ȣ���� ����
	i)�ڵ尡 �ɹ����̴�..

*/
unsigned int DoFactorial(unsigned int tN)
{
	if (0 == tN) 
	{
		//base case ( ���ȣ���� ���������̶�� �����ϸ� �ȴ�.)
		return 1;
	}
	else 
	{
		//reculsive case
		return tN * DoFactorial(tN - 1);
	}
}