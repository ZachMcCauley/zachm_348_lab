#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 4; // Adjust if necessary

class Matrix {
public:
    int data[MAX_SIZE][MAX_SIZE];
};

void read_matrix_from_stream(Matrix& matrix_1, Matrix& matrix_2) {
    ifstream in_file("matrix-data-file.txt");
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            in_file >> matrix_1.data[i][j];
        }
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            in_file >> matrix_2.data[i][j];
        }
    }
    
    in_file.close();
}

void print_matrix(const Matrix& matrix) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            cout << matrix_1.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            cout << matrix_2.data[i][j] << " ";
        }
        cout << endl;
    }
}

void get_diagonal_sum(const Matrix& matrix) {
    int sum = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        sum += matrix.data[i][i] + matrix.data[i][MAX_SIZE - i - 1];
    }
    cout << "diagonal sum = " << sum << endl;
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    if (row1 < 0 || row2 > MAX_SIZE - 1) {
        cout << "Invalid rows entered" << endl;
    }
    else if (row1 == row2) {
        cout << "Cannot swap row with itself" << endl;
    }
    else {
        int temp;
        for (int i = 0; i < MAX_SIZE; i++) {
            temp = matrix.data[row1][i];
            matrix.data[row1][i] = matrix.data[row2][i];
            matrix.data[row2][i] = temp;
        }
        print_matrix(matrix);
    }
}

Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix result;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            result.data[i][j] = matrix_1.data[i][j] + matrix_2.data[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix result;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < MAX_SIZE; k++) {
                result.data[i][j] += (matrix_1.data[i][k] * matrix_2.data[k][j]);
            }
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    Matrix matrix_1, matrix_2;
    read_matrix_from_stream(matrix_1, matrix_2);
    
    cout << "print_matrix:" << endl;
    print_matrix(matrix_1, matrix_2);
    
    Matrix add_result = matrix_1 + matrix_2;
    //add_matrices(matrix_1, matrix_2, add_result);
    cout << "add_matrices result:" << endl;
    print_matrix(add_result);
    
    Matrix multiply_result = matrix_1 * matrix_2;
    //multiply_matrices(matrix_1, matrix_2, multiply_result);
    cout << "multiply_matrices result:" << endl;
    print_matrix(multiply_result);
    
    cout << "get matrix diagonal sum" << endl;
    get_diagonal_sum(matrix_1);
    
    cout << "swap matrix rows" << endl;
    swap_matrix_row(matrix_1, 0, 1);
    
    return 0;
}
