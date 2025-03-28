// char : 1
// short : 2
// int : 4
// __int64 (long long) : 8

float F; // 근사치를 표현
double D; // float보다 정밀함

const int SCISSORS = 0; // 상수
const int ROCK = 1;
const int PAPER = 2;
enum ENUM_RSP // 열거형
{
	BSP_SCISSORS = 0,
	BSP_ROCK = 1,
	BSP_PAPER = 2
};
#define DEF_SCISSORS 0 // 매크로 - 권장x 
#define DEF_ROCK 1
#define DEF_PAPER 2

// 전역 변수 - 메모리의 Data 영역에 저장
// 지역 변수 - Stack 영역에 저장 

// Stack = 높은 주소에서 늘어났다 줄었다하면서 정보를 교환하는 함수들끼리의 공용 공간
// 매개변수 - 반환주소값 - 지역변수는 Stack에 저장
// 함수가 호출될 때 컴파일러에서 높은 주소부터 공간을 할당해줌
// 함수가 종료될때 돌아가야 할 주소를 저장함

// 레지스터 - CPU의 손발 역할
// RSP, RBP(Stack 데이터의 주소의 기준점이 되는 일종의 닻)
// 참조, 복사 -> 모든 건 복사가 일어남, 원본이 바뀌는 건 아님 (포인터 전)

// 디버그 모드 - F10(한 줄씩 but 외부함수는 실행 x), F11(한 줄씩 실행)
// F9 - 중단점 지정, 우클릭시 조건 지정 가능
// 호출 스택 - 스택에서 함수의 호출을 확인

// 영역선택 후 Ctrl-M-O를 누르면 함수를 접을 수 있음




// 포인터는 주소값을 담는 바구니
// *는 8바이트 고정
// 포인터 타입의 변수 앞의 *는 주소값을 타고 이동한다는 의미
// 포인터 앞의 타입은 주소값을 타고 가면 그 자료형이 있다는 의미
// 1) 원본 데이터를 건드리고 싶을때
// 2) 복사하는 비용을 아끼고 싶을 때

// 포인터 연산
// - 주소 연산자 (&) / - 산술 연산자(+-) / - 간접 연산자 (*) / - 간접 멤버 연산자 (->)
// 포인터에 덧셈, 뺄셈을 할 경우 데이터 크기 만큼 값이 증가함
// 배열 *ptr = numbers[0], *(ptr + 3) = numbers[3];
// 구조체 (*ptr).hp == ptr->hp

// const char* a : 데이터를 상수화
// char* const a : 주소값을 상수화

// & 참조 : 코드 내부 동작은 포인터와 사실살 동일, 문법은 일반 복사와 동일함
// 비어있는 참조는 만들 수 없음, 일종의 별명
// const + &참조 : 데이터를 수정할 의향이 없을때




// 객체 지향(OOP) ( 데이터 + 로직 )
// 참고)객체지향 3대 요소  - 상속성 / - 은닉성 / - 다형성

// class는 일종의 설계도, 붕어빵 틀 (멤버 변수, 내부에 함수도 선언 가능 >> 멤버함수)
// 멤버함수 내에서 멤버변수는 포인터 없이 접근 가능, 주소값을 알고 있기 때문에
// (Knight->_hp 와 같은 코드가 숨겨져 있음), this로 표현

// 클래스를 사용해서 샘플을 만든 것은 객체, 인스턴스	>> Knight k1
// 클래스 내의 정보들은 특정 객체에 종속적이며 객체마다 하나씩 가지고 있는 정보

// 생성자 : 어떤 객체가 만들어질때 무조건 호출되는 함수, 일종의 입장, 초기값세팅
// 소멸자 : 객체가 소멸될 때 호출됨, 일종의 퇴장
// 복사 생성자 : 자신과 같은 타입의 생성자를 복사해줌

// 상속성 : 자식 클래스는 부모 클래스의 내용물을 그대로 사용가능
// 상속 문법 - class (자식 클래스) : public (부모 클래스)

// 상속 사용할때 is-A, Has-A 잘 생각하기 ( 겹친다고 무조건 상속 X
// Knight is a player(상속), Archer has a inventory(컴포넌트)

