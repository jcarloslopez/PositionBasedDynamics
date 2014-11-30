#pragma once
#include "ofMain.h"
#include "Constraint.h"
#include "Particle.h"

class BendingConstraint: public Constraint {
	public:
		BendingConstraint(Particle*,Particle*,Particle*,float,float,int);
		void update();
		void draw();

		ofVec3f c; // Intersection point of the three medians (Centroid)
		float h0; // Rest length (rest radius of curvature)
		float K_global; // Global bending parameter of the system
		float W; // Generalized inverse mass for the triangle
};
