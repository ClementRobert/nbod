#include "parameters.h"
#include "Particle.h"
#include "MassiveParticle.h"
#include "Cluster.h"
#include "SolarSystem.h"

using namespace std;
using namespace sf;

int main() {
    srand(time(0));//pas trouvé de meilleur endroit pour le seed
    double beginwith, endwith;

    //Cluster mycluster(20,2);//20 bodies 2D cluster
    SolarSystem mycluster(15);//15 planets ssyst
    valarray <double> REFPOS(0.,3);
    int N(mycluster.getAdresses().size());

    MassiveParticle *p(0);
    vector<MassiveParticle*> copyadresses(mycluster.getAdresses());
       
    beginwith = mycluster.updateTotalEnergy();

    double start(time(0)), finish(0);
    int maxepoch = (maxtime/timestep);
    ofstream enrc("results/energycurve.txt", ios::out); //ouverture en ecriture (ecrase)
    ofstream traj("results/traj.txt", ios::out); //ouverture en ecriture (ecrase)
       
    cout << scientific << setprecision(PRINT_PREC) << right;
    traj << scientific << setprecision(16) << left;
    enrc << scientific << setprecision(16) << left;



    Event ev;
    ContextSettings settings;
    settings.antialiasingLevel=8;

    RenderWindow app(VideoMode(500,500,64), "N bodies simulation",Style::Close | Style::Titlebar | Style::Resize);
    //créé une fenêtre de 800x600px en affichage 64bits
    //avec bouton de fermeture, barre de titre et possibilité de redimensionner la fenêtre


    /*--------------------------------------------------
                        MAIN LOOP
      --------------------------------------------------*/

    cout << "in main, sun mass and radius : " << mycluster.getsun().getmass() << "   " << mycluster.getsun().getradius() << endl;
    
    while (app.isOpen()){
        while(mycluster.getEpoch()<maxepoch){
            app.clear(Color::Black);
            mycluster.euler();

            if(mycluster.getEpoch()%int(pow(10,2)) == 0){
                REFPOS[0]=mycluster.getsun().getposition()[0];
                REFPOS[1]=mycluster.getsun().getposition()[1];
                //get fun
                // REFPOS[0]=(*(copyadresses[2])).getposition()[0];
                // REFPOS[1]=(*(copyadresses[2])).getposition()[1];

                mycluster.draw(app,REFPOS);
                

                /*------------------
                  drawing test zone
                  -----------------*/

                // double R(80);
                // valarray <int> window_center(0.,2);
                // window_center[0]=app.getSize().x/2;
                // window_center[1]=app.getSize().y/2;
                // sf::CircleShape circle(R,50);
                // circle.setFillColor(sf::Color::Red);
                // valarray <double> pos(0.,2);
                // for(int i=0;i<2;i++){
                //     pos[i] = window_center[i];// - REFPOS[i];
                //     pos[i] -= R;
                // }
                // circle.setPosition(pos[0],pos[1]);//DRAWING IN 2D !
                // app.draw(circle);

                /*-------------
                  end test zone
                  -------------*/

                app.display();
            }
            if(mycluster.getEpoch()%int(pow(10,4)) == 0){
                mycluster.print();//in terminal status printing

                //file writing...
                enrc << mycluster.getEpoch() << "    ";
                enrc << mycluster.getPotentialEnergy() << "    ";
                enrc << mycluster.getKineticEnergy() << "    ";
                enrc << mycluster.getTotalEnergy() << endl;

                for(int i=0;i<N;i++){
                    p=copyadresses[i];
                    for(int j=0;j<3;j++){
                        traj << std::setw(7+16+4) << (*p).getposition()[j];
                    }
                }
                traj << endl;
            }
        }
        if(ev.type == Event::Closed) app.close();//does not respond yet
    }


    endwith = mycluster.updateTotalEnergy();
    cout << "=======================" << endl;
    cout << "total energy" << endl << endl;
    cout << "started with : " << beginwith << endl;
    cout << "ended with : " << endwith << endl;
    cout << "=======================" << endl;


    finish = time(0) - start;
    cout << "computation took : " << finish << "s" << endl;
    cout << "time reached : " << mycluster.time() << endl;
    cout << "timestep used : " << timestep << endl;


    return 0;
}

