#include "Particle.h"
#include "functions.h"

//constructeurs
Particle::Particle() {//constructeur random
    int i;
    valarray<double> a(0.,3);
    m_position = a; m_velocity = a;
    m_nextBoost = a;
    for(i=0 ; i < 3 ; i++){
        m_position[i] = rand()%(2*maxx)/1000. - maxx/1000.;
        m_velocity[i] = rand()%(2*maxv)/1000. - maxv/1000.;
    }
}

Particle::Particle(valarray<double> position, valarray<double> velocity) {
    valarray<double> a(0.,3);
    m_position = position; m_velocity = velocity;
    m_nextBoost = a;
}

//affichage

void Particle::print(ostream &stream) const {
    stream << "Particle at : ";
    int i;
    for(i = 0 ; i<3 ; i++) {
        stream << m_position[i] << "   ";
    }
    stream << endl << "with scalar speed : " << getvel() << endl;
}


void Particle::draw(sf::RenderWindow &app) const {
    sf::CircleShape circle(10,50);//size arbitraire et fixe, ici
    circle.setFillColor(sf::Color::Blue);
    int i;
    circle.setPosition(m_position[0],m_position[1]);//DRAWING IN 2D !
    app.draw(circle);
}



//accesseurs et autres méthodes constantes

valarray<double> Particle::getposition() const {
    return m_position;
}


double Particle::getvel() const {
    int i;
    double v(0);
    for(i=0 ; i<3 ; i++) {
        v += pow(m_velocity[i], 2);
    }
    v = sqrt(v);
    return v;
}

double Particle::distanceTo(valarray<double> otherPosition) const {//permet le calcul de distance à un point quelconque de l'espace, même dénué de particule
    double d(0);
    int i;
    for(i=0 ; i<3 ; i++){
        d += pow(m_position[i] - otherPosition[i] , 2);
    }
    d = sqrt(d);
    return d;
}

double Particle::distanceTo(Particle otherParticle) const {//cette surcharge permet de calculer directement la distance entre deux particules !
    return distanceTo(otherParticle.m_position);//on réutilise le premier prototype de cette méhode
}

std::valarray<double> Particle::directionTo(valarray<double> otherPosition) const { //note : puisqu'il est impossible en c++ de retourner un tableau satique, je retourne un vector (ce qui n'est pas forcément le plus habile)
    std::valarray<double> dir;
    double norm;
    norm = distanceTo(otherPosition);
    dir = (m_position - otherPosition) / norm;
    return dir;//dir est un vecteur unitaire qui pointe (ahah...) vers l'autre position
}

std::valarray<double> Particle::directionTo(Particle otherParticle) const {//surcharge élégante, cf stratégie pour distanceTo 
    return directionTo(otherParticle.m_position);
}

//mutateurs et méthodes non constantes
void Particle::setposition(valarray<double> newposition){
    m_position = newposition;
}

void Particle::setvelocity(valarray<double> newvel){
    m_velocity = newvel;
}

void Particle::translate(valarray<double> transVect){
    m_position += transVect;
}

void Particle::accelerate(valarray<double> boostVect){
    m_velocity += boostVect;
}

void Particle::resetBoost(){
    valarray<double> a(0.,3);
    m_nextBoost = a;
}

//opérateur arithémetique (c'est une méthode de classe)
Particle& Particle::operator+=(valarray<double> boostVect){
    m_position += m_velocity * timestep;
    m_velocity += boostVect * timestep;
    return *this;//la raison pour laquelle on fait ça m'échappe un peu mais c'est conseillé par le sdz
}

//mutateurs privés

void Particle::dump(){
    *this += m_nextBoost;
    resetBoost();
}

//operateurs (pas des méthodes de classes)

Particle operator+(Particle const& part, valarray<double> boostVect){
	Particle copy(part);
	copy += boostVect;
	return copy;
}

ostream &operator<<(ostream &stream, Particle const& part){
	part.print(stream);
	return stream;
}
