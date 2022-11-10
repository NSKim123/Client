/*
    자료구조 data struct : 데이터들을 담아두는 구조물 ----> 구조 ----> 특징

    (원시)배열 array : 동일한 타입의 원소들의 (물리적으로) 연속적인 메모리블럭   (캐쉬적중률, 임의접근)            
   
    링크드리스트 linked list : 노드가 데이터와 링크를 가지고 각각의 링크에 의해 한줄로(선형으로) 연결되어 있는 자료구조

        장점 : i) 실행중에 자료구조의 크가가 가변적
               ii) 데이터를 추가하거나 삭제하는데 걸리는 시간이 일정하다. ( 링크를 연결하거나 끊는 것에 의해 구현되기 때문 )

        단점 : i) 임의 접근random access 이 불가능하다
               ii) 검색에 시간이 오래 걸릴 수도 있다.( 링크를 따라가서 원소들을 찾아야 하기 때문)

    동작명세가 정해져있는 자료구조
    -스택stack : LIFO
    -큐queue : FIFO


    
    트리 tree : 1:N의 비선형자료구조, 계층형 자료구조

    이진트리 binary tree
        1)트리
        2)최대자식노드갯수 2개 이하
        3)Lt.ChiledNode, Rt.ChildNode

        순회 traverse 모든 노드들을 중복없이 한번씩 방문하는 것

        이진트리의 순회
        전위preorder : Root, Lt, Rt
        중위inorder : Lt, Root, Rt
        후위postorder : Lt, Rt, Root
        층별levelorder : 층을 하나씩 내려가면서. 왼쪽에서 오른쪽으로 노드를 방문


    이진탐색트리 binary search tree
    :해당 자료구조의 목적은? 탐색(검색) 용도의 자료구조이다.
    
        1)이진트리여야한다
        2)중복된 값이 없어야 한다
        3)Lt.Subtree 의 값은 root보다 작아야하고, Rt.Subtree의 값은 root보다 커야한다.
        4)서브트리도 이진탐색트리여야 한다.
*/



#include <iostream>
using namespace std;

struct SNode
{
    int mData = 0;

    SNode* mpLt = nullptr;
    SNode* mpRt = nullptr;
};
//검색(탐색)
//이진탐색트리를 이용한 탐색(검색)
SNode* SearchBST(SNode* tRoot, int tX)
{
    SNode* tpNode = nullptr;

    tpNode = tRoot;
    while (nullptr != tpNode)
    {
        if (tpNode->mData == tX)
        {
            return tpNode;
        }
        else if (tX < tpNode->mData)
        {
            tpNode = tpNode->mpLt;
        }
        else if(tX>tpNode->mData)
        {
            tpNode = tpNode->mpRt;
        }
    }
    cout << "찾으려는 값이 없습니다." << endl;

    return nullptr;
}

//추가
SNode* InsertNode(SNode* tRoot, int tX)
{
    SNode* tpNode = nullptr;

    tpNode = tRoot;

    //원하는 데이터가 트리에 없는 경우
    //단말노드를 찾고, 자식으로 붙이자
    if (nullptr == tRoot)
    {
        //새롭게 노드 추가. 이제 이 노드도 단말 노드이다.
        tpNode = new SNode();
        //data
        tpNode->mData = tX;
        //link 단말노드이므로 자식링크가 없다
        tpNode->mpLt = nullptr;
        tpNode->mpRt = nullptr;
    }
    else if(tX < tRoot->mData)
    {
        tRoot->mpLt = InsertNode(tRoot->mpLt, tX);
    }
    else if(tX > tRoot->mData)
    {
        tRoot->mpRt = InsertNode(tRoot->mpRt, tX);
    }
    else
    {
        cout << "이미 같은 값이 있습니다." << endl;
    }

    return tpNode;
}


