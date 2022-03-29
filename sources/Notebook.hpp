#include <string>
#include <vector>
#include <unordered_map>
#include "Direction.hpp"
#define SIZE 100

using namespace std;


namespace ariel{
        // class Row{
        //     public: 
        //         vector<char> arr;
        //         Row();
        // };
        // class Page{
        //     public:
        //         int capacity;
        //         // vector<Row> page;
        //         unordered_map<int, char[100]> rows;
        //         Page();
        //         void add(int size);
        // };
    	class Notebook{
            private:
                int size;
                // vector<Page> note;
                unordered_map<int, unordered_map<int, char[100]>> note;
		    public:
                Notebook();
                void add(int size);
		        void write(int page, int row, int col, Direction d, string s);
		        string read(int page, int row, int col, Direction d, int size);
		        void erase(int page, int row, int col, Direction d, int size);
		        void show(int page);
		};
};
