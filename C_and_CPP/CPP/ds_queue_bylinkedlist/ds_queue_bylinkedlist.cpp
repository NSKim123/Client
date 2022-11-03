/*
    큐 Queue
        FIFO First Input First Output
            가장 먼저 입력된 것이 가장 먼저 출력된다.

        동작 명세가 정해져 있는 자료구조

        data를 입력하는 것은 rear에서 일어난다. put이라고 한다.
        data를 출력하는 것은 front에서 일어난다. get이라고 한다.
        (put, get 등의 용어는 요즘 push, pop으로 통일해서 부르기도 한다.
                                enqueue, dequeue라는 용어도 마찬가지)

    
    이를테면, 큐의 경우는 심플링크드리스트를 기반으로 만들 수도 있지만, 그렇게 하면 꼬리쪽에 데이터를 추가하는데서 비효율적이게 된다
    그러므로 더블링크드리스트를 이용해서 만들어졌다.
*/

#include <iostream>
using namespace std;

//double linked list를 이용하여 queue를 만들겠다.
struct SNode
{
    int mData = 0;

    SNode* mpPrev = nullptr;
    SNode* mpNext = nullptr;
};

SNode* mpHead = new SNode();
SNode* mpTail = new SNode();

void InitQueue()
{
    mpHead->mpPrev = mpHead;
    mpHead->mpNext = mpTail;
    mpTail->mpPrev = mpHead;
    mpHead->mpNext = mpTail;
}
void Put(int k)
{
    SNode* t = nullptr;

    t = new SNode();
    //데이터 설정
    t->mData = k;
    //링크조작
    mpTail->mpPrev->mpNext = t;
    t->mpPrev = mpTail->mpPrev;
    mpTail->mpPrev = t;
    t->mpNext = mpTail;
}
void Get()
{
    SNode* t = nullptr;

    t = mpHead->mpNext;

    if (t==mpTail)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    //링크조작
    mpHead->mpNext = t->mpNext;
    t->mpNext->mpPrev = mpHead;
    //노드 삭제
    delete t;
}
int Front()
{
    int tResult = -1;
    SNode* t = nullptr;

    t = mpHead->mpNext;

    if (t == mpTail)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    tResult = t->mData;

    return tResult;
}
bool IsEmpty()
{
     if (mpHead->mpNext == mpTail)
    {
        cout << "Queue is empty" << endl;
        return true;
    }

    return false;
}

int main()
{
    InitQueue();

    Put(5);
    Put(4);
    Put(7);
    Put(88);
    Put(2);

    Get();
    Get();

    while (!IsEmpty())
    {
        int i = Front();
        cout << i << endl;

        Get();
    }

    return 0;
}


