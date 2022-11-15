

#include <iostream>
using namespace std;


//파티셔닝을 하고 피벗 인덱스를 리턴
int DoPartition(int tArray[], int tBegin, int tEnd)
{
    int tPivot = 0;     //분할의 기준점
    int L = 0;          //왼쪽 집합의 지시자 인덱스
    int R = 0;          //오른쪽 집합의 지시자 인덱스

    int tTemp = 0;      //교환을 위한 임시메모리 변수

    L = tBegin;         //<-- 처음에 왼쪽 집합 지시자는 왼쪽 집합의 왼편 끝에서부터 시작한다.
    R = tEnd;           //<--처음에 오른쪽 집합 지시자는 오른쪽 집합의 오른편 끝에서 시작한다.

    //가운데 위치의 것을 피벗으로 선정
    tPivot = (tBegin + tEnd) / 2;

    while (L < R)
    {
        //적합한 L을 찾는다.
        while (tArray[L] < tArray[tPivot] && L < R)
        {
            L++;
        }
        //적합한 R을 찾는다.
        while (tArray[R] >= tArray[tPivot] && L < R)
        {
            R--;
        }
        
        //여기까지 왔다면,
        //tArray[L] >= tArray[tPivot]   <-- 즉, tArray[L] 이라는 것은 피벗의 오른쪽에 있어야 한다는 것이다.
        //tArray[R] < tArray[tPivot]    <-- 즉, tArray[R] 이라는 것은 피벗의 왼쪽에 있어야 한다는 것이다.

        if (L < R)
        {
            tTemp = tArray[L];
            tArray[L] = tArray[R];
            tArray[R] = tTemp;

            if (L == tPivot)
            {
                //before
                //    L                 R
                //  pivot
                // 
                //after
                //    L                 R
                //                    pivot
                tPivot = R;
            }
        }
    }

    //L==R
    //값 교환 R을 피벗으로 가정한다 (이제 다른 부분집합을 위해서다)
    tTemp = tArray[tPivot];
    tArray[tPivot] = tArray[R];
    tArray[R] = tTemp;




    return R;
}

void QuickSort(int tArray[], int tBegin, int tEnd)
{
    int tPivot = 0;

    //tBegin >= tEnd 라면 우너소가 하나이므로 더 이상 쪼갤 수 없음
    //tBegin < tEnd 이면 부분집합으로 쪼갤 수 있음
    if (tBegin < tEnd)
    {
        //파티셔닝 partitioning
        //이 예시에서 pivot은 가운데 위치에 있는 것으로 하겠다.
        tPivot = DoPartition(tArray, tBegin, tEnd);

        QuickSort(tArray, tBegin, tPivot - 1);
        QuickSort(tArray, tPivot + 1, tEnd);
    }
}


int main()
{
    int tArray[] = { 69,10,30,16,2 };
    int tLength = 5;

    for (auto t : tArray)
    {
        cout << t << "\t";
    }
    cout << endl;

    QuickSort(tArray, 0, tLength - 1);

    for (auto t : tArray)
    {
        cout << t << "\t";
    }
    cout << endl;

    return 0;
}


