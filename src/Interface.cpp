#include <Interface.hpp>
#include <iostream>
#include <BoutonEnvoyer.hpp>

void Interface(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font,ZoneTexte &ZT,ZoneTexte &ZT1,ZoneTexte &ZT2,bool &EnvoyerisAcitve,bool &corrup,bool &isAlreadyPush){
   //recupere les dimentions de l'écran
    sf::Vector2u dimeEcran=w.getSize();
    uint diffX=dimeEcran.x-BsizeX;
    uint diffY=dimeEcran.y-BsizeY;

    
    uint DiffX;
    DiffX=diffX/3;

    // 1er fenetre de visionage
    uint R1x=250.f+DiffX;
    uint R1y=550.f+diffY;

	ZT1.setSize(sf::Vector2f(R1x,R1y));
    ZT1.setPosition(10, 20);

    //dexieme feneter de visionage
    uint R2x=250.f+DiffX;
    uint R2y=550.f+diffY;

    ZT2.setSize(sf::Vector2f(R2x,R2y));
    ZT2.setPosition(10+R1x+30, 20);


    uint RBEx=82;
    uint RBEy=30;
    Bouton BoutonEnvoyer(10+R1x+30+R2x+30, 500+diffY, RBEx, RBEy, "Envoyer", font);

    BoutonEnvoyer.upgrade(w);
    w.draw(BoutonEnvoyer);


	//affiche les deux fenetres



    //affichage du CMD
    uint Rpx=220+DiffX;
    uint Rpy=200+diffY/2;
    uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    uint size_Y=20+100+diffY/2+20;

    ZT.setSize(sf::Vector2f(Rpx,Rpy));
    ZT.setPosition(size_X,size_Y);

    uint CMD_lign_X=size_X;
    uint CMD_lign_Y=size_Y;
    Mise_A_jour_Position(pays,w,DiffX,diffY);

    if(isPush&&(!isAlreadyPush)){
        BoutonEnvoyer.setClicked(BoutonEnvoyer.isOver(mouse_X, mouse_Y));
            if(BoutonEnvoyer.getClicked()){
                isAlreadyPush=true;
                EnvoyerisFisrtPush=true;
                pays=genererNomPays();
                EnvoyerisAcitve=true;
                if(chance(10)){
                    corruption(ZT1.getTexte(),corrup);

                }
            }
        isPush=false;
    }
    else
        BoutonEnvoyer.setClicked(false);

}

bool isover(sf::RectangleShape &Rectangle,uint mouse_X,uint mouse_Y){
    sf::Vector2f pos=Rectangle.getPosition();
    sf::Vector2f size=Rectangle.getSize();
    return(((pos.x< mouse_X) && (pos.x+ size.x > mouse_X)) && ((pos.y< mouse_Y) && (pos.y+ size.y > mouse_Y)));
}

void Interface2(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font,bool &Binaire1, bool &Binaire2,ZoneTexte &ZT,ZoneTexte &ZT1,ZoneTexte &ZT2,bool &EnvoyerisAcitve,bool &corrup,bool &isAlreadyPush,bool &isAlreadyPushTB1,bool &isAlreadyPushTB2){
    //recupere les dimentions de l'écran
    sf::Vector2u dimeEcran=w.getSize();
    uint diffX=dimeEcran.x-BsizeX;
    uint diffY=dimeEcran.y-BsizeY;

    std::string motBinaire1;
    std::string motBinaire2;

    std::string motcharac1;
    std::string motcharac2;


    uint DiffX;
    DiffX=diffX/3;

    // 1er fenetre de visionage
    uint R1x=250.f+DiffX;
    uint R1y=500.f+diffY;
    ZT1.setSize(sf::Vector2f(R1x,R1y));
    ZT1.setPosition(10, 20);

    //dexieme feneter de visionage
    uint R2x=250.f+DiffX;
    uint R2y=500.f+diffY;


    ZT2.setSize(sf::Vector2f(R2x,R2y));
    ZT2.setPosition(10+R1x+30, 20);
    //bouton envoyer
    uint RBEx=82;
    uint RBEy=30;
    Bouton BoutonEnvoyer(10+R1x+30+R2x+30, 500+diffY, RBEx, RBEy, "Envoyer", font);
    
    uint RBCx=132;
    uint RBCy=30;
    Bouton BoutonComp(10+R1x+30+R2x+30,460+diffY,RBCx,RBCy,"Comparaison",font);

    uint RWDx=200;
    uint RWDy=30;
    Bouton BoutonWindDeff(10+R1x+30+R2x+30,420+diffY,RWDx,RWDy,"Window Defendeur",font);
    BoutonEnvoyer.upgrade(w);
    w.draw(BoutonEnvoyer);

    
    
    BoutonComp.upgrade(w);
    w.draw(BoutonComp);

    BoutonWindDeff.upgrade(w);
    w.draw(BoutonWindDeff);


    Bouton TB1(10+40+DiffX/2,540+diffY,132,25,"Texte/Binaire",font);
    TB1.upgrade(w);
    w.draw(TB1);

    Bouton TB2(10+65+R1x+DiffX/2,540+diffY,132,25,"Texte/Binaire",font);
    TB2.upgrade(w);
    w.draw(TB2);

    if(isPush&&(!isAlreadyPushTB1)){
        TB1.setClicked(TB1.isOver(mouse_X, mouse_Y));
        if(TB1.getClicked()){
        isAlreadyPushTB1=true;
        std::cout<<"tb1 ok"<<std::endl;
            if(!Binaire1){
                motBinaire1 = convertirTaB(ZT1.getTexte());
                ZT1.clear();
                for(char & caractere : motBinaire1) {
                    ZT1.setTexte(caractere);
                }
                Binaire1=true;
            }
            else{
                motcharac1=convertirBaT(ZT1.getTexte());
                for(char & caractere : motcharac1){
                    ZT1.setTexte(caractere);
                }
                Binaire1=false;
            }
        }
    }
    else{
        TB1.setClicked(false);
    }
    

    if(isPush&&(!isAlreadyPushTB2)){
        TB2.setClicked(TB2.isOver(mouse_X, mouse_Y));
        if(TB2.getClicked()){
            isAlreadyPushTB2=true;
        std::cout<<"tb2 ok"<<std::endl;
            if(!Binaire2){
                
                Binaire2=true;
            }
            else{
                std::cout<<"affiche du texte"<<std::endl;
                Binaire2=false;
            }
        }
    }
    else{
        TB2.setClicked(false);
    }
    
        //affichage de la console



    //affichage du CMD
    uint Rpx=220+DiffX;
    uint Rpy=200+diffY/2;
    uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    uint size_Y=20+100+diffY/2+20;
    ZT.setSize(sf::Vector2f(Rpx,Rpy));
    ZT.setPosition(size_X,size_Y);

    Mise_A_jour_Position(pays,w,DiffX,diffY);    
    
    if(isPush&&(!isAlreadyPush)){
        BoutonEnvoyer.setClicked(BoutonEnvoyer.isOver(mouse_X, mouse_Y));
            if(BoutonEnvoyer.getClicked()){
                isAlreadyPush=false;
                EnvoyerisFisrtPush=true;
                pays=genererNomPays();
                EnvoyerisAcitve=true;
                if(chance(10)){
                    corruption(ZT1.getTexte(),corrup);
                }
            }
        isPush=false;
    }
}
    