//---------------------------------------------------------------------------

#pragma hdrstop

#include "uLib.h"
#include <Math.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
 void RUNGE(double X0, double Xn, int NP, MMY Y0, void F(double, MMY, MMY&), MMMZ (&Z))
 {
   MMY Y = {0};
   MMY Y1 = {0};

	MMY K1 = {0};
	MMY K2={0};
	MMY K3={0};
	MMY K4={0};
	double x,dx;
	dx=(Xn-X0)/(NP-1);
	x=X0;   Y=Y0;
  for (int i=1; i < NV; i++){
	 for (int j = 1; j < PD; j++) {
		 Z.arr[0][i][j]=Y0.arr[i][j];
	 }
  }
  for (int k = 1; k < NP; k++) {
	 F(x,Y,K1);
	 x=x+dx/2;
	 for (int i = 1; i < NV; i++) {
		for (int j = 1; j < PD; j++) {
		   Y1.arr[i][j]=Y.arr[i][j]+K1.arr[i][j]*dx/2;
		}
	 }
	  F(x,Y1,K2);
	  for (int i = 1; i <NV; i++) {
		for (int j = 1; j < PD; j++) {
		   Y1.arr[i][j]=Y.arr[i][j]+K2.arr[i][j]*dx/2;
		}
	 }
	  F(x,Y1,K3);
	  x=x+dx/2;
	 for (int i = 1; i <NV; i++) {
		for (int j = 1; j < PD; j++) {
		   Y1.arr[i][j]=Y.arr[i][j]+K3.arr[i][j]*dx;
		}
	 }
	  F(x,Y1,K4);
	  for (int i = 1; i < NV; i++) {
		for (int j = 1; j < PD; j++) {
			Y.arr[i][j]=Y.arr[i][j]+(K1.arr[i][j]+2*K2.arr[i][j]+2*K3.arr[i][j]
			+K4.arr[i][j])*dx/6;
			Z.arr[k][i][j]=Y.arr[i][j];
		}
	 }
  }
    int q = x*2;
 }
double T(double A, double B, double Ta, double Tb, double R){
   //—тационарное температурное поле в стенке толстостенного цилиндра
   double T;
   if (A == 0) {
	   T = Tb;
   } else {
	   T = Ta + (Tb - Ta)*log(R/A)/log(B/A);
   }
   return T;
}

