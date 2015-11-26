#include <iostream>
#include <string>

int main(){
    bool white = false;
    bool black = false;
    bool blue = false;
    bool red = false;
    bool yellow = false;
    std::string input;
    std::cin >> input;
    while(std::getline(std::cin, input)){
	if(input == "White"){white = true;}	    
	if(input == "Black"){black = true;}	    
	if(input == "Red"){red = true;}	    	    
	if(input == "Yellow"){yellow = true;}	    	    
	if(input == "Blue"){blue = true;}
    }
    if(!white){
	std::cout << "White" << std::endl;
    }
    if(!black){
	std::cout << "Black" << std::endl;
    }
    if(!red){
	std::cout << "Red" << std::endl;
    }
    if(!blue){
	std::cout << "Blue" << std::endl;
    }
    if(!yellow){
	std::cout << "Yellow" << std::endl;
    }
    return 0;
}
