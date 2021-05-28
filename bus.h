#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

class bus
{
    private:
        int bno;
        int c_start;
        int c_end;
        
    public:
        static unordered_map<string,int> map_citynames1;
        static unordered_map<int,string> map_citynames2;        
        bus()
        {
            bno = 0;
            c_start = 0;
            c_end = 0;
        }
        bus(int b, int s, int e)
        {
            bno = b;
            c_start = s;
            c_end = e;
        }
        static void init_citynames()
        {
            std::ifstream cityfile("cities.txt");
            int cityno;
            string cityname;
            //cout<<"Static fn called"<<endl;
            while(cityfile >> cityno >> cityname)
            {
                //cout<<"Reading "<<cityno<<" "<<cityname<<endl;
                map_citynames1[cityname] = cityno;
                map_citynames2[cityno] = cityname;               
            } 
        }
        void show()
        {
            cout<<"Bus Number : "<<bno<<endl;
            cout<<"Starts at  : "<<map_citynames2[c_start]<<endl;
            cout<<"Ends at    : "<<map_citynames2[c_end]<<endl;
        }
};

unordered_map<string,int> bus::map_citynames1;
unordered_map<int,string> bus::map_citynames2;
