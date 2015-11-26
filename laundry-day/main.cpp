#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <algorithm>

int main(){
    std::unordered_map<std::string, int> clothes = std::unordered_map<std::string, int>();
    std::string input = "";
    while(std::getline(std::cin, input)){
	if(clothes.count(input) == 0){
	    clothes[input] = 1;
	}else{
	    clothes[input] = clothes[input] + 1;
	}
    }
    std::vector<std::string> keys = std::vector<std::string>();    
    auto it = clothes.begin();
    while(it != clothes.end()){
	keys.push_back(it->first);
	++ it;
    }
    std::sort(keys.begin(), keys.end(), [](std::string a, std::string b){
	    std::string aTemp = a;
	    std::string bTemp = b;
	    for(unsigned int i = 0; i < a.length(); ++ i){
		aTemp[i] = tolower(a[i]);
	    }
	    for(unsigned int i = 0; i < b.length(); ++ i){
		bTemp[i] = tolower(b[i]);
	    }
	    return bTemp > aTemp;
	});
    for(unsigned int i = 0; i < keys.size(); ++ i){
	std::string key = keys[i];
	int val = clothes[key];
	if(key.find("sock") == std::string::npos){
	    std::cout << val << "|" << key << std::endl;
	}else{
	    int pairs = floor(val / 2);
	    if(val >= 2){	       
		std::cout << pairs << "|" << key << std::endl;
	    }
	    if(val % 2 != 0){
		std::cout << "0|" << key << std::endl;
	    }
	}
    }
    return 0;
}
