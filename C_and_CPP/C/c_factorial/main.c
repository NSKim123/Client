
#include <stdio.h>

/*


	���ȣ��
	�ڱ��ڽ��� ȣ���Ѵ�.

	'��ü ����'�� ���� '�κб���'��
	��ü������ ���ԵǾ� �ִٸ�
	�̰��� ���ȣ��� ���� �� �ִ�.

*/

unsigned int DoFactorial(unsigned int tN);
unsigned int DoFactorialNoReculsive(unsigned int tN); //����͹����� �Լ�

int main()
{
	int tA = 4;
	int tResult = 0;
	tResult = DoFactorial(tA);

	printf("4!�� �����: %d\n", tResult);

	tResult = DoFactorialNoReculsive(tA);

	printf("(No Reculsive) 4!�� �����: %d\n", tResult);

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
	i) �Լ� ȣ�� ����� ���( �ӵ��� ������ )
	ii) ���� ���� �÷ο� stack over flow : ���� �޸𸮰� ���ڶ� ���� �ִ�.

	���ȣ���� ����
	i) �ڵ尡 �ɹ����̴�..

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
/*

����͹����� �Լ� ȣ���� ����(vs ���ȣ��)
i) �Լ�ȣ�� ����� ���� �ʴ´�.
ii) ����� ��������(�Ű�������)��ŭ�� �޸𸮸� ����Ѵ�.

*/
unsigned int DoFactorialNoReculsive(unsigned int tN)
{
	if (0 == tN)
	{
		return 1;
	}
	else
	{
		unsigned int tTemp = 1;  //���ȣ������� �Լ����� �Ϲ������� ǥ���Ǵ� ������� ��� �޸𸮰� ���⼭�� ������ ��������� ǥ���Ǿ���.
		unsigned int ti = 0;
		//���ȣ��Ǵ� �κ��� �ݺ�������� ����Ǿ���.
		for (ti=tN;ti>0;--ti)
		{
			tTemp = tTemp * ti;
		}
		return tTemp;
	}
}