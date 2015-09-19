#ifndef DEF_CLUSTER
#define DEF_CLUSTER

#include "MassiveParticle.h"

class Cluster{//friend class of MassiveParticle
    public :
        Cluster(int N=0, int dim=3);
        Cluster(const Cluster&);//constructeur par recopie, nécessaire pour rk4
        void euler();//walk one step (euler)
        void rk4();//rk4
        void leapfrog();//leapfrog
        int getEpoch();
        vector<MassiveParticle*> getAdresses();
        void updateKinetic();
        void updatePotential();
        double updateTotalEnergy();
        double getKineticEnergy();
        double getPotentialEnergy();
        double getTotalEnergy();//doublon
        double time();

        //affichage
        void draw(sf::RenderWindow &app);//WIP



    protected :
        int m_epoch;
        double m_kineticEnergy;
        double m_potentialEnergy;
        double m_totalEnergy;
        vector<MassiveParticle*> m_massadresses;
        void resetPotential();
        valarray<valarray<double> > componestep(valarray<valarray<double> > boostTab);
        void dealwithcollisions();
};

#endif
