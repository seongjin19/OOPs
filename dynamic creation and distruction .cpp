#include <iostream>
#include <string>

using namespace std;
//동적으로 객체를 생성하는 이유:
//
//동적으로 객체를 생성하는 경우와 아닌 경우의 차이: 메모리 영역의 차이.
//동적으로 객체를 생성하는 경우 - 힙 영역
//동적으로 객체를 생성하지 않을 경우 - 스택 영역
//
//스택 영역
//- 함수내에 정의된 지역 변수가 저장되는 영역/ 함수는 last in first out 형태의 구조를 가지고 있음.
//- 범위를 벗어날 경우 메모리 자동 해제.
//
//힙 영역
//- 동적 할당을 통해 생성된 동적 변수를 관리하기 위한 영역.
//- 직접 해제하기 전까진 메모리에 유지
//
//스택영역은 컴파일러가 미리 공간 예측. 함수에서 잠깐 쓰고 메모리 해제.
//동적 변수의 경우에는 메모리가 어느정도 할당될 지 모르기 때문에 프로그램 실행중에 결정됨.
//따라서 프로그램 내에서 해당 변수를 계속 사용해야 하는 경우 힙 영역을 사용하는 것이 좋음.
class Car
{
public:
	int speed;
	int gear;
	string color;

	void speedUp()
	{
		speed += 10;
	}
	void speedDown()
	{
		speed -= 10;
	}
	
};
int main(void)
{
	Car * mycar = new Car; //객체의 동적 생성
	mycar->speed = 100; // 멤버변수가 public이라 메인함수에서 접근 가능.
	mycar->gear = 3;
	mycar->color = "red";
	mycar->speedUp();
	mycar->speedDown();

	delete mycar; //객체 동적 삭제

}