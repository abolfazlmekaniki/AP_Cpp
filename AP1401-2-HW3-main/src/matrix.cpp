#include "../include/matrix.h"
#include <math.h>
#include <cmath>

Matrix::Matrix():row{0},col{0}{

    row_cap= pow(2,static_cast<int>(sqrt(row))+1);
    col_cap= pow(2,static_cast<int>(sqrt(col))+1);
    matrix = new int* [row_cap];
    for(size_t i{};i<row_cap;i++){
        int* column = new int[col_cap];
        for(size_t j{};j<col_cap;j++){

                column[j]=0;
        };
        matrix[i]=column;
    };

};

Matrix::Matrix(int size):row{size},col{size}{
     if(std::fmod(log2(row),1.0)==0){
        row_cap= pow(2,static_cast<int>(log2(row)));
    }
    else{ 
        row_cap= pow(2,static_cast<int>(log2(row))+1);
    }
    if(std::fmod(log2(col),1.0)==0){
        col_cap= pow(2,static_cast<int>(log2(col)));
    }
    else{ 
        col_cap= pow(2,static_cast<int>(log2(col))+1);
    }
    matrix = new int* [row_cap];
    for(size_t i{};i<row_cap;i++){
        int* column = new int[col_cap];
        for(size_t j{};j<col_cap;j++){

                column[j]=0;
        };
        matrix[i]=column;
    };
};


Matrix::Matrix(int row_, int column_):row{row_},col{column_}{
   
    if(std::fmod(log2(row),1.0)==0){
        row_cap= pow(2,static_cast<int>(log2(row)));
    }
    else{ 
        row_cap= pow(2,static_cast<int>(log2(row))+1);
    }
    if(std::fmod(log2(col),1.0)==0){
        col_cap= pow(2,static_cast<int>(log2(col)));
    }
    else{ 
        col_cap= pow(2,static_cast<int>(log2(col))+1);
    }

    std::cout<<"constructor for matrix :"<<row<<" x " <<col<<" "<<std::endl;

    matrix = new int* [row_cap];
    for(size_t i{};i<row_cap;i++){
        int* column = new int[col_cap];
        for(size_t j{};j<col_cap;j++){

                column[j]=0;
        };
        matrix[i]=column;
    };
};

Matrix::~Matrix(){
    std::cout<<"de constructor "<<std::endl;
    delete matrix;
};

Matrix::Matrix(const Matrix& m):row{m.row},col{m.col}{
    if(std::fmod(log2(row),1.0)==0){
        row_cap= pow(2,static_cast<int>(log2(row)));
    }
    else{ 
        row_cap= pow(2,static_cast<int>(log2(row))+1);
    }
    if(std::fmod(log2(col),1.0)==0){
        col_cap= pow(2,static_cast<int>(log2(col)));
    }
    else{ 
        col_cap= pow(2,static_cast<int>(log2(col))+1);
    }
    matrix = new int*[row_cap];
    for(size_t i{};i<row_cap;i++){
        int* column = new int[col_cap];
        for(size_t j{};j<col_cap;j++){

                column[j]=m.matrix[i][j];
        };
        matrix[i]=column;
    };
    std::cout<<"copy constructor for matrix :"<<row<<" x " <<col<<" "<<std::endl;
};

void Matrix::display() const{
    std::cout<<"matrix  is (we show matrix with capacity value ) : "<<std::endl;
    for(size_t i{};i<row_cap;i++){
        for(size_t j{};j<col_cap;j++){

                std::cout<< matrix[i][j]<<" ";
        };
        std::cout<<std::endl;
    };

};

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> a){ 
    int r = 0;
    row=a.size();
    if(std::fmod(log2(row),1.0)==0){
        row_cap= pow(2,static_cast<int>(log2(row)));
    }
    else{ 
        row_cap= pow(2,static_cast<int>(log2(row))+1);
    }
    
    matrix = new int*[row_cap];
    
    for(auto i : a){
                int c=0;
                col=i.size();
                if(std::fmod(log2(col),1.0)==0){
                    col_cap= pow(2,static_cast<int>(log2(col)));
                }
                else{ 
                    col_cap= pow(2,static_cast<int>(log2(col))+1);
                }
                int* column = new int[col_cap];
                
                for(auto j : i){
                    column[c]=j;
                    c++;
                }
                matrix[r]=column;
                r++;
    }
    int** matrix2 {new int*[row_cap]};
    for(size_t i{0};i<row_cap;i++){
        if(i>=row){
            int* column = new int[col_cap];
            for(size_t j{0};j<col_cap;j++){
                column[j]=0;
            }
            matrix2[i]=column;
        }
        else{
            int* column = new int[col_cap];
            for(size_t j{0};j<col;j++){
                column[j]=matrix[i][j];
            }
            for(size_t j{col};j<col_cap;j++){
                column[j]=0;
            }
            matrix2[i]=column;
        }
 
    }
    delete matrix;
    matrix = new int*[row_cap];
    matrix = matrix2;

}

