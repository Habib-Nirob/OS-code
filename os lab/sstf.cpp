#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num_locations;
	cout << "Number:";
	cin >> num_locations;
	vector<int> access_locations;
	for(int i=0; i < num_locations; i++){
		int access_location;
		cin >> access_location;

		access_locations.push_back(access_location);
	}



	int head_location;
	cout<< "Head starts at:";
	cin >> head_location;



	vector<int> path;
	path.push_back(head_location);
	int total_distance = 0;
	cout << "Total distance:";
	for(int i=0; i < num_locations; i++){
		int current_location;


		int to_remove = 0;
		int distance;
		int shortest_distance = INT_MAX;
		for(int i=0; i < access_locations.size(); i++){
			int current_temp = access_locations[i];

			int distance_temp = abs(head_location - current_temp);

			if(distance_temp < shortest_distance){
				shortest_distance = distance_temp;
				current_location = current_temp;
				distance = distance_temp;
				to_remove = i;
			}
		}

		access_locations.erase(access_locations.begin() + to_remove);

		int next_head = current_location;


		if(head_location < current_location){
			swap(head_location, current_location);
		}

		if(i){
			//cout << "+";
		}
		//cout << "(" << head_location << "-" << current_location << ")";

		// int distance = head_location - current_location;
		total_distance += distance;

		head_location = next_head;
		path.push_back(head_location);
	}

	cout << " = " << total_distance << endl;

	cout << "Path:";
	for(int i=0; i < num_locations + 1; i++){
		cout << " " << path[i];
	}

	cout << endl;

	return 0;
}
