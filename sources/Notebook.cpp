#include <string>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include "Direction.hpp"
#include "Notebook.hpp"


namespace ariel{
    Notebook :: Notebook(){
		this->size = 0;
	}
    void Notebook :: write(int page, int row, int col, Direction d, string s){
		const int min = 32;
		const int max = 125;
        if(page < 0 || row < 0 || col < 0){
			throw runtime_error ("please enter positive number");
		}
		if (col >= SIZE){
			throw runtime_error ("the maximum chars in row is 100");
		}
		int len = s.length();
		for(int i= 0; i<len; i++){
			if(s[unsigned(i)] == '~'){
				throw runtime_error("the string contain ~");
			}
			if(s[unsigned(i)] < min || s[unsigned(i)] > max){
				throw runtime_error("this string is illegal");
			}
		}
		if(col + len > SIZE && d == Direction::Horizontal){
			throw runtime_error("the row is over");
			}
        if(d == Direction::Horizontal){
			for(int i = 0; i < len; i++){ 
				if(note[page][row][unsigned(col+i)] == '~'){
					throw runtime_error("this place is erased");
				}
				if(min <= note[page][row][unsigned(col+i)] && note[page][row][unsigned(col+i)] <= max){
					if(note[page][row][unsigned(col+i)] != '_'){
						throw runtime_error("this place is full");
					}
				}
			}
            for(int i = 0; i < len; i++){ 
				note[page][row][unsigned(col)] = s[unsigned(i)];
				col = col + 1;
			}
        }
        else{
            for(int i = 0; i < len; i++){
				if(note[page][row+i][unsigned(col)] == '~'){
					throw runtime_error("this place is erased");
				}
				if(note[page][row+i][unsigned(col)] >= min && note[page][row][unsigned(col+i)] <= max){ 
					if(note[page][row+i][unsigned(col)] != '_'){
					throw runtime_error("this place is full");
					}
				}
			}
			for(int i=0; i<len; i++){
				note[page][row+i][unsigned(col)] = s[unsigned(i)];
				}
			}
        }
    string Notebook :: read(int page, int row, int col, Direction d, int size){
		const int min = 31;
		const int max =  127;
		if(page < 0 || row < 0 || col < 0 || size < 0){
			throw runtime_error ("please enter positive number");
		}
		if (col >= SIZE){
			throw runtime_error ("the maximum chars in row is 100");
		}
		if (d == Direction :: Horizontal){
			if(col + size > SIZE){
				throw runtime_error ("the row is over");
			}
		}
		string ans;
        if (d == Direction :: Horizontal){
			for(int i = 0; i<size; i++){
				if(note[page][row][unsigned(col+i)] < min || note[page][row][unsigned(col+i)] > max){
					ans += "_";
					continue;
				}
				ans += note[page][row][unsigned(col+i)];
			}
		}
        else{
            for(int i=0; i<size; i++){
				if(note[page][row +i][unsigned(col)] < min || note[page][row +i][unsigned(col)] > max){
					ans += "_";
					continue;
				}
				ans += note[page][row +i][unsigned(col)];
            }
        }
        return ans;
    }
    void Notebook :: erase(int page, int row, int col, Direction d, int size){
		if(page < 0 || row < 0 || col < 0 || size < 0){
			throw runtime_error ("please enter positive number");
		}
		if (col >= SIZE){
			throw runtime_error ("the maximum chars in row is 100");
		}
		if(d == Direction :: Horizontal){
			if(col+size >= SIZE){  
				throw runtime_error ("the row is over");
			}
		}
        if(d == Direction :: Horizontal){
			for(int i = 0; i<size; i++){
				note[page][row][unsigned(col+i)] = '~';
			}
		}
        else{
            for(int i= 0; i<size; i++){
				note[page][row + i][unsigned(col)] = '~';
			}
        }
    }
    void Notebook :: show(int page){
		if(page < 0){
			throw runtime_error("please enter positive number");
		}
		for(int i=0; ; i++){
			if(note[page].empty()){
				break;
			}
			string str = this->read(page, i, 0, Direction::Horizontal, SIZE-1);
			std :: cout << str << std :: endl;
		}
	}
    }
