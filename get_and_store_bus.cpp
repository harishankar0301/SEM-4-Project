#include "bus.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

void addbus()
{
    int num_buses;
    cout<<"Enter number of buses to add  : ";
    cin>>num_buses;
    int bn;
    string s,e;
    fstream fin("bus.txt", ios::in | ios::out| ios::app );
    for(int i=0;i<num_buses;i++)
    {
        
        cout<<"\n\nEnter Bus Number     : ";
        cin>>bn;
        cout<<"Enter starting point : ";
        cin>>s;
        cout<<"Enter ending point   : ";
        cin>>e;
        int start,end;
        start = bus::map_citynames1[s];
        end = bus::map_citynames1[e];

        bus b(bn,start,end);
        fin.write((char *)&b, sizeof(b));
        
    }
    fin.close();
}

void show()
{
    bus b;
    fstream fin("bus.txt", ios::in | ios::out);
    
    int i = 0;    
    fin.seekg(0);
    fin.read((char *)&b, sizeof(b));
    while(!fin.eof())
    {
        
        cout<<"------------------------------"<<endl;
        b.show();
        cout<<"------------------------------"<<endl;
        i++;
        fin.read((char *)&b, sizeof(b));
    }
    cout<<"Total  Number of buses is "<<i<<endl;
    fin.close();
}
int main()
{
    bus::init_citynames();
    addbus();
    show();
    
    return 0;
}