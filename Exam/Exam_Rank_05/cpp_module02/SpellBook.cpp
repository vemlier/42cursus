#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = spell_arr.begin();
	while (it != spell_arr.end())
	{
		delete it->second;
		it++;
	}
	spell_arr.clear();

}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		spell_arr.insert(std::make_pair(spell->getName(), spell->clone()));
}
void SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = spell_arr.find(name);
	if (it != spell_arr.end())
		delete it->second;
	spell_arr.erase(name);
}
ASpell *SpellBook::createSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = spell_arr.find(name);
	if (it != spell_arr.end())
		return spell_arr[name];
	return NULL;
}