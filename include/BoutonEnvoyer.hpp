#include <iostream>
#include <Bouton.hpp>
#include <genererNomPays.hpp>
#include <SFML/Graphics.hpp>
void Mise_A_jour_Position(std::string &pays,sf::RenderWindow &w,uint size_X,uint size_Y);
void BoutEnvoyer(std::string pays,sf::RenderWindow &w,uint size_X,uint size_Y,bool &EnvoyerisFisrtPush,bool isPush,uint mouse_X,uint mouse_Y);