#include "DistanceConstraint.h"


DistanceConstraint::DistanceConstraint(Particle *_p1, Particle *_p2,float _k,float _d,int _solverIterations){
	indices.push_back(_p1);
	indices.push_back(_p2);
	//k = 1 - pow(1-_k,1/_solverIterations); 
	k = _k;
	d = _d;
	n = 2;
	type = "eq";

}

void DistanceConstraint::update(){

	//  p1 - p2
	ofVec3f dif = (indices[0]->p - indices[1]->p);
	// |p1 − p2|
	float  dif_length = dif.length();
	//  w1 + w2
	float  wSum = indices[0]->w + indices[1]->w;
	// (|p1 −p2| −d)
	float  c = (dif_length - d );
	//  ((|p1 −p2| −d)/w1+w2)* ((p1 - p2)/(|p1 − p2|))
	ofVec3f Ap = ( (c/wSum) * (dif/dif_length) ) * k;

	if(!indices[0]->fixed) indices[0]->p -= (Ap * indices[0]->w);
	if(!indices[1]->fixed) indices[1]->p += (Ap * indices[1]->w);


}
void DistanceConstraint::draw(){
	ofLine(indices[0]->x.x,indices[0]->x.y,indices[0]->x.z,indices[1]->x.x,indices[1]->x.y,indices[1]->x.z);
}


