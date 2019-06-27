#include <BoutonEnvoyer.hpp>

void Mise_A_jour_Position(std::string &pays,sf::RenderWindow &w,uint size_X,uint size_Y,uint DiffX,uint diffY){
	//FRANCE CANADA ZIMBABWE NORVÉGE JAPON POLYNESIE
	sf::CircleShape PositionPoint;//creation d'un cercle
	PositionPoint.setRadius(2);//rayons de 2
	PositionPoint.setFillColor(sf::Color::Red);//couleur rouge
	if(pays=="France"){
		PositionPoint.setPosition(size_X+109.5f+DiffX/2,size_Y+20.f+diffY/4);//position du point pour la france
	}
	else if(pays=="Canada"){
		PositionPoint.setPosition(size_X+32+DiffX,size_Y+8+diffY/4);//position du point pour le canada
	}
	else if(pays=="Zimbabwe"){
		PositionPoint.setPosition(size_X+68+DiffX,size_Y+28+diffY/4);//position du point pour le zimbabwe
	}
	else if(pays=="Norvége"){
		PositionPoint.setPosition(size_X+65+DiffX,size_Y+3+diffY/4);//position du point pour la Norvége
	}
	else if(pays=="Japon"){
		PositionPoint.setPosition(size_X+105+DiffX,size_Y+10+diffY/4);//position du point pour le Japon
	}
	else if(pays=="Polynésie"){
		PositionPoint.setPosition(size_X+2+DiffX,size_Y+30+diffY/4);//position du point pour la polynesie
	}
	w.draw(PositionPoint);
}

