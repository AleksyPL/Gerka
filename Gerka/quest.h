#pragma once
#include "biblioteki.h"

class Quest
{
private:
	//container for the quest file name.
	std::string __file_name;
	//container for the quest text
	std::string __quest_text;
	//object to open file from the disc
	std::ifstream __quest_file;
	//character level requirement
	//int character_lvl;
	//character class requirement
	//std::string character_class;
	char __tmp;
public:
	Quest(std::string var1); //: __file_name(""), __quest_text(new std::string), __quest_file("") {}
	//~Quest();
	void sfile_name(std::string file_name);
	std::string gfile_name();
	void set_tmp(char tmp);
	char get_tmp();
	void squest_text(std::string quest_text);
	std::string gquest_text();
};