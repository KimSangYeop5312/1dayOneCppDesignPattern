#include "헤더.h"
Actor* actZomb = new Zombie();
int main() {
	//명령패턴 
	//한 플레이어가 있다고 치면 계속 핸들러를 불러오면서 각 키에 할당된 명령을 저장하고있다가.
	//핸들러를 불러오면서 그 명령을 가져오고, 그게 존재한다면 excute해서 그명령을 시행한다.
	//핸들러는 각 키에 할당된 명령을 리턴해주는것 뿐이다.
	//만약에 어떤 키를 변경시킨다 하면 AKey에 할당된 명령을 변경해주면 명령을 시행했을때 내용도 달라진다.
	//거의 콜백이라고 한다. 그러나 객체지향화?한 콜백이라고 한다.

	//클라이언트가 인보커를 통해서 각버튼들에 해당하는 커맨드값을 설정한다.
	//그리고 클라이언트를 통해 리시버를 행동하게 한다.
	//인보커는 각버튼의 커맨드를 세팅한다.
	//커맨드는 리시버가 행동을 하게 전달하는 역할을 한다.
	//버튼의 행위를 한다.
	//리시버는 행동을 한다.

	//활용
	//1.세팅에서 설정해준 키대로 조작을 시켜줄때
	//좀비생성
	Handler* hand = new Handler();//핸들러 생성
	Command* temp = hand->handler1();//핸들러를 통해서 현재가 A키라면 A키가 가진 현재 할당된 기능을 가져온다.
	Command* temp2 = hand->handler2();//핸들러를 통해서 현재가 A키라면 A키가 가진 현재 할당된 기능을 가져온다.
	//-----------------------------
	
	//이사이에 어떠한 처리를 해줄수도 있겠다.

	//------------------------------
	if (temp) {
		temp->excute(*actZomb);//그 기능을 시행한다.
	}
	if (temp2) {
		temp2->excute(*actZomb);
		std::cout << actZomb->GetX() << " " << actZomb->GetY() << std::endl;

	}
	if (temp2) {
		temp2->Undo();
		std::cout << actZomb->GetX() << " " << actZomb->GetY() << std::endl;
	}
	return 0;
}

Command* Handler::handler1()
{
	if (testChar == 'A') {
		return AKey;
	}
	else {
		return BKey;
	}
	return nullptr;
}

Command* Handler::handler2()
{
	if (testChar == 'A') {
		return new MoveTurnCommand(actZomb, 5, 5);
	}
}
