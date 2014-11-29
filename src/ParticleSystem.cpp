#include "ParticleSystem.h"

//#define rows 30  // Num of particles in horizontal axis
//#define cols 30  // Num of particles in vertical axis
//#define depth 4 // Num of particles in depth axis
//#define length 10.0f  // Rest distance between particles
#define dt 0.1f  // Time step
#define solverIterations 10  // Num of iterations of the solver
#define kstretch 0.1f // Stretch stiffness
#define kbend 0.8f    // Bending stiffness


ParticleSystem::ParticleSystem(ofVec3f origin){

    force = ofVec3f(0,-9.8f,0); // Gravity
	model = 0;
	
	switch(model){
		case 0:
			//Initialize a cloth with distance constraint (width,height,rest_distance)
			initClothDistance(30,30,10);
			break;
		case 1:
			//Initialize a cube with distance constraint (width,height,depth,rest_distance)
			initCubeDistance(3,3,3,10);
			break;
		case 2:
			initClothDistanceBending();
			break;
		case 3:
			initCubeVolume();
			break;
	}
	
	
}

void ParticleSystem::update()
{

	for (unsigned int i = 0; i < particles.size(); i++){
		Particle *p = particles[i];

		//Add Forces if needed (Gravity?)
		
		p->applyForce(force);

		p->v += dt * (p->w * p->forces);

		//dampVelocities
		p->v = p->v *0.99f;

		p->p = p->x + (dt * p->v );

	}

	//ProjectConstraints
	for(int i = 0; i < solverIterations ; i++){

		for(unsigned int i = 0; i < constraints.size(); ++i) {
			constraints.at(i)->update();
		}

	}

	for (unsigned int i = 0; i < particles.size(); i++){
		Particle *p = particles[i];
		p->v = (p->p - p->x) / (dt);
		if(!p->fixed)p->x = p->p;
		p->forces = ofVec3f(0);
	}
	if(model == 1) force = force * 0.4f; // hack to visualize better

}

void ParticleSystem::draw (){
	for (unsigned int i = 0; i < constraints.size(); i++){
		constraints[i]->draw();
	}
}

void ParticleSystem::initClothDistance(int width,int height,float length){
	clear();
	model = 0;
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
                Particle *p = new Particle( ofVec3f (i*length , j*length, 0 ) );

				if(j > 0) constraints.push_back(new DistanceConstraint(p,particles.at((i)*width+(j-1)),kstretch,length,solverIterations));
                if(i > 0) constraints.push_back(new DistanceConstraint(p,particles.at((i-1)*width+j),kstretch,length,solverIterations));

                particles.push_back(p);

                if(j==height-1 && ((i==0) || (i==width-1))) p->fixed =true;
		}
	}
}

void ParticleSystem::initClothDistanceBending(){

}
void ParticleSystem::initCubeDistance(int width,int height,int depth,float length){
	clear();
	model = 1;
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
		    for(int k   =  0 ;    k   <  depth;k++){
                Particle *p = new Particle( ofVec3f (i*length , j*length ,k*length ) );

				if(k > 0) constraints.push_back(new DistanceConstraint(p,particles.at(i*width*width + j*height +(k-1)),kstretch,length,solverIterations));
                if(j > 0) constraints.push_back(new DistanceConstraint(p,particles.at(i*width*width + (j-1)*height + k ),kstretch,length,solverIterations));
                if(i > 0) constraints.push_back(new DistanceConstraint(p,particles.at((i-1)*width*width + j*height + k ),kstretch,length,solverIterations));
                if(k > 0 && j > 0) constraints.push_back(new DistanceConstraint(p,particles.at(i*width*width + (j-1)*height +(k-1)),kstretch,length,solverIterations));
                if(k > 0 && i > 0) constraints.push_back(new DistanceConstraint(p,particles.at((i-1)*width*width + j*height +(k-1)),kstretch,length,solverIterations));
                if(j > 0 && i > 0) constraints.push_back(new DistanceConstraint(p,particles.at((i-1)*width*width + (j-1)*height +k),kstretch,length,solverIterations));
                if(j < height-1 && i>0) constraints.push_back(new DistanceConstraint(p,particles.at((i-1)*width*width + (j+1)*height + (k) ),kstretch,length,solverIterations));
                if(i > 0 && k < depth-1) constraints.push_back(new DistanceConstraint(p,particles.at((i-1)*width*width + (j)*height + (k+1) ),kstretch,length,solverIterations));
                if(j > 0 && k < depth-1) constraints.push_back(new DistanceConstraint(p,particles.at((i)*width*width + (j-1)*height + (k+1) ),kstretch,length,solverIterations));

                particles.push_back(p);

                if(j==height-1) p->fixed =true;
		    }
		}
	}
}
void ParticleSystem::initCubeVolume(){
	
}

void ParticleSystem::clear(){
	particles.clear();
	constraints.clear();
	force = ofVec3f(0,-9.8f,0); // Gravity
}