#ifndef PARTICLESYSTEM_H

#include "ofMain.h"
#include "Particle.h"
#include "DistanceConstraint.h"

class ParticleSystem {
	public:
		ParticleSystem(ofVec3f);
		void update();
		void draw();
		void clear();

		void initClothDistance(); // Initialize a cloth with distance constraint      model = 0
		void initCubeDistance(); // Initialize a cube with distance constraint      model = 1
		void initClothDistanceBending(); // Initialize a cloth with distance and bending constraint      model = 2
		void initCubeVolume(); // Initialize a cube with overpressure constraint      model = 3

		vector<Particle*> particles;
		vector<Constraint*> constraints;
		ofVec3f force;
		int model; 
};

#endif
