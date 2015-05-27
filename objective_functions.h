//========================
//  multi-obj test functions
//  zdt, dtlz, uf, moeadf, tdy1-5
//========================
#ifndef __OBJECTIVE_FUNCTIONS_
#define __OBJECTIVE_FUNCTIONS_
#define MAXN 200

#include "random_zhan.h"
#include "global.h"

const double pi = 3.1415926;
const double sqrt1_3 = sqrt(1.0 / 3);

const int M = 2;
const int K = 4;

inline double fmin(double a, double b)
{
	return a<b ? a : b;
}

inline double fmax(double a, double b)
{
	return a>b ? a : b;
}


inline void sch(double *x, double *f, int dim)
{
	f[0] = x[0] * x[0];
	f[1] = (x[0] - 2)*(x[0] - 2);
}
inline void fon(double *x, double *f, int dim)
{
	int j;
	double t1, t2;
	t1 = t2 = 0;
	for (j = 0; j<dim; j++){
		t1 += (x[j] - sqrt1_3)*(x[j] - sqrt1_3);
		t2 += (x[j] + sqrt1_3)*(x[j] + sqrt1_3);
	}
	f[0] = 1 - exp(-t1);
	f[1] = 1 - exp(-t2);
}
inline void pol(double *x, double *f, int dim)
{
	double A1, B1, A2, B2;
	A1 = 0.5*sin(1.0) - 2 * cos(1.0) + sin(2.0) - 1.5*cos(2.0);
	A2 = 1.5*sin(1.0) - cos(1.0) + 2 * sin(2.0) - 0.5*cos(2.0);
	B1 = 0.5*sin(x[0]) - 2 * cos(x[0]) + sin(x[1]) - 1.5*cos(x[1]);
	B2 = 1.5*sin(x[0]) - cos(x[0]) + 2 * sin(x[1]) - 0.5*cos(x[1]);
	f[0] = 1 + (A1 - B1)*(A1 - B1) + (A2 - B2)*(A2 - B2);
	f[1] = (x[0] + 3)*(x[0] + 3) + (x[1] + 1)*(x[1] + 1);
}
inline void kur(double *x, double *f, int dim)
{
	int j;
	f[0] = f[1] = 0;
	for (j = 0; j<dim - 1; j++){
		f[0] += (-10 * exp(-0.2*sqrt(x[j] * x[j] + x[j + 1] * x[j + 1])));
		f[1] += (pow(fabs(x[j]), 0.8) + 5 * sin(pow(x[j], 3)));
	}
	f[1] += (pow(fabs(x[j]), 0.8) + 5 * sin(pow(x[j], 3)));
}
inline void zdt1(double *x, double *f, int dim)
{
	int j;
	double gx;
	gx = 0;
	for (j = 0; j<dim; j++){
		gx += x[j];
	}
	gx -= x[0];
	gx = 1 + 9 * gx / (dim - 1);
	f[0] = x[0];
	f[1] = gx*(1 - sqrt(x[0] / gx));
}

inline void zdt2(double *x, double *f, int dim)
{
	int j;
	double gx;
	gx = 0;
	for (j = 0; j<dim; j++){
		gx += x[j];
	}
	gx -= x[0];
	gx = 1 + 9 * gx / (dim - 1);
	f[0] = x[0];
	f[1] = gx*(1 - (x[0] / gx)*(x[0] / gx));
}
inline void zdt3(double *x, double *f, int dim)
{
	int j;
	double gx;
	gx = 0;
	for (j = 0; j<dim; j++){
		gx += x[j];
	}
	gx -= x[0];
	gx = 1 + 9 * gx / (dim - 1);
	f[0] = x[0];
	f[1] = gx*(1 - sqrt(x[0] / gx) - x[0] * sin(10 * pi*x[0]) / gx);
}
inline void zdt4(double *x, double *f, int dim)
{
	int j;
	double gx;
	gx = 0;
	for (j = 1; j<dim; j++){
		gx += (x[j] * x[j] - 10 * cos(4 * pi*x[j]));
	}
	gx = 1 + 10 * (dim - 1) + gx;
	f[0] = x[0];
	f[1] = gx*(1 - sqrt(x[0] / gx));
}
inline void zdt5(double *x, double *f, int dim)
{
	int j;
	double gx;
	gx = 0;
	for (j = 1; j<dim; j++){
		gx += (x[j] * x[j] - 10 * cos(4 * pi*x[j]));
	}
	gx = 1 + 10 * (dim - 1) + gx;
	f[0] = x[0];
	f[1] = gx*(1 - sqrt(x[0] / gx));
}
inline void zdt6(double *x, double *f, int dim)
{
	int j;
	double gx;
	gx = 0;
	for (j = 0; j<dim; j++){
		gx += x[j];
	}
	gx -= (x[0]);
	gx = 1 + 9 * pow(gx / (dim - 1), 0.25);
	f[0] = 1 - exp(-4 * x[0])*pow(sin(6 * pi*x[0]), 6);
	f[1] = gx*(1 - (f[0] / gx)*(f[0] / gx));
}
/////////////////////////////////////////////////////////////////
inline void DTLZ1(double *x, double *f, int dim)
{
	int j; double gx;
	gx = 0;
	for (j = 2; j<dim; j++){
		gx = gx + ((x[j] - 0.5)*(x[j] - 0.5) - cos(20 * pi*(x[j] - 0.5)));
	}
	gx = 100 * (dim - 2 + gx);
	f[0] = (1 + gx)*x[0] * x[1];
	f[1] = (1 + gx)*x[0] * (1 - x[1]);
	f[2] = (1 + gx)*(1 - x[0]);
}

