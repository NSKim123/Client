
#include <stdio.h>

/*

	파일 저장과 파일 불러오기
	텍스트 모드

*/

int main()
{
	FILE* tpFile = NULL;   //파일 포인터

	//play data
	int tScore = 0;//점수
	//플레이어의 위치
	float tX = 0.0f;
	float tY = 0.0f;

	//게임을 플레이했다고 가정. 플레이한 결과가 변수, 즉 메모리에 이런 값들로 담겨있다고 가정하자.
	tScore = 777;
	tX = 240.0f;
	tY = 160.0f;

	//파일로 디스크에 '저장'한다고 가정하자.
	//파일을 연다
	fopen_s(&tpFile, "playinfo_text.sav", "wt"); //wt : write, text

		fprintf_s(tpFile, "%d\n", tScore);
		fprintf_s(tpFile, "%f\n", tX);
		fprintf_s(tpFile, "%f\n", tY);


	//파일을 닫는다
	fclose(tpFile);


	//게임을 새로 켜서 이어서한다고 가정하자.
	int tScore_0 = 0;
	
	float tX_0 = 0.0f;
	float tY_0 = 0.0f;

	//파일에서 데이터를 로드한다. load from file
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