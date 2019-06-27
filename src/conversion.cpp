#include <conversion.hpp>

std::string convertirTaB(std::string texte) {
	std::string bits = "";

	// Parcours de chaque caractere dans le string
	for (char& caractere : texte) {
    	for (int i = 0; i < 8; i++)
		{
			// Si le caractere en bit vaut 1
  			if (((caractere >> i) & 1) == 1)
  				bits += "1";
  			else
  				bits += "0";
		}	
	}

	return bits;
}

std::string convertirBaT(std::string bits) {
	std::string texte = "";
	std::string motBits = "";
	char nbCaractere = 0;
	for (char& caractere : texte) {
		motBits += caractere;
		nbCaractere++;

		if (nbCaractere == 8) {
		}
	}

	return texte;
}