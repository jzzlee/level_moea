#ifndef __GLOBAL_H_
#define __GLOBAL_H_

#include <fstream>

//目标函数数、每个粒子的维度、粒子数量、进化次数
const int numObjectives = 2;
const int numVariables = 10;
const int maxVariables = 10;
const int numParticles = 100;
const int mg = 500;

// bounds of variables
double  lowBound[maxVariables], uppBound[maxVariables];
const double min_lowBound = -5, max_uppBound = 5;
int     seed = 237;
long    rnd_uni_init;

//which test instance
int func;


void set_bound()
{
	switch (func){
	case 0://ZDT1
	case 1://ZDT2
	case 2://ZDT3
		//numVariables = 30;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1;
		}
		break;
	case 3://ZDT4
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = -5;
			uppBound[i] = 5;
		}
		lowBound[0] = 0;
		uppBound[0] = 1;
		break;
	case 4://ZDT5
	case 5://ZDT6
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1;
		}
		break;
	case 6://DTLZ1
		//numVariables = 10;
		//numObjectives = 3;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1;
		}
		break;
	case 7:
	case 8://DTLZ2
		//numVariables = 10;
		//numObjectives = 3;

		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1;
		}
		break;


	case 9://WFG1
	case 10://WFG2
	case 11://WFG3
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 2 * (i + 1);
		}
		break;

	case 12://F1 in MOEA/D
		//numVariables = 30;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1;
		}
		break;
	case 13://F2 in MOEA/D
	case 14://F3 in MOEA/D
	case 15://F4 in MOEA/D
	case 16://F5 in MOEA/D
		//numVariables = 30;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = -1;
			uppBound[i] = 1;
		}
		lowBound[0] = 0;
		uppBound[0] = 1;
		break;
	case 17:
		//numObjectives = 3;
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = -2;
			uppBound[i] = 2;
		}
		lowBound[0] = 0;
		uppBound[0] = 1;
		lowBound[1] = 0;
		uppBound[1] = 1;
		break;
	case 18://F7 in MOEA/D
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1;
		}
		break;
	case 19://F8 in MOEA/D
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1;
		}
		break;

	case 20://TYD1
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1.5;
		}
		break;
	case 21://TYD2
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 1.46;
		}
		break;
	case 22://TYD3
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 2;
		}
		break;
	case 23://TYD4
		//numVariables = 10;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 2;
		}
		break;
	case 24://TYD5
		//numVariables = 10;
		lowBound[0] = 0.6;
		uppBound[0] = 4.6;
		for (int i = 1; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 3;
		}
		break;
	case 25:
		//numVariables = 10;
		lowBound[0] = 0.7;
		uppBound[0] = 4.6;
		for (int i = 0; i<numVariables; i++){
			lowBound[i] = 0;
			uppBound[i] = 3;
		}
		break;
	default:
		;
	};
}

#endif
