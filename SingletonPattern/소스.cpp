#include <iostream>



class SingletonTest {
public:
	static void Create();
	static void Delete();
	static SingletonTest* Get();
	void heal() { std::cout << "����" << std::endl; }
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
	//�̱��� ����� ���������ʴ´��ϸ� �� ������ �ʴ´� �Ѵ�.
	//������������� �ʱ�ȭ�� ���־���Ѵ�.
	//���ϸ� �������� ����������, �޸𸮿� ��ϵ� �ȵǰ�, �ʱ�ȭ�� ���־���Ѵٰ� �Ѵ�.(���� �̻��ѵ�)
	SingletonTest::Create();

	SingletonTest::Get()->heal();


	SingletonTest::Delete();

	return 0;
}
