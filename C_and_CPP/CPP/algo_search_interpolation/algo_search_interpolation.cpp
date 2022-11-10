/*
    이분검색(이진검색) interpolation search

*/

#include <iostream>
using namespace std;

void DoBinarySearch(int tArray[], int tBegin, int tEnd, int tData)
{
    int tIndexMiddle = 0;

    tIndexMiddle = (tBegin + tEnd) / 2;

    if (tArray[tIndexMiddle] == tData)
    {
        //base case
        cout << "검색성공" << endl;
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
    return 0;
}
