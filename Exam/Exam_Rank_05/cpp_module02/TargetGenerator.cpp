#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it = arr_target.begin();
	while (it != arr_target.end())
	{
		delete it->second;
		it++;
	}
	arr_target.clear();
}

void TargetGenerator::learnTargetType(ATarget *ptr)
{
	if (ptr)
		arr_target.insert(std::make_pair(ptr->getType(), ptr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
	std::map<std::string, ATarget *>::iterator it = arr_target.find(name);
	if (it != arr_target.end())
		delete it->second;
	arr_target.erase(name);
}

ATarget *TargetGenerator::createTarget(std::string const &name)
{
	std::map<std::string, ATarget *>::iterator it = arr_target.find(name);
	if (it != arr_target.end())
		return (it->second);
	return NULL;
}