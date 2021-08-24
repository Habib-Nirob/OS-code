#include <iostream>
#include <vector>
#define NUM_CYLINDERS 200

using namespace std;


bool incomplete_access_cylinders[NUM_CYLINDERS] = {false};

int main()
{
	int head_location;
	cin >> head_location;

	int num_locations;
	cin >> num_locations;

	vector<int> access_locations;
	for(int i=0; i < num_locations; i++){
		int access_location;
		cin >> access_location;

		access_locations.push_back(access_location);


		incomplete_access_cylinders[access_location] = true;
	}

	vector<int> path;
	path.push_back(head_location);
	int total_distance = 0;
	cout << "Total distance:";


	bool first_access = true;

	for(int i=head_location; i >= 0; i--){
		if(!incomplete_access_cylinders[i] && i){

			continue;
		}

		int current_location = i;
		int next_head = current_location;

		if(head_location < current_location){
			swap(head_location, current_location);
		}

		if(!first_access){
			cout << "+";
		}
		cout << "(" << head_location << "-" << current_location << ")";

		int distance = head_location - current_location;
		total_distance += distance;

		head_location = next_head;
		path.push_back(head_location);


		incomplete_access_cylinders[i] = false;
		first_access = false;
	}


	for(int i=1; i < NUM_CYLINDERS; i++){
		if(!incomplete_access_cylinders[i]){

			continue;
		}

		int current_location = i;
		int next_head = current_location;

		if(head_location < current_location){
			swap(head_location, current_location);
		}

		if(i){
			cout << "+";
		}
		cout << "(" << head_location << "-" << current_location << ")";

		int distance = head_location - current_location;
		total_distance += distance;

		head_location = next_head;
		path.push_back(head_location);
	}

	cout << " = " << total_distance << endl;

	cout << "Path:";
	int path_length = path.size();
	for(int i=0; i < path_length; i++){
		cout << " " << path[i];
	}

	cout << endl;

	return 0;
}
