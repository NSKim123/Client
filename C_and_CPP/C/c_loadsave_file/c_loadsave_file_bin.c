
#include <stdio.h>

/*

	���� ����� ���� �ҷ�����
	���̳ʸ�binary ���


	i) ���̳ʸ� ������ ������

		��)	����� ������ ���� �����ϱ� ��ƴ�.(16����)
		��)	��ü�� �ؽ�Ʈ ���İ� ���Ͽ� �������� �뷮�� �۾�����.
			<-- ���Ͽ��� �����͸� '�Ľ�'�� �� �ӵ��� ���̳ʸ� ��忡 ���� ���� ������ �ִ�.
			
	ii) �ؽ�Ʈ ������ ������
		
		��) ����� ������ ���� ���������ϴ�.
		��)	��ü�� ���̳ʸ� ���İ� ���Ͽ� �������� �뷮�� Ŀ���� ������ �ִ�.
			<-- ���Ͽ��� �����͸� '�Ľ�'�� �� �ӵ��� ���̳ʸ� ��忡 ���� ���� ������ �ִ�.

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
	fopen_s(&tpFile, "playinfo_bin.sav", "wb"); //wt : write, binary

		fwrite(&tScore, sizeof(int), 1, tpFile);
		fwrite(&tX, sizeof(float), 1, tpFile);
		fwrite(&tY, sizeof(float), 1, tpFile);

	//������ �ݴ´�
	fclose(tpFile);


	//������ ���� �Ѽ� �̾�Ѵٰ� ��������.
	int tScore_0 = 0;
	
	float tX_0 = 0.0f;
	float tY_0 = 0.0f;

	//���Ͽ��� �����͸� �ε��Ѵ�. load from file
	fopen_s(&tpFile, "playinfo_bin.sav", "rb"); //rt : read, binary
	
		fread(&tScore_0, sizeof(int), 1, tpFile);
		fread(&tX_0, sizeof(float), 1, tpFile);
		fread(&tY_0, sizeof(float), 1, tpFile);

	fclose(tpFile);
	
	printf("%d\n", tScore_0);
	printf("%f\n", tX_0);
	printf("%f\n", tY_0);

	return 0;
}