#include <iostream>
#include <math.h>

void mass_mother2 () {
	float part1 = 938.27;
	float part2 = 139.57;
	float p1x = -1.76698e3;
	float p1y = 3.64028e3;
	float p1z = 4.77863e3;
	float p2x = -0.313754e3;
	float p2y = 0.906203e3;
	float p2z = 1.09737e3;
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
