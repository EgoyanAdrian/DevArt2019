#include <iostream>
#include <SFML/Graphics.hpp>
#include <fonctionAleatoire.hpp>
#include <Interface.hpp>
#include <genererNomPays.hpp>
#include <ZoneTexte.hpp>
#include <conversion.hpp>
#include <Bouton.hpp>

int main() {
	uint BsizeX=800;
    uint BsizeY=600;

    std::cout << "Bonjour le mondedd !" << std::endl;

	std::string pays ="France";
    bool corrupti=false;

    bool EnvoyisFirstPush=false; //permet de savoir si Envoyer a etais deja utiliser ou non
    bool isPush=false;
    uint mouse_X;
    uint mouse_Y;
    bool isAlreadyPush=false;
  
    bool EnvoyerisAcitve=false;
    bool isAlreadyPushTB1=false;
    bool isAlreadyPushTB2=false;
    bool Binaire1=false;
    bool Binaire2=true;

    char lettre;
    std::string motBinaire;
    bool isShiftPressed;

    std::string CorruptiondesDonne;
    std::string messagePays;
    std::string ipadressdapart;
    std::string ipAdressArriver;
    std::string messagefichierenvo="Fichier bien envoyer \n";
    std::string messagefichierrec="Fichier bien recu\n";
  

    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
    {
        // erreur...
    }

    ZoneTexte cmd(0,0,0,0,font);
    cmd.setLimitless(true);
    ZoneTexte zText1(0,0,0,0,font);
    ZoneTexte zText2(0,0,0,0,font);

    //Bouton (10, 20, 50, 70, "Test", font);
    
    sf::RenderWindow window(sf::VideoMode(BsizeX, BsizeY), "My window");

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {

        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::Resized)
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

            if(event.type == sf::Event::MouseMoved) {
                mouse_X = event.mouseMove.x;//coordonner X de la sourie
                mouse_Y = event.mouseMove.y;//coordonner Y de la sourie
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                isPush=true;
                isAlreadyPush=false;
                isAlreadyPushTB1=false;
                isAlreadyPushTB2=false;
                zText1.setClicked(zText1.isOver(mouse_X, mouse_Y));
                if(EnvoyisFirstPush)
                    zText2.setClicked(zText2.isOver(mouse_X, mouse_Y));
            }

            if(event.type==sf::Event::MouseButtonReleased){
                isPush=false;
                
            }

            if(event.type == sf::Event::KeyPressed) {
                if((event.key.code == sf::Keyboard::LShift) || (event.key.code == sf::Keyboard::RShift))
                    isShiftPressed = true;

                lettre = lettreKey(event, isShiftPressed);

                if(!EnvoyisFirstPush) {
                    if((zText1.getClicked()) && (lettre != '\n') && (!zText1.isFull()) && (!zText2.isFull())) {
                        if(lettre == '-') {
                            zText1.remove();
                        } else {
                            zText1.setTexte(lettre);
                        }
                        motBinaire = convertirTaB(zText1.getTexte());
                        zText2.clear();
                        for(char & caractere : motBinaire) {
                            zText2.setTexte(caractere);
                        }
                    }
                } else {
                    if((zText1.getClicked()) && (lettre != '\n') && (!zText1.isFull())) {
                        if(lettre == '-') {
                            zText1.remove();
                        } else {
                            zText1.setTexte(lettre);
                        }
                    } else if((zText2.getClicked()) && (lettre != '\n') && (!zText2.isFull())) {
                        if(lettre == '-') {
                            zText2.remove();
                        } else {
                            zText2.setTexte(lettre);
                        }
                    }
                }
            }

            if(event.type == sf::Event::KeyReleased) {
                if((event.key.code == sf::Keyboard::LShift) || (event.key.code == sf::Keyboard::RShift))
                    isShiftPressed = false;
            }
        }
        window.clear(sf::Color::White);
        
        if(!EnvoyisFirstPush){
            Interface(window,mouse_X,mouse_Y,isPush,EnvoyisFirstPush,pays,BsizeX,BsizeY,font,cmd,zText1,zText2,EnvoyerisAcitve,corrupti,isAlreadyPush);
        }
        else{
            Interface2(window,mouse_X,mouse_Y,isPush,EnvoyisFirstPush,pays,BsizeX,BsizeY,font,Binaire1,Binaire2,cmd,zText1,zText2,EnvoyerisAcitve,corrupti,isAlreadyPush,isAlreadyPushTB1,isAlreadyPushTB2);
        }

        if(EnvoyerisAcitve){
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
                ipadressdapart="Envoye en cours de " +TIP1[i-1] +" a "+TIP1[i]+"\n";//creer le message
                for(char & caractere : ipadressdapart) {
                cmd.setTexte(caractere);
                }
            }

            for(char & caractere : messagefichierenvo) {
                cmd.setTexte(caractere);
            }
            messagePays="Envoye du fichier en "+pays+"\n";
            for(char & caractere : messagePays) {
                cmd.setTexte(caractere);
            }
            for(int i=0;i<nbIP2;i++){
            ipadressdapart+"Envoye en cours de " +TIP2[i] +" à "+TIP2[i+1]+"\n";
                for(char & caractere : ipadressdapart) {
                cmd.setTexte(caractere);
                }

            }
            for(char & caractere : messagefichierrec) {
                cmd.setTexte(caractere);
            }
            EnvoyerisAcitve=false;
        }
        if(corrupti){
            CorruptiondesDonne="Attention fichier corrompue\n";
            for(char & caractere : CorruptiondesDonne) {
                cmd.setTexte(caractere);
            }
            corrupti=false;  
        }
        cmd.upgrade(window);
        window.draw(cmd);
        zText1.upgrade(window);
        zText2.upgrade(window);
        window.draw(zText1);
        window.draw(zText2);

        window.display();
    }

    return 0;
}

