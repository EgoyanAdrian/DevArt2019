#include <SFML/Graphics.hpp>
#include <genererNomPays.hpp>
#include <ZoneTexte.hpp>
#include <BoutonEnvoyer.hpp>
#include <conversion.hpp>
void Interface(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font,ZoneTexte &ZT,ZoneTexte &ZT1,ZoneTexte &ZT2,bool &EnvoyerisAcitve,bool &corruption,bool &isAlreadyPush,std::string &corruptionValue,bool &tjourCorr);
void Interface2(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font,bool &Binaire1,bool &Binaire,ZoneTexte &ZT,ZoneTexte &ZT1,ZoneTexte &ZT2,bool &EnvoyerisAcitve,bool &corruption,bool &isAlreadyPush,bool &isAlreadyPushTB1,bool &isAlreadyPushTB2,std::string &corruptionValue,bool &tjourCorr,bool &isAlreadyPushBC);
void compareCorronp(std::string orrig,std::string corrom,std::string &indiceCor,ZoneTexte &AideCorrom,sf::RenderWindow &w,Bouton &BoutCompa,sf::RectangleShape &SousAideeCorrom,uint mouse_X,uint mouse_Y,bool &isAlreadyPushBC,bool &isPush, bool &tjourCorr);
bool isover(sf::RectangleShape &Rectangle,uint mouse_X,uint mouse_Y);
bool ComparaisonBetB(std::string orrig,std::string corrom,std::string &indiceCor);