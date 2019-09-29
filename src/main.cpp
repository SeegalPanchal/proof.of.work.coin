#include "block.h"

int main()
{
    // create a new hashing object   
    SHA256 sha256;

    // hashing an std::string   
    std::cout << sha256("Hello World") << std::endl;   
    // => a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e

    // hashing a buffer of bytes   
    const char* buffer = "How are you";
    std::string temp = sha256(buffer, 11);
    std::cout << temp << std::endl;   
    // => 9c7d5b046878838da72e40ceb3179580958df544b240869b80d0275cc07209cc

    // or in a streaming fashion (re-use "How are you")   
    SHA256 sha256stream;   
    const char* message = "How are you"; 
    // 11 (sizeof(message))    
    for (int i = 0; i < 11; i++)     
        sha256stream.add(message+i, 1); // add five bytes at a time   
    std::cout << sha256stream.getHash() << std::endl;   
    // => 82aa771f1183c52f973c798c9243a1c73833ea40961c73e55e12430ec77b69f6

    int index = 50;
    std::stringstream ss; 
    std::string ind; ss << index; ss >> ind;
    std::cout << ind << std::endl;

    time_t now = time(0); 
    std::string dt = ctime(&now);
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);

    std::cout << "The local date and time is: " << dt << std::endl;

    return 0;
}