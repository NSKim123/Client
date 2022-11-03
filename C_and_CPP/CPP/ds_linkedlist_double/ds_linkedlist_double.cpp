
/*
    double linked list
    양방향 연결 리스트, 이중 연결 리스트

    

    (원시)배열 : 
        동일한 타입의 원소들의 연속적인 메모리 블럭

    링크드 리스트 : 
        '노드'가 '데이터'와 '링크'를 가지고
        각각의 링크에 의해 '한줄로(선형으로)'
        '연결'되어 있는 자료구조

        
        원시배열과 비교
        장점:
        1) 실행중에 크키가 가변적이다
        2) 원소를 추가하거나 삭제하는데 걸리는 시간이 일정하다. (링크를 연결하거나 끊는 것에 의해 구현되기 때문이다.)

        단점:
        1) 임의접근random access 이 불가능하다.
        2) 검색에 시간이 오래 걸릴 수도 있다.


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


