#include "KinematicTools.h"
#include "../Globals.h"
#include <iostream>
Matrix RotX(double angle){
  Matrix result = Matrix(4,4,false);
  double sinA = sin(angle);
  double cosA = cos(angle);

  result[0][0] = 1.0;
  result[0][1] = 0;
  result[0][2] = 0;
  result[0][3] = 0;

  result[1][0] = 0;
  result[1][1] = cosA;
  result[1][2] = -sinA;
  result[1][3] = 0;

  result[2][0] = 0;
  result[2][1] = sinA;
  result[2][2] = cosA;
  result[2][3] = 0;

  result[3][0] = 0;
  result[3][1] = 0;
  result[3][2] = 0;
  result[3][3] = 1;

  return result;
}

Matrix RotY(double angle){
  Matrix result = Matrix(4,4,false);
  double sinA = sin(angle);
  double cosA = cos(angle);

  result[0][0] = cosA;
  result[0][1] = 0;
  result[0][2] = sinA;
  result[0][3] = 0;

  result[1][0] = 0.0;
  result[1][1] = 1.0;
  result[1][2] = 0.0;
  result[1][3] = 0.0;

  result[2][0] = -sinA;
  result[2][1] = 0.0;
  result[2][2] = cosA;
  result[2][3] = 0.0;

  result[3][0] = 0.0;
  result[3][1] = 0.0;
  result[3][2] = 0.0;
  result[3][3] = 1.0;

  return result;
}

Matrix RotZ(double angle){
  Matrix result = Matrix(4,4,false);
  double sinA = sin(angle);
  double cosA = cos(angle);

  result[0][0] = cosA;
  result[0][1] = -sinA;
  result[0][2] = 0.0;
  result[0][3] = 0.0;

  result[1][0] = sinA;
  result[1][1] = cosA;
  result[1][2] = 0.0;
  result[1][3] = 0.0;

  result[2][0] = 0.0;
  result[2][1] = 0.0;
  result[2][2] = 1.0;
  result[2][3] = 0.0;

  result[3][0] = 0.0;
  result[3][1] = 0.0;
  result[3][2] = 0.0;
  result[3][3] = 1.0;

  return result;
}

Matrix Translation(double dx, double dy, double dz){
  Matrix result = Matrix(4,4);

  result[0][0] = 1.0;
  result[0][1] = 0.0;
  result[0][2] = 0.0;
  result[0][3] = dx;

  result[1][0] = 0.0;
  result[1][1] = 1.0;
  result[1][2] = 0.0;
  result[1][3] = dy;

  result[2][0] = 0.0;
  result[2][1] = 0.0;
  result[2][2] = 1.0;
  result[2][3] = dz;

  result[3][0] = 0.0;
  result[3][1] = 0.0;
  result[3][2] = 0.0;
  result[3][3] = 1.0;

  return result;
}

Matrix ModifiedDH(double alpha, double a, double theta, double d){
  Matrix result = Matrix(4,4);

//[            cos(theta),           -sin(theta),           0,             a]
//[ cos(alpha)*sin(theta), cos(alpha)*cos(theta), -sin(alpha), -d*sin(alpha)]
//[ sin(alpha)*sin(theta), sin(alpha)*cos(theta),  cos(alpha),  d*cos(alpha)]
//[                     0,                     0,           0,             1]
  using namespace std;
  double st = sin(theta);
  double ct = cos(theta);
  double sa = sin(alpha);
  double ca = cos(alpha);
// Row 0
  result[0][0] = ct;
  result[0][1] = -st;
  result[0][2] = 0.0;
  result[0][3] = a;

// Row 1
  result[1][0] = ca*st;
  result[1][1] = ca*ct;
  result[1][2] = -sa;
  result[1][3] = -d*sa;

// Row 2
  result[2][0] = sa*st;
  result[2][1] = sa*ct;
  result[2][2] = ca;
  result[2][3] = d*ca;

// Row 3
  result[3][0] = 0.0;
  result[3][1] = 0.0;
  result[3][2] = 0.0;
  result[3][3] = 1.0;
  return result;
}
