
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



	//파일을 연다
	fopen_s(&tpFile, "playinfo_text.sav", "wt"); //wt : write, text



	//파일을 닫는다
	fclose(tpFile);



	return 0;
}