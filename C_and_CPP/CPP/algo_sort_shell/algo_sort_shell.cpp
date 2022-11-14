

#include <iostream>
using namespace std;

//tInterval만큼 떨어진 원소들로 만들어진 부분집합에 대해 InsertionSort를 수행
void InsertionSort(int tArray[], int tBegin, int tEnd, int tInterval)
{
    int ti = 0;
    int tEdge = 0;
    int tTemp = 0;

    for (ti = tBegin + tInterval; ti <= tEnd; ti = ti + tInterval)
    {
        tTemp = tArray[ti];  
        tEdge = ti - tInterval;          
                        
        while (tEdge >= tBegin && tArray[tEdge] > tTemp)
        {            
            tArray[tEdge + tInterval] = tArray[tEdge];
            tEdge = tEdge - tInterval; 
        }
                
        tArray[tEdge + tInterval] = tTemp;

    }
}

void ShellSort(int tArray[], int tLength)
{
    int tInterval = 0;

    //두 부분집합으로 나누기 위한 간격 구하기
    tInterval = tLength / 2;

    while (tInterval >= 1)
    {
        for (int ti = 0; ti < tInterval; ++ti)
        {
            InsertionSort(tArray, ti, tLength - 1, tInterval);
        }

        //간격조정 : 이전 간격의 절반으로 설정
        tInterval = tInterval / 2;
    }
}

int main()
{
    int tArray[] = { 69,10,30,2,16 };
    int tLength = 5;

    //before
    for (auto t : tArray)
    {
        cout << t << "\t";
    }
    cout << endl;

    ShellSort(tArray, tLength);

    //after
    for (auto t : tArray)
    {
        cout << t << "\t";
    }
    cout << endl;

    return 0;
}

