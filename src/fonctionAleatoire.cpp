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

std::string corruption(std::string _texte,std::string &corruptionValue) {
	srand(time(0));
	int val;
	corruptionValue="";
	std::string texteTempo = "";
	for(char & caractere : _texte) {
		val = rand()%9 + 1;
		if(val == 2){
			texteTempo += '0';
			corruptionValue+="2";
		}
		else if(val == 6){
			texteTempo += '1';
			corruptionValue+="6";
		}
		else if(val == 9){
			texteTempo = texteTempo;
			corruptionValue+="9";
		}
		else{
			texteTempo += caractere;
			corruptionValue+="0";
		}
	}
	return texteTempo;
}

void hacking(ZoneTexte & ZT2) {
	std::string zt2String;
	std::string zt2Tempo;
	uint nbChar = 0;
	uint posAct = 0;
	uint pos;

	if(ZT2.getBinaire()) {
		zt2String = ZT2.getTexte();
	} else {
		zt2String = convertirTaB(ZT2.getTexte());
	}

	std::cout << zt2String << std::endl;

	for(char & caractere : zt2String) {
		nbChar++;
	}

	srand(time(0));
	pos = rand()%nbChar + 1;

	for(char & caractere : zt2String) {
		if(posAct == pos) {
			if(caractere == '0')
				zt2Tempo += '1';
			else if(caractere == '1')
				zt2Tempo += '0';
		} else {
			zt2Tempo += caractere;
		}
		posAct++;
	}
	std::cout << zt2Tempo << std::endl;
	ZT2.clear();
	if(ZT2.getBinaire()) {
		for(char & caractere : zt2Tempo)
			ZT2.setTexte(caractere);
	} else {
		zt2Tempo = convertirBaT(zt2Tempo);
		for(char & caractere : zt2Tempo)
			ZT2.setTexte(caractere);
	}


	return;
}