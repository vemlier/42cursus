#pragma once

#include "ASpell.hpp"
#include "ATarget.hpp"

#include <iostream>
#include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell *> arr_spell;

		SpellBook(const SpellBook &ref);
		SpellBook &operator=(const SpellBook &ref);

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *ptr);
		void forgetSpell(std::string const &name);
		ASpell *createSpell(std::string const &name);
};