
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

	//������ �÷����ߴٰ� ����. �÷����� ����� ����, �� �޸𸮿� �̷� ����� ����ִٰ� ��������.
	tScore = 777;
	tX = 240.0f;
	tY = 160.0f;

	//���Ϸ� ��ũ�� '����'�Ѵٰ� ��������.
	//������ ����
	fopen_s(&tpFile, "playinfo_text.sav", "wt"); //wt : write, text

		fprintf_s(tpFile, "%d\n", tScore);
		fprintf_s(tpFile, "%f\n", tX);
		fprintf_s(tpFile, "%f\n", tY);


	//������ �ݴ´�
	fclose(tpFile);


	//������ ���� �Ѽ� �̾�Ѵٰ� ��������.
	int tScore_0 = 0;
	
	float tX_0 = 0.0f;
	float tY_0 = 0.0f;

	//���Ͽ��� �����͸� �ε��Ѵ�. load from file
	fopen_s(&tpFile, "playinfo_text.sav", "rt"); //rt : read, text
	
		fscanf_s(tpFile, "%d\n", &tScore_0);
		fscanf_s(tpFile, "%f\n", &tX_0);
		fscanf_s(tpFile, "%f\n", &tY_0);

	fclose(tpFile);
	
	printf("%d\n", tScore_0);
	printf("%f\n", tX_0);
	printf("%f\n", tY_0);

	return 0;
}