#ifndef DISTANCE_CONSTRAINT_H

#include "ofMain.h"
#include "Constraint.h"
#include "Particle.h"

class DistanceConstraint: public Constraint {
	public:
		DistanceConstraint(Particle*,Particle*,float,float,int);
		void update();
		void draw();

		float d; // Rest distance constraint
};
#endif