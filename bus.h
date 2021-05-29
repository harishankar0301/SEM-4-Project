#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class bus
{
private:
    int bno;
    int c_start;
    int c_end;

public:
    static unordered_map<string, int> map_citynames1;
    static unordered_map<int, string> map_citynames2;
    static unordered_map<pair<string, string>, int, hash_pair> map_bus_no;
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

        while (cityfile >> cityno >> cityname)
        {
            map_citynames1[cityname] = cityno;
            map_citynames2[cityno] = cityname;
        }
    }
    static void init_bus_no()
    {
        bus b;
        fstream fin("bus.txt", ios::in | ios::out);

        int i = 0;
        fin.seekg(0);
        fin.read((char *)&b, sizeof(b));
        while (!fin.eof())
        {
            pair<string, string> p1(map_citynames2[b.c_start], map_citynames2[b.c_end]);
            pair<string, string> p2(map_citynames2[b.c_end], map_citynames2[b.c_start]);
            bus::map_bus_no[p1] = b.bno;
            bus::map_bus_no[p2] = b.bno;
            fin.read((char *)&b, sizeof(b));
        }

        fin.close();
    }
    void show()
    {
        bus::init_citynames();
        cout << "Bus Number : " << bno << endl;
        cout << "Starts at  : " << map_citynames2[c_start] << endl;
        cout << "Ends at    : " << map_citynames2[c_end] << endl;
    }
};

unordered_map<string, int> bus::map_citynames1;
unordered_map<int, string> bus::map_citynames2;
unordered_map<pair<string, string>, int, hash_pair> bus::map_bus_no;
