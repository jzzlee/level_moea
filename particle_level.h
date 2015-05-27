#ifndef __PARTICLE_LEVEL_H_
#define __PARTICLE_LEVEL_H_
#include "particle.h"

//One individual in particle_level, including a particle and some extra information
struct P_Level_Individual
{
	Particle particle;
	//extra information

	double namda[numObjectives];
};


P_Level_Individual *p_level_population = new P_Level_Individual[numParticles];

void init_particles(int sd)
{
	for (int i = 0; i <= sd; i++)
	{
		if (numObjectives == 2)
		{
			p_level_population[i].namda[0] = static_cast<double>(i) / sd;
			p_level_population[i].namda[1] = static_cast<double>(sd - i) / sd;
		}
		else
		{
			for (int j = 0; j <= sd; j++)
			{
				if (i + j <= sd)
				{
					p_level_population[i].namda[0] = (1.0 * i / sd);
					p_level_population[i].namda[1] = (1.0 * j / sd);
					p_level_population[i].namda[2] = (1.0 * (sd - i - j) / sd);
				}
			}
		}
	}

}
#endif
