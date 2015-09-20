#ifndef DEF_SOLARSYSTEM
#define DEF_SOLARSYSTEM

#include "MassiveParticle.h"
#include "Star.h"
#include "Cluster.h"

class SolarSystem : public Cluster{

    public :
    SolarSystem(int N = 0);//N=number of stallites at initialization
    Star getsun() const {return m_sun;};
    //valarray<MassiveParticle> getsatellites const;
    

   
    protected :
    Star m_sun;
    void setSatVelocity(MassiveParticle& newSat, valarray<double> orbitedirection);
    void genSatellite(valarray<double> orbitedirection);
        
};

#endif
