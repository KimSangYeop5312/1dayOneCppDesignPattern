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
	//프로토타입패턴은 무언가를 생성해주고싶을때 사용하는데, 다형성을 이용하여
	//굳이 여러개의 클래스마다 스포너를 생성해줄필요없이 간단하게 저렇게 사용해줄수있다.
	//간단하다.

	SpawnerFor<Zomb>* sp = new SpawnerFor<Zomb>();

	Monster* zb = sp->spawners();
	zb->Heal();

	return 0;
}