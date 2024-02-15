#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    bool notAMatrix;

public:
    // Constructor
    Matrix(const std::string& matrixString) : notAMatrix(false) {
        std::istringstream iss(matrixString);
        char discard;
        int value;
        std::vector<int> row;

        while (iss >> discard) {
            row.clear();
            while (iss >> value >> discard) {
                row.push_back(value);
            }
            data.push_back(row);
        }

        // Check if all rows have the same number of elements
        int numCols = data[0].size();
        for (const auto& row : data) {
            if (row.size() != numCols) {
                notAMatrix = true;
                break;
            }
        }
    }

    // Destructor
    ~Matrix() {
        // No explicit memory deallocation required for std::vector
    }

    // Check if matrix is Not a Matrix
    bool IsNaM() const {
        return notAMatrix;
    }

    // Indexing operator
    std::vector<int>& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Matrix addition
    Matrix operator+(const Matrix& other) const {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            throw std::invalid_argument("Matrix dimensions are not compatible for addition");
        }

        Matrix result = *this;
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                result.data[i][j] += other.data[i][j];
            }
        }
        return result;
    }

    // Matrix subtraction
    Matrix operator-(const Matrix& other) const {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            throw std::invalid_argument("Matrix dimensions are not compatible for subtraction");
        }

        Matrix result = *this;
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                result.data[i][j] -= other.data[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (data[0].size() != other.data.size()) {
            throw std::invalid_argument("Matrix dimensions are not compatible for multiplication");
        }

        Matrix result("(");
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                int sum = 0;
                for (size_t k = 0; k < data[0].size(); ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result[i].push_back(sum);
            }
            if (i != data.size() - 1) {
                result.data.emplace_back();
            }
        }
        return result;
    }

    // Print matrix
    void Print() const {
        for (const auto& row : data) {
            for (const auto& value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::string matrixString1 = "(1,2,3),(4,5,6),(7,8,9)";
    std::string matrixString2 = "(9,8,7),(6,5,4),(3,2,1)";

    Matrix matrix1(matrixString1);
    Matrix matrix2(matrixString2);

    std::cout << "Matrix 1:" << std::endl;
    matrix1.Print();
    std::cout << std::endl;

    std::cout << "Matrix 2:" << std::endl;
    matrix2.Print();
    std::cout << std::endl;

    try {
        Matrix sum = matrix1 + matrix2;
        std::cout << "Sum:" << std::endl;
        sum.Print();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
