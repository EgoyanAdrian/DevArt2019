#ifndef ZONETEXTE_HPP
#define ZONETEXTE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class ZoneTexte : public sf::RectangleShape {
	sf::Text texteArea;
	int nbCar = 0;
	bool isClicked = false;
	bool isLimitless = false;

	public:
		ZoneTexte(int _x, int _y, uint _largeur, uint _hauteur, sf::Font & font);
		~ZoneTexte();

		bool getClicked() const;
		void setClicked(bool _isClicked);

		bool getLimitless() const;
		void setLimitless(bool _isLimitless);

		std::string getTexte() const;
		void setTexte(char lettre);

		void clear();
		void remove();

		bool isOver(int _x, int _y) const;

		void upgrade(sf::RenderWindow & fenetre);

		bool isFull() const;
};

#endif