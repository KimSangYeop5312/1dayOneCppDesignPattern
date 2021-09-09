#pragma once

#include <iostream>

class Actor {
public:
	virtual ~Actor() {}
	virtual void Jump() = 0;
	virtual void Move() = 0;
	virtual int GetX() { return x; }
	virtual int GetY() { return y; }
	virtual void Move(int x, int y) { this->x=x; this->y = y; }
protected:
	int x = 0;
	int y = 0;
};

class Zombie : public Actor {//���ù�
public:
	void Jump() { std::cout << "���� ������ �ߴ�?" << std::endl; }
	void Move() { std::cout << "���� ��������?" << std::endl; }
};

class Command {
public:
	virtual ~Command() {}
	virtual void excute(Actor& act) = 0;
	virtual void Undo() = 0;
};

class JumpCommand :public Command {//Ŀ�ǵ�
public:
	virtual void excute(Actor& act) {
		act.Jump();
	}
	void Undo() {}
};

class MoveCommand : public Command {//Ŀ�ǵ�
public:
	virtual void excute(Actor& act) {
		act.Move();
	}
	void Undo() {}
};

class MoveTurnCommand : public Command {//Ŀ�ǵ�
public:
	MoveTurnCommand(Actor* act, int x, int y) : act(act), x(x), y(y),bex(0),bey(0) {}
	virtual void excute(Actor& act) {
		bex = act.GetX();
		bey = act.GetY();
		act.Move(x, y);
	}
	void Undo() {
		act->Move(bex, bey);
	}

private:
	Actor* act;
	int x;
	int y;
	int bex;
	int bey;
};


class Handler {//Ŭ���̾�Ʈ
public:
	Handler() { AKey = new MoveCommand();  BKey = new JumpCommand(); }
	Command* handler1();
	Command* handler2();
private:
	Command* AKey;
	Command* BKey;
	char testChar = 'A';
};


