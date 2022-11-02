
/*
    double linked list
    양방향 연결 리스트, 이중 연결 리스트



*/

#include <iostream>
using namespace std;

struct SNode
{
    int mData = 0;

    SNode* mpPrev = nullptr;     //tail -----> head
    SNode* mpNext = nullptr;     //head -----> tail
};

SNode* mpHead = nullptr;
SNode* mpTail = nullptr;

//double 링크드리스트의 기본구조 만들기
void InitList()
{
    mpHead = new SNode();
    mpTail = new SNode();


    //링크 조작
    mpHead->mpPrev = mpHead;
    mpHead->mpNext = mpTail;

    mpTail->mpPrev = mpHead;
    mpTail->mpNext = mpTail;
}

SNode* OrderedInsert(int k)
{
    SNode* s = nullptr;
    SNode* i = nullptr;

    s = mpHead->mpNext;

    //추가할 위치 선정
    while (s->mData <= k && s != mpTail)
    {
        s = s->mpNext;
    }

    i = new SNode();
    i->mData = k;
    
    //링크 조작
    s->mpPrev->mpNext = i;
    i->mpPrev = s->mpPrev;
    s->mpPrev = i;
    i->mpNext = s;

    return i;
}

SNode* FindNode(int k)
{
    SNode* s = nullptr;

    s = mpHead->mpNext;

    while (s->mData != k && s != mpTail)
    {
        s = s->mpNext;
    }

    return s;
}


bool DeleteNode(int k)
{
    SNode* s = nullptr;

    s = FindNode(k);

    if (s != mpTail)
    {
        s->mpPrev->mpNext = s->mpNext;
        s->mpNext->mpPrev = s->mpPrev;

        delete s;

        return true;
    }
    
    
    return false;
    

}

void DisplayList(SNode* t)
{
    while (t != mpTail)
    {
        cout << "\t" << t->mData;
        t = t->mpNext;
    }
}


int main()
{
    InitList();

    OrderedInsert(3);
    OrderedInsert(1);
    OrderedInsert(10);

    DisplayList(mpHead->mpNext);

    cout << endl;
    DeleteNode(3);

    DisplayList(mpHead->mpNext);

    return 0;
}


