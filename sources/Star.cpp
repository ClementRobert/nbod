#include "Star.h"

Star::Star() : MassiveParticle(){
}

Star::Star(valarray<double> pos, valarray<double> vel, double mass) : MassiveParticle(pos,vel,mass){
}

Star::Star(double mass) : MassiveParticle(mass){
}
//affichage


void Star::draw(sf::RenderWindow &app, valarray<double> refpos) const {

   double R(m_radius*4*pow(10,1));//MOD HERE % MASSIVEPARTICLE
    valarray <int> window_center(0.,2);
    window_center[0]=app.getSize().x/2;
    window_center[1]=app.getSize().y/2;
    sf::CircleShape circle(R,25);
    circle.setFillColor(sf::Color::White);
    valarray <double> pos(0.,2);
    for(int i=0;i<2;i++){
        pos[i]= window_center[i] + m_position[i] - refpos[i];
        pos[i] -= R;
    }
    circle.setPosition(pos[0],pos[1]);//DRAWING IN 2D !
    app.draw(circle);
}