// 은닉성(캡슐화) : 필요한 정보만 보여주겠다
// 접근지정자 - public(보안 가장약함) / protected(자식클래스에서 사용가능한 private) / private
// _hp 같은 멤버변수들은 private으로 만들고 public에서 GetHp 같이 간접적으로 수정하는 것이 좋음

// 상속에서 사용하는 접근 지정자 :
// public(대부분) - 그대로 사용 / protected는 비슷 / private - 이후 상속에서는 상속 불가

// 다형성 : 겉은 같지만 상황에 따라서 다르게 동작한다
// 오버로딩 : 함수 이름의 재사용 
// 오버라이딩(☆) : 부모클래스의 함수를 자식클래스에서 재정의

// 바인딩(Binding) = 묶는다
// 정적(static) 바인딩 - 컴파일 시점에 결정 (일반 함수)
// 동적(dynamic) 바인딩 - 실행 시점에 결정 (virtual{가상함수} 이용)

// virtual을 함수에 붙이면 상속된 함수도 virtual을 붙인걸로 동작(하지만 붙이는게 좋음)
// 부모클래스에서 소멸자를 생성할 때도 앞에 virtual을 붙여줘야함
// virtual된 함수명 뒤에 override를 붙이면 부모클래스에서 virtual을 붙이지 않았을 때 에러로 잡아줌(권장)

// 순수 가상함수 : 가상함수이지만 구현부가 없고 나중에 상속 받는 클래스가 알아서 만들어야함
// virtual (타입) (함수명) = 0; 또는 virtual (타입) (함수명) abstract;
// 순수 가상함수가 한 개 이상 들어있는 클래스는 추상 클래스로 간주
// 추상클래스는 직접 호출 불가 (상속을 통해서만) / 클래스 내의 가상함수 부분을 구현하지 않으면 에러
// 어떤 인터페이스를 구현해야하는것을 명시하고 싶을 때 사용


// 멤버 변수를 초기화할때는 생성자 옆에서 초기화하는 것이 효율적임 
// 생성자 안에선 초기화 지양 -> 선처리영역에서 이중으로 처리
// Knight() : _hp(0), _inventory(100) { ... }
// 생성자 끼리도 호출가능

// 연산자 오버로딩 : 연산자를 자기 맘대로 커스텀할 수 있다
// - 멤버 연산자 함수 ) a (연산자) b 형태에서 왼쪽을 기준으로 실행
// - 전역 연산자 함수 ) a (연산자) b 형태라면, a b 모두를 연산자 함수의 피연산자로 사용

// 대입 연산자 (※참고)
// 같은 줄에 선언과 동시에 =을 통해 값을 넣는것은 생성자를 이용하는 것임
// 생성자 앞에 explicit을 붙일 경우 대입 연산 시 컴파일러에 의한 간접적인 변화가 다 막힘 -> 의도하지 않은 변환 방지
// = 인자를 받아주는 생성자를 만들 때 유용하게 사용
// 자신의 참조가 함수타입인 함수를 만들 때 *this를 리턴값으로 사용

// struct vs class
// struct는 복사, class는 참조로 값이 전달 됨, 사실 C++에서는 미묘한 차이
// 접근 지정자를 안 붙였을 때 struct는 기본적으로 public, class는 private로 간주 된다는 정도
// struct는 여러 데이터를 모아서 관리, class는 객체지향 용도로 활용

// static 
// (☆) 특정 객체와는 무관하며 모든 객체가 값을 공유함, 일종의 전역변수
// 
// 나중에 등장할 것임을 예고하는 역할이기 때문에 선언할때 초기화하면 안됨
// 클래스 밖에서 '(타입) (클래스명)::(선언한 변수명) = (값);' 형태로 초기화
// 함수에 static을 붙이면 클래스::함수명으로 바로 접근가능
// static 함수 안에서 멤버변수를 고치려고 하면 안됨, (☆) static함수 안에는 static 변수만
// 
// 정리 ) 특정 객체와 연관성이 없으면 전역함수처럼 static 붙여서 사용,
// 클래스 안에 포함되어 있지만 어떤 특정 객체와는 연관이 없다

// 싱글톤 : 딱 1개만 존재하고 어디서든 사용할 수 있음, 매니저 클래스 등을 만들 때 쓰는 디자인기법
// 전역변수처럼 동작하는 기능을 만들고 싶을 때 사용


