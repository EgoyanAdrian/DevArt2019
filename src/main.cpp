#include <iostream>
#include <SFML/Graphics.hpp>
#include <fonctionAleatoire.hpp>
#include <Interface.hpp>

int main() {
	std::cout << "Bonjour le mondedd !" << std::endl;
	nbIP();
	std::cout<<IP()<<std::endl;
	std::cout<<chance(5)<<std::endl;
	

    
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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
        }
        window.clear(sf::Color::White);
        Interface(window);
        
        window.display();
    }

    return 0;
}

