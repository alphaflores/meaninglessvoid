#include <iostream>
#include <math.h>

void mass_mother () {
	float part1 = 139.57;
	float part2 = 139.57;
	float p1x = -0.645309e3;
	float p1y = 1.03136e3;
	float p1z = 4.29267e3;
	float p2x = -1.43542e3;
	float p2y = 3.51513e3;
	float p2z = 13.8416e3;
	float p1 = sqrt(pow(p1x,2)+pow(p1y,2)+pow(p1z,2));
	float p2 = sqrt(pow(p2x,2)+pow(p2y,2)+pow(p2z,2));
	float px = p1x+p2x;
	float py = p1y+p2y;
	float pz = p1z+p2z;
	float E1 = sqrt(pow(part1,2)+pow(p1,2));
	float E2 = sqrt(pow(part2,2)+pow(p2,2));
	float ME = E1+E2;
	float MP = sqrt(pow(px,2)+pow(py,2)+pow(pz,2));
	float MM = sqrt(pow(ME,2)-pow(MP,2));
	cout << "Mass of mother particle is : ";
	cout << MM;
	cout << " MeV/c2\n";
	return 0;

}
