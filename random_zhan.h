#include <cstdlib>
#include <cmath>
//==============Test Functions===============

//Func Name : random
//Function  : return a random between the given low and higb bound
//Param     : (double) low  and (double) high
//Autor     : Apollo (Zhihui Zhan)
//Date      : Oct.23 2006
inline double random(double low, double high)
{
	return low + (high - low)*rand()*1.0 / RAND_MAX;
	//return ((double)(rand()%1000)/1000.0)*(high - low) + low;
}
inline int rndom_int(int low, int high)
{
	if (high>low)
		return low + rand() % (high - low + 1);
	else
		return low;
}
/////////////////////////////////////////////////////////
