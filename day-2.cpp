//command to go into directory: cd /home/cobra/Desktop/programs/AOC2024
//command to compile: g++ day-2.cpp -o day-2

#include <iostream>
#include <fstream>
using namespace std;

#include <string>
#include <vector>

int main(){
	ifstream input("day-2-input");

  	vector<int> arr;

  	int ans = 0;

  	string line;
  	int lineNum = 0;
  	while(getline(input, line)){
  		arr.clear();
  		arr.push_back(0);
  		for(int i = 0; i < line.length(); i++){
  			if(line[i] == ' '){
		        arr.push_back(0);
		        continue;
		    }

		    arr[arr.size()-1] = arr[arr.size()-1]*10 + (char)(line[i]-'0');
  		}

  		bool isIncreasing = true;
  		bool isDecreasing = true;
  		for(int i = 0; i < arr.size()-1; i++){
  			if(arr[i] >= arr[i+1] || arr[i+1] - arr[i] > 3){
  				isIncreasing = false;
  			}
  			if(arr[arr.size()-1-i] >= arr[arr.size()-2-i] || arr[arr.size()-2-i] - arr[arr.size()-1-i] > 3){
  				isDecreasing = false;
  			}
  		}

  		// for(int i = 0; i < arr.size(); i++){
  		// 	printf("%d, ", arr[i]);
  		// }
  		// printf("is increasing: %d, is decreasing: %d\n", isIncreasing, isDecreasing);

  		if(isIncreasing || isDecreasing){
  			ans ++;
  		}
  	}

  	printf("ans: %d\n", ans);

  	input.close();

  	return 0;
}
