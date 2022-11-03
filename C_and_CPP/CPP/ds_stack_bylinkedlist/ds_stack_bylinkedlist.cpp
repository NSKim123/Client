
/*
    가장 기본이 되는 자료구조 : 배열, 링크드리스트

    스택stack LIFO, 큐queue FIFO : 동작 명세가 정해져 있는 자료구조

    스택 stack 
        LIFO Last Input First Output
        가장 나중에 입력된 것이 가장 먼저 출력된다.



*/

#include <iostream>
using namespace std;

struct SNode
{
    int mData = 0;
    SNode* mpNext = nullptr;
};

SNode* mpHead = nullptr;
SNode* mpTail = nullptr;

//스택의 기본구조를 만들자
void InitStack()
{
    mpHead = new SNode();
    mpTail = new SNode();

    mpHead->mpNext = mpTail;
    mpTail->mpNext = mpTail;
}

void Push(int k)
{
    SNode* t = nullptr;

    t = new SNode();

    //데이터설정
    t->mData = k;
    //링크조작
    t->mpNext = mpHead->mpNext;
    mpHead->mpNext = t;
}
void Pop()
{
    SNode* t = nullptr;

    if (mpHead->mpNext == mpTail)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    //링크조작
    t = mpHead->mpNext;
    mpHead->mpNext = t->mpNext;
    //노드삭제
    delete t;
}
int Top()
{
    int tResult = -1;
    SNode* t = nullptr;

    if (mpHead->mpNext == mpTail)
    {
        cout << "Stack is empty" << endl;
        return -1; //원소의 값을 모두 양수라고 가정하겠다.
    }

    t = mpHead->mpNext;
    tResult = t->mData;

    return tResult;
    
}
bool IsEmpty()
{
    if (mpHead->mpNext == mpTail)
    {
        cout << "Stack is empty" << endl;
        return true;
    }

    return false;
}

int main()
{
    InitStack();

    Push(3);
    Push(9);
    Push(777);
    Push(5);
    Push(1);

    while (!IsEmpty())
    {
        int t = Top();
        cout << t << endl;

        Pop();
    }


    return 0;
}

