package JSipl;

public class Complex {
	public double Real;
	public double Imaginary;
	public Complex() {
		this.Real=0;
		this.Imaginary=0;
	}
	public Complex(double Real,double Imaginray) {
		this.Real=Real;
		this.Imaginary=Imaginray;
	}
	public Complex(Complex Copy) {
		this.Real=Copy.Real;
		this.Imaginary=Copy.Imaginary;
	}
	public void Conjugate() {
		this.Imaginary*=-1;
	}
	public Complex Add(Complex B) {
        return new Complex(this.Real + B.Real, this.Imaginary + B.Imaginary);
	}
	public Complex Subtract(Complex B) {
        return new Complex(this.Real - B.Real, this.Imaginary - B.Imaginary);

	}
	public Complex Multiplication(Complex b) {
        return new Complex(this.Real * b.Real - this.Imaginary * b.Imaginary,
                this.Real * b.Imaginary + this.Imaginary * b.Real);
    }

	public void Multiplication(double b) {
       this.Real *= b;
       this.Imaginary *=b;
    }

	public void Power(int power) {
		for (int i = 1; i < power; i++) {
			this.Multiplication(this);
		}
	}
	public void Divide(Complex B) {
		double divisor = B.Real*B.Real + B.Imaginary*B.Imaginary;
		Complex t = new Complex(B);
		t.Conjugate();
		this.Multiplication(t);
		this.Real /= divisor;
		this.Imaginary /= divisor;
	}
	public String toString() {
		if(Imaginary == 0) {
			return "" + Real;
		}
		if(Imaginary > 0) {
			return " " + Real + " + " + Imaginary + "I";
		}else {
			return " " + Real +  Imaginary + "I";

		}
		
	}
    public double Abs() {
	        if (Math.abs(Real) < Math.abs(Imaginary)) {
	            if (Imaginary == 0.0) {
	                return Math.abs(Real);
	            }
	            double q = Real / Imaginary;
	            return Math.abs(Imaginary) * Math.sqrt(1 + q * q);
	        } else {
	            if (Real == 0.0) {
	                return Math.abs(Imaginary);
	            }
	            double q = Imaginary / Real;
	            return Math.abs(Real) * Math.sqrt(1 + q * q);
	        }
	    }
	public Complex Log() {
	        return new Complex(Math.log(Abs()),
	        		Math.atan2(Imaginary, Real));
	    }
	public static int bitReverse(int n, int bits) {
	        int reversedN = n;
	        int count = bits - 1;
	 
	        n >>= 1;
	        while (n > 0) {
	            reversedN = (reversedN << 1) | (n & 1);
	            count--;
	            n >>= 1;
	        }
	 
	        return ((reversedN << count) & ((1 << bits) - 1));
	    }
	static void FFT(Complex[] Values) {
	 
	        int bits = (int) (Math.log(Values.length) / Math.log(2));
	        for (int j = 1; j < Values.length / 2; j++) {
	 
	            int swapPos = bitReverse(j, bits);
	            Complex temp = Values[j];
	            Values[j] = Values[swapPos];
	            Values[swapPos] = temp;
	        }
	 
	        for (int N = 2; N <= Values.length; N <<= 1) {
	            for (int i = 0; i < Values.length; i += N) {
	                for (int k = 0; k < N / 2; k++) {
	 
	                    int evenIndex = i + k;
	                    int oddIndex = i + k + (N / 2);
	                    Complex even = Values[evenIndex];
	                    Complex odd = Values[oddIndex];
	 
	                    double term = (-2 * Math.PI * k) / (double) N;
	                    Complex exp = (new Complex(Math.cos(term), Math.sin(term)).Multiplication(odd));
	 
	                    Values[evenIndex] = even.Add(exp);
	                    Values[oddIndex] = even.Subtract(exp);
	                }
	            }
	        }
	   }

	public Complex Exp() {
	        double expReal = Math.exp(Real);
	        return new Complex(expReal *  Math.cos(Imaginary),expReal * Math.sin(Imaginary));
	    }
	public Complex Power(Complex x) {
		  return this.Log().Multiplication(x).Exp();
		    
	 }
	
}
