#include "Particle.h"
#include "MassiveParticle.h"
#include "Cluster.h"
#include "SolarSystem.h"

#include <cstdlib>
#include <iomanip>

using namespace std;
int main() {
    srand(time(0));//pas trouvé de meilleur endroit pour le seed
    double beginwith, endwith;

    Cluster mycluster(3,2);//3 bodies 2D cluster
    //printing parameters 
    int prec(3),width(7+prec+4);
    int it, N(mycluster.getAdresses().size());

    MassiveParticle *point(0);
    vector<MassiveParticle*> copyadresses(mycluster.getAdresses());
       
    beginwith = mycluster.updateTotalEnergy();

    double start(time(0)), finish(0);
    int maxepoch = (maxtime/timestep);
    ofstream enrc("energycurve.txt", ios::out); //ouverture en ecriture (ecrase)
    ofstream traj("traj.txt", ios::out); //ouverture en ecriture (ecrase)


       
    cout << scientific << setprecision(prec) << left;
    traj << scientific << setprecision(16) << left;
    enrc << scientific << setprecision(16) << left;

  
    /*--------------------------------------------------
                        MAIN LOOP
      --------------------------------------------------*/
    while(mycluster.getEpoch()<maxepoch){

        mycluster.euler();

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
                cout << setw(width) << (*point).getposition()[0];
                cout << setw(width) << (*point).getposition()[1];
                cout << setw(width) << (*point).getposition()[2];
                cout << endl;

                traj << setw(7+16+4) << (*point).getposition()[0];
                traj << setw(7+16+4) << (*point).getposition()[1];
                traj << setw(7+16+4) << (*point).getposition()[2];
            }
            cout << endl << endl;
            traj << endl;
            
        }
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

