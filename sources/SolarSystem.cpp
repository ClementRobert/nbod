#include "SolarSystem.h"

SolarSystem::SolarSystem(int N){
    valarray<double> orbitedirection(0.,3);
    orbitedirection[2] = 1.;
    valarray<double> o(0.,3);

    MassiveParticle *pointer(0);
    //    pointer = new MassiveParticle(o,o,pow(10,2)*maxm);
    pointer = new MassiveParticle(o,o,pow(10,-1)*maxm);//!!!!
    m_massadresses.push_back(pointer);
    m_sun = *pointer;
    
    int y;
    for(y=0 ; y<N; y++){
        genSatellite(orbitedirection);
    }
}

MassiveParticle SolarSystem::getsun() const {
    return m_sun;
}

// valarray<MassiveParticle> SolarSystem::getsatellites() const {
//     valarray<MassiveParticle> satlist();
// }


void SolarSystem::setSatVelocity(MassiveParticle& newSat, valarray<double> orbitedirection){
    double v = sqrt( G * m_sun.m_mass / newSat.distanceTo(m_sun) );
    valarray<double> dir = cross(orbitedirection, newSat.directionTo(m_sun));
    newSat.setvelocity(dir*v);
}


void SolarSystem::genSatellite(valarray<double> orbitedirection){
    valarray<double> copy;
    MassiveParticle *pointer(0);
    pointer = new MassiveParticle;
    copy = (*pointer).getposition(); copy[2] = 0.;
    (*pointer).setposition(copy);
    setSatVelocity(*pointer, orbitedirection);//fill in the blank pour l'excentricity
    m_massadresses.push_back(pointer);
}
