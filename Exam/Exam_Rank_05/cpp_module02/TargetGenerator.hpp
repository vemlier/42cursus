#pragma once

#include "ATarget.hpp"
#include "ATarget.hpp"

#include <iostream>
#include <map>

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *> arr_target;

		TargetGenerator(const TargetGenerator &ref);
		TargetGenerator &operator=(const TargetGenerator &ref);

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *ptr);
		void forgetTargetType(std::string const &name);
		ATarget *createTarget(std::string const &name);
};