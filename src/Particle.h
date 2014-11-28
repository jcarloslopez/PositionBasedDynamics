#ifndef PARTICLE_H
#define PARTICLE_H
#include "ofMain.h"

class Particle {
	public:
		Particle(ofVec3f);
		void applyForce(ofVec3f);
		void draw();

		ofVec3f x; // Position
		ofVec3f v; // Velocity
		ofVec3f p;	// Constraint position

		ofVec3f forces; // Force's sum (In this case just gravity)

		float m;	// Mass
		float w;	// Inverse mass

		bool fixed;
};
#endif