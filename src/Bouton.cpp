#include <Bouton.hpp>

Bouton::Bouton(int _x, int _y, uint _largeur, uint _hauteur, std::string _texte, sf::Font &_font, bool _isVisible)
:isVisible(_isVisible), texte(_texte, _font) {
	sf::Vector2f pos(_x, _y);
	sf::Vector2f size(_largeur, _hauteur);

	this->setPosition(pos);
	this->setSize(size);

	texte.setPosition(pos);
	texte.setCharacterSize(20);
	texte.setFillColor(sf::Color::Black);
}

Bouton::~Bouton()
{ }

void Bouton::upgrade(sf::RenderWindow & fenetre) {
	this->setOutlineThickness(3);

	if(isVisible && !clicked)
		this->setOutlineColor(sf::Color::Black);
	else if(isVisible && clicked)
		this->setOutlineColor(sf::Color::Blue);
	else
		this->setOutlineColor(sf::Color::Red);

	fenetre.draw(texte);
}