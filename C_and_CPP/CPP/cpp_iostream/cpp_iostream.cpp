
//헤더 파일 : 함수의 선언들이 담겨 있는 파일

//cpp에서 헤더파일 포함 구문에는 확장자를 적어주지 않는다.
#include <iostream>
#include <stdio.h>

/*
    console application
    문자열의 입출력으로 진행되는 프로그램 형식.

    여기서 입출력
    을 처리하는 역할을 하는 것

    C언어에서는 함수로 만들어져서 제공된다.
    CPP언어에서는 객체(연산자 포함)로 만들어져서 제공된다.

    버퍼buffer :
    임의의 처리를 기다리며 대기하기 위해 담아두는 메모리 공간.

    i)입력버퍼 : 이를테면 키보드 등의 '입력장치'의 입력으로 문자들을 받아 응용프로그램의 처리를 위해 잠시 대기시켜 두는 메모리
    ii)출력버퍼 : 이를테면 응용프로그램의 출력으로 문자들을 받아 출력장치(예 : 모니터)에서의 처리를 위해 잠시 대기시켜 두는 메모리

*/

int main()
{
    //함수다
    printf("%s\n", "I am a Good Boy.");

    //'객체Object'와 '연산자'로 표현한다. 함수가 아니다.
    std::cout << "I am a Good Boy." << std::endl;

    int tinput = 0;
    //함수다.
    scanf_s("%d", &tinput);
    printf("%d\n", tinput);

    std::cin >> tinput;
    std::cout << tinput << std::endl;





    return 0;
}

