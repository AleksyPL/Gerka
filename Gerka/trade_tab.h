#pragma once
#include "biblioteki.h"
#include "dwellers.h"
#include "player.h"

class table
{
public:
	string temp_table[120];
	int temp_table_price[120];
	int temp_table_amount[120];
	int strona_1;
	int strona_2;
	int counter_selected_to_buy_usage;
	int counter_selected_to_buy_alchemy;
	int counter_selected_to_buy_forge;
	int counter_selected_to_sell_usage;
	int counter_selected_to_sell_alchemy;
	int counter_selected_to_sell_forge;
	string info[7];
	table();
	void load_merch_trader(seller &handlarz, player &gracz);
	void load_merch_blacksmith(blacksmith &kowal, player &gracz);
	void switch_page_next(player gracz, seller handlarz, string wyb);
	void switch_page_previous(player gracz, seller handlarz, string wyb);
	void check_info_boxes();
	void sort_player_field();
	void select_item_to_buy(int numer, player gracz, seller handlarz);
	void select_item_to_sell(int numer, player &gracz);
	void sort_buying_field();
	void sort_seller_field();
	void delete_from_selected_to_buy(int numer);
	void delete_from_selected_to_sell(int numer, player &gracz, seller handlarz);
	int exit_trade_mode();
	void check_selected_to_buy_field(player gracz,seller handlarz);
	void check_selected_to_sell_field(player gracz, seller handlarz);
	int can_be_selected(player gracz, seller handlarz, string nazwa);
	void decline_transaction(player &gracz,seller handlarz);
	void accept_transaction(player &gracz, seller handlarz);
};
