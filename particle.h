#ifndef __PARTICLE_H_
#define __PARTICLE_H_

#include <random>
#include <functional>

#include "objective_functions.h"

std::default_random_engine generator(time(NULL));
std::uniform_real_distribution<double> dis(min_lowBound, max_uppBound);
auto uni_rnd = std::bind(dis, generator);

struct Particle
{
	double x_var[numVariables];
	double y_obj[numObjectives];
	int rank;
	//Particle();
	void rnd_init();
	void obj_eval();
	void operator=(const Particle &ind);
};

//对粒子位置随机初始化
void Particle::rnd_init()
{
	for (int n = 0; n < numVariables; n++)
		x_var[n] = (uni_rnd() - min_lowBound)*(uppBound[n] - lowBound[n]) / (max_uppBound - min_lowBound) + lowBound[n];
}

//求目标值
void objectives(double x_var[], double y_obj[])
{
	switch (func){
	case 0:
		zdt1(x_var, y_obj, numVariables); break;
	case 1:
		zdt2(x_var, y_obj, numVariables); break;
	case 2:
		zdt3(x_var, y_obj, numVariables); break;
	case 3:
		zdt4(x_var, y_obj, numVariables); break;
	case 4:
		zdt5(x_var, y_obj, numVariables); break;
	case 5:
		zdt6(x_var, y_obj, numVariables); break;
	case 6:
		DTLZ1_shift(x_var, y_obj, numVariables); break;
	case 7:
		DTLZ2_shift(x_var, y_obj, numVariables); break;
	case 8:
		DTLZ3_shift(x_var, y_obj, numVariables); break;
	}
}

//计算粒子的适应值
void Particle::obj_eval()
{
	objectives(x_var, y_obj);
}

//粒子赋值
void Particle::operator=(const Particle &ind)
{
	for (int i = 0; i<numVariables; i++)
		x_var[i] = ind.x_var[i];
	for (int n = 0; n<numObjectives; n++)
		y_obj[n] = ind.y_obj[n];
	rank = ind.rank;
}

#endif