

/*
    map

    균형이진탐색트리
        : 균형이 잡힌 이진탐색트리

*/


#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//두 원소의 데이터를 비교하는 함수객체를 위한 클래스
//템플릿으로 만들었다.
template<typename F, typename S>
class CEqualValue
{
private:
    F first;
    S second;

public:
    CEqualValue(const S& t)
        :second(t)
    {}

    bool operator()(pair<const F, S> tE)
    {
        return second == tE.second;
    }
};




typedef map<int, string> CRyuMap;
typedef CRyuMap::value_type ValueType;

int main()
{
    // 키/값 쌍의 데이터를 다루도록 만들어져 있다.
    //왜냐하면, 이진탐색트리는 중복된 데이터가 없어야 하는데, 실제 담아둘 데이터들은 중복될 수도 있으므로
    //검색용 데이터를 따로 두고 실제 데이터와 매핑해둔 것이다.

    CRyuMap tMap;  //이진탐색트리

    //------------데이터를 추가--------------
    tMap.insert(ValueType(100, "One Hundred")); //std::pair<int, string>
    tMap.insert(ValueType(3, "Three"));
    tMap.insert(ValueType(150, "One Hundred Fifty"));
    tMap.insert(ValueType(99, "Ninety nine"));
    tMap.insert(ValueType(98, "Ninety nine"));

    CRyuMap::iterator tItor;

    //데이터출력
    //map의 순회 구문은 중위순회로 설정되어 있다.
    //key에 대해서 정렬된 결과를 얻는다.  <-- 삽입과 동시에 자동으로 정렬된다.
    for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
    {
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }

    //중복된 키는 무시한다.
    tMap.insert(ValueType(99, "aaaaaaaaaaaaaaaaaa"));

    cout << endl;

    for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
    {
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }


    cout << endl;

    //연관 배열
    //배열처럼 표기법을 제공한다. 인덱스가 들어갈 자리에는 키를 넣는다. 그러면 값을 얻는다.
    cout << tMap[3].c_str() << endl;

    cout << endl;
    //배열 표기법을 사용하여 없는 키를 적용하면, 에러가 나는 것이 아니라
    //새로운 키 원소로 인식하여 추가한다.  <--그래서 주의해야 한다.
    cout << "tMap[1]: " << tMap[1].c_str() << endl;

    cout << endl;

    for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
    {
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }

    //위의 특성을 이용하면, 새로운 원소를 추가하는 표기법을 아래와 같이 간단히 할 수 있다.
    tMap[777] = "GoodGoodGood";

    cout << endl;

    for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
    {
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }

    


    //------------데이터를 검색--------------
    //이 함수의 검색 시간복잡도는 O(log n)이다.   <--- 이진탐색트리, 키로 검색
    tItor = tMap.find(777);
    if (tItor != tMap.end())
    {
        cout << endl;
        cout << "find success!!" << endl;
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }
    else
    {
        cout << endl;
        cout << "find fail.." << endl;
    }

    tItor = tMap.find(123);
    if (tItor != tMap.end())
    {
        cout << endl;
        cout << "find success!!" << endl;
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }
    else
    {
        cout << endl;
        cout << "find fail.." << endl;
    }

    //값에 대한 검색 시간복잡도는 O(n)이다.  <-- 값 데이터를 하나하나 다 비교해서 찾기 때문이다.
    //함수객체를 생성해서 넘겨줌(생성자 호출)
    tItor = find_if(tMap.begin(), tMap.end(), CEqualValue<int,string>("One Hundred Fifty"));

    if (tItor != tMap.end())
    {
        cout << endl;
        cout << "find success!!" << endl;
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }
    else
    {
        cout << endl;
        cout << "find fail.." << endl;
    }

    tItor = find_if(tMap.begin(), tMap.end(), CEqualValue<int, string>("Ninety nine"));

    if (tItor != tMap.end())
    {
        cout << endl;
        cout << "find success!!" << endl;
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }
    else
    {
        cout << endl;
        cout << "find fail.." << endl;
    }


    cout << endl;

    //------------데이터를 검색--------------
    tItor = tMap.find(3);
    if (tItor != tMap.end())
    {
        tMap.erase(tItor);
    }
        
    for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
    {
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }


    //(값을) 직접 검색
    for (tItor = tMap.begin(); tItor != tMap.end(); )
    {
        if ("GoodGoodGood" == tItor->second)
        {
            /*
                map의 erase는 다른 컨테이너와는 다르게 동작한다.
                map의 erase는 리턴값으로 반복자의 다음위치를 가리키지 않는다.
                그러므로 순회문안에서 안전한 제거를 위해 해당 구문을 사용하려면, 다음과 같이 처리해야 한다.

            */
            //tItor = tMap.erase(tItor);
            tMap.erase(tItor++);   
        }
        else
        {
            ++tItor;
        }
    }

    //delete all
    tMap.clear();

    cout << endl;
    cout << "after clear" << endl;
    for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
    {
        cout << "key: " << tItor->first << " value: " << tItor->second << endl;
    }


    return 0;
}


