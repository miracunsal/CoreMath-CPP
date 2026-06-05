// main.cpp
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

// Temel Matris Sinifi (Core Matrix Class)
class Matrix {
private:
    int rows;
    int cols;
    vector<vector<double>> data;

public:
    // Kurucu Metot (Constructor)
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, vector<double>(cols, 0.0));
    }

    // Matrise deger atama
    void setValue(int r, int c, double val) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = val;
        } else {
            throw out_of_range("Indeks sinirlarin disinda!");
        }
    }

    // Matrisi Ekrana Yazdirma
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << setw(8) << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------------------" << endl;
    }

    // 1. Matris Toplama
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Hata: Toplama islemi icin matris boyutlari ayni olmalidir!");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 2. Matris Carpimi (Dot Product)
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Hata: Ilk matrisin sutun sayisi, ikinci matrisin satir sayisina esit olmalidir!");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                double sum = 0.0;
                for (int k = 0; k < cols; ++k) {
                    sum += this->data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    // 3. Matris Transpozu (Devrigi)
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = this->data[i][j];
            }
        }
        return result;
    }
};

// Test / Demo Modulu
int main() {
    try {
        cout << "[CoreMath-CPP] Linear Algebra Engine Initialized...\n\n";

        Matrix A(2, 3);
        A.setValue(0, 0, 1); A.setValue(0, 1, 2); A.setValue(0, 2, 3);
        A.setValue(1, 0, 4); A.setValue(1, 1, 5); A.setValue(1, 2, 6);
        cout << "Matris A (2x3):" << endl;
        A.print();

        Matrix B(3, 2);
        B.setValue(0, 0, 7);  B.setValue(0, 1, 8);
        B.setValue(1, 0, 9);  B.setValue(1, 1, 10);
        B.setValue(2, 0, 11); B.setValue(2, 1, 12);
        cout << "Matris B (3x2):" << endl;
        B.print();

        cout << "A * B Sonucu (Matris Carpimi):" << endl;
        Matrix C = A.multiply(B);
        C.print();

        cout << "Matris A'nin Transpozu:" << endl;
        Matrix T = A.transpose();
        T.print();

    } catch (const exception& e) {
        cerr << "Sistem Hatasi: " << e.what() << endl;
    }

    return 0;
}