#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <ZoneTexte.hpp>
#include <conversion.hpp>

int nbIP();
std::string IP();
std::string IPp();
bool chance(int max);
std::string corruption(std::string _texte,std::string &corruptionValue);
void hacking(ZoneTexte & ZT2);