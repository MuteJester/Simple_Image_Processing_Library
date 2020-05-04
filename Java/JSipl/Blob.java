package JSipl;

public class Blob {
	
	public int Upleft_X, Upleft_Y;
	public int Downright_X, Downright_Y;
	public int Distnace_Treshold;

	private double Cordinate_Distance(int x0, int y0, int x1, int y1) {
		double Distance = (double)((x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0));
		return Distance;
	}
	
	public Blob(int x, int y, int Distnace_Treshold) {
		this.Downright_X = x;
		this.Downright_Y = y;
		this.Upleft_X = x;
		this.Upleft_Y = y;
		this.Distnace_Treshold = Distnace_Treshold;
	}
	public Blob(Blob copy) {
		this.Downright_X=copy.Downright_X;
		this.Downright_Y = copy.Downright_Y;
		this.Upleft_X = copy.Upleft_X;
		this.Upleft_Y = copy.Upleft_Y;
		this.Distnace_Treshold = copy.Distnace_Treshold;
	}
	public boolean Near(int x, int y) {
		double CentetX, CenterY, Dist;
		CentetX = Math.max(Math.min(x, Upleft_X), Downright_X);
		CenterY = Math.max(Math.min(y, Upleft_Y), Downright_Y);
		Dist = (double)(Cordinate_Distance((int)CentetX, (int)CenterY, (int)(x), (int)(y)));

		if (Dist < this.Distnace_Treshold*Distnace_Treshold) {
			return true;
		}
		else {

			return false;
		}
	}
	
	public void add(int px, int py) {
		this.Downright_X = (int)Math.min(Downright_X, px);
		this.Downright_Y = (int)Math.min(Downright_Y, py);

		this.Upleft_X = (int)Math.max(Upleft_X, px);
		this.Upleft_Y = (int)Math.max(Upleft_Y, py);
	}
	
	public void Clear() {
		this.Downright_X = this.Downright_Y = this.Upleft_X = this.Upleft_Y = -1;
	}
	
	public void SetProps(int x, int y) {
		this.Downright_X = x;
		this.Downright_Y = y;
		this.Upleft_X = x;
		this.Upleft_Y = y;
	}
	
	public double Size() {
		//return (double)Math.abs(this.Upleft_X - Downright_X)*(Upleft_Y - Downright_Y);
		return Math.sqrt((this.Downright_X-this.Upleft_X)*(this.Downright_X-this.Upleft_X) + (this.Downright_Y-this.Upleft_Y)*(this.Downright_Y-this.Upleft_Y));
	}

}
