#include <random>
#include <time.h>
#include <iostream>
#include "projetcpp.h"

int main() {
	bool val;
	int nbcoup = 12;
	std::vector<std::string>  colorchoosen;
	std::array<bool, 4> validation;
	std::vector<std::string> randcolors;
	randcolors = Projetcpp::RandomColor();
	while (nbcoup > 0) {
		colorchoosen = Projetcpp::input();
		validation = Projetcpp::comparaison(randcolors, colorchoosen);
		val = Projetcpp::valid(validation);
		if (val == true) {
			Projetcpp::Clear();
			std::cout << "you win";
			break;
		}
		else {
			nbcoup--;
		}
		std::cout << "attempt left: " << nbcoup << "\n";
	}
	if (val == false) {
		Projetcpp::Clear();
		std::cout << "you lose";
	}
}
