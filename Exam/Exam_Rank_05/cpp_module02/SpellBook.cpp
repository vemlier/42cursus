#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = arr_spell.begin();
	while (it != arr_spell.end())
	{
		delete it->second;
		it++;
	}
	arr_spell.clear();
}

void SpellBook::learnSpell(ASpell *ptr)
{
	if (ptr)
		arr_spell.insert(std::make_pair(ptr->getName(), ptr->clone()));
}

void SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = arr_spell.find(name);
	if (it != arr_spell.end())
		delete it->second;
	arr_spell.erase(name);
}

ASpell *SpellBook::createSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = arr_spell.find(name);
	if (it != arr_spell.end())
		return (it->second);
	return NULL;
}