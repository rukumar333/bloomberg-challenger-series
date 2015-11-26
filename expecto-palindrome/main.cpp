#include <iostream>
#include <string>
#include <math.h>

bool checkPalindrome(std::string input){
    for(unsigned int i = 0; i < floor(input.length() / 2); ++ i){
	if(input[i] != input[input.length() - i - 1]){
	    return false;
	}
    }
    return true;
}

int getLengthPalin(std::string input){
    std::string prepend = "";
    int index = input.length() - 1;
    while(!checkPalindrome(prepend + input)){
	prepend = prepend + input[index];
	-- index;
    }
    return (prepend + input).length();
}

int main(){
    std::string x;
    std::cin >> x;
    // std::cout << checkPalindrome(x) << std::endl;
    std::cout << getLengthPalin(x) << std::endl;
    return 0;
}
