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
    


    Cluster mycluster(5);
//    SolarSystem mycluster(10);
    vector<MassiveParticle*> copyadresses(mycluster.getAdresses());
    
    beginwith = mycluster.updateTotalEnergy();

    double start(time(0)), finish(0);
    int maxepoch = (maxtime/timestep);
    ofstream ficen("energycurve.txt", ios::out); //ouverture en ecriture (ecrase)
    ofstream fic("traj.txt", ios::out); //ouverture en ecriture (ecrase)



    //printing parameters 
    int prec(3),width(7+prec+4);
    //cout << "start loop" << endl;
    int it, N(mycluster.getAdresses().size());
    MassiveParticle *point(0);
       
    cout << scientific << setprecision(prec) << left;
    ficen << scientific << setprecision(16) << left;
    cout << "Epoch              PotEn         KiEn         TotEn" << endl;
  
    while(mycluster.getEpoch()<maxepoch){
        mycluster.walkonestep();
        if(ficen && mycluster.getEpoch()%int(pow(10,4)) == 0){
            mycluster.updateTotalEnergy();
            cout << setw(width) << double(mycluster.getEpoch());
            cout << setw(width) << mycluster.getPotentialEnergy();
            cout << setw(width) << mycluster.getKineticEnergy();
            cout << setw(width) << mycluster.getTotalEnergy() << endl;

            ficen << mycluster.getEpoch() << "    ";
            ficen << mycluster.getPotentialEnergy() << "    ";
            ficen << mycluster.getKineticEnergy() << "    ";
            ficen << mycluster.getTotalEnergy() << endl;
        }

        if(fic && mycluster.getEpoch()%200==0) { //verif que l'ouverture a fonctionné
            for(it=0 ; it<N ; it++){
                point = copyadresses[it];
                fic << (*point).getposition()[0] << "    " << (*point).getposition()[1] << "    " << (*point).getposition()[2] << "    ";
            }
            fic << endl;
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

