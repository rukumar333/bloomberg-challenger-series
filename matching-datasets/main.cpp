#include <iostream>
#include <string>
#include <vector>
#include <math.h>

double distancePoints(std::vector<double> firstPoint, std::vector<double> secondPoint){
    double sum = 0;
    for(int i = 0; i < firstPoint.size(); ++ i){
	double x = firstPoint[i];
	double y = secondPoint[i];
	sum = sum + ((x - y) * (x - y));
    }
    return sqrt(sum);
}

std::vector<double> pointToVector(std::string point){
    std::vector<double> result = std::vector<double>();
    std::string temp = "";
    unsigned int i = 0;
    while(i != point.length()){
	if(point[i] == ','){
	    result.push_back(std::stod(temp));
	    temp = "";
	}else{
	    temp = temp + point[i];	    
	}
	++ i;
    }
    result.push_back(std::stod(temp));
    return result;
}

int main(){
    std::string input = "";
    int count = 0;
    std::getline(std::cin, input);
    count = std::stoi(input);
    std::vector<double> firstSet[count];
    std::vector<double> secondSet[count];
    std::string results[count];
    for(unsigned int i = 0; i < count; ++ i){
	std::getline(std::cin, input);	
	firstSet[i] = pointToVector(input);
    }
    for(unsigned int i = 0; i < count; ++ i){
	std::getline(std::cin, input);
	secondSet[i] = pointToVector(input);
    }
    for(unsigned int i = 0; i < count; ++ i){
	std::string temp = std::to_string(i) + ",";
	double distance = -1;
	unsigned int index = 0;
	for(unsigned int k = 0; k < count; ++ k){
	    double tempDistance = distancePoints(firstSet[i], secondSet[k]);
	    if(distance < 0 || distance > tempDistance){
		index = k;
		distance = tempDistance;
	    }
	}
	std::cout << temp << index << std::endl;
    }
    return 0;
}
