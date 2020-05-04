package JSipl;

public class LabPixel {
	public double L;
	public double A;
	public double B;
	int i,j;
	public LabPixel(int l,int a,int b) {
		this.L=l;
		this.A=a;
		this.B=b;

	}

	public LabPixel(int l,int a,int b,int i,int j) {
		this.L=l;
		this.A=a;
		this.B=b;
		this.i=i;
		this.j=j;
	}
	public LabPixel() {
		this.L=0;
		this.A=0;
		this.B=0;

	}
	public LabPixel(LabPixel copy) {
		this.A = copy.A;
		this.B=copy.B;
		this.L=copy.L;
		this.i=copy.i;
		this.j=copy.j;
	}

	/*
	 * public void RGB_to_LAB(Pixel RGB) { Point XYZ = this.RGB_to_XYZ(RGB); double
	 * Xn = 95.0489; double Yn = 100; double Zn = 108.8840; this.L= 116 *
	 * (LavConvFunction((XYZ.y/Yn))) - 16; this.A = 500 *
	 * (LavConvFunction((XYZ.x/Xn)) - LavConvFunction((XYZ.y/Yn))); this.B = 200 *
	 * (LavConvFunction((XYZ.y/Yn)) - LavConvFunction((XYZ.z/Zn)));
	 * 
	 * }
	 */
		public void RGB_to_LAB(Pixel RGB) {

	    double r, g, b, X, Y, Z, xr, yr, zr;

	    // D65/2°
	    double Xr = 95.047;  
	    double Yr = 100.0;
	    double Zr = 108.883;


	    // --------- RGB to XYZ ---------//

	    r = RGB.r/255.0;
	    g = RGB.g/255.0;
	    b = RGB.b/255.0;

	    if (r > 0.04045)
	        r = Math.pow((r+0.055)/1.055,2.4);
	    else
	        r = r/12.92;

	    if (g > 0.04045)
	        g = Math.pow((g+0.055)/1.055,2.4);
	    else
	        g = g/12.92;

	    if (b > 0.04045)
	        b = Math.pow((b+0.055)/1.055,2.4);
	    else
	        b = b/12.92 ;

	    r*=100;
	    g*=100;
	    b*=100;

	    X =  0.4124*r + 0.3576*g + 0.1805*b;
	    Y =  0.2126*r + 0.7152*g + 0.0722*b;
	    Z =  0.0193*r + 0.1192*g + 0.9505*b;


	    // --------- XYZ to Lab --------- //

	    xr = X/Xr;
	    yr = Y/Yr;
	    zr = Z/Zr;

	    if ( xr > 0.008856 )
	        xr =  (float) Math.pow(xr, 1/3.);
	    else
	        xr = (float) ((7.787 * xr) + 16 / 116.0);

	    if ( yr > 0.008856 )
	        yr =  (float) Math.pow(yr, 1/3.);
	    else
	        yr = (float) ((7.787 * yr) + 16 / 116.0);

	    if ( zr > 0.008856 )
	        zr =  (float) Math.pow(zr, 1/3.);
	    else
	        zr = (float) ((7.787 * zr) + 16 / 116.0);


	    double[] lab = new double[3];

	    lab[0] = (116*yr)-16;
	    lab[1] = 500*(xr-yr); 
	    lab[2] = 200*(yr-zr); 

	    this.L=lab[0];
	    this.A=lab[1];
	    this.B=lab[2];


	} 
			public String toString() {
	        return "(" + L + ", " + A +  ", "+B+")";
	 }

}
