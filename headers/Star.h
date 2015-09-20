#ifndef DEF_STAR
#define DEF_STAR

#include "MassiveParticle.h"

class Star : public MassiveParticle {

friend class Cluster;
public :
void draw(sf::RenderWindow &app, valarray<double> refpos) const;

//constructeurs
Star();
Star(valarray<double> pos, valarray<double> vel);
Star(double mass); 
Star(valarray<double> pos, valarray<double> vel, double mass);

};

#endif




