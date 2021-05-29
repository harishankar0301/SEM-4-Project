#include <iostream>
#include "get_and_store_bus.cpp"
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

    int ch;
    cout << "\n\n\n\n\n\n\n\n";
    logo();
    cout << "\n\n\n\n\n\n\n\n\n\n Press 0 to continue:  ";
line1:
    cin >> ch;
    if (ch == 0)
    {
        bus::init_citynames();
        system("clear");
    d:
        int ch;
        cout << "\n\n\n";
        logo();
        cout << "                             Enter Login Type:-\n";
        cout << "                                   1.ADMIN \n                                   2.USER\n                                   3.EXIT\n                                 ";

        cin>>ch;

        graph g;
        fstream grap("graph.txt", ios::in | ios::out);
        grap.seekg(0);
        grap.read((char *)&g, sizeof(g));

        if (ch == 1)
        {
        admin:
            system("clear");
            logo();
            cout << "                             Enter choice Type:-\n";
            cout << "                                   1.ADD BUS \n                                   2.VIEW BUS\n                                   3.EXIT\n                                   4.Init graph(First time only !!!)\n\n                              ";
            int ch;
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                addbus();
                cout << "Do you want to continue?? Enter 1 to continue" << endl;
                int ch;
                cin >> ch;
                if (ch)
                    goto admin;
            }
            case 2:
            {
                system("clear");
                show();
                cout << "Do you want to continue?? Enter 1 to continue" << endl;
                int ch;
                cin >> ch;
                if (ch)
                    goto admin;
            }
            break;
            case 3:
            {
                cout << "Exiting....." << endl;
                exit(0);
                break;
            }
            case 4:
                initGraph();
                goto admin;
                break;
            default:
                cout << "Invalid choice." << endl;
                goto admin;
                break;
            }
        }
        else if (ch == 2)
        {
        user:
            system("clear");
            logo();
            cout << "                             Enter choice Type:-\n";
            cout << "                                   1.FIND BUSES To TAKE FOR SHORTEST ROUTE \n                                   2.VIEW ALL BUSES\n                                   3.EXIT\n\n                                   ";
            int ch;
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                system("clear");
                g.shortestRoute();
                cout << "Do you want to continue?? Enter 1 to continue" << endl;
                int ch;
                cin >> ch;
                if (ch)
                    goto user;
            }
            case 2:
            {
                system("clear");
                show();
                cout << "Do you want to continue?? Enter 1 to continue" << endl;
                int ch;
                cin >> ch;
                if (ch)
                    goto user;
            }
            case 3:
            {
                cout << "Thank You....." << endl;
                exit(0);
                break;
            }
            default:
            { 
                cout << "Invalid Choice." << endl;
                goto user;
            }
            }
        }
    }
    return 0;
}