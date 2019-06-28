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
        if(caractere != '\n') {
            motBits += caractere;
            nbCaractere++;
        }

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

char lettreKey(sf::Event _event, bool isShiftPressed) {
	char lettre;

	if(!isShiftPressed) {
		switch(_event.key.code) {
    	    case sf::Keyboard::A:
    	        	lettre = 'a';
    	        break;
    	    case sf::Keyboard::B:
    	        	lettre = 'b';
    	        break;
    	    case sf::Keyboard::C:
    	        	lettre = 'c';
    	        break;
    	    case sf::Keyboard::D:
    	        	lettre = 'd';
    	        break;
    	    case sf::Keyboard::E:
    	        	lettre = 'e';
    	        break;
    	    case sf::Keyboard::F:
    	        	lettre = 'f';
    	        break;
    	    case sf::Keyboard::G:
    	        	lettre = 'g';
    	        break;
    	    case sf::Keyboard::H:
    	        	lettre = 'h';
    	        break;
    	    case sf::Keyboard::I:
    	        	lettre = 'i';
    	        break;
    	    case sf::Keyboard::J:
    	        	lettre = 'j';
    	        break;
    	    case sf::Keyboard::K:
    	        	lettre = 'k';
    	        break;
    	    case sf::Keyboard::L:
    	        	lettre = 'l';
    	        break;
    	    case sf::Keyboard::M:
    	        	lettre = 'm';
    	        break;
    	    case sf::Keyboard::N:
    	        	lettre = 'n';
    	        break;
    	    case sf::Keyboard::O:
    	        	lettre = 'o';
    	        break;
    	    case sf::Keyboard::P:
    	        	lettre = 'p';
    	        break;
    	    case sf::Keyboard::Q:
    	        	lettre = 'q';
    	        break;
    	    case sf::Keyboard::R:
    	        	lettre = 'r';
    	        break;
    	    case sf::Keyboard::S:
    	        	lettre = 's';
    	        break;
    	    case sf::Keyboard::T:
    	        	lettre = 't';
    	        break;
    	    case sf::Keyboard::U:
    	        	lettre = 'u';
    	        break;
    	    case sf::Keyboard::V:
    	        	lettre = 'v';
    	        break;
    	    case sf::Keyboard::W:
    	        	lettre = 'w';
    	        break;
    	    case sf::Keyboard::X:
    	        	lettre = 'x';
    	        break;
    	    case sf::Keyboard::Y:
    	        	lettre = 'y';
    	        break;
    	    case sf::Keyboard::Z:
    	        	lettre = 'z';
    	        break;
            case sf::Keyboard::Space:
                    lettre = ' ';
                break;
            case sf::Keyboard::BackSpace:
                    lettre = '-';
                break;
            case sf::Keyboard::Num0:
                    lettre = '0';
                break;
            case sf::Keyboard::Numpad0:
                    lettre = '0';
                break;
            case sf::Keyboard::Num1:
                    lettre = '1';
                break;
            case sf::Keyboard::Numpad1:
                    lettre = '1';
                break;
    	    default:
    	            lettre = '\n';
    	        break;
    	}
    } else {
    	switch(_event.key.code) {
    		case sf::Keyboard::A:
    				lettre = 'A';
    			break;
    	    case sf::Keyboard::B:
    	        	lettre = 'B';
    	        break;
    	    case sf::Keyboard::C:
    	        	lettre = 'C';
    	        break;
    	    case sf::Keyboard::D:
    	        	lettre = 'D';
    	        break;
    	    case sf::Keyboard::E:
    	        	lettre = 'E';
    	        break;
    	    case sf::Keyboard::F:
    	        	lettre = 'F';
    	        break;
    	    case sf::Keyboard::G:
    	        	lettre = 'G';
    	        break;
    	    case sf::Keyboard::H:
    	        	lettre = 'H';
    	        break;
    	    case sf::Keyboard::I:
    	        	lettre = 'I';
    	        break;
    	    case sf::Keyboard::J:
    	        	lettre = 'J';
    	        break;
    	    case sf::Keyboard::K:
    	        	lettre = 'K';
    	        break;
    	    case sf::Keyboard::L:
    	        	lettre = 'L';
    	        break;
    	    case sf::Keyboard::M:
    	        	lettre = 'M';
    	        break;
    	    case sf::Keyboard::N:
    	        	lettre = 'N';
    	        break;
    	    case sf::Keyboard::O:
    	        	lettre = 'O';
    	        break;
    	    case sf::Keyboard::P:
    	        	lettre = 'P';
    	        break;
    	    case sf::Keyboard::Q:
    	        	lettre = 'Q';
    	        break;
    	    case sf::Keyboard::R:
    	        	lettre = 'R';
    	        break;
    	    case sf::Keyboard::S:
    	        	lettre = 'S';
    	        break;
    	    case sf::Keyboard::T:
    	        	lettre = 'T';
    	        break;
    	    case sf::Keyboard::U:
    	        	lettre = 'U';
    	        break;
    	    case sf::Keyboard::V:
    	        	lettre = 'V';
    	        break;
    	    case sf::Keyboard::W:
    	        	lettre = 'W';
    	        break;
    	    case sf::Keyboard::X:
    	        	lettre = 'X';
    	        break;
    	    case sf::Keyboard::Y:
    	        	lettre = 'Y';
    	        break;
    	    case sf::Keyboard::Z:
    	        	lettre = 'Z';
    	        break;
            case sf::Keyboard::Space:
                    lettre = ' ';
                break;
            case sf::Keyboard::BackSpace:
                    lettre = '-';
                break;
            case sf::Keyboard::Num0:
                    lettre = '0';
                break;
            case sf::Keyboard::Numpad0:
                    lettre = '0';
                break;
            case sf::Keyboard::Num1:
                    lettre = '1';
                break;
            case sf::Keyboard::Numpad1:
                    lettre = '1';
                break;
    		default:
    				lettre = '\n';
    			break;
    	}
    }

    return lettre;
}