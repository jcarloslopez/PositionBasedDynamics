#include "BendingConstraint.h"


BendingConstraint::BendingConstraint(Particle *_p1, Particle *_p2,Particle* _p3,float _k,float _d,int _solverIterations){
	indices.push_back(_p1); 
	indices.push_back(_p2); 
	indices.push_back(_p3); 
	k = 1.0f - pow((1.0f-_k), 1.0f/_solverIterations);
	c = 0.3333*( indices[0]->x+ indices[1]->x + indices[2]->x);
	ofVec3f rest = _p3->x - c;
	h0 = rest.length();
	W = _p1->w + _p2->w + (2*_p3->w);
	n = 3;
	type = "ieq"; 

}

void BendingConstraint::update(){
	c = 0.3333*( indices[0]->p+ indices[1]->p + indices[2]->p);
	//  v - c
	ofVec3f vc =  indices[2]->x - c;
	// | v - c |
	float vc_length = vc.length();

	// 1- ((K+h0)/(|v-c|))
	float ev = 1 - ((0+h0)/vc_length);
	// (v-c) * 1- ((K+h0)/(|v-c|))
	ofVec3f vcev = vc * ev;

	if(!indices[0]->fixed) indices[0]->p += ((2* indices[0]->w)/W)*vcev*k;
	if(!indices[1]->fixed) indices[1]->p += ((2* indices[1]->w)/W)*vcev*k;
	if(!indices[2]->fixed) indices[2]->p += -((4* indices[2]->w)/W)*vcev*k;
}
void BendingConstraint::draw(){
	ofTriangle(indices[0]->x.x,indices[0]->x.y,indices[0]->x.z,indices[1]->x.x,indices[1]->x.y,indices[1]->x.z,indices[2]->x.x,indices[2]->x.y,indices[2]->x.z);
}
