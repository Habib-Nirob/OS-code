#include <iostream>
#include <vector>
#include <utility>
#define NUM_CYLINDERS 200

using namespace std;
bool incomplete_access_cylinders[NUM_CYLINDERS] = {false};

int main()
{
	int head_location;
	cin >> head_location;

	int left_boundary, right_boundary;
	left_boundary = head_location;
	right_boundary = head_location;

	int num_locations;
	cin >> num_locations;

	vector<int> access_locations;
	for(int i=0; i < num_locations; i++){
		int access_location;
		cin >> access_location;

		access_locations.push_back(access_location);

		if(access_location > right_boundary){
			right_boundary = access_location;
		}

		if(access_location < left_boundary){
			left_boundary = access_location;
		}


		incomplete_access_cylinders[access_location] = true;
	}

	int unserved_requests = num_locations;

	vector<int> path;
	path.push_back(head_location);
	int total_distance = 0;
	cout << "Total distance:";


	bool first_access = true;

	for(int i=head_location; i <= right_boundary; i++){
		if(!incomplete_access_cylinders[i]){

			continue;
		}

		int current_location = i;
		int next_head = current_location;

		if(head_location < current_location){
			swap(head_location, current_location);
		}

		if(!first_access){
			cout << "+";
			first_access = false;
		}
		cout << "(" << head_location << "-" << current_location << ")";

		int distance = head_location - current_location;
		total_distance += distance;

		head_location = next_head;
		path.push_back(head_location);


		incomplete_access_cylinders[i] = false;

		unserved_requests--;
	}


	for(int i=left_boundary; unserved_requests; i++){
		if(!incomplete_access_cylinders[i] && i){

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


		unserved_requests--;
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
