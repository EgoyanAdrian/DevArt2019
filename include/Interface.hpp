#include <SFML/Graphics.hpp>
#include <BoutonEnvoyer.hpp>
void Interface(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY);
void Interface2(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY);
bool isover(sf::RectangleShape &Rectangle,uint mouse_X,uint mouse_Y);