package JSipl;

public class Point {
	
	public double x,y,z;
	public Point(){
		x=y=z=0;
	}
	public Point(double X,double Y,double Z){
		x=X;
		y=Y;
		z=Z;
	}
	public Point(Point copy){
		this.x=copy.x;
		this.y=copy.y;
		this.z =copy.z;
	}
	public void Add(Point B) {
		this.x+=B.x;
		this.y+=B.y;
		this.z+=B.z;
	}
	public double Distance(Point B) {
		double distance ;
		distance = Math.sqrt((B.x - this.x)*(B.x - this.x) + (B.y - this.y)*(B.y - this.y) + (B.z - this.z)*(B.z - this.z));
		return distance;
	}
	public void Divide_All(int Divider) {
		this.x /= Divider;
		this.y /= Divider;
		this.z /= Divider;

	}
	@Override
	public String toString() {
		return "[X: " + this.x +"]" +" [Y: " + this.y +"]" + " [Z: " + this.z +"]"+ "\n";
	}
	public double X_Linear_Interpolation(Point B,double y_value) {
		return (((y_value - this.y)*(B.x - this.x)) / (B.y - this.y) + this.x);
		
	}
	public double Y_Linear_Interpolation(Point B,double x_value) {
		return (x_value - this.x)*(B.y - this.y) / (B.x - this.x) + this.y;		
	}
	public Point lerp(Point B ,double amount) {
		Point ret = new Point();
		ret.x = this.x + (B.x -this.x)*amount;
		ret.y = this.y +  (B.y -this.y)*amount;
		ret.z = this.z +  (B.z -this.z)*amount;

		return ret;
	}

}
