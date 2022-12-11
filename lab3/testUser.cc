#include <string>
#include "UserTable.h"
#include <iostream>
#include "User.h"

int main(){
UserTable table("users.txt");
std::cout << table.find(21330) << std::endl;
std::cout << table.find(21331) << std::endl;
std::cout << table.find(21332) << std::endl;
std::cout << table.find(21329) << std::endl;
std::cout << table.find("Jens Holmgren") << std::endl;
table.addUser(User(1234,"blalal"));
table.addUser(User(1234,"hej hopp"));
std::cout << table.getNbrUsers() << " många användare" << std::endl;
int i = testFindNbr(table);
std::cout << i << std::endl;


}

