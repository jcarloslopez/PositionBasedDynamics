#include "Particle.h"

Particle::Particle(ofVec3f _pos){
	x = _pos;
	p = _pos;
	v = ofVec3f();
	m = 10;
	w = 1/m;
	forces = ofVec3f(0);
	fixed = false;
}

void Particle::applyForce(ofVec3f f){
	forces +=f;
}

void Particle::draw(){
	ofSetColor( 0, 0, 255 );
	ofDrawSphere(x.x,x.y,x.z,1);
}


