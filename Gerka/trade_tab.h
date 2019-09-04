#pragma once
#include "biblioteki.h"
#include "dwellers.h"

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
	int licznik;
	int licznik1;
	int licznik3;
	int licznik4;
	string info[7];
	table();
	void load_merch_trader(seller &handlarz, player &gracz);
	void switch_page_next(player gracz, seller handlarz, string wyb);
	void switch_page_previous(player gracz, seller handlarz, string wyb);
	void check_free_fields();
	void check_info_boxes();
	void sort_player_field();
	void select_item_to_buy(int numer, player gracz, seller handlarz);
	void select_item_to_sell(int numer);
	void sort_buying_field();
	void delete_from_selected_to_buy(int numer);
	void delete_from_selected_to_sell(int numer, player gracz, seller handlarz);
	int exit_trade_mode();
	void check_selected_to_buy_field(player gracz,seller handlarz);
	int can_be_selected(player gracz, seller handlarz, string nazwa);
	void accept_transaction(player &gracz, seller handlarz);
};
