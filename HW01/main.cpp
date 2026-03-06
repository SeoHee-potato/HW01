//1번 과제

#include <iostream>
using namespace std;

// 포션 지급 함수 정의
void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = *p_HPPotion + count;
	*p_MPPotion = *p_MPPotion + count;

	return;
}

// 포션 충전 함수 정의
void ChargePotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = *p_HPPotion + count;
	*p_MPPotion = *p_MPPotion + count;

	return;
}

// 메인함수 시작
int main(void)
{
	int status[4] = { 0, };
	int HPPotion = 0;
	int MPPotion = 0;
	int Level = 1;

	// 기본 포션 5개 지급
	setPotion(5, &HPPotion, &MPPotion);

	while (1)
	{
		cout << "HP와 MP을 순차적으로 입력하세요." << endl;
		cin >> status[0] >> status[1];

		if (status[0] > 50 && status[1] > 50)
		{
			cout << "성공적으로 설정 되었습니다.\n" << "HP : " << status[0] << "  , MP : " << status[1] << endl;
			break;
		}
		else
		{
			cout << "입력 값이 너무 작습니다. HP와 MP모두 50을 넘어야 합니다.\n";
		}
	}

	while (1)
	{
		cout << "공격력과 방여력을 순차적으로 입력하세요." << endl;
		cin >> status[2] >> status[3];

		if (status[2] > 0 && status[3] > 0)
		{
			cout << "성공적으로 설정 되었습니다. \n" << "공격력 : " << status[2] << "   , 방어력 : " << status[3];
			break;
		}
		else
		{
			cout << "공격력과 방어력은 0이하가 될 수 없습니다. 다시 입력하세요\n";
		}
	}

	while (1)
	{
		int menu;
		cout << "\n===========================================================";
		cout << "\n*스탯 관리 시스템*";
		cout << "\n메뉴를 선택하세요.\n1.HP UP \n2.MP UP \n3.공격력 UP \n4.방어력 UP \n5.현재 능력치 \n6.Level Up \n0.나가기" << endl;
		cin >> menu;

		// 메뉴 나가기
		if (menu == 0)
		{
			cout << "메뉴에서 나갑니다.";
			break;
		}

		// HP포션 사용하기
		else if (menu == 1)
		{
			if (HPPotion > 0)
			{
				HPPotion -= 1;
				status[0] += 20;

				cout << "HP가 20 올랐습니다. 현재 HP : " << status[0] << " , 남은 HP 포션 : " << HPPotion;
			}
			else
			{
				cout << "포션이 1개 이상이어야 사용할 수 있습니다. 남은 HP포션 : 0";
			}
		}

		// MP포션 사용하기
		else if (menu == 2)
		{
			if (MPPotion > 0)
			{
				MPPotion -= 1;
				status[1] += 20;

				cout << "MP가 20 올랐습니다. 현재 MP : " << status[1] << " , 남은 MP 포션 : " << MPPotion;
			}
			else
			{
				cout << "포션이 1개 이상이어야 사용할 수 있습니다. 남은 MP포션 : 0";
			}
		}

		// 공격력 2배 만들기
		else if (menu == 3)
		{
			status[2] *= 2;
			cout << "공격력이 2배가 됩니다. 현재 공격력 : " << status[2];
		}

		// 방어력 2배 만들기
		else if (menu == 4)
		{
			status[3] *= 2;
			cout << "방어력이 2배가 됩니다. 현재 방어력 : " << status[3];
		}

		// 현재 HP, MP, 공격력, 방어력을 출력
		else if (menu == 5)
		{
			cout << "현재 능력치를 확인합니다. \nLevel : " << Level << " , HP : " << status[0] << " , MP : " << status[1] << " , 공격력 : " << status[2] << " , 방어력 : " << status[3];
			cout << "\nHP포션 수량 : " << HPPotion << " , MP포션 수량 : " << MPPotion;
		}

		// 레벨업! 포션 하나씩 더하기.
		else if (menu == 6)
		{
			++Level;
			ChargePotion(1, &HPPotion, &MPPotion);
			cout << "레벨 업! 포션을 하나씩 얻습니다! 현재 레벨 : " << Level << " \n현재 HP포션 : " << HPPotion << ", 현재 MP 포션 : " << MPPotion;
		}

		// 다른 숫자를 눌렀을 때 출력
		else
		{
			cout << "잘못된 입력입니다. 다시 고르십시오.";
		}
	}


	return 0;
}