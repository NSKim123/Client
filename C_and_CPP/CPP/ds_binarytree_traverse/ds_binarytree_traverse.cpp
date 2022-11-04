/*
    배열

    링크드 리스트

    트리tree
        1:N의 비선형자료구조
                계층형자료구조

        최상단root노드


    이진트리 binary tree
     1)'트리'여야 한다.
     2)최대자식노드 갯수 <= 2
     3)root Node는 Lt.Node와 Rt.Node를 가진다.


*/

#include <iostream>
#include <queue> //STL에서 제공하는 queue 컨테이너
using namespace std;

struct SNode
{
    //데이터
    char mData = 0;

    //링크가 2개, 왼쪽자식노드, 오른쪽자식노드
    SNode* mpLt = nullptr;
    SNode* mpRt = nullptr;
};

//편의상 전역변수로 한다.
//층별 순회를 위한 자료구조
queue<SNode*> gQueue;

SNode* MakeRoot(char tData, SNode* tpLtNode, SNode* tpRtNode)
{
    SNode* tRoot = new SNode();
    
    tRoot->mData = tData;

    tRoot->mpLt = tpLtNode;
    tRoot->mpRt = tpRtNode;

    return tRoot;
}

//순회 traverse

//전위순회
/*
    1)root
    2)left
    3)right
    위의 규칙을 트리에 대해 재귀적으로 적용
*/
void PreOrder(SNode* tRoot)
{
    if (tRoot)
    {
        cout << tRoot->mData;

        PreOrder(tRoot->mpLt);

        PreOrder(tRoot->mpRt);
    }
}
//중위순회
/*
    1)left
    2)root
    3)right
    위의 규칙을 트리에 대해 재귀적으로 적용
*/
void InOrder(SNode* tRoot)
{
    if (tRoot)
    {
        InOrder(tRoot->mpLt);

        cout << tRoot->mData;
                
        InOrder(tRoot->mpRt);
    }
}
//후위순회
/*
    1)left
    2)right
    3)root
    위의 규칙을 트리에 대해 재귀적으로 적용
*/
void PostOrder(SNode* tRoot)
{
    if (tRoot)
    {
        PostOrder(tRoot->mpLt);

        PostOrder(tRoot->mpRt);

        cout << tRoot->mData;
    }
}
//레벨(층별)순회
//층을 내려가면서, 각층마다 왼쪽 노드에서 오른쪽 노드 순서로 방문한다(left --> right)
void LevelOrder(SNode* tRoot)
{
    gQueue.push(tRoot);

    while (!gQueue.empty())
    {
        tRoot = gQueue.front();
        gQueue.pop();

        cout << tRoot->mData;

        if (tRoot->mpLt)
        if (tRoot->mpLt)
        {
            gQueue.push(tRoot->mpLt);
        }

        if (tRoot->mpRt)
        {
            gQueue.push(tRoot->mpRt);
        }
    }
}
int main()
{
    //예시로 삼을 이진트리 구축
    SNode* n7 = MakeRoot('D', nullptr, nullptr);
    SNode* n6 = MakeRoot('C', nullptr, nullptr);
    SNode* n5 = MakeRoot('B', nullptr, nullptr);
    SNode* n4 = MakeRoot('A', nullptr, nullptr);
    SNode* n3 = MakeRoot('/', n6, n7);
    SNode* n2 = MakeRoot('*', n4, n5);
    SNode* n1 = MakeRoot('-', n2, n3);

    cout << "pre order tavarse: ";
    PreOrder(n1);
    cout << endl; // - * A B / C D

    cout << "in order tavarse: ";
    InOrder(n1);
    cout << endl; // A * B - C / D

    cout << "post order tavarse: ";
    PostOrder(n1);
    cout << endl; // A B * C D / -

    cout << "level order tavarse: ";
    LevelOrder(n1);
    cout << endl; // - * / A B C D

    return 0;
}

