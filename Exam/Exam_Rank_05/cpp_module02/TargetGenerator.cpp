#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it = target_arr.begin();
	while (it != target_arr.end())
	{
		delete it->second;
		it++;
	}
	target_arr.clear();

}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		target_arr.insert(std::make_pair(target->getType(), target->clone()));
}
void TargetGenerator::forgetTargetType(std::string const &name)
{
	std::map<std::string, ATarget *>::iterator it = target_arr.find(name);
	if (it != target_arr.end())
		delete it->second;
	target_arr.erase(name);
}
ATarget *TargetGenerator::createTarget(std::string const &name)
{
	std::map<std::string, ATarget *>::iterator it = target_arr.find(name);
	if (it != target_arr.end())
		return target_arr[name];
	return NULL;
}