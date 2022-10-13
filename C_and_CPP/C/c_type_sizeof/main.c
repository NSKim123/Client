
#include <stdio.h>

/*
	sizeof ������

	---> ������ Ÿ�Կ� ���� �޸𸮰� ���(�󸶸�ŭ) Ȯ���Ǵ��� ���캸��

*/

int main()
{
	char tChar = 0;
	int tInt = 0;

	//sizeof ������ : Ÿ���̳� ������ �޸� ũ�⸦ ���´�.( byte ���� )
	printf("%d\n", (unsigned int)sizeof(tChar));  //1byte ==8bit
	//256���� ��츦 ǥ�� ����
	//���� ������ �������� �ʴ´ٸ� 0~255
	//���� �������� �����Ѵٸ� -128~127
	printf("%d\n", (unsigned int)sizeof(tInt)); //4byte == 32bit
	//4,294,967,296 = 2^32
	//���� ������ �������� �ʴ´ٸ� 0~(2^32-1)
	//���� �������� �����Ѵٸ� -2^31 ~ 2^31-1
	
	short int tShortInt = 0;
	long int tLongInt = 0;
	long long int tLongLongInt = 0;


	printf("%d\n", (unsigned int)sizeof(tShortInt));    //2byte == 16bit
	printf("%d\n", (unsigned int)sizeof(tLongInt));     //4byte == 32bit
	printf("%d\n", (unsigned int)sizeof(tLongLongInt)); //8byte == 64bit

	float tFloat = 0.0f;
	double tDouble = 0.0; //���� ���� ���е��� �Ǽ��� ǥ��

	printf("%d\n", (unsigned int)sizeof(tFloat));     //4byte == 32bit
	printf("%d\n", (unsigned int)sizeof(tDouble));    //8byte == 64bit






	return 0;
}