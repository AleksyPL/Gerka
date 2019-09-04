#include "quest.h"

Quest::Quest(std::string var1) : __file_name("./Quest/")
{
	sfile_name(gfile_name() + var1);
	__quest_file.open(gfile_name(), std::ifstream::in);
	set_tmp(__quest_file.get());
	while (__quest_file.good())
	{
		squest_text(gquest_text()+get_tmp());
		set_tmp(__quest_file.get());
	}
	__quest_file.close();
}

//Quest::~Quest()
//{
//	delete __quest_text;
//}

void Quest::sfile_name(std::string file_name)
{
	__file_name = file_name;
}
std::string Quest::gfile_name()
{
	return __file_name;
}
void Quest::set_tmp(char tmp)
{
	__tmp = tmp;
}
char Quest::get_tmp()
{
	return __tmp;
}
void Quest::squest_text(std::string quest_text)
{
	__quest_text = quest_text;
}
std::string Quest::gquest_text()
{
	return __quest_text;
}