package JSipl;

import java.util.Random;

public class Matrix {
	public Matrix(int Rows, int Cols) {
		Matrix_Body = new  double[Rows][Cols]; 
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] =0;
			}
		}
		this.Rows = Rows;
		this.Cols = Cols;
	}
public Matrix(int R,int C, String Type) {
	if(Type.equals("Identity")) {
		Matrix_Body = new double[R][C]; 
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				Matrix_Body[i][j] = 0;
				if (i == j) {
					Matrix_Body[i][j] = 1;
				}
			}
		}
		this.Rows = R;
		this.Cols = C;
	}
	else if(Type.equals("Ones")) {
			Matrix_Body = new double[R][C]; 
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
						Matrix_Body[i][j] = 1;
				}
			}
			this.Rows = R;
			this.Cols = C;
		}
	
	
	}
public Matrix(double matrix[][],int rows,int cols) {
	this.Matrix_Body=matrix;
	this.Rows=rows;
	this.Cols=cols;
}
public Matrix(Matrix Copy) {
	this.Cols=Copy.Cols;
	this.Rows=Copy.Rows;
	Matrix_Body = new double[Rows][Cols]; 
	for(int i =0;i<Rows;i++) {
		for(int j=0;j<Cols;j++) {
			this.Matrix_Body[i][j] = Copy.Matrix_Body[i][j];
		}
	}

}
public void Fill_With_Random_Values() {
	Random r = new Random();
	for(int i = 0;i<Rows;i++) {
		for(int j=0;j<Cols;j++) {
			this.Matrix_Body[i][j] = r.nextDouble();
		}
	}
}
public void Fill_With_Random_Values(double Upper_Bound) {
	Random r = new Random();
	for(int i = 0;i<Rows;i++) {
		for(int j=0;j<Cols;j++) {
			this.Matrix_Body[i][j] = Math.abs(r.nextDouble() % Upper_Bound);
		}
	}
}
public void Fill_With_Random_Values(int Upper_Bound) {
	Random r = new Random();
	for(int i = 0;i<Rows;i++) {
		for(int j=0;j<Cols;j++) {
			this.Matrix_Body[i][j] = Math.abs(r.nextInt() % Upper_Bound);
		}
	}
}
public void Matrix_Set(Matrix B) {
	this.Rows = B.Rows;
	this.Cols = B.Cols;
	this.Matrix_Body = B.Matrix_Body;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			Matrix_Body[i][j] = B.Matrix_Body[i][j];
		}
	}

}
public void Add(Matrix B) {
	if (Rows != B.Rows || Cols != B.Cols) {
		return;
	}
	else {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] += B.Matrix_Body[i][j];
			}
		}
	}
}
public void Subtract(Matrix B) {
	if (Rows != B.Rows || Cols != B.Cols) {
		return;
	}
	else {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] -= B.Matrix_Body[i][j];
			}
		}
	}
}
public void Divide(double divide_by) {
	for(int i=0;i<this.Rows;i++) {
		for(int j=0;j<this.Cols;j++)
			this.Matrix_Body[i][j]/=divide_by;
	}
}
public Matrix Dot_Product(Matrix B) {
	if (Cols != B.Rows) {
		return null;

	}
	else {
		Matrix Res = new Matrix(this);
		double sum = 0;
		Matrix temp = new Matrix(Rows, B.Cols);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < B.Cols; j++) {
				for (int k = 0; k < Cols; k++) {
					sum += Res.Matrix_Body[i][k] * B.Matrix_Body[k][j];

				}
				temp.Matrix_Body[i][j] = sum;
				sum = 0;
			}
		}
		Res.Matrix_Body= temp.Matrix_Body;
		Res.Rows = temp.Rows;
		Res.Cols = temp.Cols;
		return Res;

	}
}

