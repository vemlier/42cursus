#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string &type) : type(type) {}

ATarget::ATarget(const ATarget &ref)
{
	*this = ref;
}

ATarget &ATarget::operator=(const ATarget &ref)
{
	this->type = ref.type;
	return (*this);
}

ATarget::~ATarget() {}

const std::string &ATarget::getType() const
{
	return (type);
}

void ATarget::getHitBySpell(const ASpell &ref) const
{
	std::cout << type << " has been " << ref.getEffects() << "!" << std::endl;
}
