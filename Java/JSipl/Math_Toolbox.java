package JSipl;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;

public class Math_Toolbox {
	
	
	public double getMean(int[] Data) {
		double sum =0;
		for(int i = 0 ; i < Data.length;i++) {
			sum+=Data[i];
		}
		
		return sum/Data.length;
	}
	public double getMedian(int[] Data) {
		int tmp[];
		
		tmp = Data.clone();
		
		Arrays.sort(tmp);
		if (tmp.length % 2 == 0) {
			return (double)(tmp[tmp.length / 2] + (double)tmp[(tmp.length / 2) - 1]) / 2;
		}
		else {

			return tmp[tmp.length / 2];
		}
	}
	public double getStandard_Deviation(int[] Data) {
		double mean = this.getMean(Data);
		double sum = 0;
		for (int i = 0; i < Data.length; i++) {
			sum += ((Data[i] - mean)*(Data[i] - mean));
		}
		sum /= (double)Data.length;
		sum = Math.sqrt(sum);
		return sum;
	}
	public double getVariance(int[] Data) {
		double Deviation = getStandard_Deviation(Data);
		return (Deviation)*(Deviation);
	}
	public double[]  getRank_Array(int[] Data) {
		double R[] = new double[Data.length]; 
        for (int i = 0; i < Data.length; i++) { 
            int r = 1, s = 1; 
              
            for (int j = 0; j < Data.length; j++)  
            { 
                if (j != i && Data[j] < Data[i]) 
                    r += 1; 
                      
                if (j != i && Data[j] == Data[i]) 
                    s += 1;      
            } 
                  R[i] = r + (double)(s - 1) /  (double)2; 
      
        }  
        return R;
	}
	public double get_Min_Of_Arrayd(double Data[]) {
		double min =Double.MAX_VALUE;
		for(int i =1 ;i<Data.length;i++) {
			if(Data[i]<min) {
				min = Data[i];
			}
		}
		return min;
	}
	public double nthRoot(int A, int N) 
    { 
        double xPre = Math.random() % 10; 
        double eps = 0.001; 
        double delX = 2147483647; 
        double xK = 0.0; 
        while (delX > eps) 
        { 
            xK = ((N - 1.0) * xPre + 
            (double)A / Math.pow(xPre, N - 1)) / (double)N; 
            delX = Math.abs(xK - xPre); 
            xPre = xK; 
        } 
      
        return xK; 
    } 
	public int getMax_From_MultiyD(ArrayList<ArrayList<Integer>> data) {
			
		int max = Integer.MIN_VALUE;
		for(int i = 0 ; i < data.size();i++) {
			for(int j =0;j<data.get(i).size();j++) {
				ArrayList<Integer> temp = data.get(i);
				if(temp.get(j) > max) {
					max = temp.get(j);
				}
			}
		}
		
		
		
		return max;
		
	}
	public int getMin_From_MultiyD(ArrayList<ArrayList<Integer>> data) {
		
		int min = Integer.MAX_VALUE;
		for(int i = 0 ; i < data.size();i++) {
			for(int j =0;j<data.get(i).size();j++) {
				ArrayList<Integer> temp = data.get(i);
				if(temp.get(j) < min) {
					min = temp.get(j);
				}
			}
		}
		
		
		
		return min;
		
	}
	public int getMax_From_ArrayList(ArrayList<Integer> data) {
		int max = Integer.MIN_VALUE;
			for(int j =0;j<data.size();j++) {
				if(data.get(j) > max) {
					max = data.get(j);
				}
			}
			return max;
	}
	public int get_array_max(int arr[]) {
		int max = Integer.MIN_VALUE;
		for(int j =0;j<arr.length;j++) {
			if(arr[j] > max) {
				max = arr[j];
			}
		}
		return max;
	}
	public static int random_int_in_range(int lower,int upper) {
		int rand = ThreadLocalRandom.current().nextInt(lower,upper);		
		return rand;
	}
	public static double random_double_in_range(double lower,double upper) {
		double rand = ThreadLocalRandom.current().nextDouble(lower,upper);		
		return rand;
	}

	public float Remap(float value, float fromMin, float fromMax, float toMin,  float toMax)
    {
        var fromAbs  =  value - fromMin;
        var fromMaxAbs = fromMax - fromMin;      
       
        var normal = fromAbs / fromMaxAbs;
 
        var toMaxAbs = toMax - toMin;
        var toAbs = toMaxAbs * normal;
 
        var to = toAbs + toMin;
       
        return to;
    }	
	// Get a random numbers between min and max
    public static float RandomFloat(float min, float max) {
        float a = (float) Math.random();
        float num = min + (float) Math.random() * (max - min);
        if(a < 0.5)
            return num;
        else
            return -num;
    }
    
    // Sigmoid function
    public static double Sigmoid(double x) {
        return (float) (1/(1+Math.pow(Math.E, -x)));
    }
    
    // Derivative of the sigmoid function
    public static double SigmoidDerivative(double x) {
        return Sigmoid(x)*(1-Sigmoid(x));
    }
    
    public static double squaredError(double output,double target) {
    	return (float) (0.5*Math.pow(2,(target-output)));
    }
    
    public static double sumSquaredError(double[] outputs,double[] targets) {
    	double sum = 0;
    	for(int i=0;i<outputs.length;i++) {
    		sum += squaredError(outputs[i],targets[i]);
    	}
    	return sum;
    }

    public static double Rectified(double x) {
    	if(x >= 0) {
    		return x;
    	}else {
    		return 0;
    	}
    }

}
