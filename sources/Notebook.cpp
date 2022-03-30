#include <string>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include "Direction.hpp"
#include "Notebook.hpp"


namespace ariel{
	// constructor
    Notebook :: Notebook(){
		this->size = 0;
	}
	// this function write to the notebook
    void Notebook :: write(int page, int row, int col, Direction d, string s){
		const int min = 32;
		const int max = 125;
		// check if the input is positive numbers
        if(page < 0 || row < 0 || col < 0){
			throw runtime_error ("please enter positive number");
		}
		// maximum chars in row is 100
		if (col >= SIZE){
			throw runtime_error ("the maximum chars in row is 100");
		}
		int len = s.length();
		// check if the string is legall
		for(int i= 0; i<len; i++){
			// ~ can't be in the string
			if(s[unsigned(i)] == '~'){
				throw runtime_error("the string contain ~");
			}
			// the string can contain only legall chars
			if(s[unsigned(i)] < min || s[unsigned(i)] > max){
				throw runtime_error("this string is illegal");
			}
		}
		// maximum chars in row is 100
		if(col + len > SIZE && d == Direction::Horizontal){
			throw runtime_error("the row is over");
			}
        if(d == Direction::Horizontal){
			// check if the place is full
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
			// write the string
            for(int i = 0; i < len; i++){ 
				note[page][row][unsigned(col)] = s[unsigned(i)];
				col = col + 1;
			}
        }
		// if the direction is Vertical
        else{
			// check if the place is full
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
			// write the string
			for(int i=0; i<len; i++){
				note[page][row+i][unsigned(col)] = s[unsigned(i)];
				}
			}
        }
	// this function read from the notebook
    string Notebook :: read(int page, int row, int col, Direction d, int size){
		const int min = 31;
		const int max =  127;
		// check if the input is positive numbers
		if(page < 0 || row < 0 || col < 0 || size < 0){
			throw runtime_error ("please enter positive number");
		}
		// maximum chars in row is 100
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
			// read from the notebook
			for(int i = 0; i<size; i++){
				// if this place is empty present is with '_'
				if(note[page][row][unsigned(col+i)] < min || note[page][row][unsigned(col+i)] > max){
					ans += "_";
					continue;
				}
				ans += note[page][row][unsigned(col+i)];
			}
		}
		// if the direction is Vertical
        else{
			// read from the notebook
            for(int i=0; i<size; i++){
				// if this place is empty present is with '_'
				if(note[page][row +i][unsigned(col)] < min || note[page][row +i][unsigned(col)] > max){
					ans += "_";
					continue;
				}
				ans += note[page][row +i][unsigned(col)];
            }
        }
        return ans;
    }
	// this function erase chars from the notebook
    void Notebook :: erase(int page, int row, int col, Direction d, int size){
		// check if the input is positive numbers
		if(page < 0 || row < 0 || col < 0 || size < 0){
			throw runtime_error ("please enter positive number");
		}
		// maximum chars in row is 100
		if (col >= SIZE){
			throw runtime_error ("the maximum chars in row is 100");
		}
		if(d == Direction :: Horizontal){
			if(col+size >= SIZE){  
				throw runtime_error ("the row is over");
			}
		}
        if(d == Direction :: Horizontal){
			// erase the chars by '~'
			for(int i = 0; i<size; i++){
				note[page][row][unsigned(col+i)] = '~';
			}
		}
		// if the direction is Vertical
        else{
			// erase the chars by '~'
            for(int i= 0; i<size; i++){
				note[page][row + i][unsigned(col)] = '~';
			}
        }
    }
	// this function present the page in the notebook
    void Notebook :: show(int page){
		// check if the input is positive
		if(page < 0){
			throw runtime_error("please enter positive number");
		}
		for(int i=0; ; i++){
			// if the row is empty- finish
			if(note[page].empty()){
				break;
			}
			// read 1 row in the page and print
			string str = this->read(page, i, 0, Direction::Horizontal, SIZE-1);
			std :: cout << str << std :: endl;
		}
	}
    }
