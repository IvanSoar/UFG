#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    int casos, tamanhoNum1, tamanhoNum2, resultado[1000], num1[41], num2[41];
    std::string string1, string2;

    std::cin >> casos;

    for (int i = 0; i < casos; i++)
    {
        std::cin >> string1;
        tamanhoNum1 = string1.length();     
    }   
    
    std::cout << std::string::stoi(string1[0]) << std::endl;
    std::cout << string1[1] << std::endl;
    std::cout << string1[2] << std::endl;

    return 0;
}
