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
	
	void Update() { cout << "���� ���  ��! �ô�"<< who << endl; }
};

class MainMan {//�ý��� 
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
	//������ �ý����� �����ڸ� ����ϰ� �������� ������ �Ǵ� ��ü�� ��ȭ�� ����� change�Լ��� ȣ���Ͽ�
	//��ϵ� ������ ��ü�鿡�� �ٲ���� ��� �˷��ִ� ���̴�.
	//�� ��ü�� Ŀ�ø��� �����ʵ��� �������ֱ⵵ �ϰ�, �������ʰ� �����ִ°� ����.
	//���� gaga ��ü�� ������ �Ͼ�� ������ change�� ȣ���Ͽ� �ٸ� ��ϵ� �����ڵ鿡�� �������ִ� �����̴�.
	//���� ����. ����
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