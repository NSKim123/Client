
#include <stdio.h>

/*

	���� ����� ���� �ҷ�����
	�ؽ�Ʈ ���

*/

int main()
{
	FILE* tpFile = NULL;   //���� ������

	//play data
	int tScore = 0;//����
	//�÷��̾��� ��ġ
	float tX = 0.0f;
	float tY = 0.0f;



	//������ ����
	fopen_s(&tpFile, "playinfo_text.sav", "wt"); //wt : write, text



	//������ �ݴ´�
	fclose(tpFile);



	return 0;
}