#ifndef UTILS_HPP
#define UTILS_HPP

#include<iostream>
#include<vector>

namespace utils {

	using std::vector;
	using std::cout;
	using std::endl;

	/*
	 *	Function that rotates a matrix 90º clockwise
	 *
	 *	Example:
	 *
	 *		1 2 3			 7 4 1
	 *		4 5 6  ->  8 5 2
	 *		7 8 9			 9 6 3
	 */
	template<typename T>
	void rotate(vector<vector<T>>& matrix) {
		auto aux = matrix;
		for(size_t i = 0; i < matrix.size(); i++) {
			for(size_t j = 0; j < matrix[i].size(); j++) {
				matrix[i][j] = aux[matrix.size() - j - 1][i];
			}
		}	
	}

	/*
	 *	Function that prints a matrix on stdout
	 */
	template<typename T>
	void print_matrix(vector<vector<T>>& matrix) {
		for(size_t i = 0; i < matrix.size(); i++) {
			for(size_t j = 0; j < matrix[i].size(); j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

}

#endif
