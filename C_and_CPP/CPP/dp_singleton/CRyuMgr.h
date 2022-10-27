#pragma once

/*

	singleton pattern을 만드는 방법

	다음 세가지 구성으로 만든다
	i) 해당 클래스 타입의 포인터 변수 mpInstance 를 static으로 만든다
	ii) 생성자는 public이 아니어야 한다.
	iii) GetInstance() 함수의 정의에는 최대 생성갯수를 1개로 제한하는 판단제어구조가 위치한다.

*/

class CRyuMgr
{
private:
	/*
		static 정적--->전역적인 성격을 띈다.
		static 예약어를 적용한 변수는 '데이터 메모리 영역'에 위치한다.
		코드상으로는 멤버변수이지만. 메모리 관점에서 볼떄는 전역변수이므로
		객체가 생성될 때 만들어지는 변수가 아니다.

		그러므로 여기서 초기화 표현이 불가능하다.
	*/
	//static CRyuMgr* mpInstance = nullptr;
	static CRyuMgr* mpInstance;

private:
	//외부에서의 생성을 막기 위해서다
	CRyuMgr();
	~CRyuMgr();

public:
	//표기상 멤버변수지만 전역함수와 성격이 같다.
	//static 변수를 다루기위해서는 static함수여야 한다.
	static CRyuMgr* GetInstance();
	static void ReleaseInstance();

	//이제 플레이어의 점수를 전역적으로 관리하겠다고 가정
public:
	int mScore = 0;
};

