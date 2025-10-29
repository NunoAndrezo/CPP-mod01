#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <memory>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(const std::string &name);
		~Zombie();

		void announce();
		void setName(const std::string &name);
};

Zombie	*zombieHorde(int N, std::string &name);

#endif