#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_SIZE = 4; // Adjust if necessary

void read_matrix_from_stream(double matrix_1[][MAX_SIZE], double matrix_2[][MAX_SIZE], int &matrix_size) {
    ifstream in_file("matrix-data-file.txt");
    in_file >> matrix_size;
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            in_file >> matrix_1[i][j];
        }
    }
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            in_file >> matrix_2[i][j];
        }
    }
    
    in_file.close();
}

void print_matrix(const double matrix[][MAX_SIZE], int matrix_size) {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void print_matrix(const double matrix_1[][MAX_SIZE], const double matrix_2[][MAX_SIZE], int matrix_size) {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            cout << matrix_1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            cout << matrix_2[i][j] << " ";
        }
        cout << endl;
    }
}

void add_matrices(const double matrix_1[][MAX_SIZE], const double matrix_2[][MAX_SIZE], double result[][MAX_SIZE], int matrix_size) {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            result[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
}

void multiply_matrices(const double matrix_1[][MAX_SIZE], const double matrix_2[][MAX_SIZE], double result[][MAX_SIZE], int matrix_size) {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < matrix_size; k++) {
                result[i][j] += (matrix_1[i][k] * matrix_2[k][j]);
            }
        }
    }
}

void get_diagonal_sum(const double matrix[][MAX_SIZE], int matrix_size) {
    int sum = 0;
    for (int i = 0; i < matrix_size; i++) {
        sum += matrix[i][i] + matrix[i][matrix_size - i - 1];
    }
    cout << "diagonal sum = " << sum << endl;
}

void swap_matrix_row(double matrix[][MAX_SIZE], int matrix_size, int row1, int row2) {
    if (row1 < 0 || row2 > matrix_size - 1) {
        cout << "Invalid rows entered" << endl;
    }
    else if (row1 == row2) {
        cout << "Cannot swap row with itself" << endl;
    }
    else {
        int temp;
        for (int i = 0; i < matrix_size; i++) {
            temp = matrix[row1][i];
            matrix[row1][i] = matrix[row2][i];
            matrix[row2][i] = temp;
        }
        print_matrix(matrix, matrix_size);
    }
}

int main(int argc, char *argv[]) {
    double matrix_1[MAX_SIZE][MAX_SIZE], matrix_2[MAX_SIZE][MAX_SIZE];
    int matrix_size;
    read_matrix_from_stream(matrix_1, matrix_2, matrix_size);
    
    cout << "print_matrix:" << endl;
    print_matrix(matrix_1, matrix_2, matrix_size);
    
    double add_result[MAX_SIZE][MAX_SIZE];
    add_matrices(matrix_1, matrix_2, add_result, matrix_size);
    cout << "add_matrices result:" << endl;
    print_matrix(add_result, matrix_size);
    
    double multiply_result[MAX_SIZE][MAX_SIZE];
    multiply_matrices(matrix_1, matrix_2, multiply_result, matrix_size);
    cout << "multiply_matrices result:" << endl;
    print_matrix(multiply_result, matrix_size);
    
    cout << "get matrix diagonal sum" << endl;
    get_diagonal_sum(matrix_1, matrix_size);
    
    cout << "swap matrix rows" << endl;
    swap_matrix_row(matrix_1, matrix_size, 0, 1);
    
    return 0;
}
