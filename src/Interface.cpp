#include <Interface.hpp>
#include <iostream>

void Interface(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font){
	//recupere les dimentions de l'écran
    sf::Vector2u dimeEcran=w.getSize();
    uint diffX=dimeEcran.x-BsizeX;
    uint diffY=dimeEcran.y-BsizeY;

    
    uint DiffX;
    DiffX=diffX/3;

    // 1er fenetre de visionage
    uint R1x=250.f+DiffX;
    uint R1y=550.f+diffY;
	sf::RectangleShape Rectangle1(sf::Vector2f(R1x,R1y));
    Rectangle1.setOutlineColor(sf::Color::Black);
    Rectangle1.setOutlineThickness(3);
	Rectangle1.setPosition(10, 20);

	//dexieme feneter de visionage
    uint R2x=250.f+DiffX;
    uint R2y=550.f+diffY;

	sf::RectangleShape Rectangle2(sf::Vector2f(R2x,R2y));
    Rectangle2.setOutlineColor(sf::Color::Black);
    Rectangle2.setOutlineThickness(3);
	Rectangle2.setPosition(10+R1x+30, 20);

    uint R3x=120+DiffX;
    uint R3y=50.+diffY;
	Bouton BoutonEnvoyer(10+R1x+30+R2x+30, 500+diffY, R3x, R3y, "Test", font);

    BoutonEnvoyer.upgrade(w);
    w.draw(BoutonEnvoyer);

    //deffini le bouton envoyer
	/*sf::RectangleShape BoutonEnvoyer(sf::Vector2f(120.f+diffX,50.f+diffY)); 
	BoutonEnvoyer.setOutlineColor(sf::Color::Black);
    BoutonEnvoyer.setOutlineThickness(3);
	BoutonEnvoyer.setPosition(650+diffX, 500+diffY);*/

	//affiche les deux fenetres
    w.draw(Rectangle1);
    w.draw(Rectangle2);

    //affiche le bouton envoyer
    //w.draw(BoutonEnvoyer);


    sf::Texture Textureplanisphere;

    if(!Textureplanisphere.loadFromFile("planisphere.png"))
    	std::cout<<"erreur"<<std::endl;

    //position du planisphére
    uint size_X=10+R1x+30+R2x+30;
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

    if(isPush){
        BoutonEnvoyer.setClicked(BoutonEnvoyer.isOver(mouse_X, mouse_Y));
            if(BoutonEnvoyer.getClicked()){
                EnvoyerisFisrtPush=true;
                BoutEnvoyer(pays,w,size_X,size_Y,EnvoyerisFisrtPush,isPush,mouse_X,mouse_Y);
            }
    }
    else
        BoutonEnvoyer.setClicked(false);

}

bool isover(sf::RectangleShape &Rectangle,uint mouse_X,uint mouse_Y){
    sf::Vector2f pos=Rectangle.getPosition();
    sf::Vector2f size=Rectangle.getSize();
    return(((pos.x< mouse_X) && (pos.x+ size.x > mouse_X)) && ((pos.y< mouse_Y) && (pos.y+ size.y > mouse_Y)));
}

void Interface2(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY){
    // 1er fenetre de visionage
    sf::RectangleShape Rectangle1(sf::Vector2f(300.f,450.f));
    Rectangle1.setOutlineColor(sf::Color::Black);
    Rectangle1.setOutlineThickness(3);
    Rectangle1.setPosition(10, 20);

    //dexieme feneter de visionage
    sf::RectangleShape Rectangle2(sf::Vector2f(300.f,450.f));
    Rectangle2.setOutlineColor(sf::Color::Black);
    Rectangle2.setOutlineThickness(3);
    Rectangle2.setPosition(340, 20);



    //Bouton BoutonEnvoyer(650+diffX, 500+diffY, 120.f+diffX, 50.f+diffY, "Test", font);

   // w.draw(BoutonEnvoyer);
   // BoutonEnvoyer.upgrade(w);
    //deffini le bouton envoyer
    /*sf::RectangleShape BoutonEnvoyer(sf::Vector2f(120.f,50.f)); 
    BoutonEnvoyer.setOutlineColor(sf::Color::Black);
    BoutonEnvoyer.setOutlineThickness(3);
    BoutonEnvoyer.setPosition(650, 500);*/

    //affiche les deux fenetres
    w.draw(Rectangle1);
    w.draw(Rectangle2);

    //affiche le bouton envoyer
    //w.draw(BoutonEnvoyer);


    sf::Texture Textureplanisphere;

    if(!Textureplanisphere.loadFromFile("planisphere.png"))
        std::cout<<"erreur"<<std::endl;

    //position du planisphére
    uint size_X=650;
    uint size_Y=20;

    //importation du planisphére
    sf::RectangleShape planisphere(sf::Vector2f(120.f,50.f)); 
    planisphere.setOutlineColor(sf::Color::Black);
    planisphere.setOutlineThickness(3);
    planisphere.setPosition(size_X,size_Y);
    planisphere.setTexture(&Textureplanisphere);
    w.draw(planisphere);


    /*if(isPush){
    BoutonEnvoyer.setClicked(BoutonEnvoyer.isOver(mouse_X, mouse_Y));
        if(BoutonEnvoyer.getClicked()){
            EnvoyerisFisrtPush=true;
            BoutEnvoyer(pays,w,size_X,size_Y,EnvoyerisFisrtPush,isPush,mouse_X,mouse_Y);
        }
    }*/
    //bouton de comparaison
    sf::RectangleShape CompaBouton(sf::Vector2f(120.f,50.f));
    CompaBouton.setOutlineColor(sf::Color::Black);
    CompaBouton.setOutlineThickness(3);
    CompaBouton.setPosition(10, 20);
}