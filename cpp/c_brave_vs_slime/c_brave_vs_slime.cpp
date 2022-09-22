
#include <time.h>
#include <iostream>
using namespace std;


/*

    게임 프로그램의 구조의 핵심은
    게임루프이므로 게임루프부터 작성한다.


    i) 게임 루프 구조 작성
    ii) 입력값을 문자로하자
         문자 타입 char
             <-- 실체는 '정수'
             <-- 아스키코드표 등을 참고하여 콘솔에(화면에) '문자기호'로 표시되는 타입이다.
         
             <--소스코드 상에서 ''로 감싸서 표현한다.

    
    iii) 만드려고 하는 게임월드를 표현할 데이터 디자인
        칸 들로 이루어진 세계를 가정한다
        -->'배열' 을 이용하겠다 
        <--원소의 타입은 정수로 하겠다 <--가위바위보게임에서 가위바위보를 수에 대응켰듯이 각 칸의 지형을 수로 대응시키겠다 이것은 '속성'이라 하겠다
      
      마지막 칸에 도착하면 보스 슬라임과 가위바위보 게임을 한다. (5회 승리 시 처치)
      가위 : 0, 바위 : 1, 보 : 2
      
      슬라임의 가위바위보 -> 난수

      지형'속성'
        빈곳 :            0
        용사의 집 :      100
        슬라임 출몰지역 : 1
        세상의 끝 :      200

        
*/

int main()
{
    //게임 세계
    int tWorld[5] = { 100,0,1,0,200 };

    //변수의 선언과 초기화
    char tMoveDir = 'd';
    int tPlayerRPS = 0;
    bool BossSlime = true; //보스 슬라임 유무

    //용사의 위치
    int tBraveX = 0;

    //보스 슬라임과의 가위바위보 대결에서 승리한 횟수;
    int count = 0;

    while (1)
    {
        cout << "게임종료는 n을 입력합니다." << endl;
        cout << "move(a/d)? ";
        //입력을 받는다.
        cin >> tMoveDir;

        if ('n' == tMoveDir)
        {
            cout << "게임세계를 탈출합니다." << endl;
            break;
        }

        //오른쪽 이동
        if ('d' == tMoveDir)
        {
            if (4 > tBraveX) 
            {
                tBraveX += 1;
                cout << "용사의 위치는 " << tBraveX << "입니다." << endl;
            }
            else //오른쪽 경계처리
            {
                cout << "더 이상 갈 수 없습니다." << endl;
            }
        }
        //왼쪽 이동
        if ('a' == tMoveDir)
        {
            if (0 < tBraveX)
            {
                if (BossSlime == false && 4 == tBraveX)  //마지막칸을 한 번 벗어나야만 보스 슬라임이 다시 생성되도록 하였다.
                {
                    BossSlime = true;
                }
                tBraveX -= 1;
                cout << "용사의 위치는 " << tBraveX << "입니다." << endl;
                
            }
            else //왼쪽 경계처리
            {
                cout << "더 이상 갈 수 없습니다." << endl;
            }
        }

        //용사가 있는 곳의 지형 표시
        int tAttribute = tWorld[tBraveX];

        switch (tAttribute)
        {
        case 0:
        {
            cout << "아무도 없습니다." << endl;
        }
        break;
        case 1:
        {
            cout <<"슬라임이 있는 것 같습니다." << endl;
        
        }
        break;
        case 100:
        {
            cout << "용사의 집." << endl;
        }
        break;
        case 200:
        {
            cout << "세상의 끝" << endl;
        }
        break;
        default:
            break;
        }



        if (4 == tBraveX && BossSlime == true)
        {
            cout << "보스 슬라임과의 가위바위보 게임을 시작합니다. 보스 슬라임을 5번 이기십시오." << endl;
            while (5 > count)
            {
                srand((unsigned int)time(nullptr));
                int tAIRPS = rand() % 3;

                cout << "가위바위보를 입력하세요(0:가위, 1 : 바위, 2 : 보) <현재 이긴횟수: " << count << " >" << " : ";
                cin >> tPlayerRPS;

                switch (tPlayerRPS)
                {
                case 0: //플레이어: 가위
                {
                    switch (tAIRPS)
                    {
                    case 0: //AI : 가위
                    {
                        cout << "무승부, player : 가위, ai : 가위" << endl;
                    }
                    break;
                    case 1: //AI : 바위
                    {
                        cout << "패, player : 가위, ai : 바위" << endl;
                    }
                    break;
                    case 2: //AI : 보
                    {
                        cout << "승, player : 가위, ai : 보" << endl;
                        count++;
                    }
                    break;

                    default:
                        break;
                    }
                }
                break;
                case 1:
                {
                    switch (tAIRPS)
                    {
                    case 0:
                    {
                        cout << "승, player : 바위, ai : 가위" << endl;
                        count++;
                    }
                    break;
                    case 1:
                    {
                        cout << "무승부, player : 바위, ai : 바위" << endl;
                    }
                    break;
                    case 2:
                    {
                        cout << "패, player : 바위, ai : 보" << endl;
                    }
                    break;

                    default:
                        break;
                    }
                }
                break;
                case 2:
                {
                    switch (tAIRPS)
                    {
                    case 0:
                    {
                        cout << "패, player : 보, ai : 가위" << endl;
                    }
                    break;
                    case 1:
                    {
                        cout << "승, player : 보, ai : 바위" << endl;
                        count++;
                    }
                    break;
                    case 2:
                    {
                        cout << "무승부, player : 보, ai : 보" << endl;
                    }
                    break;

                    default:
                        break;
                    }
                }
                break;
                }
            }
            count = 0;
            cout << "보스 슬라임 처치!" << endl;
            BossSlime = false;
        }
        
        
        
    }

    return 0;
}

