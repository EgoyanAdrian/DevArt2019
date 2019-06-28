#include <ZoneTexte.hpp>

ZoneTexte::ZoneTexte(int _x, int _y, uint _largeur, uint _hauteur, sf::Font & font) {
	sf::Vector2f pos(_x, _y);
	sf::Vector2f size(_largeur, _hauteur);

	this->setPosition(pos);
	this->setSize(size);
	this->setFillColor(sf::Color::Transparent);

	texteArea.setFont(font);
	texteArea.setFillColor(sf::Color::Black);
	texteArea.setPosition(pos);
	texteArea.setCharacterSize(10);
}

ZoneTexte::~ZoneTexte() 
{ }

bool ZoneTexte::getClicked() const {
	return isClicked;
}

void ZoneTexte::setClicked(bool _isClicked) {
	isClicked = _isClicked;
}

bool ZoneTexte::getLimitless() const {
	return isLimitless;
}

void ZoneTexte::setLimitless(bool _isLimitless) {
	isLimitless = _isLimitless;
}

std::string ZoneTexte::getTexte() const {
	return texteArea.getString();
}

void ZoneTexte::setTexte(char lettre) {
	std::string texteTemp = "";
	sf::Vector2f size(this->getSize());
	sf::FloatRect _textAreaSize = texteArea.getGlobalBounds();
	int maxChar = (size.x / texteArea.getCharacterSize());

	if((isLimitless) && (_textAreaSize.height >= size.y)) {
		std::size_t pos = texteTemp.find('\n');
		texteTemp = texteTemp.substr(pos);
	} else if((!isLimitless) && (_textAreaSize.height >= size.y)) {
		return;
	}

	if((nbCar != 0) && ((nbCar % maxChar) == 0)) {
		texteTemp += '\n';
	}

	texteTemp += lettre;
	nbCar++;
	texteArea.setString(texteArea.getString() + texteTemp);
}

bool ZoneTexte::isOver(int _x, int _y) const {
	sf::Vector2f pos(this->getPosition());
	sf::Vector2f size(this->getSize());

	return ((pos.x < _x) && (pos.y < _y) && ((pos.x + size.x) > _x) && ((pos.y + size.y) > _y));
}

void ZoneTexte::upgrade(sf::RenderWindow & fenetre) {
	this->setOutlineThickness(3);
	this->setOutlineColor(sf::Color::Black);

	texteArea.setPosition(this->getPosition());
	fenetre.draw(texteArea);
}

bool ZoneTexte::isFull() const {
	sf::Vector2f size(this->getSize());
	sf::FloatRect _texteAreaSize = texteArea.getGlobalBounds();

	return !(_texteAreaSize.height < size.y);
}