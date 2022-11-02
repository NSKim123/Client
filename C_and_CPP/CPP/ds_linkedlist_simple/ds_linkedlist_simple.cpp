

#include <iostream>
using namespace std;

//자료구조 data structure : 자료들을 담아두는 구조물, 구조와 특성
//알고리즘 algorithm: 임의의 '문제를 해결'하기 위한 '논리적인' '절차'의 명세(솔루션)

//배열 : '동일한 타입'의 '원소들'의 (물리적으로) '연속적인' 메모리 블럭

//링크드 리스트 linked list
//      :'노드'가 '데이터'와 '링크'를 가지고, 각각의 링크에 의해 '한줄로(선형으로)' '연결'되어 있는 자료구조
// 
//simple linked list 단순 연결 링크드 리스트 ( 단방향 연결 링크드 리스트, 심플링크드리스트)

//노드 를 정의
struct SNode
{
    //데이터
    int mData = 0;

    //링크
    SNode* mpNext = nullptr;
};


//편의를 위해서 전역변수로 만들겠다.
SNode* mpHead = nullptr;
SNode* mpTail = nullptr;


//편의를 위해서 선언, 정의 합쳐서 쓰겠다.
//심플링크드리스트의 기본구조를 만들자
void InitList()
{
    //head 노드, tail 노드 확보
    mpHead = new SNode();
    mpTail = new SNode();

    //링크 조작
    mpHead->mpNext = mpTail;
    mpTail->mpNext = mpTail;
}

//추가, 삭제, 탐색

//정렬하면서 추가(10, 5를 예로 들어보자)
SNode* OrderedInsert(int k)
{
    SNode* p = nullptr;
    SNode* s = nullptr;

    SNode* r = nullptr;

    p = mpHead;
    s = p->mpNext;
    
    while (s->mData <= k && s != mpTail)
    {
        p = p->mpNext;
        s = p->mpNext;
    }

    r = new SNode();
    r->mData = k;
    p->mpNext = r;
    r->mpNext = s;

    return r;
}

//임의의 노드의 주소값을 받아서 그 노드의 다음 노드 삭제
bool DeleteNext(SNode* t)
{
    SNode* tpNode = nullptr;
    if (t->mpNext == mpTail)
    {
        return false;
    }

    tpNode = t->mpNext;
    t->mpNext = t->mpNext->mpNext;

    delete tpNode;

    return true;
}

SNode* FindNode(int k)
{
    SNode* tpNode = nullptr;

    tpNode = mpHead->mpNext;
    while (tpNode->mData != k && tpNode != mpTail)
    {
        tpNode = tpNode->mpNext;
    }


    return tpNode;
}

void Display(SNode* t)
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

    OrderedInsert(10);
    OrderedInsert(5);
    OrderedInsert(7);
    OrderedInsert(1);
    OrderedInsert(8);

    Display(mpHead->mpNext);

    cout << endl;

    SNode* t = FindNode(7);
    DeleteNext(t);

    Display(mpHead->mpNext);

    cout << endl;

    SNode* tt = FindNode(1);
    tt->mData = 777;

    Display(mpHead->mpNext);

    //링크드리스트 삭제구문이 필요하다.(생략한다)

    

    return 0;
}


