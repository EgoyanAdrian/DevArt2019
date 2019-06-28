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
	std::string texteTemp = "", texteCourant = texteArea.getString();
	sf::Vector2f size(this->getSize());
	sf::FloatRect _textAreaSize = texteArea.getGlobalBounds();
	int maxChar = (size.x / texteArea.getCharacterSize());

	if((isLimitless) && (_textAreaSize.height >= size.y)) {
		std::size_t pos = texteCourant.find("\n");
		if(pos != std::string::npos)
			texteCourant = texteCourant.substr(pos + 1);
	} else if((!isLimitless) && (_textAreaSize.height >= size.y)) {
		return;
	}

	if((nbCar != 0) && ((nbCar % maxChar) == 0)) {
		texteTemp += '\n';
	}

	texteTemp += lettre;
	nbCar++;
	texteArea.setString(texteCourant + texteTemp);
	if(isClicked) {posCurseur = nbCar;}
}

int ZoneTexte::getCurseur() const {
	return posCurseur;
}

void ZoneTexte::setCurseur(int _posCurseur) {
	std::string texteTempo = texteArea.getString();
	if((_posCurseur >= 0) && (_posCurseur <= texteTempo.length()))
		posCurseur = _posCurseur;
}

void ZoneTexte::clear() {
	texteArea.setString("");
}

void ZoneTexte::remove() {
	std::string texteTempo, texteRetour;
	texteTempo = texteArea.getString();
	
	if(texteTempo.length() > 0) {
		if(posCurseur == 0) {
			texteRetour = texteTempo.substr(1, texteTempo.length());
		} else if(posCurseur == texteTempo.length()) {
			texteRetour = texteTempo.substr(0, texteTempo.length() - 1);
			posCurseur = texteTempo.length() - 1;
		} else {
			texteRetour = texteTempo.substr(0, posCurseur);
			texteRetour += texteTempo.substr(posCurseur + 1, texteTempo.length());
		}

		nbCar--;
	}
	
	texteArea.setString(texteRetour);
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