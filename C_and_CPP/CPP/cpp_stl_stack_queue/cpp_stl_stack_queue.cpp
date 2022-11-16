

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
    stl의 stack, queue

        동작명세가 정해져 있는 자료구조

        stack : LIFO
        queue : FIFO 

*/


int main()
{
    stack<int> tStack;

    tStack.push(3);
    tStack.push(2);
    tStack.push(1);
    tStack.push(777);

    while (!tStack.empty())
    {
        cout << tStack.top() << endl;
        
        tStack.pop();
    }
    cout << endl;

    queue<int> tQueue;
    
    tQueue.push(3);
    tQueue.push(2);
    tQueue.push(1);
    tQueue.push(777);

    while (!tQueue.empty())
    {
        cout << tQueue.front() << endl;  //front, rear(back)
        
        tQueue.pop();
    }

    /*
    
    stack,queue 는 동작명세가 정해져있다. 즉, 순회 동작은 정해져 있지 않으므로 iterator 생성은 불가능하다.
    
    stack<int>::iterator titor;
    queue<int>::iterator titor;

    */


    return 0;
}


