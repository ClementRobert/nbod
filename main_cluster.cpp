#include "Particle.h"
#include "MassiveParticle.h"
#include "Cluster.h"
#include "SolarSystem.h"

#include <cstdlib>
#include <iomanip>

using namespace std;
using namespace sf;

int main() {
    srand(time(0));//pas trouvé de meilleur endroit pour le seed
    double beginwith, endwith;

    //Cluster mycluster(20,2);//20 bodies 2D cluster
    SolarSystem mycluster(15);//15 planets ssyst
    //printing parameters 
    int prec(3),width(7+prec+4);
    int it, N(mycluster.getAdresses().size());

    MassiveParticle *point(0);
    vector<MassiveParticle*> copyadresses(mycluster.getAdresses());
       
    beginwith = mycluster.updateTotalEnergy();

    double start(time(0)), finish(0);
    int maxepoch = (maxtime/timestep);
    ofstream enrc("results/energycurve.txt", ios::out); //ouverture en ecriture (ecrase)
    ofstream traj("results/traj.txt", ios::out); //ouverture en ecriture (ecrase)

       
    cout << scientific << setprecision(prec) << left;
    traj << scientific << setprecision(16) << left;
    enrc << scientific << setprecision(16) << left;

  
    ContextSettings settings;
    settings.antialiasingLevel=8;

    RenderWindow app(VideoMode(500,500,64), "N bodies simulation",Style::Close | Style::Titlebar | Style::Resize);
    //créé une fenêtre de 800x600px en affichage 64bits
    //avec bouton de fermeture, barre de titre et possibilité de redimensionner la fenêtre


    Event ev;

    /*--------------------------------------------------
                        MAIN LOOP
      --------------------------------------------------*/

    valarray <double> REFPOS(0.,3);



    cout << "in main, sun mass and radius : " << mycluster.getsun().getmass() << "   " << mycluster.getsun().getradius() << endl;
    
    while (app.isOpen()){
        while(mycluster.getEpoch()<maxepoch){
            app.clear(Color::Black);
            mycluster.euler();


            if(mycluster.getEpoch()%int(pow(10,2)) == 0){
                REFPOS[0]=mycluster.getsun().getposition()[0];
                REFPOS[1]=mycluster.getsun().getposition()[1];
                //prototype de la future fonction Cluster::draw(&app)
                for(it=1 ; it<N ; it++){//ATTENTION : on part de 1 pour éviter de dessiner le soleil deux fois
                    point = copyadresses[it];
                    (*point).draw(app,REFPOS);
                }
                app.display();
            }
            if(mycluster.getEpoch()%int(pow(10,4)) == 0){
                mycluster.updateTotalEnergy();
                cout << "----------------------------------------------------" << endl;
                cout << "Epoch              PotEn         KiEn          TotEn" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << setw(width) << double(mycluster.getEpoch());
                cout << setw(width) << mycluster.getPotentialEnergy();
                cout << setw(width) << mycluster.getKineticEnergy();
                cout << setw(width) << mycluster.getTotalEnergy() << endl;

                enrc << mycluster.getEpoch() << "    ";
                enrc << mycluster.getPotentialEnergy() << "    ";
                enrc << mycluster.getKineticEnergy() << "    ";
                enrc << mycluster.getTotalEnergy() << endl;

       
                cout << endl;
                cout << "Positions of every particle..." << endl;

                for(it=0 ; it<N ; it++){
                    point = copyadresses[it];
                    cout << "body #" << it << " : ";
                    for(int j=0;j<3;j++){
                        cout << setw(width)  << (*point).getposition()[j];
                        traj << setw(7+16+4) << (*point).getposition()[j];
                    }
                    cout << setw(width) << (*point).getmass();
                    cout << setw(width) << (*point).getradius();
                    cout << endl;
                }
                cout << endl << endl;
                traj << endl;
            }
        }
        if(ev.type == Event::Closed) app.close();
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