// 다중상속 - 현대 컴퓨터 언어에서는 막아놓음
// 인터페이스 문법으로 간접적으로 구현 -> 인터페이스 클래스를 만들고 함수를 순수가상함수로 만듬
// -> 상속받는 클래스에서 함수 구현을 강제함



// 동적할당 : 실시간으로 요청하여 메모리 할당을 받아서 사용 - 힙 영역
// malloc + free(C) - free로 메모리를 해제하지 않으면 누수가 일어남
// new + delete(C++) - new와 delete는 동적할당 시 생성자와 소멸자 호출
// 둘의 차이 : malloc은 생성자 호출해주지 않음

// 메모리를 해제해도 믈리적으론 메모리를 유지하고 있음 -> 메모리를 새롭게 할당 시 문제 발생 (Use-AfterFree 문제)
// 주소값을 날리는 것으로 부분적으로 해결 가능
// nullptr를 쓸때는 항상 null 체크하기


// C스타일 캐스팅
// - 값 타입 변환 : 의미를 유지하기 위해 원본 객체와 다른 비트열 재구성
// - 참조 타입 변환 : 원본 객체의 메모리를 동일하게 넘겨줌
// 바이트 수가 더 큰 자료형으로 캐스팅하는 건 안전함(의미 일치)
// 암시적 변환, 명시적 변환


// 클래스 내에서 포인터 타입으로 변수를 만들면 
// 객체는 별도로 있지만 클래스가 변수의 정보를 가리키고 있다고 정의
// 소멸자에 virtual을 붙이지 않으면 상위 클래스로 동적할당을 했을 때
// 상위 클래스의 소멸자만 호출함 -> 소멸자에 메모리 해제 같은 기능 있을 시 누수 발생

// 전방선언 : 헤더파일에 include를 하면 내용을 다 가져오기 때문에 코드가 무거워짐 + 헤더가 꼬일 수 있음
// 따라서 class Item;과 같이 나중에 등장할 개념을 예고만 해주는 것
// 세부적인 사항은 못 건드림
// = 헤더에는 include를 자제하고 cpp소스에만 헤더를 include 해준다

// 얕은 복사 vs 깊은 복사 : 포인터를 같은 포인터로 가리키게 하지 않아야함
// 앝은 복사 : 값 자체를 일일이 복사
// 깊은 복사 : 동일한 참조값을 가리키지 않게 끊음

// 캐스팅 4총사
// (☆)static_cast : 타입원칙에 비춰볼때 상식적인 캐스팅만 허용
//		1) int <--> float
//		2) 부모와 자식 간의 상속관계
// (☆)dynamic_cast : 상속 관계에서의 안전 변환 
//		다형성을 활용하는 방식(virtual)
//		RTTI (RunTime Type Infomation)
// const_cast : const를 넣었다 뺐다 할 수 있음
// reinterpert_cast : 어떤 포인터를 전혀 관계없는 타입으로 변환할 때 사용


// - 버그 유형들
// NULL 크래시 - 프로그램이 뻗었을 때 매우 높은 확률로 원인
//	프로그램이 NULL값을 참조했을 때 발생 -> 항상 null포인터 체크
// 정수 오버(언더)플로우
// 메모리 누수
// 메모리 오염
//	- Use-After-Free / - 버퍼 오버플로우 / - 캐스팅


// 연결리스트 : 다양한 노드로 구성 <MazeProject 참조>
// [n1] <-> [n2] <-> [n3] <-> [n4] <-> [n5] : 맨 첫 번째 방(n1)을 헤드라고 부름, 맨 끝은 테일
// 양방향 리스트로 만드는게 일반적
// 헤드와 테일을 기억
// (☆)연결리스트에서 특정 노드 위치를 알고 있을때만 노드 삽입/삭제가 빠르다
// 각각의 노드를 찾는 코드를 사용하면 속도의 이점을 못 살림

// 배열(용량이 변하지 않을 때, ex)맵), 동적배열(빠름, 데이터들이 뭉쳐있어서) vs 연결리스트(중간 데이터를 삽입,삭제해야할때)
//								    vector								 list