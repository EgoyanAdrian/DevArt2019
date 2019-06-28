#include <fonctionAleatoire.hpp>

int nbIP(){
	int valeur;
	do{
		srand(time(0));
		valeur=rand()%7 + 3;//choisie un valeur aleatoire entre 3 et 7
	}while(valeur>7);
	return valeur;
}

std::string IP(){
	//initialisation des variables
	std::ostringstream tempo;
	std::string adressIP="";
	
	//selection aléatoire de la premier valeur entre 11 et 171
	int valeur=rand()%171+11;
	tempo<<valeur;
	std::string tmpoString(tempo.str());//convertion entre int et string
	adressIP+=tmpoString;//ajout a l'adress IP

	for(int i=0; i<3;i++){
	adressIP+=".";
	std::ostringstream tempo;
	int test=rand()%254+1;
	tempo<<test;
	std::string tmpoString(tempo.str());//convertion entre int et string
	adressIP+=tmpoString;//ajout a l'adress IP
	
	}	
	return adressIP;//retourne l'adress IP
}

std::string IPp(){
	//initialisation des variables
	std::ostringstream tempo;
	std::string adressIP="";
	
	//selection aléatoire de la premier valeur entre 11 et 171
	adressIP+="192.168";//ajout a l'adress IP

	for(int i=0; i<2;i++){
	adressIP+=".";
	std::ostringstream tempo;
	int test=rand()%254+1;
	tempo<<test;
	std::string tmpoString(tempo.str());//convertion entre int et string
	adressIP+=tmpoString;//ajout a l'adress IP
	
	}	
	return adressIP;//retourne l'adress IP
}

bool chance(int max){
	int valeur=rand()%max+1;
	return(1==valeur);
}

std::string corruption(std::string _texte) {
	srand(time(0));
	int val;
	std::string texteTempo = "";

	for(char & caractere : _texte) {
		val = rand()%9 + 1;
		
		if(val == 2)
			texteTempo += '0';
		else if(val == 6)
			texteTempo += '1';
		else if(val == 9)
			texteTempo = texteTempo;
		else
			texteTempo += caractere;

		std::cout << val;
	}

	std::cout << std::endl;
	std::cout << texteTempo << std::endl;
	return texteTempo;
}