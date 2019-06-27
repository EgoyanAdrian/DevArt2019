#include <Interface.hpp>
#include <iostream>

void Interface(sf::RenderWindow &w){
	// 1er fenetre de visionage
	sf::RectangleShape Rectangle1(sf::Vector2f(300.f,550.f));
    Rectangle1.setOutlineColor(sf::Color::Black);
    Rectangle1.setOutlineThickness(3);
	Rectangle1.setPosition(10, 20);

	//dexieme feneter de visionage
	sf::RectangleShape Rectangle2(sf::Vector2f(300.f,550.f));
    Rectangle2.setOutlineColor(sf::Color::Black);
    Rectangle2.setOutlineThickness(3);
	Rectangle2.setPosition(340, 20);

	//deffini le bouton envoyer
	sf::RectangleShape BoutonEnvoyer(sf::Vector2f(120.f,50.f)); 
	BoutonEnvoyer.setOutlineColor(sf::Color::Black);
    BoutonEnvoyer.setOutlineThickness(3);
	BoutonEnvoyer.setPosition(650, 500);

	//affiche les deux fenetres
    w.draw(Rectangle1);
    w.draw(Rectangle2);

    //affiche le bouton envoyer
    w.draw(BoutonEnvoyer);


    sf::Texture Textureplanisphere;

    if(!Textureplanisphere.loadFromFile("planisphere.png"))
    	std::cout<<"erreur"<<std::endl;

    sf::RectangleShape planisphere(sf::Vector2f(120.f,50.f)); 
	planisphere.setOutlineColor(sf::Color::Black);
    planisphere.setOutlineThickness(3);
	planisphere.setPosition(650, 20);
	planisphere.setTexture(&Textureplanisphere);
    w.draw(planisphere);

}