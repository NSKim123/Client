
/*

	C���� �����ϴ� 'ǥ�� (��)��� �Լ�'�� �ѷ����� ������ ��������.

	�ܼ� ���α׷��̶�� �����Ͽ� ������� �ִ� ǥ�� ������Լ��̹Ƿ�
	�翬�� ���ڿ� ���ڿ��� ���� �����ϵ��� ������� �ִ�.

	������. �� ������ ��¥ ������ �ٸ� ���̴�.



*/

#include <stdio.h>  //standard input output

int main()
{
	//i) char�� ����Ÿ���̴�.��ü�� �����̴�.
	//���� �ϳ� ���
	//putchar

	putchar('a');
	putchar(97);

	putchar('H');
	putchar('e');
	putchar('l');
	putchar('l');
	putchar('o');

	//���ڿ� ���
	//puts : ���ڿ��� ����� �� �ڵ������Ѵ�.
	puts("Hello");

	//C������ '���ڿ�'Ÿ�� type �� ���� �������� �ʴ´�.
	//�׷��� ������ ���ҿ� �����Ṯ�ڸ� �־��ش�. '\0'
	//<-- C style ���ڿ�
	char tszTemp[6] = {'H','e','l','l','o','\0'};
	puts(tszTemp);





	//�� : ������ ���� ����ϱ� ���� '�߻����� ����'
	//���� : ���� ǥ���ϱ� ���� ��ȣ ��)�ƶ��� ����



	//��ġ�����
	//���(������ �Ǵ� ��)�� ���� �ڸ�(��ġ)�ٲ����� ���ڸ� ǥ���ϴ� ���

	/*
	
		������ 10000 = 10^4 * 1 + 10^3 * 0 + 10^2 * 0 + 10^1 * 0 + 10^0 * 0

		����� �ַ� ����ϴ� ��ġ����� : '10�� ���'�� �ϴ� ��ġ�����(������) <-- �հ���
		
		��ǻ�Ͱ� �ַ� ����ϴ� ��ġ����� : '2�� ���'�� �ϴ� ��ġ�����(������) <-- ������ �帧 ���� (����off = 0, ���� on = 1)

		
		��Ʈ bit : ��ǻ�Ͱ� �ٷ�� ���� ���� �޸� ���� <-- 0�� 1�� ��Ÿ�� �� �ִ�. 

		����Ʈ byte : �ü���� �ٷ�� ���� ���� ������ ����
		1byte == 8bit


		�� �ڸ��� ��Ʈ�� ǥ���Ѵ�.
		��) ������ 1011 (= 2^3 * 1 + 2^2 * 0 + 2^1 * 1 + 2^0 * 1 = ������ 11)
			(: ��Ʈ 4���� ǥ��)

		��ǻ���� ���� ���� ǥ����

			<-- ���� : �� �ڸ��� ������ ���� ��� ������ ���� �ǰ� �ϴ� ��

		: 2�� ���� ǥ�������� �Ѵ�.
		2�� ���� = 1�� ���� + 1

		��) ������       1011					<--������ 11
			1�� ����     0100
			2�� ����	 0101(=0100+1)			<--������ -11


	*/


	//���ڿ� ���
	//printf ������ ������ ������ ���ڿ��� �����Ͽ� ����Ѵ�.
	//���ڿ��� ������ ��, %�������� ���� ����Ѵ�.
	
	//	%d ����(10����) 
	//	%f �Ǽ�
	//	%c ����
	//	%s ���ڿ�
	//
	//	%u ��ȣ�� �������� �ʰ� ǥ���ϴ� 10�� ����
	//	
	//	%o 8���� �������� ǥ��
	//	%x 16������������ ǥ��
	//
	//	%p �ּҰ��� ǥ��

	int tNumber = 777;
	printf("tNumber �� Ÿ���� �����̰� ���� %d �Դϴ�.\n", tNumber);    //\n ���� ����

	int tLevel = 999;
	int tExp = 1024;
	printf("���� ����� ������ %d �̰�, ����ġ�� %d �Դϴ�.\n", tLevel, tExp);

	char tC = 65;
	printf("%c\n", tC);
	printf("%d\n", (int)tC);

	printf("%f\n", (float)tC);
	printf("%f\n", (double)tC);  //double �Ǽ�


	float tFloat = 3.14f;
	printf("%f, %d\n", tFloat, (int)tFloat);
	
	//��ǻ�ʹ� ��(����)�� ��� ǥ���ϴ°�?
	printf("\n");

	int tInt_0 = 10;
	int tInt_1 = -10;

	printf("%d, %d \n", tInt_0, tInt_1);
	printf("%u, %u \n", tInt_0, tInt_1); //������ 4byte�� �����Ѵ�.(=32bit) ���� ������ ǥ���ϴ� ����� �����غ��� �ι������� (��Ʈ����+1)���� ��µȴ�.

	printf("%o\n", tInt_0); //8����  12
	printf("%x\n", tInt_0); //16����  A    0~9 ,A~F


	printf("%p\n", &tInt_0);    //& : �ּ� ������ (�޸� �ּ�)
	//'��� �޸�(����)���� �ּҰ� �ο��Ǿ� �ִ�.'
	//��� �����̸� �̶�� ���� �ۼ��ڰ� '�ּ�' ��� �˱� ���� ����ϴ� ���̴�. <-- ���� ����



	printf("\tI am a Good Boy.\n"); //��
	printf("\"I\" am a Good Boy.\n"); //���ڿ� �ȿ� "�� '�� �ְ� ���� ������ ������ " �� ' �տ� \�� ������ �ȴ�.
	printf("I am a \'Good\' Boy.\n");




	return 0;
}