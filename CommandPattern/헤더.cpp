#include "���.h"
Actor* actZomb = new Zombie();
int main() {
	//������� 
	//�� �÷��̾ �ִٰ� ġ�� ��� �ڵ鷯�� �ҷ����鼭 �� Ű�� �Ҵ�� ����� �����ϰ��ִٰ�.
	//�ڵ鷯�� �ҷ����鼭 �� ����� ��������, �װ� �����Ѵٸ� excute�ؼ� �׸���� �����Ѵ�.
	//�ڵ鷯�� �� Ű�� �Ҵ�� ����� �������ִ°� ���̴�.
	//���࿡ � Ű�� �����Ų�� �ϸ� AKey�� �Ҵ�� ����� �������ָ� ����� ���������� ���뵵 �޶�����.
	//���� �ݹ��̶�� �Ѵ�. �׷��� ��ü����ȭ?�� �ݹ��̶�� �Ѵ�.

	//Ŭ���̾�Ʈ�� �κ�Ŀ�� ���ؼ� ����ư�鿡 �ش��ϴ� Ŀ�ǵ尪�� �����Ѵ�.
	//�׸��� Ŭ���̾�Ʈ�� ���� ���ù��� �ൿ�ϰ� �Ѵ�.
	//�κ�Ŀ�� ����ư�� Ŀ�ǵ带 �����Ѵ�.
	//Ŀ�ǵ�� ���ù��� �ൿ�� �ϰ� �����ϴ� ������ �Ѵ�.
	//��ư�� ������ �Ѵ�.
	//���ù��� �ൿ�� �Ѵ�.

	//Ȱ��
	//1.���ÿ��� �������� Ű��� ������ �����ٶ�
	//�������
	Handler* hand = new Handler();//�ڵ鷯 ����
	Command* temp = hand->handler1();//�ڵ鷯�� ���ؼ� ���簡 AŰ��� AŰ�� ���� ���� �Ҵ�� ����� �����´�.
	Command* temp2 = hand->handler2();//�ڵ鷯�� ���ؼ� ���簡 AŰ��� AŰ�� ���� ���� �Ҵ�� ����� �����´�.
	//-----------------------------
	
	//�̻��̿� ��� ó���� ���ټ��� �ְڴ�.

	//------------------------------
	if (temp) {
		temp->excute(*actZomb);//�� ����� �����Ѵ�.
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