public Matrix Get_Upper_Matrix() {
	if(this.Rows!=this.Cols) {
		System.out.println("Matrix Needs To Be NxN");
		return null;
	}
	Matrix Upper = new Matrix(this);
	
	for(int i=0;i<this.Rows;i++) {
		for(int j=0;j<i;j++) {
			Upper.Matrix_Body[i][j]=0;
		}
	}
	return Upper;
	
}
public Matrix Get_Lower_Matrix() {
	if(this.Rows!=this.Cols) {
		System.out.println("Matrix Needs To Be NxN");
		return null;
	}
	Matrix Lower = new Matrix(this);
	
	for(int i=0;i<this.Rows;i++) {
		for(int j=i+1;j<Cols;j++) {
			Lower.Matrix_Body[i][j]=0;
		}
	}
	return Lower;
	
}
public double[] Get_Diagonal() {
	if(this.Rows!=this.Cols) {
		System.out.println("Matrix Needs To Be NxN");
		return null;
	}
	double dig[] = new double[this.Cols];
	for(int i =0;i<this.Rows;i++) {
		dig[i]=this.Matrix_Body[i][i];
	}
	return dig;
}
public Matrix[] LU_Decomposition() {
	if(this.Cols!=this.Rows) {
		System.out.println("Matrix Needs To Be NxN");
		return null;
	}
	 Matrix LU = new Matrix(this);
      double pivot[] = new double[this.Cols];
      for (int i = 0; i < this.Cols; i++) {
         pivot[i] = i;
      }
      int pivsign = 1;
      double[] LUrowi;
      double[] LUcolj = new double[this.Cols];

      // Outer loop.

      for (int j = 0; j < this.Cols; j++) {
         for (int i = 0; i < this.Cols; i++) {
            LUcolj[i] = LU.Matrix_Body[i][j];
         }

         for (int i = 0; i < this.Cols; i++) {
            LUrowi = LU.Matrix_Body[i];
            int kmax = Math.min(i,j);
            double s = 0.0;
            for (int k = 0; k < kmax; k++) {
               s += LUrowi[k]*LUcolj[k];
            }

            LUrowi[j] = LUcolj[i] -= s;
         }
         
         int p = j;
         for (int i = j+1; i < this.Cols; i++) {
            if (Math.abs(LUcolj[i]) > Math.abs(LUcolj[p])) {
               p = i;
            }
         }
         if (p != j) {
            for (int k = 0; k < this.Cols; k++) {
               double t = LU.Matrix_Body[p][k];
               LU.Matrix_Body[p][k] = LU.Matrix_Body[j][k];
               LU.Matrix_Body[j][k]= t;
            }
            double k = pivot[p];
            pivot[p] = pivot[j];
            pivot[j] = k;
            pivsign = -pivsign;
         }
         if (j < this.Cols & LU.Matrix_Body[j][j] != 0.0) {
            for (int i = j+1; i < this.Cols; i++) {
               LU.Matrix_Body[i][j] /= LU.Matrix_Body[j][j];
            }
         }
      }
     
     
	Matrix[] LUP = new Matrix[3];
	Matrix Lower = LU.Get_Lower_Matrix();
	for(int i=0;i<this.Cols;i++) {
		Lower.Matrix_Body[i][i]=1;
	}
	Matrix pivot_mat = new Matrix(1,pivot.length);
	for(int i=0;i<pivot.length;i++) {
		pivot_mat.Matrix_Body[0][i] = pivot[i];
	}
	LUP[0] = Lower;
	LUP[1] = LU.Get_Upper_Matrix();
	LUP[2] = pivot_mat;
	
	return LUP;

	
}
public Matrix[] QR_Decomposition() {
	Matrix QR = new Matrix(this);
   double[] R_diagonal = new double[this.Rows];
   
   for (int k = 0; k < this.Rows; k++) {
         double nrm = 0;
         for (int i = k; i < this.Cols; i++) {
            nrm = Math.sqrt( Math.pow(nrm, 2) + Math.pow(QR.Matrix_Body[i][k], 2) );
         }

         if (nrm != 0.0) {
            if (QR.Matrix_Body[k][k] < 0) {
               nrm = -nrm;
            }
            for (int i = k; i < this.Cols; i++) {
               QR.Matrix_Body[i][k] /= nrm;
            }
            QR.Matrix_Body[k][k] += 1.0;

            for (int j = k+1; j < this.Cols; j++) {
               double s = 0.0; 
               for (int i = k; i < this.Cols; i++) {
                  s += QR.Matrix_Body[i][k]*QR.Matrix_Body[i][j];
               }
               s = -s/QR.Matrix_Body[k][k];
               for (int i = k; i < this.Cols; i++) {
                  QR.Matrix_Body[i][j] += s*QR.Matrix_Body[i][k];
               }
            }
         }
         R_diagonal[k] = -nrm;
      }
   
   int m = this.Rows;
   int n = this.Cols;
   Matrix XQ = new Matrix(m,n);
      double[][] Q = new double[m][n];
      for (int k = n-1; k >= 0; k--) {
         for (int i = 0; i < m; i++) {
            Q[i][k] = 0.0;
         }
         Q[k][k] = 1.0;
         for (int j = k; j < n; j++) {
            if (QR.Matrix_Body[k][k] != 0) {
               double s = 0.0;
               for (int i = k; i < m; i++) {
                  s += QR.Matrix_Body[i][k]*Q[i][j];
               }
               s = -s/QR.Matrix_Body[k][k];
               for (int i = k; i < m; i++) {
                  Q[i][j] += s*QR.Matrix_Body[i][k];
               }
            }
         }
      }
      XQ.Matrix_Body = Q;
      Matrix XR = new Matrix(n,n);
      double[][] R = new double[n][n];
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (i < j) {
               R[i][j] = QR.Matrix_Body[i][j];
            } else if (i == j) {
               R[i][j] = R_diagonal[i];
            } else {
               R[i][j] = 0.0;
            }
         }
      }
      XR.Matrix_Body = R;
      
      Matrix Xh = new Matrix(m,n);
      double[][] H =new double[m][n];
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            if (i >= j) {
               H[i][j] = QR.Matrix_Body[i][j];
            } else {
               H[i][j] = 0.0;
            }
         }
      }
      Xh.Matrix_Body=H;
      Matrix[] Result = new Matrix[3];
      
      Result[0] = XQ;
      Result[1] = XR;
      Result[2] = Xh;
      return Result;
   
}
public double Get_Determinant() {
	if(this.Cols!=this.Rows) {
		System.out.println("Matrix Needs To Be NxN");
		return 0;
	}
	Matrix LU[] = this.LU_Decomposition();

    double det = LU[1].Matrix_Body[0][0];

    for (int i = 1; i < this.Cols; i++)
        det *= LU[1].Matrix_Body[i][i];

    if ((LU[2].Matrix_Body[0][this.Cols-1] - this.Cols-1) % 2 == 0)
        return det; 
    else
        return -det;

}
public double[] Get_Eigen_Values() {
	Matrix CopyOfOriginal = new Matrix(this);
	Matrix A = new Matrix(this);
	Matrix[] QR = this.QR_Decomposition();
	for(int i =0; i<20;i++) {
		A = QR[1].Dot_Product(QR[0]);
		this.Matrix_Body=A.Matrix_Body;
		QR = this.QR_Decomposition();
	}
	
	double[] EigenValues = this.Get_Diagonal();
	this.Matrix_Body=CopyOfOriginal.Matrix_Body;
	return EigenValues;
	
}
public Matrix Get_Eigen_Vectors() {
	Matrix CopyOfOriginal = new Matrix(this);
	Matrix A = new Matrix(this);
	Matrix[] QR = this.QR_Decomposition();
	Matrix Q = new Matrix(QR[0]);
	
	for(int i =0; i<30;i++) {
		A = QR[1].Dot_Product(QR[0]);
		this.Matrix_Body=A.Matrix_Body;
		QR = this.QR_Decomposition();
		Q = Q.Dot_Product(QR[0]);


	}

	this.Matrix_Body=CopyOfOriginal.Matrix_Body;
	return Q;
	
}
public double[] Gaussian_Elimination(double[] equals_to) {
	int n = this.Matrix_Body[0].length;		
    for (int p = 0; p < n; p++) {
        int max = p;
        for (int i = p + 1; i < n; i++) {
            if (Math.abs(this.Matrix_Body[i][p]) > Math.abs(this.Matrix_Body[max][p])) {
                max = i;
            }
        }
        double[] temp = this.Matrix_Body[p];
        this.Matrix_Body[p] = this.Matrix_Body[max];
        this.Matrix_Body[max] = temp;
        double t = equals_to[p];
        equals_to[p] = equals_to[max];
        equals_to[max] = t;
        if (Math.abs(this.Matrix_Body[p][p]) <= Double.MIN_VALUE) {
            throw new ArithmeticException("Matrix is singular or nearly singular");
        }
        for (int i = p + 1; i < n; i++) {
            double alpha = this.Matrix_Body[i][p] / this.Matrix_Body[p][p];
            equals_to[i] -= alpha * equals_to[p];
            for (int j = p; j < n; j++) {
            	this.Matrix_Body[i][j] -= alpha * this.Matrix_Body[p][j];
            }
        }
    }
    double[] x = new double[n];
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += this.Matrix_Body[i][j] * x[j];
        }
        x[i] = (equals_to[i] - sum) / this.Matrix_Body[i][i];
    }
    
    return x;
}
public void Matrix_Transpose() {


	Matrix temp = new Matrix(Cols, Rows);



	for (int i = 0; i < Cols; i++) {
		for (int j = 0; j < Rows; j++) {
			temp.Matrix_Body[i][j] = Matrix_Body[j][i];
		}
	}
	this.Matrix_Body = temp.Matrix_Body;
	this.Rows = temp.Rows;
	this.Cols = temp.Cols;
}
public void Multiply_By_Scalar(int scalar) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			Matrix_Body[i][j] *= scalar;
		}
	}
}
public void Multiply_By_Scalar(double scalar) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			Matrix_Body[i][j] *= scalar;
		}
	}
}

