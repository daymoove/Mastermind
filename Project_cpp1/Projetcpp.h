#include <array>
#include <iostream>
#include <vector>

#ifndef Projetcpp_H
#define Projetcpp_H


class Projetcpp
{
public:
	Projetcpp();
	~Projetcpp();
	
	static std::vector<std::string> RandomColor();
	static std::vector<std::string> input();
	static std::array<bool, 4> comparaison(const std::vector<std::string> randcolors, std::vector<std::string> colorchoosen);
	static bool valid(const std::array<bool, 4> validation);
	static void Clear();

};






#endif // !Projetcpp_H
