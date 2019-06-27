#include <iostream>
#include <SFML/Graphics.hpp>
#include <fonctionAleatoire.hpp>
#include <Interface.hpp>
#include <genererNomPays.hpp>
#include <BoutonEnvoyer.hpp>

int main() {
	std::cout << "Bonjour le mondedd !" << std::endl;
	nbIP();
	std::cout << IP() << std::endl;
	std::cout << chance(5) << std::endl;
    //std::cout << genererNomPays() << std::endl;
	std::string pays=genererNomPays();
    //std::string pays="Polynésie";
    std::cout<<pays<<std::endl;

    
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
        Mise_A_jour_Position(pays,window,650,20);
        window.display();
    }

    return 0;
}

