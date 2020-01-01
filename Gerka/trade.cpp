#include "tabelka.h"
#include "trade.h"

player trade_mode(player &gracz, seller &handlarz, table &menu)
{
	menu.load_merch_trader(handlarz, gracz);
	while (1)
	{
		menu.check_info_boxes();
		tab_trade(gracz, handlarz, menu,menu.strona_1,menu.strona_2);
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		wyb = string_tolower(wyb);
		switch (wyb[0])
		{
		case '1':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(1);
				break;
			}
			if (wyb[1] == '0')
			{
				menu.delete_from_selected_to_buy(10);
				break;
			}
			if (wyb[1] == '1')
			{
				menu.delete_from_selected_to_buy(11);
				break;
			}
			if (wyb[1] == '2')
			{
				menu.delete_from_selected_to_buy(12);
				break;
			}
			if (wyb[1] == '3')
			{
				menu.delete_from_selected_to_buy(13);
				break;
			}
			if (wyb[1] == '4')
			{
				menu.delete_from_selected_to_buy(14);
				break;
			}
			if (wyb[1] == '5')
			{
				menu.delete_from_selected_to_buy(15);
				break;
			}
			if (wyb[1] == '6')
			{
				menu.delete_from_selected_to_buy(16);
				break;
			}
			if (wyb[1] == '7')
			{
				menu.delete_from_selected_to_buy(17);
				break;
			}
			if (wyb[1] == '8')
			{
				menu.delete_from_selected_to_buy(18);
				break;
			}
			if (wyb[1] == '9')
			{
				menu.delete_from_selected_to_buy(19);
				break;
			}
			break;
		}
		case '2':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(2);
				break;
			}
			if (wyb[1] == '0')
			{
				menu.delete_from_selected_to_buy(20);
				break;
			}
			if (wyb[1] == '1')
			{
				menu.select_item_to_buy(21,gracz,handlarz);
				break;
			}
			if (wyb[1] == '2')
			{
				menu.select_item_to_buy(22, gracz, handlarz);
				break;
			}
			if (wyb[1] == '3')
			{
				menu.select_item_to_buy(23, gracz, handlarz);
				break;
			}
			if (wyb[1] == '4')
			{
				menu.select_item_to_buy(24, gracz, handlarz);
				break;
			}
			if (wyb[1] == '5')
			{
				menu.select_item_to_buy(25, gracz, handlarz);
				break;
			}
			if (wyb[1] == '6')
			{
				menu.select_item_to_buy(26, gracz, handlarz);
				break;
			}
			if (wyb[1] == '7')
			{
				menu.select_item_to_buy(27, gracz, handlarz);
				break;
			}
			if (wyb[1] == '8')
			{
				menu.select_item_to_buy(28, gracz, handlarz);
				break;
			}
			if (wyb[1] == '9')
			{
				menu.select_item_to_buy(29, gracz, handlarz);
				break;
			}
			break;
		}
		case '3':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(3);
				break;
			}
			if (wyb[1] == '0')
			{
				menu.select_item_to_buy(30, gracz, handlarz);
				break;
			}
			if (wyb[1] == '1')
			{
				menu.select_item_to_buy(31, gracz, handlarz);
				break;
			}
			if (wyb[1] == '2')
			{
				menu.select_item_to_buy(32, gracz, handlarz);
				break;
			}
			if (wyb[1] == '3')
			{
				menu.select_item_to_buy(33, gracz, handlarz);
				break;
			}
			if (wyb[1] == '4')
			{
				menu.select_item_to_buy(34, gracz, handlarz);
				break;
			}
			if (wyb[1] == '5')
			{
				menu.select_item_to_buy(35, gracz, handlarz);
				break;
			}
			if (wyb[1] == '6')
			{
				menu.select_item_to_buy(36, gracz, handlarz);
				break;
			}
			if (wyb[1] == '7')
			{
				menu.select_item_to_buy(37, gracz, handlarz);
				break;
			}
			if (wyb[1] == '8')
			{
				menu.select_item_to_buy(38, gracz, handlarz);
				break;
			}
			if (wyb[1] == '9')
			{
				menu.select_item_to_buy(39, gracz, handlarz);
				break;
			}
			break;
		}
		case '4':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(4);
				break;
			}
			if (wyb[1] == '0')
			{
				menu.select_item_to_buy(40, gracz, handlarz);
				break;
			}
			if (wyb[1] == '1')
			{
				menu.delete_from_selected_to_sell(41,gracz,handlarz);
				break;
			}
			if (wyb[1] == '2')
			{
				menu.delete_from_selected_to_sell(42, gracz, handlarz);
				break;
			}
			if (wyb[1] == '3')
			{
				menu.delete_from_selected_to_sell(43, gracz, handlarz);
				break;
			}
			if (wyb[1] == '4')
			{
				menu.delete_from_selected_to_sell(44, gracz, handlarz);
				break;
			}
			if (wyb[1] == '5')
			{
				menu.delete_from_selected_to_sell(45, gracz, handlarz);
				break;
			}
			if (wyb[1] == '6')
			{
				menu.delete_from_selected_to_sell(46, gracz, handlarz);
				break;
			}
			if (wyb[1] == '7')
			{
				menu.delete_from_selected_to_sell(47, gracz, handlarz);
				break;
			}
			if (wyb[1] == '8')
			{
				menu.delete_from_selected_to_sell(48, gracz, handlarz);
				break;
			}
			if (wyb[1] == '9')
			{
				menu.delete_from_selected_to_sell(49, gracz, handlarz);
				break;
			}
			break;
		}
		case '5':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(5);
				break;
			}
			if (wyb[1] == '0')
			{
				menu.delete_from_selected_to_sell(50, gracz, handlarz);
				break;
			}
			if (wyb[1] == '1')
			{
				menu.delete_from_selected_to_sell(51, gracz, handlarz);
				break;
			}
			if (wyb[1] == '2')
			{
				menu.delete_from_selected_to_sell(52, gracz, handlarz);
				break;
			}
			if (wyb[1] == '3')
			{
				menu.delete_from_selected_to_sell(53, gracz, handlarz);
				break;
			}
			if (wyb[1] == '4')
			{
				menu.delete_from_selected_to_sell(54, gracz, handlarz);
				break;
			}
			if (wyb[1] == '5')
			{
				menu.delete_from_selected_to_sell(55, gracz, handlarz);
				break;
			}
			if (wyb[1] == '6')
			{
				menu.delete_from_selected_to_sell(56, gracz, handlarz);
				break;
			}
			if (wyb[1] == '7')
			{
				menu.delete_from_selected_to_sell(57, gracz, handlarz);
				break;
			}
			if (wyb[1] == '8')
			{
				menu.delete_from_selected_to_sell(58, gracz, handlarz);
				break;
			}
			if (wyb[1] == '9')
			{
				menu.delete_from_selected_to_sell(59, gracz, handlarz);
				break;
			}
			break;
		}
		case '6':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(6);
				break;
			}
			if (wyb[1] == '0')
			{
				menu.delete_from_selected_to_sell(60, gracz, handlarz);
				break;
			}
			if (wyb[1] == '1')
			{
				menu.select_item_to_sell(61, gracz);
				break;
			}
			if (wyb[1] == '2')
			{
				menu.select_item_to_sell(62, gracz);
				break;
			}
			if (wyb[1] == '3')
			{
				menu.select_item_to_sell(63, gracz);
				break;
			}
			if (wyb[1] == '4')
			{
				menu.select_item_to_sell(64, gracz);
				break;
			}
			if (wyb[1] == '5')
			{
				menu.select_item_to_sell(65, gracz);
				break;
			}
			if (wyb[1] == '6')
			{
				menu.select_item_to_sell(66, gracz);
				break;
			}
			if (wyb[1] == '7')
			{
				menu.select_item_to_sell(67, gracz);
				break;
			}
			if (wyb[1] == '8')
			{
				menu.select_item_to_sell(68, gracz);
				break;
			}
			if (wyb[1] == '9')
			{
				menu.select_item_to_sell(69, gracz);
				break;
			}
			break;
		}
		case '7':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(7);
				break;
			}
			if (wyb[1] == '0')
			{
				menu.select_item_to_sell(70, gracz);
				break;
			}
			if (wyb[1] == '1')
			{
				menu.select_item_to_sell(71, gracz);
				break;
			}
			if (wyb[1] == '2')
			{
				menu.select_item_to_sell(72, gracz);
				break;
			}
			if (wyb[1] == '3')
			{
				menu.select_item_to_sell(73, gracz);
				break;
			}
			if (wyb[1] == '4')
			{
				menu.select_item_to_sell(74, gracz);
				break;
			}
			if (wyb[1] == '5')
			{
				menu.select_item_to_sell(75, gracz);
				break;
			}
			if (wyb[1] == '6')
			{
				menu.select_item_to_sell(76, gracz);
				break;
			}
			if (wyb[1] == '7')
			{
				menu.select_item_to_sell(77, gracz);
				break;
			}
			if (wyb[1] == '8')
			{
				menu.select_item_to_sell(78, gracz);
				break;
			}
			if (wyb[1] == '9')
			{
				menu.select_item_to_sell(79, gracz);
				break;
			}
			break;
		}
		case '8':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(8);
				break;
			}
			if (wyb[1] == '0')
			{
				menu.select_item_to_sell(80, gracz);
				break;
			}
			break;
		}
		case '9':
		{
			if (wyb.size() == 1)
			{
				menu.delete_from_selected_to_buy(9);
				break;
			}
			break;
		}
		case 'w':
		{
			if (menu.exit_trade_mode() == 1)
			{
				menu.decline_transaction(gracz,handlarz);
				return gracz;
			}
			else
			{
				break;
			}
		}
		case 'n':
		{
			menu.switch_page_next(gracz,handlarz,wyb);
			break;
		}
		case 'p':
		{
			menu.switch_page_previous(gracz, handlarz, wyb);
			break;
		}
		case 'z':
		{
			menu.accept_transaction(gracz,handlarz);
			break;
		}
		default:
		{
			system("cls");
		}
		}
	}
}