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
	for (char& caractere : bits) {
		motBits += caractere;
		nbCaractere++;

		if (nbCaractere >= 8) {
			std::bitset<8> bitsMot(motBits);
			nbCaractere = 0;
			motBits = "";
			unsigned long i = bitsMot.to_ulong(); 
			texte += static_cast<unsigned char>( i );
		}
	}

	return texte;
}