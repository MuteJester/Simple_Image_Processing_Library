package JSipl;

import JSipl.LabPixel;

public class Pixel {
	public Pixel(int r,int g,int b) {
		this.r=r;
		this.b=b;
		this.g=g;
		A =255;
		analysis=0;
	}
	public Pixel(int r,int g,int b,int i,int j) {
		this.r=r;
		this.b=b;
		this.g=g;
		this.i=i;
		this.j=j;
		A =255;
		analysis=0;
	}
	public Pixel() {
		this.r=0;
		this.b=0;
		this.g=0;
		this.A=255;
		analysis=0;
	}
	public Pixel(Pixel copy) {
		this.r = copy.r;
		this.g = copy.g;
		this.b = copy.b;
		this.A = copy.A;
		this.analysis = copy.analysis;
	}
	public int r;
	public int g;
	public int b;
	public int A;
	public int analysis;
	public int i,j;
	public Pixel Pixel_Mul(Pixel b) {
		Pixel ret = new Pixel();
		ret.r = this.r*b.r;
		if (ret.r > 255) {
			ret.r = ret.r % 255;
		}
		ret.g = this.g*b.g;
		if (ret.g > 255) {
			ret.g = ret.g % 255;
		}
		ret.b = this.b*b.b;
		if (ret.b > 255) {
			ret.b = ret.b % 255;
		}
		return ret;
	}
	public boolean is_Bigger(Pixel b) {
		if (this.r > b.r && this.g > b.g && this.b > b.b) {
			return true;
		}
		else {
			return false;
		}
	}
	public void Add_Location(int i,int j) {
		this.i = i;
		this.j =j;
	}
	@Override
    public String toString() {
        return "(" + r + ", " + g +  ", "+b+")";
    }
	private  void XYZtoRGB(Point XYZ){
			float x=(float)XYZ.x,y=(float)XYZ.y,z=(float)XYZ.z;
	        int[] rgb = new int[3];
	        
	        x /= 100;
	        y /= 100;
	        z /= 100;
	        
	        float r = 3.240479f * x - 1.53715f * y - 0.498535f * z;
	        float g = -0.969256f * x + 1.875991f * y + 0.041556f * z;
	        float b = 0.055648f * x - 0.204043f * y + 1.057311f * z;
	        
	        if ( r > 0.0031308 )
	            r = 1.055f * ( (float)Math.pow(r, 0.4166f) ) - 0.055f;
	        else
	            r = 12.92f * r;
	        
	        if ( g > 0.0031308 )
	            g = 1.055f * ( (float)Math.pow(g, 0.4166f) ) - 0.055f;
	        else
	            g = 12.92f * g;
	        
	        if ( b > 0.0031308 )
	            b = 1.055f * ( (float)Math.pow(b, 0.4166f) ) - 0.055f;
	        else
	            b = 12.92f * b;
	        
	       this.r = (Math.round(r * 255));
	       this.g = (Math.round(g * 255));
	       this.b = (Math.round(b * 255));
	        
	        
	    }
	private  Point LABtoXYZ(LabPixel lab){
	        Point xyz = new Point();
	        
	        float y = ( (float)lab.L + 16f ) / 116f;
	        float x = (float)lab.A / 500f + y;
	        float z = y - (float)lab.B / 200f;
	        
	        //Y
	        if ( Math.pow(y,3) > 0.008856 )
	            y = (float)Math.pow(y,3);
	        else
	            y = (float)(( y - 16 / 116 ) / 7.787);
	        
	        //X
	        if ( Math.pow(x,3) > 0.008856 )
	            x = (float)Math.pow(x,3);
	        else
	            x = (float)(( x - 16 / 116 ) / 7.787);
	        
	        // Z
	        if ( Math.pow(z,3) > 0.008856 )
	            z = (float)Math.pow(z,3);
	        else
	            z = (float)(( z - 16 / 116 ) / 7.787);
	        
	        xyz.x = x * 95.0489;
	        xyz.y = y * 100;
	        xyz.z = z * 108.8840;
	        
	        return xyz;
	    }
	public void Clamp_Outliers() {
		if(this.r > 255 || this.r < 0) {
			if(this.r>255) {
				this.r =255;
			}else {
				this.r=0;
			}
		} if(this.g > 255 || this.g < 0) {
			if(this.g>255) {
				this.g =255;
			}else {
				this.g=0;
			}
		}
		 if(this.b > 255 || this.b < 0) {
			if(this.b>255) {
				this.b =255;
			}else {
				this.b=0;
			}
		}
	}
	public void LAB_to_RGB(LabPixel lab) {
		Point xyz = this.LABtoXYZ(lab);
		this.XYZtoRGB(xyz);
	}

}
