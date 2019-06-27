#include <Interface.hpp>
#include <iostream>
#include <BoutonEnvoyer.hpp>

void Interface(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font){
	std::cout << pays << std::endl;
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

    uint RBEx=82;
    uint RBEy=30;
    Bouton BoutonEnvoyer(10+R1x+30+R2x+30, 500+diffY, RBEx, RBEy, "Envoyer", font);

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

    Mise_A_jour_Position(pays,w,size_X,size_Y,DiffX,diffY);

    if(isPush){
        BoutonEnvoyer.setClicked(BoutonEnvoyer.isOver(mouse_X, mouse_Y));
            if(BoutonEnvoyer.getClicked()){
                EnvoyerisFisrtPush=true;
                //pays=genererNomPays();
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

void Interface2(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font){
    std::cout << pays << std::endl;
    //recupere les dimentions de l'écran
    sf::Vector2u dimeEcran=w.getSize();
    uint diffX=dimeEcran.x-BsizeX;
    uint diffY=dimeEcran.y-BsizeY;

    
    uint DiffX;
    DiffX=diffX/3;

    // 1er fenetre de visionage
    uint R1x=250.f+DiffX;
    uint R1y=500.f+diffY;
    sf::RectangleShape Rectangle1(sf::Vector2f(R1x,R1y));
    Rectangle1.setOutlineColor(sf::Color::Black);
    Rectangle1.setOutlineThickness(3);
    Rectangle1.setPosition(10, 20);

    //dexieme feneter de visionage
    uint R2x=250.f+DiffX;
    uint R2y=500.f+diffY;

    sf::RectangleShape Rectangle2(sf::Vector2f(R2x,R2y));
    Rectangle2.setOutlineColor(sf::Color::Black);
    Rectangle2.setOutlineThickness(3);
    Rectangle2.setPosition(10+R1x+30, 20);
    
    //bouton envoyer
    uint RBEx=82;
    uint RBEy=30;
    Bouton BoutonEnvoyer(10+R1x+30+R2x+30, 500+diffY, RBEx, RBEy, "Envoyer", font);
    
    uint RBCx=132;
    uint RBCy=30;
    Bouton BoutonComp(10+R1x+30+R2x+30,400+diffY,RBCx,RBCy,"Comparaison",font);

    uint RWDx=200;
    uint RWDy=30;
    Bouton BoutonWindDeff(10+R1x+30+R2x+30,300+diffY,RWDx,RWDy,"Window Deffendeur",font);
    BoutonEnvoyer.upgrade(w);
    w.draw(BoutonEnvoyer);

    
    
    BoutonComp.upgrade(w);
    w.draw(BoutonComp);

    BoutonWindDeff.upgrade(w);
    w.draw(BoutonWindDeff);



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

    Mise_A_jour_Position(pays,w,size_X,size_Y,DiffX,diffY);    
    
    if(isPush){
        BoutonEnvoyer.setClicked(BoutonEnvoyer.isOver(mouse_X, mouse_Y));
            if(BoutonEnvoyer.getClicked()){
                EnvoyerisFisrtPush=true;
                 //pays=genererNomPays();
            }
    }
    else
        BoutonEnvoyer.setClicked(false);

}