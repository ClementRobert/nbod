#include "Cluster.h"

Cluster::Cluster(int N,int dim){
    MassiveParticle *pointer(0);
    int y,d;
    
        for(y=0 ; y<N; y++){
            pointer = new MassiveParticle;
            if(dim==2){
                valarray<double> projpos(0.,3), projvel(0.,3);
                for(d=0;d<2;d++){
                    projpos[d] = (*pointer).m_position[d];
                    projvel[d] = (*pointer).m_velocity[d];
                }
                (*pointer).setposition(projpos); 
                (*pointer).setvelocity(projvel); 
            }
            m_massadresses.push_back(pointer);
        }
    pointer = 0;
    m_epoch = 0;
}


valarray<valarray<double> > Cluster::componestep(valarray<valarray<double> > boostTab){
    int N(m_massadresses.size()), i,j;
    valarray<double> acc(0.,3), o(0.,3);
    valarray<valarray<double> > newboostTab(o,N);
    MassiveParticle *ptr1(0), *ptr2(0);
    for(i=0 ; i < N ; i++){
        ptr1 = m_massadresses[i];
        for(j=i+1 ; j < N ; j++){
            ptr2 = m_massadresses[j];
            MassiveParticle copy1(*ptr1+boostTab[i]);
            MassiveParticle copy2(*ptr2+boostTab[j]);
            acc = (copy1).compacc(copy2);
            if((*ptr2).m_mass != 0){
                newboostTab[i] +=   acc;
                newboostTab[j] += - acc * (*ptr1).m_mass / (*ptr2).m_mass;
            }
        }
    }
    return newboostTab;
}

/*--------------------------------------------------
                     INTEGRATORS
  --------------------------------------------------*/
void Cluster::euler(){
    int N(m_massadresses.size()), i;
    valarray<double> o(0.,3);
    valarray<valarray<double> > boostTab(o,N);
    boostTab = componestep(boostTab);
    MassiveParticle *ptr(0);
    for(i=0 ; i < N ; i++){
        ptr = m_massadresses[i];
        (*ptr).m_nextBoost = boostTab[i];
        (*ptr).dump();
    }
    dealwithcollisions();
    m_epoch++;
}

// void Cluster::rk4(){
//     Cluster cp1(*this),cp2(*this),cp3(*this),cp4(*this);
//     cp1.euler();
//     cp2 = cp1;
//     cp2.euler();
//     cp3 = cp2();
//     cp3.euler();
//     cp4 = cp3;
//     cp4.euler();
    
    
// }

//MISC
void Cluster::dealwithcollisions(){
    MassiveParticle *ptr1(0), *ptr2(0);
    int i,j, N(m_massadresses.size());
    for(i=0 ; i < N ; i++){
        ptr1 = m_massadresses[i];
        j=i+1;
        while(j<N){
            ptr2 = m_massadresses[j];
            double r((*ptr1).distanceTo(*ptr2));
            if(r < (*ptr1).m_radius + (*ptr2).m_radius){
                cout << "collision at epoch " << m_epoch << " , distance " << r << endl;                
//                (*ptr1).m_mass += (*ptr2).m_mass;
//                (*ptr2).m_mass = 0.;
            }
            j++;
        }
    }
}


void Cluster::draw(sf::RenderWindow &app){
    int i,N;
    N=m_massadresses.size();
    MassiveParticle& copy(*m_massadresses[0]);
    for(i=0 ; N ; i++){
        copy=*m_massadresses[i];
        std::cout << N << endl;
        //copy.draw(app);
    }
}


vector<MassiveParticle*> Cluster::getAdresses(){
    return m_massadresses;
}

int Cluster::getEpoch(){
    return m_epoch;
}

double Cluster::time(){
    return m_epoch * timestep;
}

void Cluster::updateKinetic(){
    m_kineticEnergy = 0.;
    MassiveParticle *ptr(0);
    int i, N(m_massadresses.size());
    for(i=0 ; i<N ; i++){
        ptr = m_massadresses[i];
        (*ptr).setke();
        m_kineticEnergy += (*ptr).m_kineticEnergy;
    }
}

void Cluster::resetPotential(){
    MassiveParticle *ptr(0);
    int i, N(m_massadresses.size());
    for(i=0 ; i<N ; i++){
        ptr = m_massadresses[i];
        (*ptr).m_potentialEnergy = 0.;
    }
    m_potentialEnergy = 0.;
}

void Cluster::updatePotential(){
    resetPotential();
    MassiveParticle *ptr1(0), *ptr2(0);
    int i, j, N(m_massadresses.size());
    double bound;
    for(i=0; i<N ; i++){
        ptr1 = m_massadresses[i];
        for(j=i+1 ; j<N ; j++){
            ptr2 = m_massadresses[j];
            bound = (*ptr1).boundingEnergy(*ptr2);
            (*ptr1).m_potentialEnergy += bound;
            (*ptr2).m_potentialEnergy += bound;
            m_potentialEnergy += 2*bound;
        }
    }
}

double Cluster::updateTotalEnergy(){
        updateKinetic();
        updatePotential();
        m_totalEnergy = m_kineticEnergy + m_potentialEnergy;
        return m_totalEnergy;
}

double Cluster::getKineticEnergy(){
        return m_kineticEnergy;
}

double Cluster::getPotentialEnergy(){
        return m_potentialEnergy;
}

double Cluster::getTotalEnergy(){
        return m_totalEnergy;
}
