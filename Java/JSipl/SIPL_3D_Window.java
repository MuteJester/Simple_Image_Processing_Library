package JSipl;

import java.awt.BorderLayout;
import java.awt.image.BufferedImage;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class SIPL_3D_Window extends JFrame {
	private static final long serialVersionUID = 1L;
	BufferedImage IMG;
	Point Camera = new Point(0,0,0);
	Point RotationAngle = new Point(0,0,0);
	Point Teta = new Point(0,0,0);
	Point E = new Point(0,0,0);
	Color_Palette CSET = new Color_Palette();
	Image Background;
	JLabel label;
	SIPL_3D_Window(){
		Background = new Image();
		Background.Load_Blank_Canvas(600, 600,CSET.White_Smoke );
		label=new JLabel();
		IMG = Background.IMG;
	    label.setIcon((Icon) new ImageIcon(IMG));
	    this.getContentPane().add(label,BorderLayout.CENTER);
	    //this.setLocationRelativeTo(null);
	    this.setSize(IMG.getWidth(), IMG.getHeight());
		this.setVisible(true);
		this.setLayout(null);
	
	}
	public void rotateAZ(double theta,Point Cord) {
		double sinTheta = Math.sin(theta);
		double cosTheta = Math.cos(theta);
		double y = Cord.x;
		double x = Cord.y;
		Cord.x = x * cosTheta - y * sinTheta;
		Cord.y = y * cosTheta + x * sinTheta;

	};
	public void rotateAX(double theta, Point Cord) {
		double sinTheta = Math.sin(theta);
		double cosTheta = Math.cos(theta);
		double y = Cord.y;
		double z = Cord.z;
		double x = Cord.x;
		Cord.y = y * cosTheta - z * sinTheta;
		Cord.z = z * cosTheta + y * sinTheta;
	};
	public void rotateAY(double theta, Point Cord){
		double sinTheta = Math.sin(theta);
		double cosTheta = Math.cos(theta);
		double x = Cord.x;
		double z = Cord.z;
		Cord.x = x * cosTheta + z * sinTheta;
		Cord.z = z * cosTheta - x * sinTheta;
	};
	public Point  point_to_coordinate(Point point) {	
		Point Result = new Point(0,0,0);
		double TR = Math.PI / 180;
		Point ToW = new Point();
		ToW.x = point.x;
		ToW.y = point.y;
		ToW.z = point.z;
		Matrix RE, A = new Matrix(3, 3), B = new Matrix(3, 3), C = new Matrix(3, 3),D,F,FINAL = new Matrix(3,1),Ppoint = new Matrix(3,1);
		Matrix Hproj = new Matrix(3, 1), MProj = new Matrix(3, 3);

		this.rotateAX(this.RotationAngle.x*TR, ToW);
		this.rotateAY(this.RotationAngle.y*TR, ToW);
		this.rotateAZ(this.RotationAngle.z*TR, ToW);

		Ppoint.Matrix_Body[0][0] = ToW.x - Camera.x;
		Ppoint.Matrix_Body[1][0] = ToW.y - Camera.y;
		Ppoint.Matrix_Body[2][0] = ToW.z - Camera.z;

		A.Matrix_Body[0][0] = 1;
		A.Matrix_Body[0][1] = 0;
		A.Matrix_Body[0][2] = 0;
		A.Matrix_Body[1][0] = 0;
		A.Matrix_Body[1][1] = Math.cos(Teta.x * TR);
		A.Matrix_Body[1][2] = Math.sin(Teta.x* TR);
		A.Matrix_Body[2][0] = 0;
		A.Matrix_Body[2][1] = -Math.sin(Teta.x* TR);
		A.Matrix_Body[2][2] = Math.cos(Teta.x* TR);
		
		B.Matrix_Body[0][0] = Math.cos(Teta.y* TR);
		B.Matrix_Body[0][1] = 0;
		B.Matrix_Body[0][2] = -Math.sin(Teta.y* TR);
		B.Matrix_Body[1][0] = 0;
		B.Matrix_Body[1][1] = 1;
		B.Matrix_Body[1][2] = 0;
		B.Matrix_Body[2][0] = Math.sin(Teta.y* TR);
		B.Matrix_Body[2][1] = 0;
		B.Matrix_Body[2][2] = Math.cos(Teta.y* TR);

		C.Matrix_Body[0][0] = Math.cos(Teta.z* TR);
		C.Matrix_Body[0][1] = Math.sin(Teta.z* TR);
		C.Matrix_Body[0][2] = 0;
		C.Matrix_Body[1][0] = -Math.sin(Teta.z* TR);
		C.Matrix_Body[1][1] = Math.cos(Teta.z* TR);
		C.Matrix_Body[1][2] = 0;
		C.Matrix_Body[2][0] = 0;
		C.Matrix_Body[2][1] = 0;
		C.Matrix_Body[2][2] = 1;

		A.Dot_Product(B);
		RE = A;
		RE.Dot_Product(C);
		F = RE;
		F.Dot_Product(Ppoint);
		FINAL = F;
		

		MProj.Matrix_Body[0][0] = 1;
		MProj.Matrix_Body[0][1] = 0;
		MProj.Matrix_Body[0][2] = E.x / E.z;
		MProj.Matrix_Body[1][0] = 0;
		MProj.Matrix_Body[1][1] = 1;
		MProj.Matrix_Body[1][2] = E.y / E.z;
		MProj.Matrix_Body[2][0] = 0;
		MProj.Matrix_Body[2][1] = 0;
		MProj.Matrix_Body[2][2] = 1 / E.z;

		MProj.Dot_Product(FINAL);
		Hproj = MProj;
		Result.x = (FINAL.Matrix_Body[0][0] + E.x)*Camera.z;
		Result.y = (FINAL.Matrix_Body[1][0] + E.y)*Camera.z;
		return Result;
	}
	public void Refresh_Frame(BufferedImage img) {
		this.IMG = img;
		label.setIcon((Icon) new ImageIcon(IMG));
	    this.setSize(IMG.getWidth(), IMG.getHeight());
	    this.revalidate();
	    this.repaint();
}
	
}
