#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    size_t rows, cols;

public:
    // Конструктор для инициализации матрицы
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data.resize(rows, vector<int>(cols, 0.0));
    }

    // Доступ к элементам матрицы
    int& operator()(size_t i, size_t j) {
        return data[i][j];
    }

    const int& operator()(size_t i, size_t j) const {
        return data[i][j];
    }

    // Заполнение матрицы одним значением
    void fill(int value) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }

    // Заполнение матрицы случайными числами
    void fill_random(int min_val, int max_val) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] = min_val + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (max_val - min_val)));
            }
        }
    }

    // Сложение двух матриц
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + other(i, j);
            }
        }
        return result;
    }

    // Вычитание двух матриц
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] - other(i, j);
            }
        }
        return result;
    }

    // Умножение матрицы на скаляр
    Matrix operator*(int scalar) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Умножение матриц
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cout << "Невозможно умножить матрицы: несоответствующие размеры." << endl;
            exit(1); // Завершение программы с ошибкой
        }
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                result(i, j) = 0;
                for (size_t k = 0; k < cols; ++k) {
                    result(i, j) += data[i][k] * other(k, j);
                }
            }
        }
        return result;
    }

    // Транспонирование матрицы
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(j, i) = data[i][j];
            }
        }
        return result;
    }

    // Создание диагональной матрицы
    static Matrix diagonal(const vector<double>& diagonalElements) {
        size_t n = diagonalElements.size();
        Matrix result(n, n);
        for (size_t i = 0; i < n; ++i) {
            result(i, i) = diagonalElements[i];
        }
        return result;
    }

    // Вычисление определителя матрицы
    double determinant() const {
        if (rows != cols) {
            cout << "Определитель можно вычислить только для квадратных матриц." << endl;
            return 0; // Или можно использовать exit(1);
        }

        if (rows == 1) {
            return data[0][0];
        }

        if (rows == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }

        double det = 0.0;
        for (size_t p = 0; p < cols; ++p) {
            Matrix subMatrix(rows - 1, cols - 1);
            for (size_t i = 1; i < rows; ++i) {
                size_t jIndex = 0;
                for (size_t j = 0; j < cols; ++j) {
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
    vector<int> getRow(size_t i) const {
        return data[i];
    }

    // Применение функции к каждому элементу матрицы
    void applyFunction(double (*func)(double)) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
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
    mat1.fill_random(1.0, 10.0);
    cout << "Матрица 1:" << endl;
    mat1.print();

    Matrix mat2(3, 3);
    mat2.fill_random(1.0, 10.0);
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