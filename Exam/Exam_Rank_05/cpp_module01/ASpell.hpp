#pragma once

#include "ATarget.hpp"

#include <iostream>

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;
	
	public:
		ASpell();
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &ref);
		ASpell &operator=(const ASpell &ref);
		virtual ~ASpell();

		const std::string &getName() const;
		const std::string &getEffects() const;

		void launch(const ATarget &ref) const;

		virtual ASpell *clone() const = 0;
};