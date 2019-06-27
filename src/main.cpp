#include <iostream>
#include <SFML/Graphics.hpp>
#include <fonctionAleatoire.hpp>
#include <Interface.hpp>
#include <genererNomPays.hpp>
#include <BoutonEnvoyer.hpp>
#include <conversion.hpp>
#include <Bouton.hpp>

int main() {
	uint BsizeX=800;
    uint BsizeY=600;

    std::cout << "Bonjour le mondedd !" << std::endl;
	nbIP();
	std::cout << IP() << std::endl;
	std::cout << chance(5) << std::endl;
	std::string pays = genererNomPays();
    std::cout << pays << std::endl;
    std::cout << convertirTaB("bonjour le monde") << std::endl;
    std::cout << convertirBaT("01100010011011110110111001101010011011110111010101110010001000000110110001100101001000000110110101101111011011100110010001100101") << std::endl;
    bool EnvoyisFirstPush=false; //permet de savoir si Envoyer a etais deja utiliser ou non
    bool isPush=false;
    uint mouse_X;
    uint mouse_Y;

    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
    {
        // erreur...
    }

    Bouton bonjur(10, 20, 50, 70, "Test", font);
    
    sf::RenderWindow window(sf::VideoMode(BsizeX, BsizeY), "My window");

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {

        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::Resized)
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

            if(event.type == sf::Event::MouseMoved) {
                mouse_X = event.mouseMove.x;//coordonner X de la sourie
                mouse_Y = event.mouseMove.y;//coordonner Y de la sourie
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                isPush=true;
                bonjur.setClicked(bonjur.isOver(mouse_X, mouse_Y));
            }

            if(event.type==sf::Event::MouseButtonReleased){
                isPush=false;
                bonjur.setClicked(false);
            }

        }
        window.clear(sf::Color::White);
        
        /*if(!EnvoyisFirstPush){
            Interface(window,mouse_X,mouse_Y,isPush,EnvoyisFirstPush,pays,BsizeX,BsizeY);
        }
        else{
            Interface2(window,mouse_X,mouse_Y,isPush,EnvoyisFirstPush,pays,BsizeX,BsizeY);
        }*/
        
        window.draw(bonjur);
        bonjur.upgrade(window);
        window.display();
    }

    return 0;
}

