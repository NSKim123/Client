
/*
    priority queue
    우선순위 큐

*/
#include <iostream>
#include <queue>
using namespace std;


int main()
{
    //priority_queue 기본설정은 최대힙
    priority_queue<int> tPriortyQ;

    tPriortyQ.push(8);
    tPriortyQ.push(1);
    tPriortyQ.push(6);
    tPriortyQ.push(2);

    while(!tPriortyQ.empty())
    {
        cout << tPriortyQ.top() << endl;

        tPriortyQ.pop(); //8,6,2,1
    }




    return 0;
}

