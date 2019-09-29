#include "quest.h"

void change_flags(barman &bobby,string name)
{
	if (name == "BARMAN")
	{
		int help = bobby.quest_info();
		bobby.quest_set(help + 1);
	}
}
void reject_guest_giving()
{
	sound_rejection();
	fancy_text("Ju¿ wykonujesz jakieœ zadanie");
}
int dialog_box()
{
	while (1)
	{
		cout << "Czy zrobisz to?" << endl;
		cout << "1. Tak" << endl;
		cout << "2. Nie" << endl;
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
		case '1':
		{
			return 1;
		}
		case '2':
		{
			return 0;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}
void give_quest_shaman(player &gracz)
{
	
}
//void return_quest_shaman(player gracz, shaman szaman)
//{
//	if (gracz.quest_compl == 1)
//	{
//		if (szaman.quest_info == 0)
//		{
//			fancy_text("Zadanie zakoñczone");
//		}
//	}
//	else
//	{
//		fancy_text("Nie mo¿esz jeszcze zwróciæ zadania");
//	}
//}