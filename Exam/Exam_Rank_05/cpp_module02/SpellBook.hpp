#pragma once

#include "ASpell.hpp"

#include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell *> spell_arr;
		
		SpellBook(const SpellBook &SpellBook);
		SpellBook &operator=(const SpellBook &SpellBook);

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &name);
		ASpell *createSpell(std::string const &name);
};