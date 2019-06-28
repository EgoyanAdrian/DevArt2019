#include <BoutonEnvoyer.hpp>
#include <SFML/Graphics.hpp>
#include <unistd.h>

void Mise_A_jour_Position(std::string &pays,sf::RenderWindow &w,uint DiffX,uint diffY){
	//FRANCE CANADA ZIMBABWE NORVÉGE JAPON POLYNESIE
	if(pays=="France"){
		sf::Texture Textureplanisphere;

    	if(!Textureplanisphere.loadFromFile("planisphereFr.png"))
    		std::cout<<"erreur"<<std::endl;

    	//position du planisphére
    	uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    	uint size_Y=20;

    	//importation du planisphére
    	uint Rpx=220+DiffX;
    	uint Rpy=100+diffY/2;
    	sf::RectangleShape planisphere(sf::Vector2f(Rpx,Rpy)); 
		planisphere.setOutlineColor(sf::Color::Black);
    	planisphere.setOutlineThickness(3);
		planisphere.setPosition(size_X,size_Y);
		planisphere.setTexture(&Textureplanisphere);
    	w.draw(planisphere);
	}
	else if(pays=="Canada"){
		sf::Texture Textureplanisphere;

    	if(!Textureplanisphere.loadFromFile("planisphereCn.png"))
    		std::cout<<"erreur"<<std::endl;

    	//position du planisphére
    	uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    	uint size_Y=20;

    	//importation du planisphére
    	uint Rpx=220+DiffX;
    	uint Rpy=100+diffY/2;
    	sf::RectangleShape planisphere(sf::Vector2f(Rpx,Rpy)); 
		planisphere.setOutlineColor(sf::Color::Black);
    	planisphere.setOutlineThickness(3);
		planisphere.setPosition(size_X,size_Y);
		planisphere.setTexture(&Textureplanisphere);
    	w.draw(planisphere);
	}
	else if(pays=="Zimbabwe"){
	
		sf::Texture Textureplanisphere;

    	if(!Textureplanisphere.loadFromFile("planisphereZb.png"))
    		std::cout<<"erreur"<<std::endl;

    	//position du planisphére
    	uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    	uint size_Y=20;

    	//importation du planisphére
    	uint Rpx=220+DiffX;
    	uint Rpy=100+diffY/2;
    	sf::RectangleShape planisphere(sf::Vector2f(Rpx,Rpy)); 
		planisphere.setOutlineColor(sf::Color::Black);
    	planisphere.setOutlineThickness(3);
		planisphere.setPosition(size_X,size_Y);
		planisphere.setTexture(&Textureplanisphere);
    	w.draw(planisphere);
	}
	else if(pays=="Norvége"){
		sf::Texture Textureplanisphere;

    	if(!Textureplanisphere.loadFromFile("planisphereNv.png"))
    		std::cout<<"erreur"<<std::endl;

    	//position du planisphére
    	uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    	uint size_Y=20;

    	//importation du planisphére
    	uint Rpx=220+DiffX;
    	uint Rpy=100+diffY/2;
    	sf::RectangleShape planisphere(sf::Vector2f(Rpx,Rpy)); 
		planisphere.setOutlineColor(sf::Color::Black);
    	planisphere.setOutlineThickness(3);
		planisphere.setPosition(size_X,size_Y);
		planisphere.setTexture(&Textureplanisphere);
    	w.draw(planisphere);
	}
	else if(pays=="Japon"){
		sf::Texture Textureplanisphere;

    	if(!Textureplanisphere.loadFromFile("planisphereJp.png"))
    		std::cout<<"erreur"<<std::endl;

    	//position du planisphére
    	uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    	uint size_Y=20;

    	//importation du planisphére
    	uint Rpx=220+DiffX;
    	uint Rpy=100+diffY/2;
    	sf::RectangleShape planisphere(sf::Vector2f(Rpx,Rpy)); 
		planisphere.setOutlineColor(sf::Color::Black);
    	planisphere.setOutlineThickness(3);
		planisphere.setPosition(size_X,size_Y);
		planisphere.setTexture(&Textureplanisphere);
    	w.draw(planisphere);
	}
	else if(pays=="Polynésie"){
	
		sf::Texture Textureplanisphere;

    	if(!Textureplanisphere.loadFromFile("planispherePf.png"))
    		std::cout<<"erreur"<<std::endl;

    	//position du planisphére
    	uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    	uint size_Y=20;

    	//importation du planisphére
    	uint Rpx=220+DiffX;
    	uint Rpy=100+diffY/2;
    	sf::RectangleShape planisphere(sf::Vector2f(Rpx,Rpy)); 
		planisphere.setOutlineColor(sf::Color::Black);
    	planisphere.setOutlineThickness(3);
		planisphere.setPosition(size_X,size_Y);
		planisphere.setTexture(&Textureplanisphere);
    	w.draw(planisphere);
	}
}

