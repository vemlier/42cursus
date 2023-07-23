#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>

class ASpell;

class ATarget
{
	private:
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

#endif