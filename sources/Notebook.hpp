#include <string>
#include <vector>
#include <unordered_map>
#include "Direction.hpp"
#define SIZE 100

using namespace std;


namespace ariel{
    	class Notebook{
            private:
                int size;
                unordered_map<int, unordered_map<int, char[100]>> note;
		    public:
                Notebook();
		        void write(int page, int row, int col, Direction d, string s);
		        string read(int page, int row, int col, Direction d, int size);
		        void erase(int page, int row, int col, Direction d, int size);
		        void show(int page);
		};
};