const Matrix& Matrix::append(const Matrix& m, int axis){
    if(row==m.row && axis==0){
        int** matrix2 {new int*[row]};
        for(size_t i{};i<row;i++){
            int* column = new int[col+m.col];
            for(size_t j{};j<col;j++){
                column[j]=matrix[i][j];
            }
            for(size_t j{col};j<col+m.col;j++){
                column[j]=m.matrix[i][j-col];
            }
            matrix2[i]=column;
        }
        row = row ;
        col = col+m.col;
        if(std::fmod(log2(row),1.0)==0){
            row_cap= pow(2,static_cast<int>(log2(row)));
        }
        else{ 
            row_cap= pow(2,static_cast<int>(log2(row))+1);
        }
        if(std::fmod(log2(col),1.0)==0){
            col_cap= pow(2,static_cast<int>(log2(col)));
        }
        else{ 
            col_cap= pow(2,static_cast<int>(log2(col))+1);
        }
        int** matrix3 {new int*[row_cap]};
        for(size_t i{0};i<row_cap;i++){
            if(i>=row){
                int* column = new int[col_cap];
                for(size_t j{0};j<col_cap;j++){
                    column[j]=0;
                }
                matrix3[i]=column;
            }
            else{
                int* column = new int[col_cap];
                for(size_t j{0};j<col;j++){
                    column[j]=matrix2[i][j];
                }
                for(size_t j{col};j<col_cap;j++){
                    column[j]=0;
                }
                matrix3[i]=column;
            }
    
        }
        delete matrix;
        matrix = new int*[row_cap];
        matrix = matrix3;
        return *this;
    }




    else if(col==m.col && axis==1){
        int** matrix2 {new int*[row+m.row]};
        for(size_t i{};i<row;i++){
            int* column = new int[col];
            for(size_t j{};j<col;j++){
                column[j]=matrix[i][j];
            }
            matrix2[i]=column;
        }
        for(size_t i{row};i<row+m.row;i++){
            int* column = new int[col];
            for(size_t j{};j<m.col;j++){
                column[j]=m.matrix[i-row][j];
            }
            matrix2[i]=column;
        }
        row = row+m.row ;
        col = col;
        if(std::fmod(log2(row),1.0)==0){
            row_cap= pow(2,static_cast<int>(log2(row)));
        }
        else{ 
            row_cap= pow(2,static_cast<int>(log2(row))+1);
        }
        if(std::fmod(log2(col),1.0)==0){
            col_cap= pow(2,static_cast<int>(log2(col)));
        }
        else{ 
            col_cap= pow(2,static_cast<int>(log2(col))+1);
        }
        int** matrix3 {new int*[row_cap]};
        for(size_t i{0};i<row_cap;i++){
            if(i>=row){
                int* column = new int[col_cap];
                for(size_t j{0};j<col_cap;j++){
                    column[j]=0;
                }
                matrix3[i]=column;
            }
            else{
                int* column = new int[col_cap];
                for(size_t j{0};j<col;j++){
                    column[j]=matrix2[i][j];
                }
                for(size_t j{col};j<col_cap;j++){
                    column[j]=0;
                }
                matrix3[i]=column;
            }
    
        }
        delete matrix;
        matrix = new int*[row_cap];
        matrix = matrix3;
        return *this;
    }
};

int Matrix::getRowSize(){
    return row;
};
int Matrix::getColSize(){
    return col;
};
int Matrix::getRowCapacity(){
    return row_cap;
};
int Matrix::getColCapacity(){
    return col_cap;
};
int** Matrix::getMatrix(){
    return matrix;

};

const Matrix& Matrix::operator*(const Matrix& m){
    for(size_t i{};i<row;i++){
        int* column = new int[m.col];
        for(size_t j{};j<m.col;j++){
            double sum=0;
            for(size_t t{};t<m.row;t++){
                sum += (matrix[i][t] * m.matrix[t][j]);
            }
            column[j]=sum;

        }
        matrix[i]=column;
    };
    row=row;
    col=m.col;
    if(std::fmod(log2(row),1.0)==0){
            row_cap= pow(2,static_cast<int>(log2(row)));
        }
    else{ 
            row_cap= pow(2,static_cast<int>(log2(row))+1);
        }
    if(std::fmod(log2(col),1.0)==0){
            col_cap= pow(2,static_cast<int>(log2(col)));
        }
    else{ 
            col_cap= pow(2,static_cast<int>(log2(col))+1);
        }
    
    int** matrix3 {new int*[row_cap]};
    for(size_t i{0};i<row_cap;i++){
        if(i>=row){
            int* column = new int[col_cap];
            for(size_t j{0};j<col_cap;j++){
                column[j]=0;
            }
            matrix3[i]=column;
        }
        else{
            int* column = new int[col_cap];
            for(size_t j{0};j<col;j++){
                column[j]=matrix[i][j];
            }
            for(size_t j{col};j<col_cap;j++){
                column[j]=0;
            }
            matrix3[i]=column;
        }
 
    }
    delete matrix;
    matrix = new int*[row_cap];
    matrix = matrix3;
    return *this;

};

