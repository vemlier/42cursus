#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string &name, const std::string &effects) : name(name), effects(effects) {}

ASpell::ASpell(const ASpell &ref)
{
	*this = ref;
}

ASpell &ASpell::operator=(const ASpell &ref)
{
	this->name = ref.name;
	this->effects = ref.effects;
	return (*this);
}

ASpell::~ASpell() {}

const std::string &ASpell::getName() const
{
	return (name);
}

const std::string &ASpell::getEffects() const
{
	return (effects);
}

void ASpell::launch(const ATarget &ref) const
{
	ref.getHitBySpell(*this);
}