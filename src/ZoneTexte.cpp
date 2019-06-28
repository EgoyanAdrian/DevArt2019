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
	texteArea.setCharacterSize(18);
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
	std::string texteRetour;
	std::string texteTempo = texteArea.getString();
	for(char & caractere : texteTempo) {
		if(caractere != '\n')
			texteRetour += caractere;
	}
	
	return texteRetour;
}

void ZoneTexte::setTexte(char lettre) {
	std::string texteTemp = "", texteCourant = texteArea.getString();
	sf::Vector2f size(this->getSize());
	sf::FloatRect _textAreaSize = texteArea.getGlobalBounds();
	int maxChar = (size.x / texteArea.getCharacterSize()) + 10;

	if((!isBinaire) || (isBinaire && ((lettre == '0') || (lettre == '1')))) {
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
	}
}

int ZoneTexte::getBinaire() const {
	return isBinaire;
}

void ZoneTexte::setBinaire(bool _isBinaire) {
	isBinaire = _isBinaire;
}

void ZoneTexte::clear() {
	texteArea.setString("");
}

void ZoneTexte::remove() {
	std::string texteTempo, texteRetour;
	texteTempo = texteArea.getString();
	
	if(texteTempo.length() > 0) {
		texteRetour = texteTempo.substr(0, texteTempo.length() - 1);
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