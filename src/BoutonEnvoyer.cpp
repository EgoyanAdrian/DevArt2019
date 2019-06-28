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
	else if(pays=="Norvege"){
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
	else if(pays=="Polynesie"){
	
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
