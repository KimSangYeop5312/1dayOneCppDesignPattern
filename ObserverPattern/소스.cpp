#include <iostream>
#include <vector>

using namespace std;

class Observer {
public:
	int who = 0;
	virtual void Update() = 0;

};
class SeeMan:public Observer {
public:
	
	void Update() { cout << "나는 방송  을! 봤다"<< who << endl; }
};

class MainMan {//시스템 
public:
	void addObserver(Observer* ob) { observer.push_back(ob); }
	void deleteObserver(Observer* ob) { observer.erase(observer.begin() + (find(observer.begin(),observer.end(),ob)-observer.begin())); }
protected:
	void notify() {
		for (Observer* temp : observer) {
			temp->Update();
		}
	}
private:
	vector<Observer*> observer;
};

class gaga : public MainMan {
public:
	void change() { notify(); }
};
int main() {
	//관찰자 시스템은 관찰자를 등록하고 관찰자의 메인이 되는 객체가 변화가 생기면 change함수를 호출하여
	//등록된 관찰자 객체들에게 바뀌었다 라고 알려주는 것이다.
	//각 객체가 커플링이 되지않도록 방지해주기도 하고, 꼬이지않게 도와주는거 같다.
	//만약 gaga 객체가 변경이 일어나면 스스로 change를 호출하여 다른 등록된 관찰자들에게 전달해주는 형식이다.
	//아주 좋다. 아주
	gaga* tempGa = new gaga();
	
	Observer* seeman1 = new SeeMan();
	seeman1->who = 1;
	Observer* seeman2 = new SeeMan();
	seeman2->who = 2;
	Observer* seeman3 = new SeeMan();
	seeman3->who = 3;

	tempGa->addObserver(seeman1);
	tempGa->addObserver(seeman2);
	tempGa->addObserver(seeman3);
	tempGa->change();

	tempGa->deleteObserver(seeman2);
	tempGa->change();



	return 0;
}