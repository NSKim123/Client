#pragma once

//reference count ����� ������ Ŭ����

/*
	reference count

	�����Ҵ��� �޸𸮸�	�����ϴ� Ƚ���� ����ϴ� ������ �ΰ�

	����ȹ���� 0���� ũ�� ����Ƚ���� �����ϰ�,
	����Ƚ���� 0�̸� ������ �����Ҵ��� �޸𸮸� �����ϴ� ���

*/

class CRef
{
public:
	CRef();
	virtual ~CRef();

public:
	int mRef = 0; //����Ƚ�� ī��Ʈ ����

	inline void Addref()
	{
		//���� ī��Ʈ�� �ϳ� ������Ų��.
		++mRef;
	}
	inline int Release()
	{
		//���� ī��Ʈ�� �ϳ� ���ҽ�Ų��.
		--mRef;

		//���������� ����ī��Ʈ�� 0�̸�
		//���̻� �������� �ʴ� �����Ҵ�޸��̹Ƿ� �����Ѵ�
		if (0 == mRef)
		{
			delete this;
			return 0;
		}

		return mRef;
	}

};

