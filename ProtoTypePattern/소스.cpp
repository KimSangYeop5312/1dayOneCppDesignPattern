#include <iostream>
class Monster {
public:
	virtual void Heal() {}
};
class Zomb :public Monster {
public:
	void Heal() { std::cout << "DASDASDAS" << std::endl; }
};

class Spawner {
public:

	virtual ~Spawner() {}
	virtual Monster* spawners() = 0;

};

template <class T>
class SpawnerFor :public Spawner {
public:
	Monster* spawners() {
		return new T();
	}
};

int main() {
	//������Ÿ�������� ���𰡸� �������ְ������ ����ϴµ�, �������� �̿��Ͽ�
	//���� �������� Ŭ�������� �����ʸ� ���������ʿ���� �����ϰ� ������ ������ټ��ִ�.
	//�����ϴ�.

	SpawnerFor<Zomb>* sp = new SpawnerFor<Zomb>();

	Monster* zb = sp->spawners();
	zb->Heal();

	return 0;
}