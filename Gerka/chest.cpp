#include "chest.h"
#include "tabelka.h"

void enter_chest_mode(player &gracz, chest &krzynka)
{
	int tryb = 0;
	string info[7];
	info[0] = "W:ZAMKNIJ SKRZYNIÊ ";
	info[1] = "";
	info[2] = "";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	do
	{
		tab_chest(gracz,krzynka,info);
		cout << "Twoj wybor to: ";
		string wyb;
		cin >> wyb;
		wyb = string_tolower(wyb);
		switch (wyb[0])
		{
		case 'g':
		{
			if (wyb == "g1")
			{
				krzynka.move_to_chest(1, gracz);
				break;
			}
			else if (wyb == "g2")
			{
				krzynka.move_to_chest(2, gracz);
				break;
			}
			else if (wyb == "g3")
			{
				krzynka.move_to_chest(3, gracz);
				break;
			}
			else if (wyb == "g4")
			{
				krzynka.move_to_chest(4, gracz);
				break;
			}
			else if (wyb == "g5")
			{
				krzynka.move_to_chest(5, gracz);
				break;
			}
			else if (wyb == "g6")
			{
				krzynka.move_to_chest(6, gracz);
				break;
			}
			else if (wyb == "g7")
			{
				krzynka.move_to_chest(7, gracz);
				break;
			}
			else if (wyb == "g8")
			{
				krzynka.move_to_chest(8, gracz);
				break;
			}
			else if (wyb == "g9")
			{
				krzynka.move_to_chest(9, gracz);
				break;
			}
			else if (wyb == "g10")
			{
				krzynka.move_to_chest(10, gracz);
				break;
			}
			else if (wyb == "g11")
			{
				krzynka.move_to_chest(11, gracz);
				break;
			}
			else if (wyb == "g12")
			{
				krzynka.move_to_chest(12, gracz);
				break;
			}
			else if (wyb == "g13")
			{
				krzynka.move_to_chest(13, gracz);
				break;
			}
			else if (wyb == "g14")
			{
				krzynka.move_to_chest(14, gracz);
				break;
			}
			else if (wyb == "g15")
			{
				krzynka.move_to_chest(15, gracz);
				break;
			}
			else if (wyb == "g16")
			{
				krzynka.move_to_chest(16, gracz);
				break;
			}
			else if (wyb == "g17")
			{
				krzynka.move_to_chest(17, gracz);
				break;
			}
			else if (wyb == "g18")
			{
				krzynka.move_to_chest(18, gracz);
				break;
			}
			else if (wyb == "g19")
			{
				krzynka.move_to_chest(19, gracz);
				break;
			}
			else if (wyb == "g20")
			{
				krzynka.move_to_chest(20, gracz);
				break;
			}
			else if (wyb == "g21")
			{
				krzynka.move_to_chest(21, gracz);
				break;
			}
			else if (wyb == "g22")
			{
				krzynka.move_to_chest(22, gracz);
				break;
			}
			else if (wyb == "g23")
			{
				krzynka.move_to_chest(23, gracz);
				break;
			}
			else if (wyb == "g24")
			{
				krzynka.move_to_chest(24, gracz);
				break;
			}
			else if (wyb == "g25")
			{
				krzynka.move_to_chest(25, gracz);
				break;
			}
			else if (wyb == "g26")
			{
				krzynka.move_to_chest(26, gracz);
				break;
			}
			else if (wyb == "g27")
			{
				krzynka.move_to_chest(27, gracz);
				break;
			}
			else if (wyb == "g28")
			{
				krzynka.move_to_chest(28, gracz);
				break;
			}
			else if (wyb == "g29")
			{
				krzynka.move_to_chest(29, gracz);
				break;
			}
			else if (wyb == "g30")
			{
				krzynka.move_to_chest(30, gracz);
				break;
			}
			else if (wyb == "g31")
			{
				krzynka.move_to_chest(31, gracz);
				break;
			}
			else if (wyb == "g32")
			{
				krzynka.move_to_chest(32, gracz);
				break;
			}
			else if (wyb == "g33")
			{
				krzynka.move_to_chest(33, gracz);
				break;
			}
			else if (wyb == "g34")
			{
				krzynka.move_to_chest(34, gracz);
				break;
			}
			else if (wyb == "g35")
			{
				krzynka.move_to_chest(35, gracz);
				break;
			}
			else if (wyb == "g36")
			{
				krzynka.move_to_chest(36, gracz);
				break;
			}
			else if (wyb == "g37")
			{
				krzynka.move_to_chest(37, gracz);
				break;
			}
			else if (wyb == "g38")
			{
				krzynka.move_to_chest(38, gracz);
				break;
			}
			else if (wyb == "g39")
			{
				krzynka.move_to_chest(39, gracz);
				break;
			}
			else if (wyb == "g40")
			{
				krzynka.move_to_chest(40, gracz);
				break;
			}
			else if (wyb == "g41")
			{
				krzynka.move_to_chest(41, gracz);
				break;
			}
			else if (wyb == "g42")
			{
				krzynka.move_to_chest(42, gracz);
				break;
			}
			else if (wyb == "g43")
			{
				krzynka.move_to_chest(43, gracz);
				break;
			}
			else if (wyb == "g44")
			{
				krzynka.move_to_chest(44, gracz);
				break;
			}
			else if (wyb == "g45")
			{
				krzynka.move_to_chest(45, gracz);
				break;
			}
			else if (wyb == "g46")
			{
				krzynka.move_to_chest(46, gracz);
				break;
			}
			else if (wyb == "g47")
			{
				krzynka.move_to_chest(47, gracz);
				break;
			}
			else if (wyb == "g48")
			{
				krzynka.move_to_chest(48, gracz);
				break;
			}
			else if (wyb == "g49")
			{
				krzynka.move_to_chest(49, gracz);
				break;
			}
			else if (wyb == "g50")
			{
				krzynka.move_to_chest(50, gracz);
				break;
			}
			else if (wyb == "g51")
			{
				krzynka.move_to_chest(51, gracz);
				break;
			}
			else if (wyb == "g52")
			{
				krzynka.move_to_chest(52, gracz);
				break;
			}
			else if (wyb == "g53")
			{
				krzynka.move_to_chest(53, gracz);
				break;
			}
			else if (wyb == "g54")
			{
				krzynka.move_to_chest(54, gracz);
				break;
			}
			else if (wyb == "g55")
			{
				krzynka.move_to_chest(55, gracz);
				break;
			}
			else if (wyb == "g56")
			{
				krzynka.move_to_chest(56, gracz);
				break;
			}
			else if (wyb == "g57")
			{
				krzynka.move_to_chest(57, gracz);
				break;
			}
			else if (wyb == "g58")
			{
				krzynka.move_to_chest(58, gracz);
				break;
			}
			else if (wyb == "g59")
			{
				krzynka.move_to_chest(59, gracz);
				break;
			}
			else if (wyb == "g60")
			{
				krzynka.move_to_chest(60, gracz);
				break;
			}
			break;
		}
		case 's':
		{
			if (wyb == "s1")
			{
				krzynka.move_to_player(1, gracz);
				break;
			}
			else if (wyb == "s2")
			{
				krzynka.move_to_player(2, gracz);
				break;
			}
			else if (wyb == "s3")
			{
				krzynka.move_to_player(3, gracz);
				break;
			}
			else if (wyb == "s4")
			{
				krzynka.move_to_player(4, gracz);
				break;
			}
			else if (wyb == "s5")
			{
				krzynka.move_to_player(5, gracz);
				break;
			}
			else if (wyb == "s6")
			{
				krzynka.move_to_player(6, gracz);
				break;
			}
			else if (wyb == "s7")
			{
				krzynka.move_to_player(7, gracz);
				break;
			}
			else if (wyb == "s8")
			{
				krzynka.move_to_player(8, gracz);
				break;
			}
			else if (wyb == "s9")
			{
				krzynka.move_to_player(9, gracz);
				break;
			}
			else if (wyb == "s10")
			{
				krzynka.move_to_player(10, gracz);
				break;
			}
			else if (wyb == "s11")
			{
				krzynka.move_to_player(11, gracz);
				break;
			}
			else if (wyb == "s12")
			{
				krzynka.move_to_player(12, gracz);
				break;
			}
			else if (wyb == "s13")
			{
				krzynka.move_to_player(13, gracz);
				break;
			}
			else if (wyb == "s14")
			{
				krzynka.move_to_player(14, gracz);
				break;
			}
			else if (wyb == "s15")
			{
				krzynka.move_to_player(15, gracz);
				break;
			}
			else if (wyb == "s16")
			{
				krzynka.move_to_player(16, gracz);
				break;
			}
			else if (wyb == "s17")
			{
				krzynka.move_to_player(17, gracz);
				break;
			}
			else if (wyb == "s18")
			{
				krzynka.move_to_player(18, gracz);
				break;
			}
			else if (wyb == "s19")
			{
				krzynka.move_to_player(19, gracz);
				break;
			}
			else if (wyb == "s20")
			{
				krzynka.move_to_player(20, gracz);
				break;
			}
			else if (wyb == "s21")
			{
				krzynka.move_to_player(21, gracz);
				break;
			}
			else if (wyb == "s22")
			{
				krzynka.move_to_player(22, gracz);
				break;
			}
			else if (wyb == "s23")
			{
				krzynka.move_to_player(23, gracz);
				break;
			}
			else if (wyb == "s24")
			{
				krzynka.move_to_player(24, gracz);
				break;
			}
			else if (wyb == "s25")
			{
				krzynka.move_to_player(25, gracz);
				break;
			}
			else if (wyb == "s26")
			{
				krzynka.move_to_player(26, gracz);
				break;
			}
			else if (wyb == "s27")
			{
				krzynka.move_to_player(27, gracz);
				break;
			}
			else if (wyb == "s28")
			{
				krzynka.move_to_player(28, gracz);
				break;
			}
			else if (wyb == "s29")
			{
				krzynka.move_to_player(29, gracz);
				break;
			}
			else if (wyb == "s30")
			{
				krzynka.move_to_player(30, gracz);
				break;
			}
			else if (wyb == "s31")
			{
				krzynka.move_to_player(31, gracz);
				break;
			}
			else if (wyb == "s32")
			{
				krzynka.move_to_player(32, gracz);
				break;
			}
			else if (wyb == "s33")
			{
				krzynka.move_to_player(33, gracz);
				break;
			}
			else if (wyb == "s34")
			{
				krzynka.move_to_player(34, gracz);
				break;
			}
			else if (wyb == "s35")
			{
				krzynka.move_to_player(35, gracz);
				break;
			}
			else if (wyb == "s36")
			{
				krzynka.move_to_player(36, gracz);
				break;
			}
			else if (wyb == "s37")
			{
				krzynka.move_to_player(37, gracz);
				break;
			}
			else if (wyb == "s38")
			{
				krzynka.move_to_player(38, gracz);
				break;
			}
			else if (wyb == "s39")
			{
				krzynka.move_to_player(39, gracz);
				break;
			}
			else if (wyb == "s40")
			{
				krzynka.move_to_player(40, gracz);
				break;
			}
			else if (wyb == "s41")
			{
				krzynka.move_to_player(41, gracz);
				break;
			}
			else if (wyb == "s42")
			{
				krzynka.move_to_player(42, gracz);
				break;
			}
			else if (wyb == "s43")
			{
				krzynka.move_to_player(43, gracz);
				break;
			}
			else if (wyb == "s44")
			{
				krzynka.move_to_player(44, gracz);
				break;
			}
			else if (wyb == "s45")
			{
				krzynka.move_to_player(45, gracz);
				break;
			}
			else if (wyb == "s46")
			{
				krzynka.move_to_player(46, gracz);
				break;
			}
			else if (wyb == "s47")
			{
				krzynka.move_to_player(47, gracz);
				break;
			}
			else if (wyb == "s48")
			{
				krzynka.move_to_player(48, gracz);
				break;
			}
			else if (wyb == "s49")
			{
				krzynka.move_to_player(49, gracz);
				break;
			}
			else if (wyb == "s50")
			{
				krzynka.move_to_player(50, gracz);
				break;
			}
			else if (wyb == "s51")
			{
				krzynka.move_to_player(51, gracz);
				break;
			}
			else if (wyb == "s52")
			{
				krzynka.move_to_player(52, gracz);
				break;
			}
			else if (wyb == "s53")
			{
				krzynka.move_to_player(53, gracz);
				break;
			}
			else if (wyb == "s54")
			{
				krzynka.move_to_player(54, gracz);
				break;
			}
			else if (wyb == "s55")
			{
				krzynka.move_to_player(55, gracz);
				break;
			}
			else if (wyb == "s56")
			{
				krzynka.move_to_player(56, gracz);
				break;
			}
			else if (wyb == "s57")
			{
				krzynka.move_to_player(57, gracz);
				break;
			}
			else if (wyb == "s58")
			{
				krzynka.move_to_player(58, gracz);
				break;
			}
			else if (wyb == "s59")
			{
				krzynka.move_to_player(59, gracz);
				break;
			}
			else if (wyb == "s60")
			{
				krzynka.move_to_player(60, gracz);
				break;
			}
			break;
		}
		case 'w':
		{
			tryb = 1;
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	} while (tryb == 0);
	
}
