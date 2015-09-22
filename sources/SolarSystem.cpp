#include "SolarSystem.h"

SolarSystem::SolarSystem(int N){
    valarray<double> orbitedirection(0.,3);
    orbitedirection[2] = 1.;
    valarray<double> o(0.,3);

    Star *starptr(0);
    //    pointer = new MassiveParticle(o,o,pow(10,2)*maxm);
    starptr = new Star(o,o,pow(10,5)*RANGEM*maxm);
    m_sun = *starptr;
    m_massadresses.push_back(starptr);//Pas compatible    
    cout << "in SS constructor, radius of the sun is : " << m_sun.m_radius << endl; 
    
    int y;
    for(y=0 ; y<N; y++){
        genSatellite(orbitedirection);
    }
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

//affichage
void SolarSystem::draw(sf::RenderWindow &app, valarray<double> refpos) const{
    getsun().draw(app,refpos);
    //(*this).Cluster::draw(app,refpos);//à rétanlir quand la fonction d'intégration temporelle sera à jour

    MassiveParticle *p(0);
    int N(m_massadresses.size());
    for(int i=1 ; i<N ; i++){
        p = m_massadresses[i];
        (*p).draw(app,refpos);
    }


}
