#include <iostream>



class SingletonTest {
public:
	static void Create();
	static void Delete();
	static SingletonTest* Get();
	void heal() { std::cout << "힐띠" << std::endl; }
private:
	static SingletonTest* instance;
};
SingletonTest* SingletonTest::instance=nullptr;
void SingletonTest::Create()
{
	if (instance == nullptr) {
		instance = new SingletonTest();
	}
}

void SingletonTest::Delete()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

SingletonTest* SingletonTest::Get()
{
	return instance;

}
int main() {
	//싱글톤 사용은 권장하지않는다하며 잘 쓰지도 않는다 한다.
	//정적멤버변수는 초기화를 해주어야한다.
	//안하면 전역으로 쓸수없으며, 메모리에 등록도 안되고, 초기화도 해주어야한다고 한다.(말이 이상한데)
	SingletonTest::Create();

	SingletonTest::Get()->heal();


	SingletonTest::Delete();

	return 0;
}
