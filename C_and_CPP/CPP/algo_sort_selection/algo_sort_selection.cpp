

#include <iostream>
using namespace std;

//선택정렬, 오름차순 정렬(작은 것부터 큰 것 순으로)
void SelectionSort(int tArray[], int tLength)
{
    int ti = 0;
    int tj = 0;

    int tMin = 0;
    int tTemp = 0;

    for (ti = 0; ti < tLength - 1; ++ti)
    {
        //기준위치 선정(일단 이것이 가장 최소값이라고 가정하고 시작한다 라는 의미)
        tMin = ti;

        //기준위치 이후에 있는 원소들과 비교할 것이므로
        for (tj = ti + 1; tj < tLength; ++tj)
        {
            //기준위치 이후에 있는 원소가 더 작다면 그것이 바로 최소값
            if (tArray[tMin] > tArray[tj])
            {
                //최소값 갱신
                tMin = tj;
            }
        }

        //여기까지오면 '선택selection'인 것이다.
        if (tMin != ti)
        {
            //교환 swap
            tTemp = tArray[ti];    //기준위치의 원소의 값
            tArray[ti] = tArray[tMin];    //선택한 최솟값
            tArray[tMin] = tTemp;
        }
    }
}



int main()
{
    int tArray[] = {69, 10 , 30, 2, 16};
    int tLength = 5;

    //before
    for (auto t : tArray)
    {
        cout << t << "\t";
    }
    cout << endl;

    SelectionSort(tArray, tLength);

    //after
    for (auto t : tArray)
    {
        cout << t << "\t";
    }
    cout << endl;



    return 0;
}


