#include "include/Player.h"

void Player::print()
{
	std::cout << "This is a test to see if anything works.\n";
}

std::string Player::operator[](const int& index)
{

	std::cout << values->size() << ", index: " << index << '\n';
	std::cout << "address is: " << &values << std::endl;
	if (values->size() > index)
	{
		std::cout << "Works" << std::endl;
		return values->at(index);
	}
}
