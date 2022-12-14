#pragma once

#include <functional>
using namespace std;
//Ÿ�̸� Ŭ����
//����� ���� �ּ������θ� �ֵ��� �ϰڴ�.

// void �Լ��̸�()
class CUnit;

class CRyuTimer
{
public:
	void SetTimer(float tTimeInterval, std::function<void(CUnit&)> tFunction, CUnit* tpUnit);

	void Update(float tDeltaTime);

private:
	//�Լ��� �����ѵ� �������
	std::function<void(CUnit&)> mFunction;

	float mTimeTick = 0.0f;    //deltatime ������ ����
	float mTimeInterval = 0.0f;    //���� �ð� ����

	CUnit* mpUnit = nullptr;   //��ü�� ����
};

