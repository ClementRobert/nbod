#ifndef DEF_PARTICLE
#define DEF_PARTICLE

#include "parameters.h"
#include "functions.h"

class Particle {
    public :
        //constructeurs et destructeurs
        Particle();
        Particle(valarray<double> position, valarray<double> velocity);

        //affichage et flux
        virtual void print(std::ostream &stream) const;
        void draw(sf::RenderWindow &app) const;

        //accesseurs et autres méthodes constantes
        valarray<double> getposition() const;
        double getvel() const; //on se contente de récuperer le scalaire vitesse, le seul paramètre intéressant pour les calculs energétiques
        double distanceTo(valarray<double> otherPosition) const;
        double distanceTo(Particle otherParticle) const;
        std::valarray<double> directionTo(valarray<double> otherPosition) const;
        std::valarray<double> directionTo(Particle otherParticle) const;

        //mutateurs
        void setposition(valarray<double> newposition);
        void setvelocity(valarray<double> newvel);

        //méthodes de transformation
        Particle& operator+=(valarray<double> boostVect);


    protected :
        valarray<double> m_position;
        valarray<double> m_velocity; //tableaux statiques de 3 coords stockées en "double" (float)
        valarray<double> m_nextBoost;
        void dump();
        void resetBoost();
        void translate(valarray<double> transVect);
        void accelerate(valarray<double> boostVect);
};

//opérateurs
Particle operator+(Particle const& part, valarray<double> change);
ostream& operator<<(ostream &stream, Particle const& part);

#endif
