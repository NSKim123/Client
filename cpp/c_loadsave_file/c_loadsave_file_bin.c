
#include <stdio.h>

/*

	파일 저장과 파일 불러오기
	바이너리binary 모드


	i) 바이너리 형식의 데이터

		가)	사람이 눈으로 보고 이해하기 어렵다.(16진수)
		나)	대체로 텍스트 형식과 비교하여 데이터의 용량이 작아진다.
			<-- 파일에서 데이터를 '파싱'할 때 속도가 바이너리 모드에 비교적 빠른 경향이 있다.
			
	ii) 텍스트 형식의 데이터
		
		가) 사람이 눈으로 보고 편집가능하다.
		나)	대체로 바이너리 형식과 비교하여 데이터의 용량이 커지는 경향이 있다.
			<-- 파일에서 데이터를 '파싱'할 때 속도가 바이너리 모드에 비해 느린 경향이 있다.

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
	fopen_s(&tpFile, "playinfo_bin.sav", "wb"); //wt : write, binary

		fwrite(&tScore, sizeof(int), 1, tpFile);
		fwrite(&tX, sizeof(float), 1, tpFile);
		fwrite(&tY, sizeof(float), 1, tpFile);

	//파일을 닫는다
	fclose(tpFile);


	//게임을 새로 켜서 이어서한다고 가정하자.
	int tScore_0 = 0;
	
	float tX_0 = 0.0f;
	float tY_0 = 0.0f;

	//파일에서 데이터를 로드한다. load from file
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