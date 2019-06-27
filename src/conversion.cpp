#include <conversion.hpp>

std::string convertirTaB(std::string texte) {
	std::string bits = "", bitsTemp = "";

	// Parcours de chaque caractere dans le string
	for (char& caractere : texte) {
    	for (int i = 0; i < 8; i++)
		{
			// Si le caractere en bit vaut 1
  			if (((caractere >> i) & 1) == 1)
  				bitsTemp += "1";
  			else
  				bitsTemp += "0";
		}

		// invereser le sens de la suite de 8 bits pour être dans le bonne ordre
		reverse(bitsTemp.begin(), bitsTemp.end());
		bits += bitsTemp;
		bitsTemp = "";
	}

	return bits;
}

std::string convertirBaT(std::string bits) {
	std::string texte = "";
	std::string motBits = "";
	char nbCaractere = 0;

	// Parcours de chaque caractere
	for (char& caractere : bits) {
		motBits += caractere;
		nbCaractere++;

		// Si il y a 8 caractere alors une suite de bits
		if (nbCaractere >= 8) {
			std::bitset<8> bitsMot(motBits);
			nbCaractere = 0;
			motBits = "";

			// Conversion de chaque suite de bits en caractere
			unsigned long i = bitsMot.to_ulong(); 
			texte += static_cast<unsigned char>( i );
		}
	}

	return texte;
}