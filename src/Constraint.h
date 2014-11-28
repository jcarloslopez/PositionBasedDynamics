#ifndef CONSTRAINT_H

#include "ofMain.h"
#include "Particle.h"

class Constraint {
	public:
		//Constraint(Particle*,Particle*,float,float);
		virtual void update() = 0;
		virtual void draw() = 0;

		vector<Particle*> indices; //a set of indices {i1,...inj}, ik  [1,...N]
		float k; //a stiffness parameter k j  [0...1] 
		int n; // a cardinality nj
		string type; //a type of either equality("eq") or inequality("ineq")
};
#endif