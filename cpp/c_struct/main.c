
#include <stdio.h>

/*

	����ü

	C���� '����ȭ ���α׷��� �з�����'�� ����Ͽ� ������� ����.
	<-- �Լ��� ����ü ���� '������'�� '��ǰ'���� ����� 
		'���α׷� ����'�� ����� �����

	�Լ� : �ڵ��� �߻�ȭ 
	����ü : �������� �߻�ȭ

	'������' ���� ���� �߻�ȭ�Ͽ�
	'�����( ���α׷��� )���� Ÿ��'�� ���� ���̴�.

*/

//��ǥ�� : ��ü�� ��ġ�� �����ϴ� �ý���

//�簢�� ������ ��� �������� �߻�ȭ
//struct RyuRect
//{
//	//����ü�� ���� ����
//	//C������ ����ü�� '��� ����'�� �ʱ�ȭ ǥ���� �Ұ����ϴ�. (C++�� ����)
//	int mLeft;
//	int mTop;
//	int mRight;
//	int mBottom;
//};

//step_2
//typedef A B         : A�� B�� �������Ѵ�.
typedef unsigned int RYU_INT;

typedef struct RyuRect //A
{
	//����ü�� ���� ����
	//C������ ����ü�� '��� ����'�� �ʱ�ȭ ǥ���� �Ұ����ϴ�. (C++�� ����)
	int mLeft;
	int mTop;
	int mRight;
	int mBottom;
} sRyuRect;//B

int CalcuAreaSize(sRyuRect tRect);

int main()
{
	//step_0
	//�簢���� ���� ���ϱ�
	//��ǥ��� ������ ��ǥ��(2D) ����
	/*int tLeft = 0;
	int tTop = 0;
	int tRight = 0;
	int tBottom = 0;

	tLeft = 100;
	tTop = 100;
	tRight = 200;
	tBottom = 200;

	int tWidth = tRight - tLeft;
	int tHeight = tBottom - tTop;

	int tAreaSize = tWidth * tHeight;

	printf("Area Size : %d\n", tAreaSize);*/

	//step_1
	/*int tLeft = 0;
	int tTop = 0;
	int tRight = 0;
	int tBottom = 0; */
	//struct RyuRect tRect;   //����ü RyuRect Ÿ���� ���� ����(C++�� struct��� �� �ᵵ �ȴ�.)
	//

	//tRect.mLeft = 100;    //. : ��� ���� ������
	//tRect.mTop = 100;
	//tRect.mRight = 200;
	//tRect.mBottom = 200;

	//int tWidth = tRect.mRight - tRect.mLeft;
	//int tHeight = tRect.mBottom - tRect.mTop;

	//int tAreaSize = tWidth * tHeight;

	//printf("Area Size : %d\n", tAreaSize);


	//step_2

	//unsigned int tA = 777;
	//printf("tA : %d\n", tA);
	//RYU_INT tB = 333;
	//printf("tB : %d\n", tB);


	//sRyuRect tRect; 


	//tRect.mLeft = 100;    
	//tRect.mTop = 100;
	//tRect.mRight = 200;
	//tRect.mBottom = 200;

	//int tWidth = tRect.mRight - tRect.mLeft;
	//int tHeight = tRect.mBottom - tRect.mTop;

	//int tAreaSize = tWidth * tHeight;

	//printf("Area Size : %d\n", tAreaSize);


	//step_3
	sRyuRect tRect;


	tRect.mLeft = 100;
	tRect.mTop = 100;
	tRect.mRight = 200;
	tRect.mBottom = 200;

	//int CalcuAreaSize(sRyuRect tRect)
	int tAreaSize = CalcuAreaSize(tRect);//int tWidth = tRect.mRight - tRect.mLeft;
										 //int tHeight = tRect.mBottom - tRect.mTop;
										 //tWidth * tHeight;
	printf("Area Size : %d\n", tAreaSize);
	

	return 0;
}

int CalcuAreaSize(sRyuRect tRect)
{
	int tResult = 0;

	int tWidth = tRect.mRight - tRect.mLeft;
	int tHeight = tRect.mBottom - tRect.mTop;

	tResult = tWidth * tHeight;

	return tResult;
}
