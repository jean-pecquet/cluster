
#include <iostream>
#include "puma.h"
using namespace std;
int main (int argc, char **argv){

// generaterandomfibers: straightCircle
cout << endl << "Creating a 100^3 domain with non-intersecting random fibers having a circular cross section, slight preference for angle in XY:"<< endl;

// Creates an empty workspace
puma::Workspace ws(1e-6, false);

// Preparing inputs for fibers generation
RandomFibersInput input;
input.straightCircle(100,100,100,5,0,400,0,90,90,20,false,0.89,100);
input.print = true; // printing option can be turned off like this, ON as a default

// Generating fibers
puma::generateRandomFibers(&ws, input);

// fvthermalconductivity: FiberForm 100^3
cout << endl << "Computing the thermal conductivity using finite volume"<< endl;

// Segmenting workspace by thresholding
ws.setMaterialID(&ws,puma::Cutoff(0,127),0);
ws.setMaterialID(&ws,puma::Cutoff(128,255),1);

// Initializing Temperature field and material conductivity
puma::Matrix<double> T;
map<int, double> matCond;
matCond[0] = 0.0257; // air conductivity
matCond[1] = 12; // approximation to fiber conductivity

// Running simulation in three directions
puma::Vec3<double> kz = puma::compute_FVThermalConductivity(&ws, &T, matCond,"symmetric","bicgstab",'z',1e-3,10000,true);

cout << endl << "Conductivity: " << endl;
cout << "kzx " << kz.x << " kzy " << kz.y << " kzz " << kz.z << endl;

return 0;
}
