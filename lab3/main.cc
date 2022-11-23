#include <iostream>

#include "User.h"
#include "UserTable.h"

using std::cout;
using std::endl;

int main () {
    UserTable ut("users.txt");
    //UserTable ut{};

    cout << "Adding users..." << endl;

    cout << ut.find(21330) << endl;

    cout << ut.find(21331) << endl;

    cout << ut.find("Jens Holmgren") << endl;

    ut.addUser(User(1234, "Pelle Pelle"));

    ut.addUser(User(12334, "s Pelle"));

    cout << ut.getNbrUsers() << endl;

    cout << testFindNbr(ut) << endl;

    cout << ut.getNbrUsers() << endl;

    //ut.print(cout);

}