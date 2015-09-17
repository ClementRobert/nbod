#include "Particle.h"
#include "MassiveParticle.h"
#include "Cluster.h"
#include "SolarSystem.h"
#include <SFML/Graphics.hpp>


using namespace sf;

int main() {
    srand(time(0));
    double beginwith, endwith;//stockent l'énergie tot de départ et de fin pour les comparer
    

    //    Cluster mycluster(5);
    SolarSystem mycluster(15);//arg = satellite number
    vector<MassiveParticle*> copyadresses(mycluster.getAdresses());
    
    beginwith = mycluster.updateTotalEnergy();

    double start(time(0)), finish(0);
    int i;
    int maxepoch = (maxtime/timestep);
    ofstream ficen("energycurve.txt", ios::out); //ouverture en ecriture (ecrase)
    ofstream fic("traj.txt", ios::out); //ouverture en ecriture (ecrase)

    int it, N(mycluster.getAdresses().size());
    MassiveParticle *point(0);

    //WIP
    //-----------------------------------------------
    ContextSettings settings;
    settings.antialiasingLevel=8;

    RenderWindow app(VideoMode(600,600,64), "une fenetre SFML !",Style::Close | Style::Titlebar | Style::Resize);
    //créé une fenêtre de 800x600px en affichage 64bits
    //avec bouton de fermeture, barre de titre et possibilité de redimensionner la fenêtre

    MassiveParticle& sun(mycluster.getsun());//WRONG SYNTAX
    while (app.isOpen()){
        // for(i=0 ; i<maxepoch ; i++){
        //     mycluster.walkonestep();
        // }
        
        Event event;
        while (app.pollEvent(event)){
            if (event.type == Event::Closed)
                app.close();
        }

        app.clear(Color::Black);
        
        mycluster.walkonestep();
        
        sun.draw(app);
        //mycluster.draw(app);
        app.display();
        cout << sun.getposition()[0] << endl;
    }
    //-----------------------------------------------

    finish = time(0) - start;
    cout << "computation took : " << finish << "s" << endl;
    cout << "time reached : " << mycluster.time() << endl;
    cout << "timestep used : " << timestep << endl;

    return 0;
    //   Return EXIT_SUCCESS;
}
