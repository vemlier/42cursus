#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "ASpell.hpp"
# include "ATarget.hpp"

# include <iostream>
# include <map>

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell *> arr;

		Warlock();
		Warlock(Warlock &ref);
		Warlock &operator=(Warlock &ref);

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);

		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, const ATarget &ref);
};

#endif