/*
    이분검색(이진검색) interpolation search

        정렬되어있는 자료들에 대해 이분하여 검색의 범위를 반씩 줄여가며 검색하는 방법

        시간복잡도 : O(log n)
        공간복잡도 : n
*/

#include <iostream>
using namespace std;

int gCount = 0;

void DoBinarySearch(int tArray[], int tBegin, int tEnd, int tData)
{
    int tIndexMiddle = 0;

    gCount++;

    //base case
    //원소가 1개인 경우 <-- 더이상 이분할 수 없는 상태
    if (tBegin == tEnd)
    {
        if (tData == tArray[tBegin])
        {
            cout << "--검색 성공" << endl;
            cout << "--gCount: " << gCount << endl;
        }
        else
        {
            cout << "--검색 실패" << endl;
        }

        return;
    }

    tIndexMiddle = (tBegin + tEnd) / 2;

    if (tArray[tIndexMiddle] == tData)
    {
        //base case
        cout << "검색성공" << endl;
        cout << "gCount: " << gCount << endl;
    }
    else if(tArray[tIndexMiddle] > tData)
    {
        //recursive case
        DoBinarySearch(tArray, tBegin, tIndexMiddle - 1, tData);
    }
    else if(tArray[tIndexMiddle] < tData)
    {
        //recursive case
        DoBinarySearch(tArray, tIndexMiddle + 1, tEnd , tData);
    }
    else
    {
        //base case
        cout << "검색실패" << endl;
    }

}


int main()
{
    int tArray[] = { 1,2,8,9,11,19,29 };
    int tLength = 7;

    int tData = 29;
    DoBinarySearch(tArray, 0, tLength - 1, tData);


    return 0;
}
