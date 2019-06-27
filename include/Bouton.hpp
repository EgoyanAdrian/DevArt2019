#ifndef BOUTON_HPP
#define BOUTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Bouton : public sf::RectangleShape {
	sf::Text texte;
	bool isVisible;
	bool clicked = false;

	public:
		Bouton(int _x, int _y, uint _largeur, uint _hauteur, std::string _texte, sf::Font &_font, bool _isVisible = true);
		~Bouton();

		inline int getX() const { sf::Vector2f pos(this->getPosition()); return pos.x;}
		inline int getY() const { sf::Vector2f pos(this->getPosition()); return pos.y;}
		inline void setXY(int _x, int _y) { sf::Vector2f pos(_x, _y); this->setPosition(pos);}

		inline uint getLargeur() const { sf::Vector2f size(this->getSize()); return size.x;}
		inline uint getHauteur() const { sf::Vector2f size(this->getSize()); return size.y;}
		inline void setLargHaut(int _hauteur, int _largeur) { sf::Vector2f size(_hauteur, _largeur); this->setSize(size);}

		inline bool getIsVisible() const { return isVisible;}
		inline void setIsVisible(bool _isVisible) { isVisible = _isVisible;}

		inline bool getClicked() const { return clicked;}
		inline void setClicked(bool _clicked) { clicked = _clicked;}

		inline bool isOver(int _x, int _y) const { sf::Vector2f pos(this->getPosition()); sf::Vector2f size(this->getSize()); return ((pos.x <= _x) && (pos.y <= _y) && (pos.x + size.x >= _x) && (pos.y + size.y >= _y));}
		void upgrade(sf::RenderWindow & fenetre);
};

#endif