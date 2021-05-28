#include <iostream>
#include "graph.h"
#include <fstream>
using namespace std;
void logo()
{
    for (int i = 0; i <= 79; i++)
        cout << "$";
    cout << "\n\n*************************      Bus Finder     ***********************";
    cout << "\n\n\n";
    for (int i = 0; i <= 79; i++)
        cout << "$";
    cout << endl
         << endl;
}
int main()
{
    //fin.open("Library.dat",ios::in|ios::out|::ios::binary|ios::app);

    int ch;
    cout << "\n\n\n\n\n\n\n\n";
    logo();
    cout << "\n\n\n\n\n\n\n\n\n\n Press 0 to continue:  ";
line1:
    cin >> ch;
    if (ch == 0)
    {
        system("clear");
    d:
        int ch;
        cout << "\n\n\n";
        logo();
        cout << "                             Enter Login Type:-\n";
        cout << "                                   1.ADMIN \n                                   2.USER\n                                   3.EXIT\n                                 ";

        graph g(4);
        fstream grap("graph.txt", ios::in | ios::out);
    grap.seekg(0);
    grap.read((char *)&g, sizeof(g));
    g.printGraph();
    }
    return 0;
}