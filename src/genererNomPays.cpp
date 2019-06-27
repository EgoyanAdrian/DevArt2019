#include <genererNomPays.hpp>

std::string genererNomPays() {
	// Faire un tirage aleatoire en fonction de l'heure
	srand(time(0));
	
	// Déclaration des variables
	std::string nomPays = "";
	int nbPays = 0, idPays;
	std::ifstream comptePays;	// Permet de compter de parcourir le fichier pour compter le nombre de ligne
	std::ifstream listePays;

	// Ouverture du meme fichier dans 2 variables differentes pour compter et lire
	comptePays.open("config/ListePays.txt", std::ifstream::in);
	listePays.open("config/ListePays.txt", std::ifstream::in);

	// Si le fichier na pa pus etre ouvert
	if (!comptePays || !listePays)
		std::cerr << "Erreur dans l'ouverture de listePays.txt" << std::endl;
	else {
		// Comptage du nompre de ligne
		while (comptePays >> nomPays)
			nbPays++;

		// Tirage aleatoire d'un nombre en fonction du nombre de ligne
		idPays = rand()%nbPays;

		for (int i = 0; i < idPays; i++) {
			listePays >> nomPays;
		}

		listePays >> nomPays;
	}

	return nomPays;
}