#include<iostream>
#include<string>
#include <ctime>

#include "global_level.h"
#include "sub_level.h"
#include "particle_level.h"

void mem_recall()
{
	delete[] g_level_population, g_level_sorted_population, p_level_population, s_level_population;
}
int main()
{

	set_bound();

	global_level(99);

	mem_recall();
	return 0;
}