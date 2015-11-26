#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>

unsigned int minBase(char c){
    if(c >= 48 && c <= 57){
	return c - 47;
    }
    if(c >= 65 && c <= 70){
	return c - 54;
    }
    return 0;
}

unsigned int findMinBase(std::string input){
    unsigned int min = 0;
    for(unsigned int i = 0; i < input.length(); ++ i){
	short temp = minBase(input[i]);
	if(min < temp){
	    min = temp;
	}
    }
    return min;
}

unsigned int charToNum(char c){
    if(c >= 48 && c <= 57){
	return c - 48;
    }
    if(c >= 65 && c <= 70){
	return c - 55;
    }    
}

long long convertBaseTen(std::string input){
    unsigned int base = findMinBase(input);
    long long result = 0;
    for(unsigned int i = 0; i < input.length(); ++ i){
	char c = input[i];
	unsigned int exponent = input.length() - i - 1;
	unsigned int num = charToNum(c);
	result = result + (num * pow(base, exponent));
    }
    return result;
}

int main(){
    std::string x;
    std::string y;
    std::cin >> x;
    std::cin >> y;
    long long result = convertBaseTen(x) + convertBaseTen(y);
    std::cout << result << std::endl;
    return 0;
}



