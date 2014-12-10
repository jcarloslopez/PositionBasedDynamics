#include "Particle.h"

Particle::Particle(ofVec3f _pos,float _m){
	x = _pos;
	p = _pos;
	v = ofVec3f();
	if(_m <= 0){
		m=0.00000000001f;
		w=0.0f;
		fixed = true;
	}else{
		m = _m;
		w = 1/m;
		fixed = false;
	}
	
	forces = ofVec3f(0);

}

void Particle::applyForce(ofVec3f f){
	forces +=f;
}

void Particle::draw(){
	ofSetColor( 0, 0, 255 );
	ofDrawSphere(x.x,x.y,x.z,1);
}


