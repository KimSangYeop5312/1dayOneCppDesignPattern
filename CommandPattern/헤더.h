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

class Zombie : public Actor {//리시버
public:
	void Jump() { std::cout << "좀비가 점프를 했다?" << std::endl; }
	void Move() { std::cout << "좀비가 움직였다?" << std::endl; }
};

class Command {
public:
	virtual ~Command() {}
	virtual void excute(Actor& act) = 0;
	virtual void Undo() = 0;
};

class JumpCommand :public Command {//커맨드
public:
	virtual void excute(Actor& act) {
		act.Jump();
	}
	void Undo() {}
};

class MoveCommand : public Command {//커맨드
public:
	virtual void excute(Actor& act) {
		act.Move();
	}
	void Undo() {}
};

class MoveTurnCommand : public Command {//커맨드
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


class Handler {//클라이언트
public:
	Handler() { AKey = new MoveCommand();  BKey = new JumpCommand(); }
	Command* handler1();
	Command* handler2();
private:
	Command* AKey;
	Command* BKey;
	char testChar = 'A';
};