const Matrix& Matrix::operator+(const Matrix& m){

    if(row==m.row && col==m.col){

        for(size_t i{};i<row;i++){
            for(size_t j{};j<col;j++){
                matrix[i][j]+=m.matrix[i][j];
            }
        }

    }

    return *this;
}

const Matrix& Matrix::operator-(const Matrix& m){

    if(row==m.row && col==m.col){

        for(size_t i{};i<row;i++){
            for(size_t j{};j<col;j++){
                matrix[i][j]-=m.matrix[i][j];
            }
        }

    }

    return *this;
}

Matrix& Matrix::operator+=(const Matrix& m){

    int** matrix2 {new int*[row]};
    for(size_t i{};i<row;i++){
        int* column = new int[col];
        for(size_t j{};j<col;j++){
            column[j]=matrix[i][j]+m.matrix[i][j];
        }
        matrix2[i]=column;
    }
    delete matrix;
    matrix = matrix2;
    return *this;
}


const Matrix& Matrix::operator++(){
    for(size_t i{};i<row;i++){
        for(size_t j{};j<col;j++){
            matrix[i][j]+=1;
        }
    }
    return *this;
}


const Matrix Matrix::operator++(int){
    Matrix copy {*this};
    int** matrix2 {new int*[row]};
    for(size_t i{};i<row;i++){
        int* column = new int[col];
        for(size_t j{};j<col;j++){
            column[j]=matrix[i][j]+1;
        }
        matrix2[i]=column;
    }
    delete matrix;
    matrix = matrix2;
    return copy;
}

const Matrix& Matrix::operator--(){
    for(size_t i{};i<row;i++){
        for(size_t j{};j<col;j++){
            matrix[i][j]-=1;
        }
    }
    return *this;
}


const Matrix Matrix::operator--(int){
    Matrix copy {*this};
    int** matrix2 {new int*[row]};
    for(size_t i{};i<row;i++){
        int* column = new int[col];
        for(size_t j{};j<col;j++){
            column[j]=matrix[i][j]-1;
        }
        matrix2[i]=column;
    }
    delete matrix;
    matrix = matrix2;
    return copy;
}

int* Matrix::operator[](size_t i){
            return matrix[i];
};

bool Matrix::operator==(const Matrix& m) const{
    if(row==m.row && col==m.col){
            for(size_t i{};i<row;i++){
                for(size_t j{};j<col;j++){
                    if(matrix[i][j]!=m.matrix[i][j]){
                        return false;
                    }
            }
        }

        return true;
    }
    else{
        return false;
    }
    
};

const Matrix& Matrix::operator|(const Matrix& m){
    double determian = 0;
    double** matrix2 {new double*[row]};
    if (row==1 && col==1) {
     determian= matrix[0][0];
   }
   else if (row==2 && col==2) {
      determian=(matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
   }

   else if(row==3 && col==3){
    determian=matrix[0][0]*(matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1])+matrix[0][1]*(matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0])+matrix[0][3]*(matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]);
   }
    if(determian>0){
        for(int i = 0; i < 3; i++){
            double* column = new double[3];
            for(int j = 0; j < 3; j++){
                column[j]=((matrix[(j+1)%3][(i+1)%3] * matrix[(j+2)%3][(i+2)%3]) - (matrix[(j+1)%3][(i+2)%3] * matrix[(j+2)%3][(i+1)%3]))/determian;
            }
            matrix2[i]=column;
        }
            
    };
    for(size_t i{};i<row;i++){
        int* column = new int[m.col];
        for(size_t j{};j<m.col;j++){

            double sum=0;
            for(size_t t{};t<m.row;t++){
                sum += (matrix2[i][t] * m.matrix[t][j]);
            }
            column[j]=sum;

        }
        matrix[i]=column;
    };
    return *this;

};

const Matrix& Matrix::operator=(const Matrix& m){

    delete matrix;
    matrix =new int*[m.row];
    for(size_t t{};t<m.row;t++){
        for(size_t j{};j<m.col;j++){
            matrix[t][j]=m.matrix[t][j];
        };
        
    };
    row = m.row;
    col=m.col;
    row_cap = m.row_cap;
    col_cap = m.col_cap;

    return *this;


};

std::ostream& operator<<(std::ostream & out ,const Matrix& m){
        out << "matrix is :"<<std::endl;
        for(size_t t{};t<m.row;t++){
            for(size_t j{};j<m.col;j++){
                out << m.matrix[t][j]<<" ";
            };
            out<<std::endl;
        };
        return out;
};


std::partial_ordering Matrix::operator<=>(const Matrix& m){

    if(row!=m.row){
        return row<=>m.row;
    }
    else if(col!=m.col){
        return col<=>m.col;
    }
    else{
        double m_sum{0};
        double z_sum{0};
        for(size_t i{};i<row;i++){
            for(size_t j{};j<col;j++){
                m_sum+= matrix[i][j];
                z_sum+= m.matrix[i][j];
                
            }
        }
        return m_sum<=>z_sum;
    }
    
};