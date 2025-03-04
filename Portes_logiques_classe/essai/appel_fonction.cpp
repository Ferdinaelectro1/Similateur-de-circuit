#include <iostream>
#include <functional>
#include <string>

void afficher_message(std::string message)
{
    std::cout << "Message : "<< message<<std::endl;
}

void executer_func(std::function<void(std::string)> fonction,std::string msg)
{
    fonction(msg);
}
int main()
{
    executer_func(afficher_message,"Salut");
    return 0;
}