//삭제
void DeleteNode(SNode* tRoot, int tX)
{
    SNode* parent = nullptr, * p = nullptr, * succ = nullptr, * succ_parent = nullptr;
    SNode* child = nullptr;

    parent = nullptr;
    p = tRoot;

    //삭제할 노드의 탐색
    while (p != nullptr && p->mData != tX) //단말노드인가? && 찾으려는 값이 아닌가?
    {
        parent = p;

        if (tX < p->mData)
        {
            p = p->mpLt;
        }
        else
        {
            p = p->mpRt;
        }
    }
    //찾지 못했다면
    if (p == nullptr)
    {
        cout << "찾으려는 값이 없습니다.(삭제 필요 없음)" << endl;

        return;
    }
    //삭제하려는 값을 찾았다면
    //case 차수0
    if (p->mpLt == nullptr && p->mpRt == nullptr)
    {
        if (parent != nullptr)
        {
            if (parent->mpLt == p)
            {
                parent->mpLt = nullptr;
            }
            else
            {
                parent->mpRt = nullptr;
            }
        }
        else
        {
            tRoot = nullptr;
        }
    }
    //case 차수1
    //else if (p->mpLt != nullptr || p->mpRt != nullptr)  // 둘다 null인 경우는 이번 if문에서 걸러진다.
    else if (p->mpLt == nullptr || p->mpRt == nullptr)  // 둘다 null인 경우는 이번 if문에서 걸러진다.
    {
        //child 설정. 왼쪽 or 오른쪽 판별 후 child에 대입
        if (p->mpLt != nullptr)
        {
            child = p->mpLt;
        }
        else
        {
            child = p->mpRt;
        }
        //자신의 부모와 자신의 자식을 연결
        if (parent != nullptr)
        {
            if (parent->mpLt == p)
            {
                parent->mpLt = child;
            }
            else
            {
                parent->mpRt = child;
            }
        }
        else
        {
            tRoot = child;
        }
    }
    //case 차수2
    else
    {
        succ_parent = p;
        succ = p->mpLt;  //왼쪽 서브트리에서 탐색할 것임을 나타내는 것이다

        while (succ->mpRt != nullptr )
        {
            succ_parent = succ;
            succ = succ->mpRt;
        }

        if (succ_parent->mpLt == succ)
        {
            succ_parent->mpLt = succ->mpLt;
        }
        else
        {
            succ_parent->mpRt = succ->mpLt;
        }

        p->mData = succ->mData;
        p = succ;
    }

    delete p;
}



void DisplayPreOrder(SNode* root)
{
    if (root)
    {
        cout << root->mData << ", ";

        DisplayPreOrder(root->mpLt);
        DisplayPreOrder(root->mpRt);
    }
}
//붙여넣자
void DisplayMenu()
{
    cout << endl << "*---------------------------*";
    cout << endl << "\t1 : 트리 출력";
    cout << endl << "\t2 : 숫자 삽입";
    cout << endl << "\t3 : 숫자 삭제";
    cout << endl << "\t4 : 숫자 검색";
    cout << endl << "\t5 : 종료";
    cout << endl << "*---------------------------*";
    cout << endl << "메뉴입력 >> ";
}
//main은 붙여넣자.
int main(int argc, const char* argv[])
{
    SNode* root = NULL;
    SNode* foundedNode = NULL;
    int tChoice = 0;
    int mData = 0;

    //예시 그림과 맞춰 둔 예시코드이다
    //이러한 순서대로 추가하였으므로 예시 그림과 같은 형태가 된다
    root = InsertNode(root, 8);
    InsertNode(root, 3);
    InsertNode(root, 10);
    InsertNode(root, 2);
    InsertNode(root, 5);
    InsertNode(root, 14);
    InsertNode(root, 11);
    InsertNode(root, 16);


    while (1)
    {
        DisplayMenu();

        cin >> tChoice;

        switch (tChoice)
        {
        case 1:
        {
            cout << "\t[이진 트리 출력]  ";
            DisplayPreOrder(root);

            cout << endl;
        }
        break;

        case 2:
        {
            cout << "삽입할 문자를 입력하세요 : ";

            cin >> mData;

            InsertNode(root, mData);
        }
        break;

        case 3:
        {
            cout << "삭제할 문자를 입력하세요 : ";

            cin >> mData;
            DeleteNode(root, mData);
        }
        break;

        case 4:
        {
            cout << "찾을 문자를 입력하세요 : ";

            cin >> mData;
            foundedNode = SearchBST(root, mData);

            if (foundedNode != NULL)
            {

                cout << endl << foundedNode->mData << "를 찾았습니다! " << endl;
            }
            else
            {

                cout << endl << " 문자를 찾지 못했습니다. " << endl;
            }
        }
        break;

        case 5:
        {
            return 0;
        }

        default:
        {
            cout << "없는 메뉴입니다. 메뉴를 다시 선택하세요! " << endl;
        }
        break;
        }
    }

    return 0;
}
