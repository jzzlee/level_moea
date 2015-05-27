#ifndef _SUB_LEVEL_H_
#define _SUB_LEVEL_H_

#include "particle.h"

struct G_Level_Individual;
extern  G_Level_Individual *global_level_population, *global_level_sorted_population;

//One individual on sub_level, including a particle and some extra information
struct S_Level_Individual
{
	Particle particle;
	//extra infoemation
	int subspecies; //the subspecies the individual belongs to
};

//the number of subspecies and the number of particles in a subspecies
const int numSubspecies = 5;
const int numNeighbors = numParticles / numSubspecies;
//One subspecies, including numNeighbors particles.
struct S_Level_Subspecies
{
	S_Level_Individual *s_level_subspecies;

	S_Level_Subspecies() : s_level_subspecies(new S_Level_Individual[numNeighbors]){}
	~S_Level_Subspecies() { delete[] s_level_subspecies; }

};
//the population on sub_level
S_Level_Subspecies *s_level_population = new S_Level_Subspecies[numSubspecies];

void init_sub_population()
{
	;
}

#endif
