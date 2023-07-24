#pragma once

#include "ATarget.hpp"

#include <map>

class  TargetGenerator
{
	private:
		std::map<std::string, ATarget *> target_arr;
		
		 TargetGenerator(const  TargetGenerator & targetGenerator);
		 TargetGenerator &operator=(const  TargetGenerator & targetGenerator);

	public:
		 TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &name);
		ATarget *createTarget(std::string const &name);
};