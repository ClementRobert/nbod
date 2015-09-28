#include "SolarSystem.h"

SolarSystem::SolarSystem(int N) : m_sun(pow(10,5)*RANGEM*maxm){

  cout << "balise 0" << endl;
    valarray<double> orbitedirection(0.,3);
    orbitedirection[2] = 1.;
    valarray<double> nullvector(0.,3);
    Star *starptr(&m_sun);
    m_sun.setposition(nullvector);
    m_sun.setvelocity(nullvector);
    
    m_massadresses.push_back(starptr);//Pas compatible    
    for(int i=0 ; i<N; i++){
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
