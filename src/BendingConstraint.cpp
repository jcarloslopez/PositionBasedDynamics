#include "BendingConstraint.h"


BendingConstraint::BendingConstraint(Particle *_p1, Particle *_p2,Particle* _p3,float _k,float _d,int _solverIterations){
	indices.push_back(_p1); //b0
	indices.push_back(_p2); //v
	indices.push_back(_p3); //b1
	k = 1 - pow(1-_k,1/_solverIterations); 
	//k = 0;
	h0 = _d;
	W = _p1->w + _p3->w + (2*_p2->w);
	n = 3;
	//K=10:
	type = "ieq"; //eq

}

void BendingConstraint::update(){

	c = (1/3)*( indices[0]->x+ indices[1]->x + indices[2]->x);
	K_global = 10;
	//  v - c
	ofVec3f vc = c - indices[1]->x;
	// | v - c |
	float vc_length = vc.length();

	// 1- ((K+h0)/(|v-c|))
	float ev = 1 - ((K_global+h0)/vc_length);
	// (v-c) * 1- ((K+h0)/(|v-c|))
	ofVec3f vcev = vc * ev;

	if(!indices[0]->fixed) indices[0]->p += ((2* indices[0]->w)/W)*vcev*k;
	if(!indices[2]->fixed) indices[2]->p += ((2* indices[2]->w)/W)*vcev*k;
	if(!indices[1]->fixed) indices[1]->p -= ((4* indices[1]->w)/W)*vcev*k;
}
void BendingConstraint::draw(){
	//ofTriangle(indices[0]->x.x,indices[0]->x.y,indices[0]->x.z,indices[1]->x.x,indices[1]->x.y,indices[1]->x.z,indices[2]->x.x,indices[2]->x.y,indices[2]->x.z);
}
