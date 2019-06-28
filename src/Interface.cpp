#include <Interface.hpp>
#include <iostream>
#include <BoutonEnvoyer.hpp>

void Interface(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font,ZoneTexte &ZT,ZoneTexte &ZT1,ZoneTexte &ZT2,bool &EnvoyerisAcitve,bool &corrup,bool &isAlreadyPush,std::string &corruptionValue,bool &tjourCorr){
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
                if(chance(3)){
                    tjourCorr=corrup=true;
                    ZT2.clear();
                    std::cout<<"corruption"<<std::endl;
                    std::string modif=corruption(convertirTaB(ZT1.getTexte()),corruptionValue);
                    for(char & caractere : modif) {
                        ZT2.setTexte(caractere);
                    }
                    ZT2.upgrade(w);
                    w.draw(ZT2);

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

void Interface2(sf::RenderWindow &w,uint mouse_X,uint mouse_Y,bool isPush,bool &EnvoyerisFisrtPush,std::string &pays,uint BsizeX,uint BsizeY,sf::Font &font,bool &Binaire1, bool &Binaire2,ZoneTexte &ZT,ZoneTexte &ZT1,ZoneTexte &ZT2,bool &EnvoyerisAcitve,bool &corrup,bool &isAlreadyPush,bool &isAlreadyPushTB1,bool &isAlreadyPushTB2,std::string &corruptionValue,bool &tjourCorr,bool &isAlreadyPushBC){
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
    
    

    uint RWDx=200;
    uint RWDy=30;
    Bouton BoutonWindDeff(10+R1x+30+R2x+30,420+diffY,RWDx,RWDy,"Window Defendeur",font,false);
    BoutonEnvoyer.upgrade(w);
    w.draw(BoutonEnvoyer);

    
    
    

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
            if(!Binaire1){
                Binaire1=true;
                ZT1.setBinaire(Binaire1);
                motBinaire1 = convertirTaB(ZT1.getTexte());
                ZT1.clear();
                for(char & caractere : motBinaire1) {
                    ZT1.setTexte(caractere);
                }
            }
            else{
                Binaire1=false;
                ZT1.setBinaire(Binaire1);
                motcharac1=convertirBaT(ZT1.getTexte());
                ZT1.clear();
                for(char & caractere : motcharac1){
                    ZT1.setTexte(caractere);
                }
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
            if(!Binaire2){
                Binaire2=true;
                ZT2.setBinaire(Binaire2);
                motBinaire2 = convertirTaB(ZT2.getTexte());
                ZT2.clear();
                for(char & caractere : motBinaire2) {
                    ZT2.setTexte(caractere);
                }
                ZT2.upgrade(w);
                w.draw(ZT2);
            }
            else{
                Binaire2 = false;
                ZT2.setBinaire(Binaire2);
                motcharac2=convertirBaT(ZT2.getTexte());
                ZT2.clear();
                for(char & caractere : motcharac2){
                    ZT2.setTexte(caractere);
                }
                ZT2.upgrade(w);
                w.draw(ZT2);
            }
        }
    }
    else{
        TB2.setClicked(false);
    }
    
        //affichage de la console

    uint RBCx=132;
    uint RBCy=30;
    Bouton BoutonComp(10+R1x+30+R2x+30,460+diffY,RBCx,RBCy,"Comparaison",font,false);

    


    if(corrup||tjourCorr){
        BoutonComp.setIsVisible(true);
    }
    else
        BoutonComp.setIsVisible(false);

    BoutonComp.upgrade(w);
    w.draw(BoutonComp);

    //affichage du CMD
    uint Rpx=220+DiffX;
    uint Rpy=200+diffY/2;
    uint size_X=10+250.f+DiffX+30+250.f+DiffX+30;
    uint size_Y=20+100+diffY/2+20;
    ZT.setSize(sf::Vector2f(Rpx,Rpy));
    ZT.setPosition(size_X,size_Y);

    Mise_A_jour_Position(pays,w,DiffX,diffY);    
    
    sf::RectangleShape SousAideeCorrom;
    SousAideeCorrom.setSize(sf::Vector2f(Rpx,Rpy));
    SousAideeCorrom.setPosition(size_X,size_Y);
    SousAideeCorrom.setFillColor(sf::Color::White);
    
    ZoneTexte AideCorrum(0,0,0,0,font);
    AideCorrum.setSize(sf::Vector2f(Rpx,Rpy));
    AideCorrum.setPosition(size_X,size_Y);


    if(isPush&&(!isAlreadyPush)&&!tjourCorr){
        BoutonEnvoyer.setClicked(BoutonEnvoyer.isOver(mouse_X, mouse_Y));
            if(BoutonEnvoyer.getClicked()){
                isAlreadyPush=true;
                EnvoyerisFisrtPush=true;
                pays=genererNomPays();
                EnvoyerisAcitve=true;
                std::string ZT2tempo = ZT2.getTexte();
                ZT1.clear();
                for(char & caractere : ZT2tempo)
                    ZT1.setTexte(caractere);

                if(chance(3)){
                    std::cout<<"corruption"<<std::endl;
                    tjourCorr=corrup=true;
                    ZT2.clear();
                    std::string modif=corruption(convertirTaB(ZT1.getTexte()),corruptionValue);
                    Binaire2 = true;
                    ZT2.setBinaire(Binaire2);
                    for(char & caractere : modif) {
                        ZT2.setTexte(caractere);
                    }
                    ZT2.upgrade(w);
                    w.draw(ZT2);
                }
            }
        isPush=false;
    }
    if(tjourCorr){
        compareCorronp(ZT1.getTexte(),ZT2.getTexte(),corruptionValue,AideCorrum,w,BoutonComp,SousAideeCorrom,mouse_X,mouse_Y,isAlreadyPushBC,isPush,tjourCorr);
    }
}

void compareCorronp(std::string orrig,std::string corrom,std::string &indiceCor,ZoneTexte &AideCorrom,sf::RenderWindow &w,Bouton &BoutCompa,sf::RectangleShape &SousAideeCorrom,uint mouse_X,uint mouse_Y,bool &isAlreadyPushBC,bool &isPush,bool &tjourCorr){
    std::string message="Attention des donnees on etais corrompu\nVoici comment les recuperes";
    std::string Aidee="Les 0 signifie de le bytes (0 ou 1) non pas changes, les 2 signifie que les bytes ont etais change par des 0\nles 6 signifie que les bytes on etais change en 1 et\n le 9 signifie que les bytes on etais change pas des 0 ou des 1";
    std::string liste="Les modifications doivent etre apporter sur la fenetre en rouge\nvoici votre aide: "+indiceCor+"\n";
    std::string consig="effectuer les modifications puis clicke sur 'Comparaison'";
    
    

    for(char & caractere : message) {
        AideCorrom.setTexte(caractere);
    }
    for(char & caractere : Aidee) {
        AideCorrom.setTexte(caractere);
    }
    for(char & caractere : liste) {
        AideCorrom.setTexte(caractere);
    }
    for(char & caractere : consig) {
        AideCorrom.setTexte(caractere);
    }
    AideCorrom.upgrade(w);
    w.draw(AideCorrom);

    if(tjourCorr){
        std::string liste="Le probleme n'est pas resolute voici l'aide avec les modification trouver\n"+indiceCor+"\n";
        for(char & caractere : liste){
            AideCorrom.setTexte(caractere);
        }
        AideCorrom.upgrade(w);
        w.draw(AideCorrom);
    }

    if(isPush&&(!isAlreadyPushBC)){
        
        BoutCompa.setClicked(BoutCompa.isOver(mouse_X,mouse_Y));
        if(BoutCompa.getClicked()){
            std::cout<<"ok"<<std::endl;
            isAlreadyPushBC=true;
            if(ComparaisonBetB(orrig,corrom,indiceCor)){
                std::cout<<"conparaison identique"<<std::endl;
                tjourCorr=false;
            }
        }
        
    }
}


bool ComparaisonBetB(std::string orrig,std::string corrom,std::string &indiceCor){
    uint a;
    bool same=true;
    if(corrom.size()<orrig.size())
        a=corrom.size();
    else
        a=orrig.size();
    
    for(uint i=0; i<a;i++){
        if(corrom[i]==orrig[i]){
            indiceCor[i]='0';
        }
        else
            same=false;
    }
    return same;
}