public Matrix Hadamard_Product(Matrix Mul_By) {
	if (Cols != Mul_By.Rows || Rows != Mul_By.Rows) {
		return new Matrix(1,1);

	}
	else {
		Matrix Result = new Matrix(Rows, Cols);
		double sum = 0;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Mul_By.Cols; j++) {
				Result.Matrix_Body[i][j] = Matrix_Body[i][j] * Mul_By.Matrix_Body[i][j];
			}
		}
		return Result;

	}
}
public Matrix Kronecker_Product(Matrix Mul_By) {
	Matrix Kronecker = new Matrix(Rows*Mul_By.Rows, Cols*Mul_By.Cols);
	int startRow, startCol;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			startRow = i * Mul_By.Rows;
			startCol = j * Mul_By.Cols;
			for (int k = 0; k < Mul_By.Rows; k++) {
				for (int l = 0; l < Mul_By.Cols; l++) {
					Kronecker.Matrix_Body[startRow + k][startCol + l] = Matrix_Body[i][j] * Mul_By.Matrix_Body[k][l];
				}
			}
		}
	}
	return Kronecker;
}
public void Horizontal_Matrix_Concatenation(Matrix To_HConcat) {
	if (this.Rows != To_HConcat.Rows)
		return;

	int  i, j, k, l = 0;
	Matrix ConcatH = new Matrix(Rows, Cols + To_HConcat.Cols);

	for (i = 0; i < Rows; i++) {
		for (j = 0; j < Cols; j++) {
			ConcatH.Matrix_Body[i][l] = Matrix_Body[i][j];
			l++;
		}
		for (k = 0; k < To_HConcat.Cols; k++) {
			ConcatH.Matrix_Body[i][l] = To_HConcat.Matrix_Body[i][k];
			l++;
		}
		l = 0;
	}
	this.Matrix_Body = ConcatH.Matrix_Body;
	this.Rows =ConcatH.Rows;
	this.Cols = ConcatH.Cols;
}

public void print_Matrix() {
	for (int i = 0; i < Rows; i++) {
		System.out.print("[");
		for (int j = 0; j < Cols; j++) {
			if(j <Cols-1) {
			System.out.print(Matrix_Body[i][j]+" | ");
			System.out.print(" ");
			}else {
				System.out.print(Matrix_Body[i][j]);

			}
		}
		System.out.print("]");
		System.out.print('\n');
	}
}

//members
public double Matrix_Body[][];
public int Rows, Cols;

}
