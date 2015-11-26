#include <iostream>
#include <string>
#include <vector>
#include <math.h>

//2
std::string getFromKicks(int score){
    if(score % 2 != 0){
	return "";
    }else{
	int val = score / 2;
	return std::to_string(val);
    }
}

//3
std::string getFromTries(int score, int tries){
    int temp = score - (tries * 3);    
    std::string kicks = getFromKicks(temp);
    if(kicks == ""){
	return "";
    }else{
	return std::to_string(tries) + " " + kicks;	
    }
}

//7
std::vector<std::string> getFromTouchdowns(int score, int touchdowns){
    int temp = score - (touchdowns * 7);
    int maxTries = floor(temp / 3);
    std::vector<std::string> results = std::vector<std::string>();
    for(unsigned int i = 0; i <= maxTries; ++ i){
    	std::string kicksTries = getFromTries(temp, i);
	if(kicksTries != ""){
	    results.push_back(std::to_string(touchdowns) + " " + kicksTries);   	    
	}
    }
    return results;
}

int main(){
    int score;
    std::cin >> score;
    bool printed = false;
    int maxTouchdowns = floor(score / 7);
    for(unsigned int i = 0; i <= maxTouchdowns; ++ i){
	std::vector<std::string> listResults = getFromTouchdowns(score, i);
	if(listResults.size() > 0){
	    printed = true;
	}
	for(unsigned int k = 0; k < listResults.size(); ++ k){
	    std::cout << listResults[k] << std::endl;	    
	}
    }
    if(!printed){
	std::cout << "0 0 0" << std::endl;
    }
    return 0;
}
