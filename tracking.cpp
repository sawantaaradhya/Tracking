#include <iostream>
#include <armadillo>
arma::Mat<float> tracker(float u1,float v1,float u2,float v2, float vx,float vy,float vz,float wx,float wy,float wz, float t)	{
	float cx=200;
	float cy=200;
	float fx=0.03;
	float fy=0.03;
	arma::Mat<float> A;
	A << fx << 0 << 0 << 0 << cx-u1 << 0 << arma::endr
	  << 0 << 0 << fy << 0 << cy-v1 << 0 <<arma::endr
	  << 0 << fx << 0 << 0 << 0 << cx-u2 <<arma::endr
	  << 0 <<0 << 0 << fy << 0 << cy-v2 <<arma::endr
  	  << -1 << 1 << -wz*t << 0 << wy*t << 0 <<arma::endr
	  << wz*t << 0 << -1 << 1 << -wx*t << 0 <<arma::endr
	  <<-wy*t <<0 << wx*t << 0 <<-1 << 1 <<arma::endr ;
	arma::Mat<float> B;
	B << 0 << arma::endr
	  << 0 << arma::endr
	  << 0 << arma::endr
	  << 0 << arma::endr
	  << -vx*t << arma::endr
	  << -vy*t << arma::endr
	  << -vz*t << arma::endr;
	arma::Mat<float> pos = ((A.t()*A).i())*(A.t()*B);
	//A.print();
	//B.print();
	return pos;	
}
int main()
{
	arma::Mat<float> pos=tracker(200,200,400,400,-20,-20,0,0,0,0,0.1);
	pos.print();
 	return 1;
}
