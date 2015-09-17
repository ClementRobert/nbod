#include "Particle.h"
#include "MassiveParticle.h"
#include "Cluster.h"
#include "SolarSystem.h"


int main() {
    srand(time(0));//pas trouvé de meilleur endroit pour le seed
    double beginwith, endwith;
    


        Cluster mycluster(5);
//    SolarSystem mycluster(10);
    vector<MassiveParticle*> copyadresses(mycluster.getAdresses());
    
    beginwith = mycluster.updateTotalEnergy();

    double start(time(0)), finish(0);
    int i;
    int maxepoch = (maxtime/timestep);
    ofstream ficen("energycurve.txt", ios::out); //ouverture en ecriture (ecrase)
    ofstream fic("traj.txt", ios::out); //ouverture en ecriture (ecrase)


    int it, N(mycluster.getAdresses().size());
    MassiveParticle *point(0);
    for(i=0 ; i<maxepoch ; i++){
        mycluster.walkonestep();
        
        if(ficen && i%2000 == 0){
            mycluster.updateTotalEnergy();
            ficen << mycluster.getEpoch() << "    ";
            ficen << mycluster.getPotentialEnergy() << "    ";
            ficen << mycluster.getKineticEnergy() << "    ";
            ficen << mycluster.getTotalEnergy() << endl;
        }

        if(fic && i%200==0) { //verif que l'ouverture a fonctionné

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

