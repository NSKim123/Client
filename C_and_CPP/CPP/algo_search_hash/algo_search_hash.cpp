
/*
    해쉬검색 hash search 
            해쉬함수를 통해 데이터를 바로 위치로 만들어 해당위치에 해당 데이터를 저장하는 자료구조인 해쉬를 이용한 검색

*/

#include <iostream>
using namespace std;

//전처리 구문, 매크로
//매크로 상수
#define TABLE_SIZE 10    //해쉬테이블의 크기 : 버킷의 갯수

//여기에 사용된 링크드리스트는 심플이며, 따로 꼬리 노드의 개념이 없이 nullptr로 설정한다.
struct SNode
{
    int mData = 0;
    SNode* mpNext = nullptr;
};


//함수는 편의상 선언, 정의를 합쳐서 만들겠다

void HashInit(SNode tArray[], int* tpTotalElementCount, int tLength)
{
    for (int ti = 0; ti < tLength; ++ti)
    {
        tArray[ti].mpNext = nullptr;
    }
    //처음 원소의 갯수는 0개
    *tpTotalElementCount = 0;
}

//해쉬테이블 만들기
void HashCreate(SNode** tpNode, int* tpTotalElementCount, int tLength)
{
    *tpNode = new SNode[tLength];

    HashInit(*tpNode, tpTotalElementCount, tLength);
}

//해쉬테이블원소들 모두 삭제
void HashDestroy(SNode tArray[], int* tpTotalElementCount, int tLength)
{
    SNode* tpNode = nullptr;    //버킷
    SNode* tpPtr = nullptr;     //체이닝의 노드
    //버킷
    for (int ti = 0; ti < tLength; ++ti)
    {
        tpNode = tArray[ti].mpNext;
        //체이닝
        while (nullptr != tpNode)
        {
            //링크를 따라간다
            tpPtr = tpNode;
            tpNode = tpNode->mpNext;
            //노드를 삭제
            delete tpPtr;
        }
    }

    *tpTotalElementCount = 0;
}

//해쉬함수
//해쉬 자료구조에선 데이터가 곧 위치가 된다. 데이터를 위치로 만드는 함수를 해쉬함수라고 한다.
int HashFunc(int tData)
{
    int tResult = -1;
    //여기서는 MOD연산을 해쉬연산으로 삼았다.
    tResult = tData % TABLE_SIZE;

    return tResult;
}

//추가
SNode* HashInsert(int tData, SNode tArray[], int* tpTotalElementCount)
{
    int tHashIndex = -1;   //해쉬값, 버킷 인덱스
    SNode* tpNode = nullptr;  //슬롯의 지역변수

    //새로운 원소 하나 추가
    tpNode = new SNode();

    tHashIndex = HashFunc(tData);

    tpNode->mpNext = tArray[tHashIndex].mpNext;
    tArray[tHashIndex].mpNext = tpNode;
    //데이터설정
    tpNode->mData = tData;
    (*tpTotalElementCount)++;

    return tpNode;
}
//삭제
SNode* HashDelete(int tData, SNode tArray[], int* tpTotalElementCount)
{
    SNode* tpNode = nullptr;    //버킷
    SNode* tpPtr = nullptr;     //체이닝의 노드

    //원소가 한개이상 있으면 삭제
    if (*tpTotalElementCount > 0)
    {
        int tHashIndex = HashFunc(tData);
        tpPtr = &tArray[tHashIndex];
        tpNode = tpPtr->mpNext;

        while (nullptr != tpNode && tpNode->mData != tData)
        {
            tpPtr = tpNode;
            tpNode = tpNode->mpNext;
        }

        //다 찾아봤는데 못찾은 경우
        if (nullptr == tpNode)
        {
            return nullptr;
        }
        //찾은경우
        //링크 조작
        tpPtr->mpNext = tpNode->mpNext;
        //노드 삭제
        delete tpNode;
        //총 원소의 갯수 하나 감소
        (*tpTotalElementCount)--;

        return tpPtr;
    }
}
//검색
SNode* HashSearch(int tData, SNode tArray[])
{
    SNode* tpNode = nullptr;    //체이닝의 노드
         
    //O(1)
    int tHashIndex = HashFunc(tData);
    tpNode = &tArray[tHashIndex];
    //O(m)
    while (nullptr != tpNode && tpNode->mData != tData) 
    {
        tpNode = tpNode->mpNext;
    }

    return tpNode;
}

void HashList(SNode tArray[], int tLength)
{
    SNode* tpNode = nullptr;
    //버킷
    for (int ti = 0; ti < tLength; ti++)
    {
        cout << endl << ti << "Bucket : ";

        tpNode = tArray[ti].mpNext;
        //체이닝 chaining
        while (nullptr != tpNode)
        {
            cout << "  -> " << tpNode->mData;

            tpNode = tpNode->mpNext;
        }
    }

    cout << endl;
}

void Interpret(SNode tArray[], int* tpTotalElementCount, int tLength)
{
    cout << "(q: quit, ";
    cout << "i: input, ";
    cout << "l: view, ";
    cout << "s: search, ";
    cout << "d: delete )" << endl;

    char tCommand[2] = { 0,0 };
    int tKey[2] = { 0,0 };

    while (tCommand[0] != 'q')
    {
        cout << endl << "Input command ->";

        cin >> tCommand;

        switch (tCommand[0])
        {
        case 'i':
        case 'I':
        {

            cin >> tKey[0];

            HashInsert(tKey[0], tArray, tpTotalElementCount);

            cout << "\n   Successful insert.";
        }
        break;
        case 'd':
        case 'D':
        {

            cin >> tKey[0];

            if (HashDelete(tKey[0], tArray, tpTotalElementCount) == NULL)
            {
                cout << "\n   Error : Table Empty or Can't find";
            }
            else
            {
                cout << "\n   Successful delete.";
            }
        }
        break;
        case 's':
        case 'S':
        {

            cin >> tKey[0];

            SNode* tpTemp = NULL;
            tpTemp = HashSearch(tKey[0], tArray);

            if (tpTemp == NULL)
            {
                cout << "\n   Error : Can'f find that key";
            }
            else
            {
                cout << "\n   Ok! find in " << tpTemp->mData << " th position";
            }
        }
        break;
        case 'l':
        case 'L':
        {
            HashList(tArray, tLength);
        }
        break;
        }


        cout << "  n = " << *tpTotalElementCount;
    }
}


int main()
{
    std::cout << "algo_search_hash" << endl;

    SNode* tpTable = nullptr;

    int tTotalElementCount = 0;

    HashCreate(&tpTable, &tTotalElementCount, TABLE_SIZE);

    Interpret(tpTable, &tTotalElementCount, TABLE_SIZE);

    HashDestroy(tpTable, &tTotalElementCount, TABLE_SIZE);


    delete[] tpTable;

    return 0;
}


