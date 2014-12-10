#ifndef PARTICLESYSTEM_H

#include "ofMain.h"
#include "Particle.h"
#include "DistanceConstraint.h"
#include "BendingConstraint.h"

class ParticleSystem {
	public:
		ParticleSystem(ofVec3f);
		void update();
		void draw();
		void clear();

		void initClothDistance(int width,int height,float length); // Initialize a cloth with distance constraint      model = 0
		void initCubeDistance(int width,int height,int depth,float length); // Initialize a cube with distance constraint      model = 1
		void initClothDistanceBending(int width,int height,float length); // Initialize a cloth with distance and bending constraint      model = 2

		vector<Particle*> particles;
		vector<Constraint*> constraints;
		ofVec3f force;
		int model; 
};

#endif
