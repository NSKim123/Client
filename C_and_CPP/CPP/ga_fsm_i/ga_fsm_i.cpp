
/*
    유한상태기계 FSM Finite State Machine
    라는 개념을 살펴보면서
    다음 내용들을 관찰하자.

    i 유한상태기계 개념의 숙지
    ii 함수참조테이블 의 개념
    iii 함수포인터의 클래스에서의 사용

*/

#include <iostream>
using namespace std;

void DoIdle();      //대기동작
void DoAttack();    //공격동적


int main()
{
    //step_0
    //상태를 나타내는 변수로 가정
    int tState = 0;   //0: idle state, 1: attack tate

    //상태가 결정되었다고 가정
    tState = 0;

    //해당상태에 따라 행동
    if (0 == tState)
    {
        DoIdle();
    }

    if (1 == tState)
    {
        DoAttack();
    }


    //step_1

    //상태가 결정되었다고 가정
    tState = 0;

    //해당상태에 따라 행동
    if (0 == tState)
    {
        DoIdle();
    }
    else if (1 == tState)
    {
        DoAttack();
    }


    //step_2
    //tState의 값에 따라 해당 라벨로 점프
    //그러므로, step_1과 비교하면 이것이 더욱 효율적이다.


    //상태가 결정되었다고 가정
    tState = 1;

    //해당 상태에 따라 행동
    switch (tState)
    {
    case 0:
    {
        DoIdle();
    }
    break;
    case 1:
    {
        DoAttack();
    }
    break;
    default:
        break;
    }



    //step_3
    //함수의 참조 테이블

    
    //배열 : 동일한 타입의 원소들의 연속적인 메모리 블럭, 임의접근(random access)가 가능하다.
    /*
    step_2와는 속도는 같다고 본다.

    step_2까지의 코드와 비교해보면 , OOP 적으로 좀더 좋은 코드라고 할 수 있다.
    왜냐하면, 이를테면 switch구문으로 만들어진 코드의 경우
    추가, 수정, 삭제 의 요구사항 발생시
    점점 해당 구문의 크기가 커지므로
    버그 발생의 확률이 높기 떄문이다.
    
    반면에 step_3의 코드는
    호출의 형태가 정해져 있고,
    추가, 수정, 삭제,의 요구사항 발생시
    코드 수정의 형태가 정형화되므로
    버그를 발생시킬 확률이 적다.
    */

    typedef void (*FuncPtr)();
    //함수의 참조테이블 만듦
    FuncPtr tArray[2] = { DoIdle, DoAttack };

    //상태가 결정되었다고 가정
    tState = 0;
    tArray[tState]();

    tState = 1;
    tArray[tState]();


    return 0;
}

void DoIdle()
{
    cout << "DoIdle" << endl;
}
void DoAttack()
{
    cout << "DoAttack" << endl;
}