inline void DTLZ1_shift(double *x, double *f, int dim)
{
	int j; double gx;
	gx = 0;
	for (j = 2; j<dim; j++){
		gx = gx + ((x[j])*(x[j]) - cos(20 * pi*(x[j])));
	}
	gx = 100 * (dim - 2 + gx);
	f[0] = (1 + gx)*x[0] * x[1];
	f[1] = (1 + gx)*x[0] * (1 - x[1]);
	f[2] = (1 + gx)*(1 - x[0]);
}
//scalable
inline void DTLZ1_S(double *x, double *f, int dim, int objs)
{
	int i, j; double gx;
	int k = 5;
	gx = 0;

	for (j = objs - 1; j<objs + k - 1; j++){
		gx = gx + ((x[j] - 0.5)*(x[j] - 0.5) - cos(20 * pi*(x[j] - 0.5)));
	}
	gx = 100 * (k + gx);
	f[0] = 0.5*(1 + gx);
	for (j = 0; j<objs - 1; j++)
		f[0] *= x[j];

	for (i = 1; i<objs; i++){
		f[i] = 0.5*(1 + gx);
		for (j = 0; j<objs - i - 1; j++)
			f[i] *= x[j];

	}
	for (j = 1; j<objs; j++){
		f[j] *= (1 - x[objs - j - 1]);
	}
}
inline void DTLZ2_S(double *x, double *f, int dim, int objs)
{
	int i, j; double gx;
	gx = 0;
	for (j = 1; j<dim; j++){
		gx = gx + (x[j] - 0.5)*(x[j] - 0.5);
	}
	f[0] = (1 + gx);
	for (j = 0; j<objs - 1; j++)
		f[0] *= cos(x[j] * 0.5*pi);

	for (i = 1; i<objs; i++){
		f[i] = (1 + gx)*sin(x[objs - i - 1] * pi*0.5);
		for (j = i; j<objs - 1; j++)
			f[i] *= cos(x[j - i] * pi*0.5);
	}

}

inline void DTLZ2(double *x, double *f, int dim)
{
	int j; double gx;
	gx = 0;
	for (j = 1; j<dim; j++){
		gx = gx + (x[j] - 0.5)*(x[j] - 0.5);
	}
	f[0] = (1 + gx)*cos(x[0] * pi / 2);
	f[1] = (1 + gx)*sin(x[0] * pi / 2);
}

inline void DTLZ2_shift(double *x, double *f, int dim)
{
	int j; double gx;
	gx = 0;
	for (j = 2; j<dim; j++){
		gx = gx + (x[j])*(x[j]);
	}
	f[0] = (1 + gx)*cos(x[0] * pi / 2)*cos(x[1] * pi / 2);
	f[1] = (1 + gx)*cos(x[0] * pi / 2)*sin(x[1] * pi / 2);
	f[2] = (1 + gx)*sin(x[0] * pi / 2);
}


inline void DTLZ3_S(double *x, double *f, int dim, int objs)
{
	int i, j; double gx;
	gx = 0;

	for (j = 1; j<dim; j++){
		gx = gx + ((x[j] - 0.5)*(x[j] - 0.5) - cos(20 * pi*(x[j] - 0.5)));
	}
	gx = 100 * (dim - 1 + gx);
	f[0] = (1 + gx);
	for (j = 0; j<objs - 1; j++)
		f[0] *= cos(x[j] * 0.5*pi);

	for (i = 1; i<objs; i++){
		f[i] = (1 + gx)*sin(x[objs - i - 1] * pi*0.5);
		for (j = i; j<objs - 1; j++)
			f[i] *= cos(x[j - i] * pi*0.5);
	}

}
inline void DTLZ3_shift(double *x, double *f, int dim)
{
	int j; double gx;
	gx = 0;
	for (j = 2; j<dim; j++){
		gx = gx + ((x[j])*(x[j]) - cos(20 * pi*(x[j])));
	}
	gx = 100 * (dim - 2 + gx);
	f[0] = (1 + gx)*cos(x[0] * pi / 2)*cos(x[1] * pi / 2);
	f[1] = (1 + gx)*cos(x[0] * pi / 2)*sin(x[1] * pi / 2);
	f[2] = (1 + gx)*sin(x[0] * pi / 2);
}
inline void DTLZ3(double *x, double *f, int dim)
{
	int j; double gx;
	gx = 0;
	for (j = 1; j<dim; j++){
		gx = gx + ((x[j] - 0.5)*(x[j] - 0.5) - cos(20 * pi*(x[j] - 0.5)));
	}
	gx = 100 * (dim - 1 + gx);
	f[0] = (1 + gx)*cos(x[0] * pi / 2);
	f[1] = (1 + gx)*sin(x[0] * pi / 2);
}
#endif