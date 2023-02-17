class Matrix {

    public:
        // need to make the state accessible to the vector class
        int mat[4];

        Matrix(int arr[4]) { for (int i=0; i<4; i++) {mat[i] = arr[i]; } }
        Matrix(): mat({0,0,0,0}) {};

        Matrix operator+(const Matrix& m);
        Matrix operator-(const Matrix& m);
        Matrix operator*(const Matrix& m);
        Matrix operator/(const Matrix& m);
};

    Matrix Matrix::operator+(const Matrix& m) {
        Matrix newmat = Matrix();
        for (int i=0; i<4; i++) {
            newmat.mat[i] = mat[i] + m.mat[i];
        }
        return newmat;
    }

    Matrix Matrix::operator+(const Matrix& m) {
        Matrix newmat = Matrix();
        for (int i=0; i<4; i++) {
            newmat.mat[i] = mat[i] - m.mat[i];
        }
        return newmat;
    }

    Matrix Matrix::operator*(const Matrix& m) {
        Matrix newmat = Matrix();
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                newmat.mat[2*i + j] = mat[i/2] * m.mat[j] + mat[i/2 + 1] * mat[j+2];
            }    
        }
    }

    Matrix Matrix::operator/(const Matrix& m) {
        Matrix newmat = Matrix();
        for (int i=0; i<4; i++) {
            newmat.mat[i] = mat[i] / m.mat[i];
        }
        return newmat;
    }


class Vector {
    int vec[2];

    public:
        Vector(int arr[2]) { for (int i=0; i<2; i++) { vec[i] = arr[i]; } }
        Vector(): vec({0,0}) {};

        Vector operator+(const Vector& v);
        Vector operator-(const Vector& v);
        Vector operator*(const Vector& v);
        Vector operator/(const Vector& v);

        Vector operator*(const Matrix& m);
};

    Vector Vector::operator+(const Vector& v) {
        Vector newvec = Vector();
        for (int i=0; i<2; i++) {
            newvec.vec[i] = vec[i] + v.vec[i];
        }
        return newvec;
    }

    Vector Vector::operator-(const Vector& v) {
        Vector newvec = Vector();
        for (int i=0; i<2; i++) {
            newvec.vec[i] = vec[i] - v.vec[i];
        }
        return newvec;
    }

    // just doing simple scalar multiplication and division, but across the whole vector!!
    Vector Vector::operator+(const Vector& v) {
        Vector newvec = Vector();
        for (int i=0; i<2; i++) {
            newvec.vec[i] = vec[i] * v.vec[i];
        }
        return newvec;
    }

    Vector Vector::operator+(const Vector& v) {
        Vector newvec = Vector();
        for (int i=0; i<2; i++) {
            newvec.vec[i] = vec[i] / v.vec[i];
        }
        return newvec;
    }


    Vector Vector::operator*(const Matrix& m) {
        Vector newvec = Vector();
        for (int i=0; i<2; i++) {
            newvec.vec[i] = vec[0] * m.mat[i*2] + vec[1] * m.mat[i*2 + 1];
        }
        return newvec;
    }


int main() {
    int i[] = {1,0,0,1};
    Matrix identity = Matrix(i);
    return 0;
}
