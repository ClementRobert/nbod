#ifndef DEF_MPARTICLE
#define DEF_MPARTICLE

#include "Particle.h"

class MassiveParticle : public Particle {

    friend class Cluster;
    friend class SolarSystem;
    public :
        //méthodes statiques
        static void printSystem();
        static vector<MassiveParticle*> getAdresses();


        //constructeurs
        MassiveParticle();
        MassiveParticle(valarray<double> pos, valarray<double> vel);
        MassiveParticle(double mass); 
        MassiveParticle(valarray<double> pos, valarray<double> vel, double mass); //probablement trop de constructeurs, on peut sans doute faire aussi bien avec des valeurs par défaut

        //affichage
        virtual void print(ostream &stream) const;
        void draw(sf::RenderWindow &app, valarray <double> refpos) const;
        //accesseurs et autres méthodes constantes
        double getmass() const {return m_mass;};
        double getradius() const {return m_radius;};
        double getke() const {return m_kineticEnergy;};
        double getpe() const;//pas très utile, je l'implémenterai SI ça le devient

        double boundingEnergy(MassiveParticle otherParticle) const;
        valarray<double> compacc(MassiveParticle part2) const;
        valarray<double> compjerk(MassiveParticle part2) const;


        //mutateurs
        void setradius();
        void setmass(double newmass);
        void setke();//def l'energie cinétique

    //opérateurs intra-classe 
        virtual MassiveParticle& operator=(MassiveParticle newpart);

    protected :
        double m_radius;
        double m_mass;
        double m_kineticEnergy;
        double m_potentialEnergy;

        //attributs statiques
        static vector<MassiveParticle*> adresses;
        
        //méthodes statiques privées
//        static void dealwithcollisions();
};

MassiveParticle operator+(MassiveParticle const& part, valarray<double> boostVect);

#endif
