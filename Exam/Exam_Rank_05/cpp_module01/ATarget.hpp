#pragma once

#include "ASpell.hpp"

#include <iostream>

class ASpell;

class ATarget
{
	protected:
		std::string type;
	
	public:
		ATarget();
		ATarget(const std::string &type);
		ATarget(const ATarget &ref);
		ATarget &operator=(const ATarget &ref);
		virtual ~ATarget();

		const std::string &getType() const;

		void getHitBySpell(const ASpell &ref) const;

		virtual ATarget *clone() const = 0;
};