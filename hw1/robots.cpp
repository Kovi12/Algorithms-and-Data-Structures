#include <iostream>
#include <fstream>
#include <tuple>
#define N 15000
#define M 10000
using namespace std;

int maximum_discharge(int robot_energy[], int total_robots,  tuple<int, int> discharge) {
	int max_robots = 0;
	int energy = get<1>(discharge);
	for (int i = get<0>(discharge) - 1; i < total_robots; i++)
	{
		if (energy >= robot_energy[i] && max_robots < total_robots)
		{
			energy -= robot_energy[i];
			max_robots++;
		}
		else
			break;

		if (i == total_robots - 1)
			i = -1;

	}
	return max_robots;
}

int main(){
	ifstream input("robots.in");
	
	int total_robots, discharge_robots;
	input >> total_robots >> discharge_robots;

	int robot_energy[N];
	for (int i = 0; i < total_robots; i++)
		input >> robot_energy[i];

	tuple<int,int> robot_discharge[M];
	for (int i = 0; i < discharge_robots; i++)
	{
		int index, discharge;
		input >> index >> discharge;
		robot_discharge[i] = make_tuple(index, discharge);
	}
	input.close();

	ofstream output("robots.out");
	for (int i = 0; i < discharge_robots; i++)
		output << maximum_discharge(robot_energy, total_robots, robot_discharge[i]) << endl;
	output.close();

	return 0;
}