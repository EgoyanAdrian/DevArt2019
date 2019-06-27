#include <BoutonEnvoyer.hpp>
void Mise_A_jour_Position(std::string pays,sf::RenderWindow &w,uint size_X,uint size_Y){
	//FRANCE CANADA ZIMBABWE NORVÉGE JAPON POLYNESIE
	sf::CircleShape PositionPoint;
	PositionPoint.setRadius(2);
	PositionPoint.setFillColor(sf::Color::Red);
	if(pays=="France"){
		PositionPoint.setPosition(size_X+59.5f,size_Y+12.f);
	}
	else if(pays=="Canada"){
		PositionPoint.setPosition(size_X+32,size_Y+8);
	}
	else if(pays=="Zimbabwe"){
		PositionPoint.setPosition(size_X+68,size_Y+28);
	}
	else if(pays=="Norvége"){
		PositionPoint.setPosition(size_X+65,size_Y+3);
	}
	else if(pays=="Japon"){
		PositionPoint.setPosition(size_X+105,size_Y+10);
	}
	else if(pays=="Polynésie"){
		PositionPoint.setPosition(size_X+2,size_Y+30);
	}
	w.draw(PositionPoint);
}