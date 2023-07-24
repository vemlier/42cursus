#pragma once

#include "ASpell.hpp"
#include "ATarget.hpp"

#include <iostream>
#include <map>

class Warlock
{
	private:
		std::string name;
		std::string title;

		Warlock();
		Warlock(const Warlock &ref);
		Warlock &operator=(const Warlock &ref);

		std::map<std::string, ASpell *> arr;

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);

		void introduce() const ;
		
		void learnSpell(ASpell *ptr);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, const ATarget &ref);
};