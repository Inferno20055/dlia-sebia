#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    int rows, cols;

public:
    // Конструктор для инициализации матрицы
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, vector<int>(cols, 0.0));
    }

    // Доступ к элементам матрицы
    int& operator()(int i, int j) {
        return data[i][j];
    }

    const int& operator()(int i, int j) const {
        return data[i][j];
    }

    // Заполнение матрицы одним значением
    void fill(int value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }

    // Заполнение матрицы случайными числами
    void fill_random(int min_val, int max_val) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = min_val + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (max_val - min_val)));
            }
        }
    }

    // Сложение двух матриц
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + other(i, j);
            }
        }
        return result;
    }

    // Вычитание двух матриц
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] - other(i, j);
            }
        }
        return result;
    }

    // Умножение матрицы на скаляр
    Matrix operator*(int scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Умножение матриц
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cout << "Невозможно умножить матрицы: несоответствующие размеры." << endl;
            exit(1); 
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result(i, j) = 0;
                for (int k = 0; k < cols; ++k) {
                    result(i, j) += data[i][k] * other(k, j);
                }
            }
        }
        return result;
    }

    // Транспонирование матрицы
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(j, i) = data[i][j];
            }
        }
        return result;
    }

    // Создание диагональной матрицы
    static Matrix diagonal(const vector<double>& diagonalElements) {
        int n = diagonalElements.size();
        Matrix result(n, n);
        for (int i = 0; i < n; ++i) {
            result(i, i) = diagonalElements[i];
        }
        return result;
    }

    // Вычисление определителя матрицы
    double determinant() const {
        if (rows != cols) {
            cout << "Определитель можно вычислить только для квадратных матриц." << endl;
            exit(1);
        }

        if (rows == 1) {
            return data[0][0];
        }

        if (rows == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }

        double det = 0.0;
        for (int p = 0; p < cols; ++p) {
            Matrix subMatrix(rows - 1, cols - 1);
            for (int i = 1; i < rows; ++i) {
                int jIndex = 0;
                for (int j = 0; j < cols; ++j) {
                    if (j == p) continue;
                    subMatrix(i - 1, jIndex) = data[i][j];
                    jIndex++;
                }
            }
            det += (p % 2 == 0 ? 1 : -1) * data[0][p] * subMatrix.determinant();
        }
        return det;
    }

    // Доступ к строкам матрицы
    vector<int> getRow(int i) const {
        return data[i];
    }

    // Применение функции к каждому элементу матрицы
    void applyFunction(double (*func)(double)) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = func(data[i][j]);
            }
        }
    }

    // Вывод матрицы на экран
    void print() const {
        for (const auto& row : data) {
            for (const auto& element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

// Пример функции для применения
double square(double x) {
    return x * x;
}

int main() {
    setlocale(LC_ALL,"RU");
    srand(static_cast<unsigned int>(time(0)));

    Matrix mat1(3, 3);
    mat1.fill_random(1, 10);
    cout << "Матрица 1:" << endl;
    mat1.print();

    Matrix mat2(3, 3);
    mat2.fill( 10);
    cout << "Матрица 2:" << endl;
    mat2.print();

    Matrix sum = mat1 + mat2;
    cout << "Сумма матриц:" << endl;
    sum.print();

    Matrix difference = mat1 - mat2;
    cout << "Разность матриц:" << endl;
    difference.print();

    Matrix product = mat1 * 2.0;
    cout << "Матрица 1, умноженная на 2:" << endl;
    product.print();

    Matrix multiplied = mat1 * mat2;
    cout << "Матрица 1, умноженная на Матрицу 2:" << endl;
    multiplied.print();

    Matrix transposed = mat1.transpose();
    cout << "Транспонированная матрица 1:" << endl;
    transposed.print();

    Matrix diagonalMatrix = Matrix::diagonal({ 1, 2, 3 });
    cout << "Диагональная матрица:" << endl;
    diagonalMatrix.print();

    cout << "Определитель матрицы 1: " << mat1.determinant() << endl;

    mat1.applyFunction(square);
    cout << "Матрица 1 после применения функции (возведение в квадрат):" << endl;
    mat1.print();

    return 0;
}