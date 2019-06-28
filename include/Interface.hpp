#include <SFML/Graphics.hpp>
#include <genererNomPays.hpp>
#include <ZoneTexte.hpp>
#include <BoutonEnvoyer.hpp>
void Interface(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font,ZoneTexte &ZT,ZoneTexte &ZT1,ZoneTexte &ZT2,bool &EnvoyerisAcitve);
void Interface2(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font,bool &Binaire1,bool &Binaire,ZoneTexte &ZT,ZoneTexte &ZT1,ZoneTexte &ZT2,bool &EnvoyerisAcitve);
bool isover(sf::RectangleShape &Rectangle,uint mouse_X,uint mouse_Y);