void Action_Console(std::string &pays,sf::Font &font,sf::RenderWindow &w,uint CMD_lign_X,uint CMD_lign_Y){
 
 	std::string messagePays="Envoye du fichier en "+pays;
 	//definition des sf::text
	sf::Text ipAdressDepart;
	sf::Text MessageFichierRecu;
	sf::Text paysDestination;
	sf::Text ipAdressArriver;

	//definition de la font
	ipAdressDepart.setFont(font);
	MessageFichierRecu.setFont(font);
	paysDestination.setFont(font);
	ipAdressArriver.setFont(font);

	//definition de la taille
	ipAdressDepart.setCharacterSize(24);
	MessageFichierRecu.setCharacterSize(24);
	paysDestination.setCharacterSize(24);
	ipAdressArriver.setCharacterSize(24);

	//couleur du texte
	ipAdressDepart.setFillColor(sf::Color::Green);
	MessageFichierRecu.setFillColor(sf::Color::Green);
	paysDestination.setFillColor(sf::Color::Green);
	ipAdressArriver.setFillColor(sf::Color::Green);

	ipAdressDepart.setPosition(sf::Vector2f(200,200));
	ipAdressArriver.setPosition(sf::Vector2f(CMD_lign_X,CMD_lign_Y));

	//definition des messages
	MessageFichierRecu.setString("Fichier reçu");
	paysDestination.setString(messagePays);

	std::string ipadressmessage;

	ipAdressDepart.setString("test");
	w.draw(ipAdressDepart);


	uint nbIP1=nbIP();
	uint nbIP2=nbIP();
	bool Affiche=false;
	std::string TIP1[8];
	std::string TIP2[8];
	TIP1[0]=IPp();
	for(int i=1;i<nbIP1;i++)
		TIP1[i]=IP();
	std::string ip=IP();
	TIP2[0]=ip;
	TIP1[nbIP1]=ip;
	for(int i=1;i<nbIP2+1;i++)
		TIP2[i]=IP();

	TIP2[nbIP2]=IPp();
	uint timeIPE=(20/nbIP1);
	uint timeIPR=(20/nbIP2);
	unsigned tmax = timeIPE; 
	for(int i=1;i<nbIP1+1;i++){
		std::cout<<"ok"<<std::endl;
		ipadressmessage="Envoye en cours de " +TIP1[i-1] +" à "+TIP1[i]+"\n";//creer le message
		ipAdressDepart.setString(ipadressmessage);//le passe dans le sf::Text
		w.draw(ipAdressDepart);//draw du sf::Text
		sleep(tmax); //pause

	}
	/*std::cout<<"fichier reçu"<<std::endl;

	for(int i=0;i<nbIP2;i++){
		std::cout<<"Envoye en cours de " <<TIP2[i] <<" à "<<TIP2[i+1]<<std::endl;
		sleep(tmax); 

	}
	std::cout<<"fichier reçu"<<std::endl;*/
}