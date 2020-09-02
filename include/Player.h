#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

/*
 * TODO:
 * Switch to using shared_ptr to access vector, and make the vector in Generator.cpp a shared_ptr
 */

class Player
{
public:
	Player(const std::vector<std::string>& v_name, std::vector<std::string>* val) : v_names(v_name), values(val) { }
	void print();
	std::string operator[](const int& index);
//	~Player() { //std::cerr << "Deleting" << std::endl; }
private:
	const std::vector<std::string>& v_names;
	std::vector<std::string>* values;
};

#endif
