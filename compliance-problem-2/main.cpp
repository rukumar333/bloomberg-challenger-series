#include <unordered_map>
#include <iostream>
#include <string>

int main(){
    std::string input = "";
    std::getline(std::cin, input);
    std::unordered_map<char, int> letterMap = std::unordered_map<char, int>();
    for(unsigned int i = 0; i < input.length(); ++ i){
	char c = input[i];
	if(letterMap.count(c) > 0){
	    letterMap[c] = letterMap[c] + 1;
	}else{
	    letterMap[c] = 1;
	}
    }
    int oddCount = 0;
    auto it = letterMap.begin();
    while(it != letterMap.end() && oddCount < 2){
	if(it->second % 2 != 0){
	    ++ oddCount;
	}
	++ it;
    }
    if(oddCount > 1){
	std::cout << "0" << std::endl;
    }else{
	std::cout << "yes" << std::endl;	
    }
    return 0;
}
