#ifndef __GLOBAL_LEVEL_H_
#define __GLOBAL_LEVEL_H_
#include "global.h"
#include "particle.h"

//store the uniform weights
double all_lambda[numParticles][numObjectives];

//One individual in global_level, including a particle and some extra information
struct G_Level_Individual
{
	Particle particle;
	//extra infoemation

	void operator= (const G_Level_Individual &ind);
};

void G_Level_Individual::operator= (const G_Level_Individual &ind)
{
	particle = ind.particle;
}

//population and sorted_population in global level
G_Level_Individual *g_level_population = new G_Level_Individual[numParticles];
G_Level_Individual *g_level_sorted_population = new G_Level_Individual[numParticles];

//calculate the fitness for y_obj with weight vector lambda
double cal_fitness(double y_obj[], double lambda[])
{
	double fitness = 0;
	for (int i = 0; i != numObjectives; ++i)
		fitness += lambda[i] * y_obj[i];
	return fitness;
}

bool flag[numParticles];
int order[numParticles];
void g_level_population_sort()
{
	double indeal_fitness; //best fitness
	int indeal_index;   // the index of the particle which gains the best fitness
	double fitness;                
	if (numObjectives == 2)
	{
		
		for (int i = 0; i != numParticles; ++i) //loop for weight vectors
		{
			indeal_fitness = 0x7FFFFFFF;
			for (int j = 0; j != numParticles; ++j) //loop for individuals
			{
				if (!flag[j]) //if the individual is not used
				{
					fitness = cal_fitness(g_level_population[j].particle.y_obj, all_lambda[i]);
					
					if (fitness < indeal_fitness)
					{
						indeal_fitness = fitness;
						indeal_index = j;
					}
				}
			}
			//find the best individual for the ith weight vector
			flag[indeal_index] = true;
			order[i] = indeal_index + 1;
			g_level_sorted_population[i] = g_level_population[indeal_index];
		}
	}
}

void init_uniformweight(int sd)
{
	for (int i = 0; i <= sd; i++)
	{
		if (numObjectives == 2)
		{
			all_lambda[i][0] = static_cast<double>(i) / sd;
			all_lambda[i][1] = static_cast<double>(sd - i) / sd;
		}
		else
		{
			for (int j = 0; j <= sd; j++)
			{
				if (i + j <= sd)
				{
					all_lambda[i][0] = (1.0 * i / sd);
					all_lambda[i][1] = (1.0 * j / sd);
					all_lambda[i][2] = (1.0 * (sd - i - j) / sd);
				}
			}
		}
	}
}



void init_global_population()
{
	for (int i = 0; i != numParticles; ++i)
	{
		g_level_population[i].particle.rnd_init();
		g_level_population[i].particle.obj_eval();
	}
}

void print()
{
	char *global_p = "global_population.txt";
	char *global_sorted_p = "global_sorted_population.txt";
	char *g_lambda = "global_lambda.txt";
	std::ofstream gf(global_p);
	std::ofstream gsf(global_sorted_p);
	for (int i = 0; i<numParticles; ++i)
	{
		for (int j = 0; j != numObjectives; ++j)
			gf << g_level_population[i].particle.y_obj[j] << " ";
		for (int j = 0; j != numVariables; ++j)
			gf << g_level_population[i].particle.x_var[j] << " ";
		gf << std::endl;
	}
	gf.close();

	for (int i = 0; i<numParticles; ++i)
	{
		gsf << order[i] << " ";
		for (int j = 0; j != numObjectives; ++j)
			gsf << g_level_sorted_population[i].particle.y_obj[j] << " ";
		for (int j = 0; j != numVariables; ++j)
			gsf << g_level_sorted_population[i].particle.x_var[j] << " ";
		gsf << std::endl;
	}
	gsf.close();

	gf.open(g_lambda);
	for (int i = 0; i<numParticles; ++i)
	{
		for (int j = 0; j != numObjectives; ++j)
			gf << all_lambda[i][j] << " ";
		gf << std::endl;
	}
	gf.close();
}
void global_level(int sd)
{
	init_uniformweight(sd);
	init_global_population();
	g_level_population_sort();

	print();

}
#endif
