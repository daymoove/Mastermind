#include <random>
#include <time.h>
#include <iostream>
#include <array>
#include "projetcpp.h"


Projetcpp::Projetcpp()
{
}


Projetcpp::~Projetcpp()
{
}


std::vector<std::string> Projetcpp::RandomColor() {
	std::default_random_engine generator(static_cast<unsigned int>(time(0)));
	std::uniform_int_distribution<int> distribution(0, 5);
	int randcolor;
	std::vector<std::string> colors;
	for (int i = 0; i < 5;i++) {
		randcolor = distribution(generator);
		switch (randcolor)
		{
			case 1:
				colors.push_back("vert_caca_d'oie");
			case 2:
				colors.push_back("jaune");
			case 3:
				colors.push_back("bleu");
			case 4:
				colors.push_back("blanc");
			case 5:
				colors.push_back("rouge");
			default:
				break;
		}
	}
	for (int i = 0; i < 4; i++) {
		std::cout << colors[i] << "\n";
	}
	return colors;
}


std::vector<std::string> Projetcpp::input()
{
	int i = 1;
	std::vector<std::string> colorchoosen;
	std::string inputcolor;
	int position;
	std::cout << "choose a color between vert_caca_d'oie, jaune, bleu, blanc, rouge for each position: " << "\n";
	while (i <= 4) {
		std::cout << "color position " << i << " : " << "\n";
		std::cin >> inputcolor;
		if (inputcolor == "bleu" || inputcolor == "jaune" || inputcolor == "blanc" || inputcolor == "rouge" || inputcolor == "vert_caca_d'oie") {
			colorchoosen.push_back(inputcolor);
			i++;
		}
		else {
			std::cout << "invalid color" << "\n";
		}
	}
	Projetcpp::Clear();
	return colorchoosen;
}


std::array<bool, 4> Projetcpp::comparaison(const std::vector<std::string> randcolors, std::vector<std::string> colorchoosen)
{
	int nbgpos = 0;
	int nbbpos = 0;
	int nbf = 0;
	bool colorverif = false;
	std::array<bool,4> validation {false,false,false,false};
	for (int i = 0; i < 4; i++) {
		for (int m = 0; m < 4; m++) {
			if (randcolors[m] == colorchoosen[i]) {
				if (i == m) {
					colorverif = true;
					nbgpos++;
					validation[i] = true;
				}
				else {
					colorverif = true;
					nbbpos++;
					validation[i] = false;
				}
			}
			else if (randcolors[m] != colorchoosen[i] && m == 4) {
				colorverif = false;
			}
		}
		if (colorverif == false) {
			nbf++;
		}
	}
	if (nbgpos > 0) {
		std::cout << "there is " << nbgpos << " good color at a good position" << "\n";
	}
	if (nbbpos > 0) {
		nbbpos += nbgpos;
		std::cout << "there is " << nbbpos << " good color" << "\n";
	}
	return validation;
}


bool Projetcpp::valid(const std::array<bool, 4> validation)
{
	bool val = false;
	for (int i = 0; i < 4; i++) {
		if (validation[i] == true) {
			val = true;
			continue;
		}
		else {
			val = false;
			break;
		}
	}
	return val;
}

