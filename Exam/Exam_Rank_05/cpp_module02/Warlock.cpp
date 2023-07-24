#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return (name);
}

const std::string &Warlock::getTitle() const
{
	return (title);
}

void Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *ptr)
{
	book.learnSpell(ptr);
}

void Warlock::forgetSpell(std::string name)
{
	book.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, const ATarget &ref)
{
	const ATarget *test = 0;

	if (test == &ref)
		return ;
	ASpell *spell = book.createSpell(name);
	if (spell)
		spell->launch(ref);
}