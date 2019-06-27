#include <BoutonEnvoyer.hpp>
void Mise_A_jour_Position(std::string pays,sf::RenderWindow &w,uint size_X,uint size_Y){
	//FRANCE CANADA ZIMBABWE NORVÉGE JAPON POLYNESIE
	sf::CircleShape PositionPoint;//creation d'un cercle
	PositionPoint.setRadius(2);//rayons de 2
	PositionPoint.setFillColor(sf::Color::Red);//couleur rouge
	if(pays=="France"){
		PositionPoint.setPosition(size_X+59.5f,size_Y+12.f);//position du point pour la france
	}
	else if(pays=="Canada"){
		PositionPoint.setPosition(size_X+32,size_Y+8);//position du point pour le canada
	}
	else if(pays=="Zimbabwe"){
		PositionPoint.setPosition(size_X+68,size_Y+28);//position du point pour le zimbabwe
	}
	else if(pays=="Norvége"){
		PositionPoint.setPosition(size_X+65,size_Y+3);//position du point pour la Norvége
	}
	else if(pays=="Japon"){
		PositionPoint.setPosition(size_X+105,size_Y+10);//position du point pour le Japon
	}
	else if(pays=="Polynésie"){
		PositionPoint.setPosition(size_X+2,size_Y+30);//position du point pour la polynesie
	}
	w.draw(PositionPoint);
}

void BoutEnvoyer(std::string pays,sf::RenderWindow &w,uint size_X,uint size_Y,bool &EnvoyerisFisrtPush,bool isPush,uint mouse_X,uint mouse_Y){

}