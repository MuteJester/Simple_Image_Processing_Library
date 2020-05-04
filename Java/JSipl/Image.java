package JSipl;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Toolkit;
import java.awt.Transparency;
import java.awt.event.ActionEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.URL;

import javax.imageio.ImageIO;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.xml.crypto.Data;

import java.util.LinkedList;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;
import java.util.Collections;



public class Image {
	
	
	
	
	
	
	
	public BufferedImage IMG;
	public Pixel Pixel_Matrix[][];
	public int Image_Width,Image_Height;
	public String F_Path;
	//public boolean hasAlphaChannel;
	
	//functionality
	public Image(){

		
	}
	public Image(Image copy){
		this.F_Path = copy.F_Path;
		this.Load_Blank_Canvas(copy.Image_Height, copy.Image_Width, new Pixel(0,0,0));
		this.IMG = copy.IMG;
		this.init_pixel_matrix();
	}
	protected void Image_Load_Wrapper() {
		  this.Image_Width = IMG.getWidth();
		  this.Image_Height = IMG.getHeight();
		  this.init_pixel_matrix();

	  }
    public void Set_Color(int i,int j,int r,int g, int b) {
	  int p_value =0;
	  p_value = (255<<24) | (r<<16) | (g<<8) | b;
		  this.IMG.setRGB(j, i, p_value);
		  
	  }
    public void Set_Color(int i,int j,Pixel color) {
	  int p_value =0;
	  p_value = (255<<24) | (color.r<<16) | (color.g<<8) | color.b;
		  this.IMG.setRGB(j, i, p_value);
		  
	  }
    public void Set_Color(Pixel target,int r,int g,int b) {
		target.r=r;
		target.g=g;
		target.b=b;
	}
    public void Load_Image(String FilePath) throws IOException {
		try {
			if(FilePath.contains("http://")||FilePath.contains("https://")||FilePath.contains("www.")) {
				this.F_Path = FilePath;
				URL url = new URL(FilePath);
				this.IMG = ImageIO.read(url);
				this.Image_Load_Wrapper();
			}else {
			this.F_Path = FilePath;
			this.IMG = ImageIO.read(Image.class.getResource(FilePath));
			this.Image_Load_Wrapper();
			}
		}catch(IOException e) {
			System.out.println("Error");
		}
		
		
	
	}
	public void Crop_Image(int left_corner_y,int left_corner_x,int right_corner_y,int right_corner_x) {
		int width = right_corner_x - left_corner_x;
		int height = right_corner_y-left_corner_y;
		Image tmp = new Image();
		int x=0,y =0;
		tmp.Load_Blank_Canvas(height, width, new Pixel(0,0,0));
		for(int i = left_corner_y ; i  < right_corner_y ;i++) {
			for(int j = left_corner_x;j<right_corner_x;j++) {
				tmp.Pixel_Matrix[y][x] = this.Pixel_Matrix[i][j];
				x++;
			}
			y++;
			x=0;
		}
		tmp.Commint_Matrix_Changes();
		this.IMG=tmp.IMG;
		this.Image_Width=tmp.Image_Width;
		this.Image_Height=tmp.Image_Height;
	}
	public void Crop_Image(int left_corner_y,int left_corner_x,int right_corner_y,int right_corner_x,String save_as) {
		int width = right_corner_x - left_corner_x;
		int height = right_corner_y-left_corner_y;
		Image tmp = new Image();
		int x=0,y =0;
		tmp.Load_Blank_Canvas(height, width, new Pixel(0,0,0));
		for(int i = left_corner_y ; i  < right_corner_y ;i++) {
			for(int j = left_corner_x;j<right_corner_x;j++) {
				tmp.Pixel_Matrix[y][x] = this.Pixel_Matrix[i][j];
				x++;
			}
			y++;
			x=0;
		}
		tmp.Commint_Matrix_Changes();
		tmp.Write_Image(save_as);
	}
	public void Arithmetic_Addition(Image Image_To_Add) {
		for(int i =0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r += Image_To_Add.Pixel_Matrix[i][j].r;
				this.Pixel_Matrix[i][j].g += Image_To_Add.Pixel_Matrix[i][j].g;
				this.Pixel_Matrix[i][j].b += Image_To_Add.Pixel_Matrix[i][j].b;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Subtraction(Image Image_To_Subtract) {
		for(int i =0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r -= Image_To_Subtract.Pixel_Matrix[i][j].r;
				this.Pixel_Matrix[i][j].g -= Image_To_Subtract.Pixel_Matrix[i][j].g;
				this.Pixel_Matrix[i][j].b -= Image_To_Subtract.Pixel_Matrix[i][j].b;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Multiplication(Image Image_To_Multiply_By) {
		for(int i =0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r *= Image_To_Multiply_By.Pixel_Matrix[i][j].r;
				this.Pixel_Matrix[i][j].g *= Image_To_Multiply_By.Pixel_Matrix[i][j].g;
				this.Pixel_Matrix[i][j].b *= Image_To_Multiply_By.Pixel_Matrix[i][j].b;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Division(Image Image_To_Divide_By) {
		for(int i =0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r /= Image_To_Divide_By.Pixel_Matrix[i][j].r;
				this.Pixel_Matrix[i][j].g /= Image_To_Divide_By.Pixel_Matrix[i][j].g;
				this.Pixel_Matrix[i][j].b /= Image_To_Divide_By.Pixel_Matrix[i][j].b;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Addition(int int_To_Add) {
		for(int i =0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r += int_To_Add;
				this.Pixel_Matrix[i][j].g += int_To_Add;
				this.Pixel_Matrix[i][j].b += int_To_Add;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Subtraction(int int_To_Subctract) {
		for(int i =0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r -= int_To_Subctract;
				this.Pixel_Matrix[i][j].g -= int_To_Subctract;
				this.Pixel_Matrix[i][j].b -= int_To_Subctract;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Multiplication(int int_To_Multiply_By) {
		for(int i =0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r *= int_To_Multiply_By;
				this.Pixel_Matrix[i][j].g *= int_To_Multiply_By;
				this.Pixel_Matrix[i][j].b *= int_To_Multiply_By;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Division(int int_To_Divide_By) {
		for(int i =0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r /= int_To_Divide_By;
				this.Pixel_Matrix[i][j].g /= int_To_Divide_By;
				this.Pixel_Matrix[i][j].b /= int_To_Divide_By;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Union(Image to_Union) {
		if(to_Union.Image_Height != this.Image_Height || this.Image_Width != to_Union.Image_Width) {
			System.out.println("Operation Aborted: Images Are Different In Size");
			return;
		}
		
		for(int i = 0 ; i < this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = Math.max(this.Pixel_Matrix[i][j].r, to_Union.Pixel_Matrix[i][j].r);
				this.Pixel_Matrix[i][j].g = Math.max(this.Pixel_Matrix[i][j].g, to_Union.Pixel_Matrix[i][j].g);
				this.Pixel_Matrix[i][j].b = Math.max(this.Pixel_Matrix[i][j].b, to_Union.Pixel_Matrix[i][j].b);

			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_Complement() {
		for(int i = 0 ; i < this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = 255 - this.Pixel_Matrix[i][j].r ;
				this.Pixel_Matrix[i][j].g = 255 - this.Pixel_Matrix[i][j].g ;
				this.Pixel_Matrix[i][j].b = 255 - this.Pixel_Matrix[i][j].b ;


			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_AND(Image to_AND) {
		if(to_AND.Image_Height != this.Image_Height || this.Image_Width != to_AND.Image_Width) {
			System.out.println("Operation Aborted: Images Are Different In Size");
			return;
		}
		int a,b,res;
		for(int i = 0 ; i < this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				a = this.Pixel_Matrix[i][j].r /255;
				b= to_AND.Pixel_Matrix[i][j].r /255;				
				if((b & a) == 1) {
					this.Pixel_Matrix[i][j].r =255;
					this.Pixel_Matrix[i][j].g =255;
					this.Pixel_Matrix[i][j].b =255;

				}else {
					this.Pixel_Matrix[i][j].r =0;
					this.Pixel_Matrix[i][j].g =0;
					this.Pixel_Matrix[i][j].b =0;

				}

			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_AND_NOT(Image to_AND) {
		if(to_AND.Image_Height != this.Image_Height || this.Image_Width != to_AND.Image_Width) {
			System.out.println("Operation Aborted: Images Are Different In Size");
			return;
		}
		int a,b;
		for(int i = 0 ; i < this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				a = this.Pixel_Matrix[i][j].r /255;
				b= to_AND.Pixel_Matrix[i][j].r /255;				
				if((a & (~b)) == 1) {
					this.Pixel_Matrix[i][j].r =255;
					this.Pixel_Matrix[i][j].g =255;
					this.Pixel_Matrix[i][j].b =255;

				}else {
					this.Pixel_Matrix[i][j].r =0;
					this.Pixel_Matrix[i][j].g =0;
					this.Pixel_Matrix[i][j].b =0;

				}

			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Arithmetic_NOT() {

		this.Arithmetic_Complement();
	}
	public void Arithmetic_OR(Image to_OR) {
		if(to_OR.Image_Height != this.Image_Height || this.Image_Width != to_OR.Image_Width) {
			System.out.println("Operation Aborted: Images Are Different In Size");
			return;
		}
		int a,b,res;
		for(int i = 0 ; i < this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				a = this.Pixel_Matrix[i][j].r /255;
				b= to_OR.Pixel_Matrix[i][j].r /255;				
				if((b | a) == 1) {
					this.Pixel_Matrix[i][j].r =255;
					this.Pixel_Matrix[i][j].g =255;
					this.Pixel_Matrix[i][j].b =255;

				}else {
					this.Pixel_Matrix[i][j].r =0;
					this.Pixel_Matrix[i][j].g =0;
					this.Pixel_Matrix[i][j].b =0;

				}

			}
		}
		this.Commint_Matrix_Changes();
	}	
	public void Arithmetic_XOR(Image to_XOR) {
		if(to_XOR.Image_Height != this.Image_Height || this.Image_Width != to_XOR.Image_Width) {
			System.out.println("Operation Aborted: Images Are Different In Size");
			return;
		}
		int a,b;
		for(int i = 0 ; i < this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				a = this.Pixel_Matrix[i][j].r /255;
				b= to_XOR.Pixel_Matrix[i][j].r /255;				
				if((b ^ a) == 1) {
					this.Pixel_Matrix[i][j].r =255;
					this.Pixel_Matrix[i][j].g =255;
					this.Pixel_Matrix[i][j].b =255;

				}else {
					this.Pixel_Matrix[i][j].r =0;
					this.Pixel_Matrix[i][j].g =0;
					this.Pixel_Matrix[i][j].b =0;

				}

			}
		}
		this.Commint_Matrix_Changes();
	}	
	
	public void Commint_Matrix_Changes() {
		for(int i=0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Set_Color(i, j, this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,this.Pixel_Matrix[i][j].b);
			}
		}
	}
    public void Update_Pixel_Matrix() {
    	this.init_pixel_matrix();
    }
	public void Write_Image() {
		try{
		      File f = new File("Output.jpg");
		      ImageIO.write(IMG, "jpg", f);
		    }catch(IOException e){
		      System.out.println(e);
		    }

	}
	public void Write_Image(String Filename) {
		try{
			
		      File f = new File(Filename);
		      ImageIO.write(IMG, "png", f);
		    }catch(IOException e){
		      System.out.println(e);
		    }

	}
	public void Write_Image(String Filename,String Type) {
		try{
			
		      File f = new File(Filename);
		      ImageIO.write(IMG, Type, f);
		    }catch(IOException e){
		      System.out.println(e);
		    }

	}
	public void Show_Image() {
		SIPL_Window frame = new SIPL_Window(this.IMG);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		/*
		 * frame.addWindowListener( new WindowAdapter() { public void
		 * windowClosing(WindowEvent e) { JFrame frame = (JFrame)e.getSource();
		 * 
		 * int result = JOptionPane.showConfirmDialog( frame,
		 * "Are you sure you want to exit the application?", "Exit Application",
		 * JOptionPane.YES_NO_OPTION);
		 * 
		 * if (result == JOptionPane.YES_OPTION)
		 * frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); } });
		 */
	}

	public Pixel Get_Pixel(int i,int j) {
		Pixel temp = new Pixel();
		int holder =IMG.getRGB(j, i);
		temp.r = (holder & 0xff0000) >> 16;
		temp.g = (holder & 0xff00 ) >> 8;
		temp.b = holder & 0xff;
		temp.A = 255;
		return temp;
	}
	private void init_pixel_matrix() {
		this.Pixel_Matrix = new Pixel[this.Image_Height][this.Image_Width];
		for(int i=0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j] = this.Get_Pixel(i, j);
			}
		}
	}
	public void Load_Blank_Canvas(int height,int width,Pixel Background_Color) {
		this.IMG = new BufferedImage(width,height,BufferedImage.TYPE_3BYTE_BGR);
		this.Image_Height = height;
		this.Image_Width =width;
		this.init_pixel_matrix();
		this.Image_Load_Wrapper();
		for(int i=0;i<height;i++) {
			for(int j=0;j<width;j++) {
				this.Set_Color(i, j,Background_Color);
			}
		}
		
		this.Update_Pixel_Matrix();
	}
	public void convertToARGB()
	{
	    BufferedImage newImage = new BufferedImage(
	        IMG.getWidth(), IMG.getHeight(),
	        BufferedImage.TYPE_INT_ARGB);
	    Graphics2D g = newImage.createGraphics();
	    g.drawImage(IMG, 0, 0, null);
	    g.dispose();
	    this.IMG = newImage;
	}
	public void Draw_Square(int center_x,int center_y,int square_Image_Width,int square_Image_Height,Pixel Color) {
		if (center_x + square_Image_Width >= this.Image_Width || center_y + square_Image_Height >= this.Image_Height || center_x - square_Image_Width < 0 || center_y - square_Image_Height < 0) {
			System.out.println("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n");
			System.out.println("Image_Height Of Image: ");
			System.out.println("Image_Width Of Image: ");
			return;
		}
		for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i++) {
			this.Set_Color(center_y + square_Image_Height, i, Color);
			//Pixel_Matrix[center_y + square_Image_Height][i] = new Pixel(Color);
		}
		for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i++) {
			this.Set_Color(center_y - square_Image_Height, i, Color);
			//Pixel_Matrix[center_y - square_Image_Height][i]= new Pixel(Color);
		}
		for (int i = center_y - square_Image_Height; i <= center_y + square_Image_Height; i++) {
			this.Set_Color(i, center_x - square_Image_Width, Color);
			//Pixel_Matrix[i][center_x - square_Image_Width]= new Pixel(Color);
		}
		for (int i = center_y - square_Image_Height; i <= center_y + square_Image_Height; i++) {
			//Pixel_Matrix[i][center_x + square_Image_Width]= new Pixel(Color);
			this.Set_Color(i, center_x + square_Image_Width, Color);
		}
	}
	private void BresenhamsLine(int start_y,int start_x,int target_y,int target_x, Pixel color) {
		double dx, sx, dy, sy, err, e2;
		double x0 = start_y, x1 = target_y, y0 = start_x, y1 = target_x;
		dx = Math.abs(target_y - start_y);
		sx = start_y < target_y ? 1 : -1;
		dy = -Math.abs(target_x - start_x);
		sy = start_x < target_x ? 1 : -1;
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0), color);
				//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = new Pixel(color);

				break;
			}

			//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = new Pixel(color);
			this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0), color);

			
			e2 = 2 * err;
			if (e2 >= dy) {
				err += dy;
				x0 += sx;
			}
			if (e2 <= dx) {
				err += dx;
				y0 += sy;
			}

		}
	}
	public void Draw_Line(int start_y,int start_x,int target_y,int target_x, Pixel color) {

		this.BresenhamsLine(start_y, start_x, target_y, target_x, color);
	}
	public void Draw_Line(int start_x,int start_y,int target_y,Pixel color) {
	
		if (target_y > this.Image_Height || start_y > this.Image_Height || start_y < 0 || start_x > Image_Width || start_x < 0) {
			System.out.println("Line Out Of Image Range\nDraw Action Aborted");
			return;
		}

		if (start_y < target_y) {
			for (int i = start_y; i < target_y; i++) {
				//Pixel_Matrix[i][start_x] = new Pixel(color);
				this.Set_Color(i, start_x, color);
			}
		}
		else {
			for (int i = start_y; i > target_y; i--) {
				//Pixel_Matrix[i][start_x]= new Pixel(color);
				this.Set_Color(i, start_x, color);
			}
		}

	}
	public void Draw_Line(int start_x,int start_y,int target_x,int target_y, Pixel color, int line_Image_Width) {
		if (line_Image_Width > 0) {
			float dx, sx, dy, sy, err, e2;
			float x0 = (float)start_x, x1 = (float)target_x, y0 = (float)start_y, y1 = (float)target_y;
			dx = (float)Math.abs(target_x - start_x);
			sx = (float)(start_x < target_x ? 1 : -1);
			dy = (float)(-Math.abs(target_y - start_y));
			sy = (float)(start_y < target_y ? 1 : -1);
			err = dx + dy;  /* error value e_xy */
			while (true) {
				if (x0 == x1 && y0 == y1) {
					this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0), color);
					//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = new Pixel(color);
					if (line_Image_Width > 0) {

						if (start_y != target_y) {
							for (int i = 1; i <= line_Image_Width; i++) {
							
								this.Set_Color((int)Math.floor(x0) + i, (int)Math.floor(y0), color);
								this.Set_Color((int)Math.floor(x0) - i,(int)Math.floor(y0), color);

								//Pixel_Matrix[(int)Math.floor(x0) + i][(int)Math.floor(y0)] = new Pixel(color);
								//Pixel_Matrix[(int)Math.floor(x0) - i][(int)Math.floor(y0)] = new Pixel(color);
							}
						}
						else {
							for (int i = 1; i <= line_Image_Width; i++) {
								
								this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0) + i, color);
								this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0) - i, color);

								//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) + i] = new Pixel(color);
								//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) - i] = new Pixel(color);
							}
						}


					}



					break;
				}

				Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = color;
				if (line_Image_Width > 0) {
					if (start_y != target_y) {
						for (int i = 1; i <= line_Image_Width; i++) {
		
							this.Set_Color((int)Math.floor(x0) + i, (int)Math.floor(y0), color);
							this.Set_Color((int)Math.floor(x0) - i,(int)Math.floor(y0), color);
							//Pixel_Matrix[(int)Math.floor(x0) + i][(int)Math.floor(y0)] = color;				
							//Pixel_Matrix[(int)Math.floor(x0) - i][(int)Math.floor(y0)] =color;
						}
					}
					else {
						for (int i = 1; i <= line_Image_Width; i++) {
							
							this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0) + i, color);
							this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0) - i, color);

							//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) + i] = color;
							//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) - i] = color;
						}
					}




				}

				e2 = 2 * err;
				if (e2 >= dy) {
					err += dy; /* e_xy+e_x > 0 */
					x0 += sx;
				}
				if (e2 <= dx) {
					err += dx;
					y0 += sy;
				}

			}
		}
		else {
			this.BresenhamsLine(start_x, start_y, target_x, target_y, color);
		}
	}
	public void Draw_Square(int center_x,int center_y,int square_Image_Width,int square_Image_Height,Pixel Color,String Mode) {
	
		if (Mode.equals("Fill")) {
		
			if (center_x + square_Image_Width > this.Image_Width || center_y + square_Image_Height >= this.Image_Height || center_x - square_Image_Width < 0 || center_y - square_Image_Height < 0) {				System.out.println("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n");
				System.out.println("Image_Height Of Image: ");
				System.out.println("Image_Width Of Image: ");
				return;
			}
			
			for (int j = center_y - square_Image_Height; j <= center_y + square_Image_Height; j++) {
				for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i++) {
					//Pixel_Matrix[j][i] = new Pixel(Color);
					this.Set_Color(j, i, Color);
				}
			}
		}
		else if (Mode.equals("Checkered")) {
			if (center_x + square_Image_Width > this.Image_Width || center_y + square_Image_Height >= this.Image_Height || center_x - square_Image_Width < 0 || center_y - square_Image_Height < 0) {				System.out.println("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n");
			System.out.println("Image_Height Of Image: ");
			System.out.println("Image_Width Of Image: ");
			return;
		}
			
			for (int j = center_y - square_Image_Height; j <= center_y + square_Image_Height; j++) {
				for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i +=8) {
					//Pixel_Matrix[j][i] = new Pixel(Color);
					this.Set_Color(j, i, Color);
				}
			}
			
			for (int j = center_y - square_Image_Height; j <= center_y + square_Image_Height; j++) {
				for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i +=8) {
					//Pixel_Matrix[i][j] = new Pixel(Color);
					this.Set_Color(i, j, Color);
				}
			}
		}
		else if (Mode.equals("Corners")) {
			
			this.Draw_Line(center_x, center_y, square_Image_Width, center_y, Color);
			this.Draw_Line(center_x, center_y, center_x, square_Image_Height, Color);
			this.Draw_Line(center_x, square_Image_Height, square_Image_Width, square_Image_Height, Color);
			this.Draw_Line(square_Image_Width, center_y, square_Image_Width, square_Image_Height, Color);



		}
	}
	public void Draw_Circle(int center_x,int center_y,int c_radius, Pixel color) {
		int x, y, r2;
		if (center_x + c_radius >= this.Image_Width || center_x - c_radius <= 0 || center_y + c_radius >= this.Image_Height || center_y - c_radius <= 0) {
			System.out.println("Image_Height Of Image: ");
			System.out.println("Image_Width Of Image: ");
			return;
	
		}
		r2 = c_radius * c_radius;


		for (x = -c_radius; x <= c_radius; x++) {
			y = (int)(Math.sqrt(r2 - x * x) + 0.5);
			this.Set_Color(center_y + y,center_x + x, color);
			this.Set_Color(center_y + y,center_x - x, color);

			Pixel_Matrix[center_y + y][center_x + x] = color;
			Pixel_Matrix[center_y + y][center_x - x] = color;
		}
		for (x = -c_radius; x <= c_radius; x++) {
			y = (int)(Math.sqrt(r2 - x * x) + 0.5);
			this.Set_Color(center_y - y,center_x + x, color);
			this.Set_Color(center_y - y,center_x - x, color);
			Pixel_Matrix[center_y - y][center_x + x] = color;
			Pixel_Matrix[center_y - y][center_x - x] = color;
		}
		for (x = -c_radius; x <= c_radius; x++) {
			y = (int)(Math.sqrt(r2 - x * x) + 0.5);
			this.Set_Color(center_y - x,center_x + y, color);
			this.Set_Color(center_y - x,center_x - y, color);
			Pixel_Matrix[center_y - x][center_x + y] = color;
			Pixel_Matrix[center_y - x][center_x - y] = color;
		}


	}
	public void Draw_Circle(int center_x,int center_y,int c_radius, Pixel color,String Mode) {
	
		if (Mode.equals("Fill")) {
			
			int x = 0, y;
			if (center_x + c_radius > Image_Width || center_x - c_radius <0 || center_y + c_radius > Image_Height || center_y - c_radius < 0) {
				System.out.println("Image_Height Of Image: ");
				System.out.println("Image_Width Of Image: ");
				return;
		
			}
			for (y = -c_radius; y <= c_radius; y++) {
				for (x = -c_radius; x <= c_radius; x++) {
					if ((x * x) + (y * y) <= (c_radius * c_radius)) {
						Pixel_Matrix[center_y + y][center_x + x] = new Pixel(color);
						this.Set_Color(center_y + y, center_x + x, color);
					}
				}
			}
		}
	}
	public void Draw_Text(int center_y,int center_x,String text, Pixel color) {

		int text_length = text.length();
		int start_x, draw_y, flag = 0, temp=0;
		LibCharacters Set = new LibCharacters();
		if (center_x + (9 * (text_length / 2)) > Image_Width || center_x - (9 * (text_length / 2)) < 0
			|| center_y + 4 > Image_Height || center_y - 4 < 0) {
			System.out.println("Text Longer The Image Frame, Aborting...\n");
			return;
		}

		start_x = center_x - (9 * (text_length / 2));
		draw_y = center_y - 4;

		for (int i = 0; i < text.length(); i++) {

			switch (text.charAt(i))
			{

			case '0':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Zero[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);
						//Pixel_Matrix[draw_y][start_x]=color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '1':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_One[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '2':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Two[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '3':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Three[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '4':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Four[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '5':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Five[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '6':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Six[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '7':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Seven[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '8':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Eight[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '9':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Nine[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'A':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_A[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'B':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_B[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'C':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_C[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'D':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_D[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'E':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_E[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'F':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_F[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'G':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_G[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'H':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_H[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'I':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_I[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'J':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_J[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'K':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_K[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'L':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_L[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'M':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_M[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'N':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_N[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'O':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_O[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'P':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_P[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'Q':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_Q[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'R':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_R[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'S':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_S[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'T':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_T[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'U':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_U[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'V':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_V[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'W':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_W[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;

				break;

			case 'X':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_X[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'Y':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_Y[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'Z':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_Z[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '?':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Quesiton_Mark[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '!':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Exclamation_Point[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '(':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Left_Braket[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case ')':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Right_Braket[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '&':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Ampersand[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case ',':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Comma[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '[':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Squaure_Braket_Left[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case ']':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Square_Braket_Right[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case ' ':
				temp += 9;
				break;

			case ':':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Colon[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case '=':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.EqualSign[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case '+':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.PlusSign[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
				
			case '%':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Precent[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
				
			case '*':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Astersik[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
				
			case '.':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Dot[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
				
			case ';':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Semi_Colon[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '-':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.MinusSign[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

		

			default:
				break;
				
				
			}
			
			

			draw_y = center_y - 4;
			start_x = temp;
			start_x += 9;

		}



	}
	public double Get_Square(double value) {
		return value * value;
	}
	public double squared_3Point_distance(Point first, Point second) {
		return Get_Square(first.x - second.x) + Get_Square(first.y - second.y) + Get_Square(first.z - second.z);
	}
	public void Grayscale(int alter) {
		for (int i = 0; i < Image_Height; i++) {

			for (int j = 0; j < Image_Width; j++) {
				double val = this.Pixel_Matrix[i][j].r*0.29 + this.Pixel_Matrix[i][j].g*0.59 + this.Pixel_Matrix[i][j].b*0.11;
				this.Pixel_Matrix[i][j].r = (int)Math.round(val);
				this.Pixel_Matrix[i][j].g = (int)Math.round(val);
				this.Pixel_Matrix[i][j].b = (int)Math.round(val);
			}
		}
		if(alter == 1) {
			this.Commint_Matrix_Changes();
		}
	}
	/*
	 * public void Grayscale(int alter) { for (int i = 0; i < Image_Height; i++) {
	 * 
	 * for (int j = 0; j < Image_Width; j++) {
	 * 
	 * if (Pixel_Matrix[i][j].b >= Pixel_Matrix[i][j].r && Pixel_Matrix[i][j].b >=
	 * Pixel_Matrix[i][j].g) { Pixel_Matrix[i][j].r = Pixel_Matrix[i][j].b;
	 * Pixel_Matrix[i][j].g = Pixel_Matrix[i][j].b; } else if (Pixel_Matrix[i][j].r
	 * >= Pixel_Matrix[i][j].b &&Pixel_Matrix[i][j].r >= Pixel_Matrix[i][j].g) {
	 * Pixel_Matrix[i][j].b = Pixel_Matrix[i][j].r; Pixel_Matrix[i][j].g =
	 * Pixel_Matrix[i][j].r; } else if (Pixel_Matrix[i][j].g >= Pixel_Matrix[i][j].r
	 * &&Pixel_Matrix[i][j].g >= Pixel_Matrix[i][j].b) { Pixel_Matrix[i][j].r =
	 * Pixel_Matrix[i][j].g; Pixel_Matrix[i][j].b = Pixel_Matrix[i][j].g; }
	 * 
	 * } } if(alter == 1) { this.Commint_Matrix_Changes(); } }
	 */
    public double Color_Delta(Pixel A, Pixel B) {
		long  R_Gag = ((long)(A.r + (long)(B.r)) / 2);
		long  r = (long)A.r - (long)B.r;
		long  g = (long)A.g - (long)B.g;
		long  b = (long)A.b - (long)B.b;
		return (float)(Math.sqrt((((512 + R_Gag)*r*r) >> 8) + 4 * g*g + (((767 - R_Gag)*b*b) >> 8)));
	}
	public int Color_Distance(Pixel a, Pixel b) {
		int recored;
		recored = (a.b - b.b) + (a.r - b.r) + (a.g - b.g);
		if (recored < 0) {
			recored *= -1;
		}

		return recored;
	}
	public double Color_DistanceSq(Pixel a, Pixel b) {
		double  recored;
		recored = (b.r - a.r)*(b.r - a.r) + (b.g - a.g)*(b.g - a.g) + (b.b - a.b)*(b.b - a.b);
		return Math.sqrt(recored);
	}
	public double Image_Difference_Value(Image b) {

		double result = 0;
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				result = result + Color_DistanceSq(Pixel_Matrix[i][j], b.Pixel_Matrix[i][j]);
			}
		}
		return result / Image_Height * Image_Width;

	}
	public boolean Distance_Neighbors(double max_distance, int i, int j) {
		Pixel center, point;
		center = Pixel_Matrix[i][j];
		double dist = 0;
		if (i - 1 < 0 && j + 1 < this.Image_Width && j - 1 > 0 && i + 1 < Image_Height) {
			point = Pixel_Matrix[i][j + 1];
			dist = (double)(Color_DistanceSq(point, center));
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i][j - 1];
			dist = (double)Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j];
			dist = (double)Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j - 1];
			dist = (double)Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j + 1];
			dist = (double)Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}

		}
		if (i + 1 > Image_Height && j + 1 < Image_Width && j - 1 > 0 && i - 1 > 0)
		{
			point = Pixel_Matrix[i][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}

		}
		if (j - 1 < 0 && i + 1 < Image_Height && i - 1 > 0 && j + 1 < Image_Width) {
			point = Pixel_Matrix[i + 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
		}
		if (j + 1 > Image_Width && i + 1 < Image_Height && i - 1 > 0 && j - 1 > 0) {
			point = Pixel_Matrix[i][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
		}

		return true;


	}
	public double Get_Neighbour_Mean_R(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].r;

		if (i + 1 <= this.Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].r;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].r;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].r;
			Divider++;
		}
		if (j - 1 <= 0) {
			Mean += Pixel_Matrix[i][j - 1].r;
			Divider++;
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].r;
			Divider++;
		}
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].r;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].r;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].r;
			Divider++;
		}
		return Mean / Divider;

	}
	public double Get_Neighbour_Mean_G(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].g;

		if (i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].g;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].g;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].g;
			Divider++;
		}
		if (j - 1 <= 0) {
			Mean += Pixel_Matrix[i][j - 1].g;
			Divider++;
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].g;
			Divider++;
		}
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].g;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].g;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].g;
			Divider++;
		}
		return Mean / Divider;

	}
	public double Get_Neighbour_Mean_B(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].b;

		if (i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].b;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].b;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].b;
			Divider++;
		}
		if (j - 1 <= 0) {
			Mean += Pixel_Matrix[i][j - 1].b;
			Divider++;
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].b;
			Divider++;
		}
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].b;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].b;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].b;
			Divider++;
		}
		return Mean / Divider;
	}
	public double Get_Neighbour_Mean_G(int i, int j, double Kernel[][], double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].g * Kernel[1][1];

		if (i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].g * Kernel[2][1];
			if (Kernel[2][1] != 0) {
				Divider++;
			}
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].g * Kernel[0][1];
			if (Kernel[0][1] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].g * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].g * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].g * Kernel[0][0];
			Divider++;

		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].g * Kernel[2][0];
			if (Kernel[2][0] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].g * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].g * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	public double Get_Neighbour_Mean_R(int i, int j, double Kernel[][], double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].r * Kernel[1][1];

		if (i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].r * Kernel[2][1];
			if (Kernel[2][1] != 0) {
				Divider++;
			}
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].r * Kernel[0][1];
			if (Kernel[0][1] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].r * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].r * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].r * Kernel[0][0];
			if (Kernel[0][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].r * Kernel[2][0];
			Divider++;

		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].r * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].r * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	public double Get_Neighbour_Mean_B(int i, int j, double Kernel[][], double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].b * Kernel[1][1];

		if (i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].b * Kernel[2][1];
			if (Kernel[2][1] != 0) {
				Divider++;
			}
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].b * Kernel[0][1];
			if (Kernel[0][1] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].b * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].b * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].b * Kernel[0][0];
			if (Kernel[0][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].b * Kernel[2][0];
			Divider++;

		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].b * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].b * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	public void Mark_Identical_Pixels(Pixel Target) {
		Color_Palette cset = new Color_Palette();
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				if (Pixel_Matrix[i][j] == Target) {
					this.Draw_Square(j, i, 2, 2, cset.Red);
				}
			}
		}

	}
	public void Mark_Identical_Pixels(Image Source) {
		Color_Palette cset = new Color_Palette();

		if (this.Image_Width*this.Image_Height <= Source.Image_Height * Source.Image_Width) {
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
						this.Draw_Square(j, i, 2, 2, cset.Red);
					}
				}
			}
		}
		else if (this.Image_Width*this.Image_Height > Source.Image_Height * Source.Image_Width) {
			for (int i = 0; i < Source.Image_Height; i++) {
				for (int j = 0; j < Source.Image_Width; j++) {
					if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
						this.Draw_Square(j, i, 2, 2, cset.Red);
					}
				}
			}
		}

	}
	public void Mark_Identical_Pixels(Image Source, String mode) {
		Color_Palette cset = new Color_Palette();
		if (mode.equals("Strict")) {//strict
			if (this.Image_Width*this.Image_Height <= Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Image_Height; i++) {
					for (int j = 0; j < Image_Width; j++) {
						if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
							this.Draw_Square(j, i, 2, 2, cset.Red);
						}
					}
				}
			}
			else if (this.Image_Width*this.Image_Height  > Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Source.Image_Height; i++) {
					for (int j = 0; j < Source.Image_Width; j++) {
						if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
							this.Draw_Square(j, i, 2, 2, cset.Red);
						}
					}
				}
			}
		}
		else if (mode.equals("Loose")) {//loose

			if (this.Image_Width*this.Image_Height <= Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Image_Height; i++) {
					for (int j = 0; j < Image_Width; j++) {
						if (Color_Distance(this.Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50) {
							this.Draw_Square(j, i, 2, 2, cset.Red);
						}
					}
				}
			}
			else if (this.Image_Width*this.Image_Height > Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Source.Image_Height; i++) {
					for (int j = 0; j < Source.Image_Width; j++) {
						if (Color_Distance(this.Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50) {
							this.Draw_Square(j, i, 2, 2, cset.Red);
						}
					}
				}
			}
		}
	}
	public void Mark_Different_Pixels(Image Source, int Color_Treshold, int Distnace_Treshold, Pixel frame_color) {


		if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
			return;
		}
		
		ArrayList<Blob> Blobs = new ArrayList<Blob>();
		//Blob temp = new Blob(0, 0, Distnace_Treshold);
		boolean detected = false;

		for (int i = 0; i < this.Image_Width; i++)
		{ 
			for (int j = 0 ; j < this.Image_Height ; j++)
			{

				if (Color_Delta(this.Pixel_Matrix[j][i], Source.Pixel_Matrix[j][i]) > Color_Treshold)
				{
					for (int m = 0; m < Blobs.size(); ++m) {
						if (Blobs.get(m).Near(i, j)) {
							Blobs.get(m).add(i, j);
							detected = true;
							break;
						}

					}

					if (!detected) {
						//temp.SetProps(i, j);
						Blobs.add(new Blob(i,j,Distnace_Treshold));
					}
					detected = false;
			}
		}
		}

		
		
		for (int m = 0; m < Blobs.size(); ++m) {
			this.Draw_Square(Blobs.get(m).Upleft_Y, Blobs.get(m).Upleft_X, Blobs.get(m).Downright_Y, Blobs.get(m).Downright_X, frame_color, "Corners");
			//System.out.format("UL-x: %d UL-y: %d DR-x: %d DR-y: %d\n",Blobs.get(m).Upleft_X, Blobs.get(m).Upleft_Y, Blobs.get(m).Downright_X, Blobs.get(m).Downright_Y);
		}
		



	}
	public void Write_Pixel_Difference(Image Source, String mode, int min_diff) {

		if (mode.equals("Copy")) {
			if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
				return;
			}
			Image Temp = this;
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					if (Color_Distance(Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > min_diff) {
						Temp.Pixel_Matrix[i][j] = Source.Pixel_Matrix[i][j];
					}
				}
			}
			this.Write_Image("Pixel_Diffrence.jpg");
		}
		else {
			return;
		}
	}
	public void Mark_Different_Pixels(Image Source) {
		if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
			return;
		}
		Color_Palette cset =new Color_Palette();
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				if (this.Color_Distance(this.Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > 2) {
					this.Draw_Square(i, j, 2, 2, cset.Red);
				}
			}
		}


	}
	public void Mark_Different_Pixels(Image Source, String mode) {
	


		if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
			return;
		}
		Color_Palette cset =new Color_Palette();

		if (mode.equals("Strict")) {
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					if (Pixel_Matrix[i][j] != Source.Pixel_Matrix[i][j]) {
						this.Draw_Square(j, i, 2, 2, cset.Red);
					}
				}
			}
		}

	}
	public void Write_Channel_Row_Level_Graph() {
		int posR, PosG, PosB, H = 500, W = 1300;
		int bar_width = this.Image_Width / 300;
		if (bar_width == 0) {
			bar_width = 1;
		}
		int sR = 0, sG = 0, sB = 0;
		Image frame = new Image();
		Color_Palette CSET = new Color_Palette();
		frame.Load_Blank_Canvas(H, W, CSET.Azure);
		
		frame.Draw_Square(250, 250, 150, 150, CSET.Black);
		frame.Draw_Square(650, 250, 150, 150, CSET.Black);
		frame.Draw_Square(1050, 250, 150, 150, CSET.Black);
		frame.Draw_Square(250, 250, 151, 151, CSET.Black);
		frame.Draw_Square(650, 250, 151, 151, CSET.Black);
		frame.Draw_Square(1050, 250, 151, 151, CSET.Black);

		for (int i = 103; i <= 400; i += 5) {
			frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
		}
		for (int i = 103; i <= 400; i += 5) {
			frame.Draw_Line(i, 100, i, 400, CSET.Light_Gray);
		}

		for (int i = 503; i <= 800; i += 5) {
			frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
		}
		for (int i = 103; i <= 400; i += 5) {
			frame.Draw_Line(i, 500, i, 800, CSET.Light_Gray);
		}

		for (int i = 903; i <= 1200; i += 5) {
			frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
		}
		for (int i = 103; i <= 400; i += 5) {
			frame.Draw_Line(i, 900, i, 1200, CSET.Light_Gray);
		}

		frame.Draw_Text(90, 240, "RED GRAPH",CSET.Black);
		frame.Draw_Text(90, 640, "GREEN GRAPH",CSET.Black);
		frame.Draw_Text(90, 1040, "BLUE GRAPH",CSET.Black);


		posR = 101;
		PosG = 501;
		PosB = 901;

		

		for (int i = 0; i < this.Image_Width; i++) {
			for (int k = 0; k < bar_width; k++) {
				for (int j = 0; j < this.Image_Height; j++) {
					if (Pixel_Matrix[j][i].r >= Pixel_Matrix[j][i].g &&Pixel_Matrix[j][i].r >= Pixel_Matrix[j][i].b &&
							Pixel_Matrix[j][i] != CSET.Black
						&& Pixel_Matrix[j][i] != CSET.White) {
						
						sR++;
					}
					else if (Pixel_Matrix[j][i].g >= Pixel_Matrix[j][i].r &&Pixel_Matrix[j][i].g >= Pixel_Matrix[j][i].b
						&& Pixel_Matrix[j][i] != CSET.Black
						&&Pixel_Matrix[j][i] != CSET.White) {
						//sG += Pixel_Matrix[j][i].g;
						sG++;
					}
					else if (Pixel_Matrix[j][i].b >= Pixel_Matrix[j][i].r &&Pixel_Matrix[j][i].b >= Pixel_Matrix[j][i].g
						&& Pixel_Matrix[j][i] != CSET.Black
						&& Pixel_Matrix[j][i] != CSET.White) {
						//sB += Pixel_Matrix[j][i].b;
						sB++;
					}

				}
				if (bar_width > 1) {
					i++;
				}
			}

			sR /= bar_width;
			sG /= bar_width;
			sB /= bar_width;

			sR %= 300;
			sG %= 300;
			sB %= 300;

			
			if (posR < 399) {
				//frame.Draw_Line(posR, 399, 399 - sR, CSET.Red,bar_width);
				frame.Draw_Line(399, posR, 399 - sR, posR, CSET.Red,Math.max(1,bar_width/3));
			}
			if (PosG < 799) {
				//frame.Draw_Line(PosG, 399, 399 - sG, CSET.Green);
				frame.Draw_Line(399, PosG, 399 - sG, PosG, CSET.Green,Math.max(1,bar_width/3));

			}
			if (PosB < 1199) {
				//frame.Draw_Line(PosB, 399, 399 - sB, CSET.Blue);
				frame.Draw_Line(399, PosB, 399 - sB, PosB, CSET.Blue,Math.max(1,bar_width/3));

			}

			posR += bar_width;
			PosG += bar_width;
			PosB += bar_width;

			sR = sG = sB = 0;

		}



		frame.Write_Image("ChannelGraph.png");
	}
	public void Write_Channel(char color) {
		
		switch (color)
		{
		case 'R':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].g =0;
					Pixel_Matrix[i][j].b =0;

				}
			}
			break;
		case 'G':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].r =0;
					Pixel_Matrix[i][j].b =0;

				}
			}
			break;
		case 'B':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].g =0;
					Pixel_Matrix[i][j].r =0;

				}
			}
			break;
		default:
			break;
		}


	}
	public void Shutdown_Channel(char color) {
		
		switch (color)
		{
		case 'R':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					
					Pixel_Matrix[i][j].r = 0;
				}
			}
			break;
		case 'G':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {

					Pixel_Matrix[i][j].g = 0;

				}
			}
			break;
		case 'B':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {

					Pixel_Matrix[i][j].b = 0;
				}
			}
			break;
		default:
			break;
		}
	}
	public void Flip180() {
		Image temp = new Image();
		temp.Load_Blank_Canvas(this.Image_Height, this.Image_Width, new Pixel(0,0,0));
		int k=0,m=0;
		
		for (int i = Image_Height - 1; i >= 0; i--) {
			for (int j = Image_Width - 1; j >= 0; j--) {
				temp.Pixel_Matrix[k][m] = new Pixel(this.Pixel_Matrix[i][j]);
				m++;
			}
			
			k++;
			m=0;

		}

		for(int i=0;i<Image_Height;i++) {
			for(int j=0;j<Image_Width;j++) {
				this.Pixel_Matrix[i][j] = new Pixel(temp.Pixel_Matrix[i][j]);

			}
		}
	}
	public void Color_Flooring(String mode , int alter) {
	
		if (mode.equals("10")) {
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					this.Pixel_Matrix[i][j].r = (this.Pixel_Matrix[i][j].r / 10) * 10;
					this.Pixel_Matrix[i][j].g = (this.Pixel_Matrix[i][j].g / 10) * 10;
					this.Pixel_Matrix[i][j].b = (this.Pixel_Matrix[i][j].b / 10) * 10;

				}
			}



		}
		else if (mode.equals("100")) {

			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					this.Pixel_Matrix[i][j].r = (this.Pixel_Matrix[i][j].r / 100) * 100;
					this.Pixel_Matrix[i][j].g = (this.Pixel_Matrix[i][j].g / 100) * 100;
					this.Pixel_Matrix[i][j].b = (this.Pixel_Matrix[i][j].b / 100) * 100;

				}
			}

		}
		if(alter == 1) {
			this.Commint_Matrix_Changes();
		}
	}
	public void Thresholding(String mode, int value ,int alter) {
		
		if (mode.equals("Trunc")) {
		
			this.Color_Flooring("10",1);
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 1; j < Image_Width; j++) {
					if (Pixel_Matrix[i][j].r > value || Pixel_Matrix[i][j].g > value || Pixel_Matrix[i][j].b > value)
					{
						Pixel_Matrix[i][j].r = 255;
						Pixel_Matrix[i][j].g = 255;
						Pixel_Matrix[i][j].b = 255;



					}
					else {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;



					}

				}
			}
			
		}

		else if (mode.equals("EdgeTriggerd")) {
			Pixel prev = new Pixel();
			
			for (int i = 0; i < Image_Height; i++) {
				prev.r = Pixel_Matrix[i][0].r;
				prev.g = Pixel_Matrix[i][0].g;
				prev.b = Pixel_Matrix[i][0].b;

				Pixel_Matrix[i][0].r = 0;
				Pixel_Matrix[i][0].g = 0;
				Pixel_Matrix[i][0].b = 0;

				for (int j = 1; j < Image_Width; j++) {
					if (Color_Distance(prev, Pixel_Matrix[i][j]) > value)
					{
						Pixel_Matrix[i][j].r = 255;
						Pixel_Matrix[i][j].g = 255;
						Pixel_Matrix[i][j].b = 255;



					}
					else {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;



					}

				}
			}
			
		}
		if (alter == 1) {
			this.Commint_Matrix_Changes();
		}

	}
	public void Thresholding(int alter) {
		this.Grayscale(alter);
		//using otsus method
		int Histogram[] = new int[256];
		Arrays.fill(Histogram, 0);
		for(int i =0;i<this.Image_Height;i++) {
			for(int j =0;j<this.Image_Width;j++) {
				Histogram[this.Pixel_Matrix[i][j].r]++;
			}
		}
		int total = this.Image_Height*this.Image_Width;
		float sum = 0;
		for (int t=0 ; t<256 ; t++) sum += t * Histogram[t];
		float varMax = 0;
		int threshold = 0;
		float sumB = 0;
		int wB = 0;
		int wF = 0;
		for(int t = 0 ; t <256;t++) {
			  wB += Histogram[t];               // Weight Background
			   if (wB == 0) continue;

			   wF = total - wB;                 // Weight Foreground
			   if (wF == 0) break;

			   sumB += (float) (t * Histogram[t]);

			   float mB = sumB / wB;            // Mean Background
			   float mF = (sum - sumB) / wF;    // Mean Foreground

			   // Calculate Between Class Variance
			   float varBetween = (float)wB * (float)wF * (mB - mF) * (mB - mF);

			   // Check if new maximum found
			   if (varBetween > varMax) {
			      varMax = varBetween;
			      threshold = t;
			   }
		}
		
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j<this.Image_Width;j++) {
				if(this.Pixel_Matrix[i][j].r <= threshold) {
					this.Pixel_Matrix[i][j] = new Pixel(0,0,0);
					
				}else {
					this.Pixel_Matrix[i][j] = new Pixel(255,255,255);

				}
			}
		}
		
		
		if(alter == 1) {
		this.Commint_Matrix_Changes();
		}
		
	}
	public void Edge_Detection() {
		Pixel prev = new Pixel() ;

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			Pixel_Matrix[i][0].r = 0;
			Pixel_Matrix[i][0].g = 0;
			Pixel_Matrix[i][0].b = 0;

			for (int j = 1; j < Image_Width; j++) {
				if (Color_Distance(prev, Pixel_Matrix[i][j]) > 50)
				{
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j].r = 255;
					Pixel_Matrix[i][j].g = 255;
					Pixel_Matrix[i][j].b = 255;



				}
				else {
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;



				}

			}
		}
		

	}
	public void Edge_Detection(int max_color_gap) {
		
		Pixel prev = new Pixel() ;

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			Pixel_Matrix[i][0].r = 0;
			Pixel_Matrix[i][0].g = 0;
			Pixel_Matrix[i][0].b = 0;

			for (int j = 1; j < Image_Width; j++) {
				if (Color_Distance(prev, Pixel_Matrix[i][j]) > max_color_gap)
				{
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j].r = 255;
					Pixel_Matrix[i][j].g = 255;
					Pixel_Matrix[i][j].b = 255;



				}
				else {
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;



				}

			}
		}
	}
	public void Mark_Contour(Pixel Color,int max_color_gap) {
		Pixel prev = new Pixel();

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			for (int j = 1; j < Image_Width; j++) {
				if (Color_Distance(prev, Pixel_Matrix[i][j]) > max_color_gap)
				{
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j] = Color;



				}
				else {
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;



				}

			}
		}

		for (int i = 0; i < Image_Width; i++) {
			prev.r = Pixel_Matrix[0][i].r;
			prev.g = Pixel_Matrix[0][i].g;
			prev.b = Pixel_Matrix[0][i].b;

			for (int j = 1; j < Image_Height; j++) {
				if (Color_Distance(prev, Pixel_Matrix[j][i]) > max_color_gap)
				{
					prev.r = Pixel_Matrix[j][i].r;
					prev.g = Pixel_Matrix[j][i].g;
					prev.b = Pixel_Matrix[j][i].b;

					Pixel_Matrix[j][i] = Color;



				}
				else {
					prev.r = Pixel_Matrix[j][i].r;
					prev.g = Pixel_Matrix[j][i].g;
					prev.b = Pixel_Matrix[j][i].b;



				}

			}
		}

	}
	public void Feature_Matching(int source_x,int source_y) {
		if ((source_x + 1 > Image_Width) || (source_x - 1 < 0) || (source_y + 1 > Image_Height) || (source_y - 1 < 0)) {
			//out of image border;
			return;
		}
		Pixel up=new Pixel(), down=new Pixel(), left=new Pixel(), right=new Pixel(), center = new Pixel();
		Color_Palette cset = new Color_Palette();
		int band = 5;
		center.r = Pixel_Matrix[source_y][source_x].r;
		center.g = Pixel_Matrix[source_y][source_x].g;
		center.b = Pixel_Matrix[source_y][source_x].b;

		up.r = Pixel_Matrix[source_y - 1][source_x].r;
		up.g = Pixel_Matrix[source_y - 1][source_x].g;
		up.b = Pixel_Matrix[source_y - 1][source_x].b;

		down.r = Pixel_Matrix[source_y + 1][source_x].r;
		down.g = Pixel_Matrix[source_y + 1][source_x].g;
		down.b = Pixel_Matrix[source_y + 1][source_x].b;

		left.r = Pixel_Matrix[source_y][source_x - 1].r;
		left.g = Pixel_Matrix[source_y][source_x - 1].g;
		left.b = Pixel_Matrix[source_y][source_x - 1].b;

		right.r = Pixel_Matrix[source_y][source_x + 1].r;
		right.g = Pixel_Matrix[source_y][source_x + 1].g;
		right.b = Pixel_Matrix[source_y][source_x + 1].b;

		Draw_Circle(source_x, source_y, 3, cset.Red);
		Draw_Circle(source_x, source_y, 2, cset.Blue);


		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				if (i + 1 < Image_Height && i - 1 > 0 && j + 1 < Image_Width && j - 1 > 0) {
					if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], down) < band &&Color_Distance(Pixel_Matrix[i - 1][j], up) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], right) < band &&Color_Distance(Pixel_Matrix[i][j - 1], left) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);
					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
				}
			}
		}



	}
	public void Quarantine_Pixel(Pixel sample,double max_difference,String mode) {

		if (mode.equals("Keep_Self")) {
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					if (Color_DistanceSq(Pixel_Matrix[i][j], sample) > max_difference) {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;

					}
				}
			}

		}
		else if (mode.equals("Drop_Self")) {
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					if (Color_DistanceSq(Pixel_Matrix[i][j], sample) < max_difference) {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;

					}
				}
			}
			
		}
	}
	public void Kronecker_product(Image b, String mode,int Alter) {
		
		if (mode.equals("Mul")) {
			Pixel[][] Kr_mat = new Pixel[b.Image_Height*this.Image_Height][this.Image_Width*b.Image_Width];
			BufferedImage Kronecker =  new BufferedImage(this.Image_Width*b.Image_Width,b.Image_Height*this.Image_Height,BufferedImage.TYPE_3BYTE_BGR);
		    long startRow=0, startCol=0;
			Pixel temp = new Pixel();
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
							temp = this.Pixel_Matrix[i][j].Pixel_Mul(b.Pixel_Matrix[k][l]);
							Kr_mat[(int)startRow + k][(int)startCol + l] = temp;

						}
					}
				}
			}

			if (Alter == 1) {
				this.Image_Width *= b.Image_Width;
				this.Image_Height *= b.Image_Height;
				this.Pixel_Matrix = Kr_mat;
				this.IMG = Kronecker;

			}


		}
		else if (mode.equals("Size")) {
			Pixel[][] Kr_mat = new Pixel[b.Image_Height*this.Image_Height][this.Image_Width*b.Image_Width];
			BufferedImage Kronecker =  new BufferedImage(this.Image_Width*b.Image_Width,b.Image_Height*this.Image_Height,BufferedImage.TYPE_3BYTE_BGR);
			
			Pixel temp = new Pixel();
			int startRow =0 , startCol= 0;
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
							if (this.Pixel_Matrix[i][j].is_Bigger(b.Pixel_Matrix[k][l])) {
								temp = this.Pixel_Matrix[i][j];
							}
							else {
								temp = b.Pixel_Matrix[k][l];
							}

							Kr_mat[startRow + k][startCol + l] = temp;

						}
					}
				}
			}

			if (Alter == 1) {
				this.Image_Width *= b.Image_Width;
				this.Image_Height *= b.Image_Height;
				this.Pixel_Matrix = Kr_mat;
				this.IMG = Kronecker;
			}
		}
		else if (mode.equals("Build_From")) {
			Pixel[][] Kr_mat = new Pixel[b.Image_Height*this.Image_Height][this.Image_Width*b.Image_Width];
			BufferedImage Kronecker =  new BufferedImage(this.Image_Width*b.Image_Width,b.Image_Height*this.Image_Height,BufferedImage.TYPE_3BYTE_BGR);
			
			Pixel temp = new Pixel();
			int startRow =0 , startCol= 0;
			int flag = 0;
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
							if (flag == 0) {
								temp = this.Pixel_Matrix[i][j];
								flag = 1;
							}
							else {
								temp = b.Pixel_Matrix[k][l];
								flag = 0;
							}

							Kr_mat[startRow + k][startCol + l] = temp;

						}
					}
				}
			}

			if (Alter == 1) {
				this.Image_Width *= b.Image_Width;
				this.Image_Height *= b.Image_Height;
				this.Pixel_Matrix = Kr_mat;
				this.IMG = Kronecker;

			}
		}
		else if (mode.equals("Mix")) {

			Pixel[][] Kr_mat = new Pixel[b.Image_Height*this.Image_Height][this.Image_Width*b.Image_Width];
			BufferedImage Kronecker =  new BufferedImage(this.Image_Width*b.Image_Width,b.Image_Height*this.Image_Height,BufferedImage.TYPE_3BYTE_BGR);
			
			Pixel temp = new Pixel();
			int startRow =0 , startCol= 0,flag =0;


			for (int i = 0; i < this.Image_Height; i++) {

				for (int j = 0; j < this.Image_Width; j++)
				{
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++)
					{
						if (flag == 1) {
							temp = this.Pixel_Matrix[i][j];
						}
						else if (flag == 0) {
							temp = b.Pixel_Matrix[i][j];
						}

						for (int l = 0; l < b.Image_Width; l++)
						{

							Kr_mat[startRow + k][startCol + l] = temp;
						}
						if (flag == 1) {
							flag = 0;
						}
						else {
							flag = 1;
						}
					}


				}

			}

			if (Alter == 1) {
				this.Image_Width *= b.Image_Width;
				this.Image_Height *= b.Image_Height;
				this.Pixel_Matrix = Kr_mat;
				this.IMG = Kronecker;
			}
		}


	}
	public void Image_Transpose() {
		int H = this.Image_Width, W = this.Image_Height;
		Pixel[][] tmat = new Pixel[H][W];
		for (int i = 0; i < this.Image_Height; i++) {
			for (int j = 0; j < this.Image_Width; j++) {
				tmat[j][i] = this.Pixel_Matrix[i][j];
			}
		}

		this.Pixel_Matrix = tmat;


	}
	public double Pixel_Dataframe_Difference(Pixel Pix, Point DF_point) {
		double distance;
		distance = ((DF_point.x - Pix.r)*(DF_point.x - Pix.r) + (DF_point.y - Pix.g)*(DF_point.y - Pix.g) + (DF_point.z - Pix.b)*(DF_point.z - Pix.b));
		return Math.sqrt(distance);
	}
	private ArrayList<Point> K_Means(ArrayList<Point> data, int k, int number_of_iterations) {
		Random random_machine = new Random();
		
		ArrayList<Point> means = new ArrayList<Point>(k);
		for(int i = 0 ; i<k;i++) {
			means.add(new Point());
		}
		
		
		for(int cluster =0 ;cluster < means.size();cluster++) {
			means.set(cluster, data.get(random_machine.nextInt(data.size())));
		}

		ArrayList<Integer> assignments = new ArrayList<Integer>(data.size());
		for(int i=0;i<data.size();i++) {
			assignments.add(0);
		}

		for (int iteration = 0; iteration < number_of_iterations; ++iteration) {
			// Find assignments.
			for (int point = 0; point < data.size(); ++point) {
				double best_distance = Double.MAX_VALUE;
				int best_cluster = 0;
				for (int cluster = 0; cluster < k; ++cluster) {
					double distance = squared_3Point_distance(data.get(point), means.get(cluster));
					if (distance < best_distance) {
						best_distance = distance;
						best_cluster = cluster;
					}
				}
				assignments.set(point, best_cluster);

			}

			// Sum up and count points for each cluster.
			ArrayList<Point> new_means = new ArrayList<Point>(k);
			for(int i = 0 ; i <k ; i++) {
				new_means.add(new Point());
			}
			ArrayList<Integer> counts = new ArrayList<>(k);
			for(int i=0;i<k;i++) {
				counts.add(0);
			}
		

			for (int point = 0; point < data.size(); ++point) {
				int cluster = assignments.get(point);
				double x,y,z;
				Point temp = new Point();
				x = new_means.get(cluster).x + data.get(point).x;
				y = new_means.get(cluster).y + data.get(point).y;
				z = new_means.get(cluster).z + data.get(point).z;
				temp.x=x;
				temp.y=y;
				temp.z=z;
				//System.out.println("Iter: "+iteration  + " temp: " + temp );

				new_means.set(cluster, temp);
				int c = counts.get(cluster);
				c++;
				counts.set(cluster, c);
			}

			// Divide sums by counts to get new centroids.
			for (int cluster = 0; cluster < k; ++cluster) {
				// Turn 0/0 into 0/1 to avoid zero division.
				int count = Math.max(1, counts.get(cluster));
				Point temp = new Point();
				temp.x = new_means.get(cluster).x / count;
				temp.y = new_means.get(cluster).y / count;
				temp.z = new_means.get(cluster).z / count;
				//System.out.println(temp);
				means.set(cluster, temp);
			
			}
		}

		return means;

		
		
		
	}
	public void Image_Segmentation(int k, int iterations) {
		
		ArrayList<Point> image_ThreeD_Mat = new ArrayList<Point>();
		ArrayList<Point> Result = new ArrayList<Point>();
	
		for(int i=0;i<Image_Height;i++) {
			for(int j=0;j<Image_Width;j++) {
				image_ThreeD_Mat.add(new Point(this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,
						this.Pixel_Matrix[i][j].b));
			}
		}

		Result = this.K_Means(image_ThreeD_Mat, k, iterations);


		double best_dist;
		Point temp = new Point();

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				best_dist = Double.MAX_VALUE;
				
				for(int m = 0 ;m < Result.size();m++) {
					if (Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Result.get(m)) < best_dist) {
						best_dist = Pixel_Dataframe_Difference(Pixel_Matrix[i][j],  Result.get(m));
						temp =  Result.get(m);
					}
				}
				
				Pixel_Matrix[i][j].r = (int)temp.x;
				Pixel_Matrix[i][j].g = (int)temp.y;
				Pixel_Matrix[i][j].b = (int)temp.z;

			}
		}






	}
	private void Blob_Framing(int distance_treshold, Pixel frame_color) {
		Color_Palette CSET = new Color_Palette();
		ArrayList<Blob> Blobs = new ArrayList<Blob>();

		Blob temp = new Blob(0, 0, distance_treshold);
		boolean detected = false;
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < this.Image_Width; j++) {

				if (this.Pixel_Matrix[i][j].analysis == 42) {
				
					for (int k = 0; k < (int)Blobs.size(); ++k) {
						if (Blobs.get(k).Near(i, j) == true) {
							Blobs.get(k).add(i, j);
							detected = true;

							break;

						}

					}

					if (detected == false) {
						temp.SetProps(i, j);
						Blobs.add(new Blob(temp));
					}
					
					detected = false;

				}
			}
		}

		for (int k = 0; k < (int)Blobs.size(); k++) {
			if (Blobs.get(k).Size() < distance_treshold) {

				Blobs.remove(k);
			}

		}

		for (int k = 0; k < (int)Blobs.size(); ++k) {

			Draw_Square(Blobs.get(k).Downright_X, Blobs.get(k).Downright_Y, Blobs.get(k).Upleft_X, Blobs.get(k).Upleft_Y, frame_color, "Corners");
			//Pixel_Matrix[Blobs.get(k).Upleft_X][Blobs.get(k).Upleft_Y] = new Pixel(CSET.Yellow);
			//Pixel_Matrix[Blobs.get(k).Downright_X][Blobs.get(k).Downright_Y] = new Pixel(CSET.Green);



		}
	}
	public void Figure_Detection(int blob_distance_treshold, int color_distance_treshold, int Thresholding_level) {

		this.Thresholding("Trunc",Thresholding_level,0);
		
		int[][] adj_matrix = new int[Image_Height][Image_Width];
		int color_treshold = color_distance_treshold;
		Color_Palette C = new Color_Palette();
		for (int i = 0; i < this.Image_Height; i++) {
			for(int j=0;j<Image_Width;j++) {
				adj_matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < this.Image_Height; i++) {
			for (int j = 0; j < this.Image_Width-1; j++) {
				if (Color_Delta(Pixel_Matrix[i][j], Pixel_Matrix[i][j + 1]) > color_treshold) {
					adj_matrix[i][j] = 1;


				}
			}
		}


		for (int i = 0; i < this.Image_Height; i++) {
			for (int j = 0; j < this.Image_Width; j++) {
				if (adj_matrix[i][j] == 1) {
					Pixel_Matrix[i][j].analysis = 42;
				}
			}
		}
		
		this.Blob_Framing(blob_distance_treshold, C.Red);
		this.Update_Pixel_Matrix();
	}
	public void Write_Average_Color_Palette(int palette_size) {
		int H, W, lx;
		Color_Palette CSET =new Color_Palette();
		Pixel palette_sample = new Pixel();
		ArrayList<Point> imData = new ArrayList<Point>(), Means = new ArrayList<Point>();
		Image palette_image = new Image();
		
		
		
		for(int i =0;i<Image_Height;i++) {
			for(int j =0 ;j<Image_Width;j++) {
				imData.add(new Point(this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,this.Pixel_Matrix[i][j].b));
			}
		}
		
		
		Means = K_Means(imData, palette_size, 200);
		H = 200;
		W = 200 * palette_size;
		palette_image.Load_Blank_Canvas(H, W, CSET.Black);
		lx = 0;

		for (int m = 0 ; m<Means.size();m++) {
			palette_sample.r = (int)Means.get(m).x;
			palette_sample.g = (int)Means.get(m).y;
			palette_sample.b = (int)Means.get(m).z;
			
			  for (int j = 0; j < 199; j++) {
				  palette_image.Draw_Line(j,lx,j,lx + 199,palette_sample);
			  
			  
			  }
			 

			lx += 199;
		}

		palette_image.Write_Image(palette_size + " Bit Palette.png");

	}
	public void Pixel_Griding() {
		double sigma = 1.0;
		double r, s = 2.0 * sigma * sigma;
		double GKernel[][] = new double[5][5];
		double sum = 0.0;
		for (int x = -2; x <= 2; x++) {
			for (int y = -2; y <= 2; y++) {
				r = Math.sqrt(x * x + y * y);
				GKernel[x + 2][y + 2] = (Math.exp(-(r * r) / s)) / (Math.PI * s);
				sum += GKernel[x + 2][y + 2];
			}
		}

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				GKernel[i][j] /= sum;
			}
		}


		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				Pixel_Matrix[i][j].r += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].r;
				Pixel_Matrix[i][j].g += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].g;
				Pixel_Matrix[i][j].b += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].b;

			}
		}



	}
	public ArrayList<Point> Get_Average_Color_Palette(int palette_size,int number_of_iterations) {
		ArrayList<Point> imData = new ArrayList<Point>();

		for(int i =0;i<Image_Height;i++) {
			for(int j =0 ;j<Image_Width;j++) {
				imData.add(new Point(this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,this.Pixel_Matrix[i][j].b));
			}
		}
		

		return this.K_Means(imData, palette_size, number_of_iterations);

	}

	public	void Set_Colors_Using_Average_Palette(ArrayList<Point> Average_Colors) {
		double best_dist;
		Point temp = new Point();

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				best_dist = Double.MAX_VALUE;
			
				
				for(int m = 0 ; m <Average_Colors.size();m++) {
					if (Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Average_Colors.get(m)) < best_dist) {
						best_dist = Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Average_Colors.get(m));
						temp.x = Average_Colors.get(m).x;
						temp.y = Average_Colors.get(m).y;
						temp.z = Average_Colors.get(m).z;

					}
				}
				
				Pixel_Matrix[i][j] = new Pixel((int)temp.x,(int)temp.y,(int)temp.z);
			

			}
			
			
			
		}




	}
	public ArrayList<Pixel> Get_Line_Pixels(int start_y,int start_x,int target_y,int target_x) {
		double dx, sx, dy, sy, err, e2;

		ArrayList<Pixel> Points = new ArrayList<Pixel>();
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)(Math.abs(target_y - start_y));
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-Math.abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
				Points.add(new Pixel(Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].r,Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].g,
						Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].b,(int)Math.floor(x0),(int)Math.floor(x0)));
				break;
			}

			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.add(new Pixel(Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].r,Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].g,
					Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].b,(int)Math.floor(x0),(int)Math.floor(x0)));
			
			e2 = 2 * err;
			if (e2 >= dy) {
				err += dy;
				x0 += sx;
			}
			if (e2 <= dx) {
				err += dx;
				y0 += sy;
			}

		}



		return Points;
	}
	public void Register_PixelFrame(ArrayList<Pixel> Frame) {
		Pixel color= new Pixel();
		for(int i =0;i< Frame.size();i++) {
			color.r = Frame.get(i).r;
			color.g = Frame.get(i).g;
			color.b = Frame.get(i).b;
			this.Pixel_Matrix[Frame.get(i).i][Frame.get(i).j] = new Pixel(color.r,color.g,color.b);
		}
	}
	public Pixel Dominant_Color_Via_Line(int start_y,int start_x,int target_y,int target_x) {
		double dx, sx, dy, sy, err, e2;
		Pixel Dom_Color = new Pixel();
		ArrayList<Point> Points = new ArrayList<Point>();
		ArrayList<Point> Res = new ArrayList<Point>();
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)Math.abs(target_y - start_y);
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-Math.abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
				Points.add(new Point(Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].r,Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].g,
						Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].b));
				
				break;
			}

			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.add(new Point(Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].r,Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].g,
					Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].b));
			e2 = 2 * err;
			if (e2 >= dy) {
				err += dy;
				x0 += sx;
			}
			if (e2 <= dx) {
				err += dx;
				y0 += sy;
			}

		}

		Res = K_Means(Points, 1, 100);
		Dom_Color.r = (int)Res.get(0).x;
		Dom_Color.g = (int)Res.get(0).y;
		Dom_Color.b = (int)Res.get(0).z;

		return Dom_Color;
	}
	public void Image_Rebuild_With_Lines(int Iterations) {
	
		Random x0_picks = new Random();
		Random x1_picks = new Random();
		Random y0_picks = new Random();
		Random y1_picks = new Random();
		
		Color_Palette CSET = new Color_Palette();
		Pixel dominant_color = new Pixel();
		ArrayList<Pixel> Line = new ArrayList<Pixel>();
		Image B = new Image(), C = new Image();
		B.Load_Blank_Canvas(this.Image_Height,this.Image_Width, CSET.Black);
		C.Load_Blank_Canvas(this.Image_Height,this.Image_Width, CSET.Black);

/*	#ifdef Line_StepByStep



		std::stringstream ss;
		std::string via;
		int counter = 0;

	#endif
*/
		int x0, y0, x1, y1;
		double cur_difference, temp_dif;

		cur_difference = this.Image_Difference_Value(B);

		for (int i = 0; i < Iterations; i++) {
			//Runtime.getRuntime().gc();
				
				  x0 = x0_picks.nextInt(Math.abs(Image_Width)); 
				  y0 = y0_picks.nextInt(Math.abs(Image_Height)); 
				  x1 = x1_picks.nextInt(Image_Width);
				  y1 = y1_picks.nextInt(Image_Height);
				 
			//System.out.println("Iter: " + i + " W/H: "+Image_Width +"/ "+Image_Height );
			
			/*
			 * x0 = (int)((double)(Image_Width-1) * Math.random()); y0 =
			 * (int)((double)(Image_Height-1) * Math.random()); x1 =
			 * (int)((double)(Image_Width-1) * Math.random()); y1 =
			 * (int)((double)(Image_Height-1) * Math.random());
			 */
			
			dominant_color = this.Dominant_Color_Via_Line(y0, x0, y1, x1);
			Line = B.Get_Line_Pixels(y0, x0, y1, x1);
			B.Draw_Line(y0, x0, y1, x1, dominant_color);


			temp_dif = this.Image_Difference_Value(B);

			if (temp_dif < cur_difference) {
				C.Draw_Line(y0, x0, y1, x1, dominant_color);
/*	#ifdef Line_StepByStep
				ss << counter;
				via = ss.str();
				if ((counter + 1) % 40 == 0) {
					C.Write_Image(via.c_str());

				}
				ss.str(std::string());
				counter++;


	#endif // Line_StepByStep
*/
				cur_difference = temp_dif;
				

			}
			else {
				B.Register_PixelFrame(Line);
				Line.clear();
				
			}


		}

		C.Write_Image("Build_From_Random_Lines.png");



	}

	public ArrayList<Point> GetCoordinateFrame(int start_y,int start_x,int target_y,int target_x) {
		double dx, sx, dy, sy, err, e2;
		
		ArrayList<Point> Points = new ArrayList<Point>();
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)(Math.abs(target_y - start_y));
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-Math.abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				Points.add(new Point((int)x0,(int)y0 ,0));
				break;
			}

			Points.add(new Point((int)x0,(int)y0 ,0));

			e2 = 2 * err;
			if (e2 >= dy) {
				err += dy;
				x0 += sx;
			}
			if (e2 <= dx) {
				err += dx;
				y0 += sy;
			}

		}



		return Points;
	}
	public void Up_Scale() {

		//BufferedImage scaled = new BufferedImage(this.Image_Width * 3,	this.Image_Height * 3,BufferedImage.TYPE_3BYTE_BGR);
		
		
		Image scaled = new Image();
		int p=0,z=0;
		scaled.Load_Blank_Canvas((Image_Height*3), (Image_Width*3), new Pixel(0,0,0));
		for(int i=0;i<scaled.Image_Height;i+=3) {
			for(int j =0 ; j <scaled.Image_Width;j+=3) {
				for(int k =0 ;k<3;k++) {
					for(int m = 0 ; m<3;m++) {
						scaled.Pixel_Matrix[i+k][j+m] = new Pixel(this.Pixel_Matrix[p][z]);
					}
				}
				z++;
			}
			p++;
			z=0;
		}
		



		//quality enchancment


		for (int i = 0; i < this.Image_Height - 3; i += 3) {
			for (int j = 0; j < this.Image_Width - 3; j += 3) {

				if (j < 3) {
					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + k][j + 2].r = (scaled.Pixel_Matrix[i + k][j + 2].r + scaled.Pixel_Matrix[i + k][j + 3].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].g = (scaled.Pixel_Matrix[i + k][j + 2].g + scaled.Pixel_Matrix[i + k][j + 3].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].b = (scaled.Pixel_Matrix[i + k][j + 2].b + scaled.Pixel_Matrix[i + k][j + 3].b) / 2;
					}

					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + 2][j + k].r = (scaled.Pixel_Matrix[i + 2][j + k].r + scaled.Pixel_Matrix[i + 3][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].g = (scaled.Pixel_Matrix[i + 2][j + k].g + scaled.Pixel_Matrix[i + 3][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].b = (scaled.Pixel_Matrix[i + 2][j + k].b + scaled.Pixel_Matrix[i + 3][j + k].b) / 2;

					}
				}

				else {

					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + k][j + 2].r = (scaled.Pixel_Matrix[i + k][j + 2].r + scaled.Pixel_Matrix[i + k][j + 3].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].g = (scaled.Pixel_Matrix[i + k][j + 2].g + scaled.Pixel_Matrix[i + k][j + 3].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].b = (scaled.Pixel_Matrix[i + k][j + 2].b + scaled.Pixel_Matrix[i + k][j + 3].b) / 2;

						scaled.Pixel_Matrix[i + k][j + 3].r = (scaled.Pixel_Matrix[i + k][j + 3].r + scaled.Pixel_Matrix[i + k][j + 2].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 3].g = (scaled.Pixel_Matrix[i + k][j + 3].g + scaled.Pixel_Matrix[i + k][j + 2].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 3].b = (scaled.Pixel_Matrix[i + k][j + 3].b + scaled.Pixel_Matrix[i + k][j + 2].b) / 2;

					}


					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + 2][j + k].r = (scaled.Pixel_Matrix[i + 2][j + k].r + scaled.Pixel_Matrix[i + 3][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].g = (scaled.Pixel_Matrix[i + 2][j + k].g + scaled.Pixel_Matrix[i + 3][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].b = (scaled.Pixel_Matrix[i + 2][j + k].b + scaled.Pixel_Matrix[i + 3][j + k].b) / 2;


						scaled.Pixel_Matrix[i + 3][j + k].r = (scaled.Pixel_Matrix[i + 3][j + k].r + scaled.Pixel_Matrix[i + 2][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 3][j + k].g = (scaled.Pixel_Matrix[i + 3][j + k].g + scaled.Pixel_Matrix[i + 2][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 3][j + k].b = (scaled.Pixel_Matrix[i + 3][j + k].b + scaled.Pixel_Matrix[i + 2][j + k].b) / 2;
					}

				}


			}
		}
		this.Pixel_Matrix = scaled.Pixel_Matrix;
		this.IMG=scaled.IMG;
		this.Image_Height *=3;
		this.Image_Width*=3;

	}
	public void Set_Scale(int Height ,int Width) {
	    BufferedImage bi = new BufferedImage(Width, Height, this.IMG.getTransparency() == Transparency.OPAQUE ? BufferedImage.TYPE_INT_RGB : BufferedImage.TYPE_INT_ARGB);
	    Graphics2D g2d = bi.createGraphics();
	    g2d.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BILINEAR); //produces a balanced resizing (fast and decent quality)
	    g2d.drawImage(this.IMG, 0, 0, Width, Height, null);
	    g2d.dispose();
	    this.IMG =bi;
	    this.Image_Height =  Height;
	    this.Image_Width = Width;
	    this.init_pixel_matrix();
	}
	public void Detect_Faces() {
		short flag = 0;
		Color_Palette CSET = new Color_Palette();
		int distance = 0 ,min_d = 355, skin_thresh = 15, grap_thresh = 60;
		float treshold = 45;
		int validation_level = 0;
		int n_valid_bounty = 10;
		Point left_eye = new Point(), right_eye= new Point();
		left_eye.x = right_eye.x = 0;
		left_eye.y = right_eye.y = 0;
		Pixel black = new Pixel();
		Pixel skin_graph= new Pixel(), nose_graph= new Pixel(), forhead_graph = new Pixel(), chin_graph = new Pixel();
		black.r = black.g = black.b = 0;

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				if (flag == 0) {
					if (Pixel_Matrix[i][j].r < treshold  && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold) {
						left_eye.x = j;
						left_eye.y = i;
						flag = 1;
	//#ifdef FaceDebug	



						Draw_Circle(j, i, 3, CSET.Green); //detected eye loctaion -left eye-

	//#endif
					}
				}
				else if (flag == 1) {
					if (distance > Image_Width / 3) {
						break;
					}
					else if (Pixel_Matrix[i][j].r < treshold && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold && distance > 30) {
						right_eye.x = j;
						right_eye.y = i;
						flag = 2;
						//i += 4;
	//#ifdef FaceDebug


						Draw_Circle(j, i, 3, CSET.Red); //detected eye location -right eye
						Draw_Circle((int)left_eye.x, (int)left_eye.y, 3, CSET.Green); //detected eye location -right eye
	//#endif


						//defenition of skin graphs for validation sequance
						skin_graph = Pixel_Matrix[(int)(left_eye.y)][(int)(left_eye.x) + (distance / 2)];
						if ((left_eye.y) + (distance / 2) < Image_Height && (left_eye.x) + (distance / 2) < Image_Width) {
							nose_graph = Pixel_Matrix[(int)(left_eye.y) + (distance / 2)][(int)(left_eye.x) + (distance / 2)];
						}
						if (left_eye.y - (distance / 4) > 0) {
							forhead_graph = Pixel_Matrix[(int)(left_eye.y - (distance / 4))][(int)(left_eye.x) + (distance / 2)];
						}
						if (left_eye.y + 1.3*distance < Image_Height) {
							int temp = (int)1.3*distance;
							chin_graph = Pixel_Matrix[(int)(left_eye.y + (temp))][(int)(left_eye.x) + (distance / 2)];
						}
						//

						//in case skin graph is black -> most likely not a skin color
						if (Color_Distance(black, skin_graph) < 30) {
							flag = 0;
							break;
						}
					}
					distance++;
				}

			}
			if (flag == 2 && distance > 50 && left_eye.x + (distance / 2) < Image_Width &&
				left_eye.y + (distance / 2) < Image_Height &&Color_Distance(Pixel_Matrix[(int)(left_eye.y) + (distance / 2)][(int)(left_eye.x) + (distance / 2)], black) > min_d) {


				skin_graph = Pixel_Matrix[(int)(left_eye.y)][(int)(left_eye.x) + (distance / 2)];

				if (skin_graph.r < 120 && skin_graph.g < 120 && skin_graph.b < 120) {
					continue;
				}






	//#ifdef FaceDebug

				Draw_Circle((int)(left_eye.x) + (distance / 2), (int)(left_eye.y), 3, CSET.Blue); //sking graph location
				Draw_Circle((int)(left_eye.x) + (distance / 2), (int)(left_eye.y), 4, CSET.Red); //sking graph location
				Draw_Circle((int)(left_eye.x) + (distance / 2), (int)(left_eye.y), 2, CSET.Green); //sking graph location

				Draw_Line((int)left_eye.y, (int)left_eye.x, (int)left_eye.y, (int)left_eye.x + distance / 2, CSET.Black); // line to cetner point 
	//#endif
				if (Color_Distance(skin_graph, Pixel_Matrix[(int)left_eye.y + distance / 2][(int)left_eye.x]) < grap_thresh) {

					if (Color_Distance(skin_graph, Pixel_Matrix[(int)left_eye.y + distance / 2][(int)left_eye.x]) < skin_thresh) { // left chick cmp

						validation_level++; //level 1

						if (Distance_Neighbors(treshold, (int)left_eye.y + distance / 2, (int)left_eye.x)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated --Neighbor-- left chick: " + validation_level);

						}
	//#ifdef FaceDebug
						Draw_Circle((int)(left_eye.x), (int)(left_eye.y) + (distance / 2), 3, CSET.White); //chick graph location -left eye-
						Draw_Line((int)left_eye.y, (int)left_eye.x, (int)left_eye.y + distance / 2, (int)left_eye.x, CSET.White); // line to chick point -left eye-
						System.out.println("Validated left chick: " + validation_level);
	//#endif // FaceDebug


					}

					if (Color_Distance(skin_graph, Pixel_Matrix[(int)right_eye.y + distance / 2][(int)right_eye.x]) < skin_thresh) {//right chick
						validation_level++; //level 2
						System.out.println("Validated Right chick: " + validation_level);

						if (Distance_Neighbors(treshold, (int)right_eye.y + distance / 2, (int)right_eye.x)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated  --Neighbor-- right chick: " + validation_level);

						}

					}



					if (Color_Distance(skin_graph, forhead_graph) < grap_thresh) { //forhead vs skin center cmp
	//#ifdef FaceDebug
						Draw_Circle((int)left_eye.x + distance / 2, (int)left_eye.y - (distance / 4), 3, CSET.White); //at forhead
						Draw_Line((int)left_eye.y, (int)left_eye.x + distance / 2, (int)left_eye.y - (distance / 4), (int)left_eye.x + distance / 2, CSET.White);

	//#endif
						validation_level++; //level 3
						System.out.println("Validated Forhead - Center: " + validation_level );

						if (Distance_Neighbors(treshold, (int)left_eye.y - (distance / 4), (int)left_eye.x + distance / 2)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated  --Neighbor-- Forhead - Center: "+validation_level);

						}

					}





					if (Color_Distance(nose_graph, skin_graph) < grap_thresh) {//nose vs middle face cmp
	//#ifdef FaceDebug
						Draw_Circle((int)left_eye.x + distance / 2, (int)left_eye.y + distance / 2, 3, CSET.White);
						//Draw_Line(left_eye.x + distance / 2, left_eye.y, left_eye.x + distance / 2, left_eye.y + (distance / 2), 'W');

	//#endif
						validation_level++; //level 4
						System.out.println("Validated Nose - Center: " + validation_level );

						if (Distance_Neighbors(treshold, (int)left_eye.y + distance / 2, (int)left_eye.x + distance / 2)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated  --Neighbor-- Nose - Center: " + validation_level);

						}
					}


					if (Color_Distance(chin_graph, skin_graph) < grap_thresh) {//chin vs middle face cmp
	//#ifdef FaceDebug
						Draw_Circle((int)left_eye.x + distance / 2, (int)(left_eye.y + 1.3*distance), 3, CSET.White);
						Draw_Line((int)left_eye.y, (int)left_eye.x + distance / 2, (int)(left_eye.y + 1.3*(distance)), (int)left_eye.x + distance / 2, CSET.White);

	//#endif
						validation_level++; //level 5
						System.out.println("Validated Chin - Center: " + validation_level);

						if (Distance_Neighbors(treshold, (int)left_eye.y + (int)(1.3*distance), (int)left_eye.x + distance / 2)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated  --Neighbor-- Chin - Center: " + validation_level);

						}
					}





	//#ifdef FaceDebug




					//right eye validate for v2 yet to be added to calculation
					Draw_Line((int)right_eye.y, (int)right_eye.x, (int)right_eye.y, (int)right_eye.x - distance / 2, CSET.Black); // line to cetner point from -right eye-
					Draw_Circle((int)(right_eye.x), (int)(right_eye.y) + (distance / 2), 3, CSET.White); //chick graph location -right eye- 
					Draw_Line((int)right_eye.y, (int)right_eye.x, (int)right_eye.y + distance / 2, (int)right_eye.x, CSET.White); // line to chick point -right eye-

	//#endif

					if (validation_level >= 30) {
						Draw_Square((int)left_eye.x + distance / 2, (int)left_eye.y + distance / 2, distance, distance, CSET.Red);
						i += 4;
						validation_level = 0;
					}

				}

				flag = 0;
				distance = 0;
			}
			else {
				flag = 0;
				distance = 0;
			}

		}

		
		
		
		
		
		
	}
	public int[] Get_Red_Histogram() {
		int Rh[] = new int[256];
		Arrays.fill(Rh, 0);
		for(int i = 0;i<this.Image_Height;i++) {
			for(int j = 0 ; j<this.Image_Width;j++) {
				Rh[this.Pixel_Matrix[i][j].r]++;
			}
		}
		return Rh;
	}
	public int[] Get_Green_Histogram() {
		int Rh[] = new int[256];
		Arrays.fill(Rh, 0);
		for(int i = 0;i<this.Image_Height;i++) {
			for(int j = 0 ; j<this.Image_Width;j++) {
				Rh[this.Pixel_Matrix[i][j].g]++;
			}
		}
		return Rh;
	}
	public int[] Get_Blue_Histogram() {
		int Rh[] = new int[256];
		Arrays.fill(Rh, 0);
		for(int i = 0;i<this.Image_Height;i++) {
			for(int j = 0 ; j<this.Image_Width;j++) {
				Rh[this.Pixel_Matrix[i][j].b]++;
			}
		}
		return Rh;
	}

	public void Histogram_Equalization() {
		int xxR[] = new int[256];
		int xxG[] = new int[256];
		int xxB[] = new int[256];
		double xxRProp[] = new double[256];
		double xxGProp[] = new double[256];
		double xxBProp[] = new double[256];
		
		double xxRCP[] = new double[256];
		double xxGCP[] = new double[256];
		double xxBCP[] = new double[256];
		
		//double xxBytag[] = new double[256];
		Arrays.fill(xxR, 0);
		Arrays.fill(xxG, 0);
		Arrays.fill(xxB, 0);
		
		int max_y = this.Image_Height*this.Image_Width;
		for(int i =0;i<this.Image_Height;i++) {
			for(int j =0;j<this.Image_Width;j++) {
				xxR[this.Pixel_Matrix[i][j].r]++;
				xxG[this.Pixel_Matrix[i][j].g]++;
				xxB[this.Pixel_Matrix[i][j].b]++;

			}
		}
			//propobility calculations
			for(int i = 0;i<256;i++) {
				xxRProp[i] = (double)xxR[i]/(double)max_y;
				xxGProp[i] = (double)xxG[i]/(double)max_y;
				xxBProp[i] = (double)xxB[i]/(double)max_y;
				//System.out.println(xxRProp[i]);
			}
			double sumRP=0,sumGP=0,sumBP=0;
			for(int i = 0 ;i<256;i++) {
				sumRP+=xxRProp[i];
				sumGP+=xxGProp[i];
				sumBP+=xxBProp[i];
				xxRCP[i] =sumRP;
				xxGCP[i] =sumGP;
				xxBCP[i] =sumBP;
			}
			//normalization to 255
			for(int i = 0;i<256;i++) {
				xxRCP[i] *=255;
				xxGCP[i] *=255;
				xxBCP[i] *=255;
				//System.out.println(xxRCP[i] );

			}
			
		//double rankR[] = tlb.getRank_Array(xxR);
		//double rankG[] = tlb.getRank_Array(xxG);
		//double rankB[] = tlb.getRank_Array(xxB);
		int hvR[] = new int[256];
		int hvG[] = new int[256];
		int hvB[] = new int[256];
		//double R_cdf_min = tlb.get_Min_Of_Arrayd(rankR);
		//double G_cdf_min = tlb.get_Min_Of_Arrayd(rankG);
		//double B_cdf_min = tlb.get_Min_Of_Arrayd(rankB);

		for(int i =0;i<256;i++) {
			
			//hvR[i] = (int)Math.round(((rankR[i] - R_cdf_min)/(max_y - R_cdf_min)) * (255));
			//hvG[i] = (int)Math.round(((rankG[i] - G_cdf_min)/(max_y - G_cdf_min)) * (255));
			//hvB[i] = (int)Math.round(((rankB[i] - B_cdf_min)/(max_y - B_cdf_min)) * (255));
			hvR[i] = (int)Math.round(xxRCP[i]);
			hvG[i] = (int)Math.round(xxGCP[i]);
			hvB[i] = (int)Math.round(xxBCP[i]);
			//System.out.println(hvR[i]);
			//System.out.println("Val " +i+  " R freq: "+xxR[i] + " Rank R : " + rankR[i]);

		}
		
		
		for(int i =0;i<this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = (int)hvR[this.Pixel_Matrix[i][j].r];
				this.Pixel_Matrix[i][j].g = (int)hvG[this.Pixel_Matrix[i][j].g];
				this.Pixel_Matrix[i][j].b = (int)hvB[this.Pixel_Matrix[i][j].b];

			}
		}
		
		this.Commint_Matrix_Changes();
	}
	public void Histogram_Linear_Correction() {
		int maxR=Integer.MIN_VALUE,maxG=Integer.MIN_VALUE,maxB=Integer.MIN_VALUE,minR =Integer.MAX_VALUE,minG=Integer.MAX_VALUE,minB=Integer.MAX_VALUE;
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				if(this.Pixel_Matrix[i][j].r > maxR) {
					maxR=this.Pixel_Matrix[i][j].r;
				}
				if(this.Pixel_Matrix[i][j].r < minR) {
					minR=this.Pixel_Matrix[i][j].r;
				}
				if(this.Pixel_Matrix[i][j].g > maxG) {
					maxG=this.Pixel_Matrix[i][j].g;
				}
				if(this.Pixel_Matrix[i][j].g < minG) {
					minG=this.Pixel_Matrix[i][j].g;
				}
				if(this.Pixel_Matrix[i][j].b > maxB) {
					maxB=this.Pixel_Matrix[i][j].b;
				}
				if(this.Pixel_Matrix[i][j].b < minB) {
					minB=this.Pixel_Matrix[i][j].b;
				}

			}
		}
		
		
		
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = ((this.Pixel_Matrix[i][j].r - minR)*255)/maxR;
				this.Pixel_Matrix[i][j].g = ((this.Pixel_Matrix[i][j].g - minG)*255)/maxG;
				this.Pixel_Matrix[i][j].b = ((this.Pixel_Matrix[i][j].b - minB)*255)/maxB;

			}
		}
		
		this.Commint_Matrix_Changes();
	}
	public void Histogram_Power_Correction() {
		int maxR=Integer.MIN_VALUE,maxG=Integer.MIN_VALUE,maxB=Integer.MIN_VALUE,minR =Integer.MAX_VALUE,minG=Integer.MAX_VALUE,minB=Integer.MAX_VALUE;
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				if(this.Pixel_Matrix[i][j].r > maxR) {
					maxR=this.Pixel_Matrix[i][j].r;
				}
				if(this.Pixel_Matrix[i][j].r < minR) {
					minR=this.Pixel_Matrix[i][j].r;
				}
				if(this.Pixel_Matrix[i][j].g > maxG) {
					maxG=this.Pixel_Matrix[i][j].g;
				}
				if(this.Pixel_Matrix[i][j].g < minG) {
					minG=this.Pixel_Matrix[i][j].g;
				}
				if(this.Pixel_Matrix[i][j].b > maxB) {
					maxB=this.Pixel_Matrix[i][j].b;
				}
				if(this.Pixel_Matrix[i][j].b < minB) {
					minB=this.Pixel_Matrix[i][j].b;
				}

			}
		}
		
		
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = ((this.Pixel_Matrix[i][j].r - minR));
				this.Pixel_Matrix[i][j].g = ((this.Pixel_Matrix[i][j].g - minG));
				this.Pixel_Matrix[i][j].b = ((this.Pixel_Matrix[i][j].b - minB));

			}
		}
		
		double powR = Math.log(255)/Math.log(maxR);
		double powG = Math.log(255)/Math.log(maxG);
		double powB = Math.log(255)/Math.log(maxB);
		
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = (int)(Math.pow(this.Pixel_Matrix[i][j].r,powR));
				this.Pixel_Matrix[i][j].g = (int)(Math.pow(this.Pixel_Matrix[i][j].g,powG));
				this.Pixel_Matrix[i][j].b = (int)(Math.pow(this.Pixel_Matrix[i][j].b,powB));

			}
		}
		
		this.Commint_Matrix_Changes();
	}
	public void Histogram_Log_Correction() {
		int maxR=Integer.MIN_VALUE,maxG=Integer.MIN_VALUE,maxB=Integer.MIN_VALUE,minR =Integer.MAX_VALUE,minG=Integer.MAX_VALUE,minB=Integer.MAX_VALUE;
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				if(this.Pixel_Matrix[i][j].r > maxR) {
					maxR=this.Pixel_Matrix[i][j].r;
				}
				if(this.Pixel_Matrix[i][j].r < minR) {
					minR=this.Pixel_Matrix[i][j].r;
				}
				if(this.Pixel_Matrix[i][j].g > maxG) {
					maxG=this.Pixel_Matrix[i][j].g;
				}
				if(this.Pixel_Matrix[i][j].g < minG) {
					minG=this.Pixel_Matrix[i][j].g;
				}
				if(this.Pixel_Matrix[i][j].b > maxB) {
					maxB=this.Pixel_Matrix[i][j].b;
				}
				if(this.Pixel_Matrix[i][j].b < minB) {
					minB=this.Pixel_Matrix[i][j].b;
				}

			}
		}
		
		Math_Toolbox tlb = new Math_Toolbox();
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = ((this.Pixel_Matrix[i][j].r - minR+1));
				this.Pixel_Matrix[i][j].g = ((this.Pixel_Matrix[i][j].g - minG+1));
				this.Pixel_Matrix[i][j].b = ((this.Pixel_Matrix[i][j].b - minB+1));

			}
		}
		
		double BaseR = tlb.nthRoot(maxR, 255);
		double BaseG = tlb.nthRoot(maxG, 255);
		double BaseB = tlb.nthRoot(maxB, 255);
		
		for(int i = 0 ; i <this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = (int)(Math.log(this.Pixel_Matrix[i][j].r)/Math.log(BaseR));
				this.Pixel_Matrix[i][j].g = (int)(Math.log(this.Pixel_Matrix[i][j].g)/Math.log(BaseG));
				this.Pixel_Matrix[i][j].b = (int)(Math.log(this.Pixel_Matrix[i][j].b)/Math.log(BaseB));

			}
		}
		
		this.Commint_Matrix_Changes();
	}
	public void Zero_Padding() {
		Image padded = new Image();
		Color_Palette CSET = new Color_Palette();
		padded.Load_Blank_Canvas(this.Image_Height+2, this.Image_Width+2, CSET.Black);
		for(int i = 0 ; i<this.Image_Height;i++) {
			for(int j =0;j<this.Image_Width;j++) {
				padded.Pixel_Matrix[i+1][j+1] = this.Pixel_Matrix[i][j];
			}
		}
		
		this.IMG = padded.IMG;
		this.Image_Height = padded.Image_Height;
		this.Image_Width=padded.Image_Width;
		this.Pixel_Matrix = padded.Pixel_Matrix;
		this.Commint_Matrix_Changes();
	}
	public void Extended_Padding() {
		Image padded = new Image();
		Color_Palette CSET = new Color_Palette();
		padded.Load_Blank_Canvas(this.Image_Height+2, this.Image_Width+2, CSET.Black);
		for(int i = 0 ; i<this.Image_Height;i++) {
			for(int j =0;j<this.Image_Width;j++) {
				padded.Pixel_Matrix[i+1][j+1] = this.Pixel_Matrix[i][j];
			}
		}
		for(int i = 0;i<this.Image_Height+2;i++) {
			padded.Pixel_Matrix[i][0] = padded.Pixel_Matrix[i][1];
			padded.Pixel_Matrix[i][this.Image_Width+1] = padded.Pixel_Matrix[i][this.Image_Width-1];
		}
		for(int i = 0;i<this.Image_Width+2;i++) {
			padded.Pixel_Matrix[0][i] = padded.Pixel_Matrix[1][i];
			padded.Pixel_Matrix[this.Image_Height+1][i] = padded.Pixel_Matrix[this.Image_Height-1][i];
		}
		
		this.IMG = padded.IMG;
		this.Image_Height = padded.Image_Height;
		this.Image_Width=padded.Image_Width;
		this.Pixel_Matrix = padded.Pixel_Matrix;
		this.Commint_Matrix_Changes();
	}
	/**
	 * @implNote
	 * Median_Filter
	 * @implNote
	 * Mean_Blur
	 * @implNote
	 * Gaussian_Blur
	 * @implNote
	 * Low_Pass
	 * @implNote
	 * High_Pass
	 * @implNote
	 * High_Pass_Streached
	 * @implNote
	 * Unsharp_Mask
	 * @implNote
	 * Sobel_Kernel
	 * 
	 * */
	public void Image_Convolution(String Mode) {
		if(Mode.equals("Median_Filter")) {
			int GroupR[] = new int[9];
			int GroupG[] = new int[9];
			int GroupB[] = new int[9];
			Math_Toolbox tlb = new Math_Toolbox();
			this.Extended_Padding();
			Image copy = new Image(this);
			
			for(int i =1;i<this.Image_Height-1;i++) {
				for(int j=1;j<this.Image_Width-1;j++) {
					//red
					GroupR[0] = this.Pixel_Matrix[i][j].r;
					GroupR[1] = this.Pixel_Matrix[i-1][j].r;
					GroupR[2] = this.Pixel_Matrix[i-1][j-1].r;
					GroupR[3] = this.Pixel_Matrix[i-1][j+1].r;
					GroupR[4] = this.Pixel_Matrix[i+1][j].r;
					GroupR[5] = this.Pixel_Matrix[i+1][j-1].r;
					GroupR[6] = this.Pixel_Matrix[i+1][j+1].r;
					GroupR[7] = this.Pixel_Matrix[i][j+1].r;
					GroupR[8] = this.Pixel_Matrix[i][j-1].r;
					//green
					GroupG[0] = this.Pixel_Matrix[i][j].g;
					GroupG[1] = this.Pixel_Matrix[i-1][j].g;
					GroupG[2] = this.Pixel_Matrix[i-1][j-1].g;
					GroupG[3] = this.Pixel_Matrix[i-1][j+1].g;
					GroupG[4] = this.Pixel_Matrix[i+1][j].g;
					GroupG[5] = this.Pixel_Matrix[i+1][j-1].g;
					GroupG[6] = this.Pixel_Matrix[i+1][j+1].g;
					GroupG[7] = this.Pixel_Matrix[i][j+1].g;
					GroupG[8] = this.Pixel_Matrix[i][j-1].g;
					//blue
					GroupB[0] = this.Pixel_Matrix[i][j].b;
					GroupB[1] = this.Pixel_Matrix[i-1][j].b;
					GroupB[2] = this.Pixel_Matrix[i-1][j-1].b;
					GroupB[3] = this.Pixel_Matrix[i-1][j+1].b;
					GroupB[4] = this.Pixel_Matrix[i+1][j].b;
					GroupB[5] = this.Pixel_Matrix[i+1][j-1].b;
					GroupB[6] = this.Pixel_Matrix[i+1][j+1].b;
					GroupB[7] = this.Pixel_Matrix[i][j+1].b;
					GroupB[8] = this.Pixel_Matrix[i][j-1].b;
					
					copy.Pixel_Matrix[i][j].r = (int)tlb.getMedian(GroupR);
					copy.Pixel_Matrix[i][j].g = (int)tlb.getMedian(GroupG);
					copy.Pixel_Matrix[i][j].b = (int)tlb.getMedian(GroupB);
					

				}
			}
			for(int i =1;i<this.Image_Height-1;i++) {
				for(int j=1;j<this.Image_Width-1;j++) {
					this.Pixel_Matrix[i][j].r = copy.Pixel_Matrix[i][j].r;
					this.Pixel_Matrix[i][j].g = copy.Pixel_Matrix[i][j].g;
					this.Pixel_Matrix[i][j].b = copy.Pixel_Matrix[i][j].b;
					

				}
			}
			this.Commint_Matrix_Changes();
			this.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
			
		}
		else if(Mode.equals("Mean_Blur")) {
			int Kernel[][] = new int[3][3];
			Kernel[0][0] =1;
			Kernel[0][1] =1;
			Kernel[0][2] =1;
			Kernel[1][0] =1;
			Kernel[1][1] =1;
			Kernel[1][2] =1;
			Kernel[2][0] =1;
			Kernel[2][1] =1;
			Kernel[2][2] =1;

			this.Extended_Padding();
			double scaling_factor = (double)1/9;
			double R_sum =0,G_sum=0,B_sum=0;
			for(int i =1;i<this.Image_Height-1;i++) {
				for(int j=1;j<this.Image_Width-1;j++) {
					//red
					R_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].r;
					R_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].r;
					R_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].r;
					R_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].r;
					R_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].r;
					R_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].r;
					R_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].r;
					R_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].r;
					//green
					G_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].g;
					G_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].g;
					G_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].g;
					G_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].g;
					G_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].g;
					G_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].g;
					G_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].g;
					G_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].g;
					//Blue
					B_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].b;
					B_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].b;
					B_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].b;
					B_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].b;
					B_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].b;
					B_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].b;
					B_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].b;
					B_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].b;
					
					this.Pixel_Matrix[i][j].r = (int)((R_sum * scaling_factor));
					this.Pixel_Matrix[i][j].g = (int)(G_sum * scaling_factor);
					this.Pixel_Matrix[i][j].b = (int)(B_sum * scaling_factor);
					
					R_sum=0;
					B_sum=0;
					G_sum=0;
				}
			}
			this.Commint_Matrix_Changes();
			this.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
			
		}
		else if(Mode.equals("Gaussian_Blur")) {
			int Kernel[][] = new int[3][3];
			Kernel[0][0] =1;
			Kernel[0][1] =2;
			Kernel[0][2] =1;
			Kernel[1][0] =2;
			Kernel[1][1] =4;
			Kernel[1][2] =2;
			Kernel[2][0] =1;
			Kernel[2][1] =2;
			Kernel[2][2] =1;

			this.Extended_Padding();
			double scaling_factor = (double)1/16;
			double R_sum =0,G_sum=0,B_sum=0;
			for(int i =1;i<this.Image_Height-1;i++) {
				for(int j=1;j<this.Image_Width-1;j++) {
					//red
					R_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].r;
					R_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].r;
					R_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].r;
					R_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].r;
					R_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].r;
					R_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].r;
					R_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].r;
					R_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].r;
					//green
					G_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].g;
					G_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].g;
					G_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].g;
					G_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].g;
					G_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].g;
					G_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].g;
					G_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].g;
					G_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].g;
					//Blue
					B_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].b;
					B_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].b;
					B_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].b;
					B_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].b;
					B_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].b;
					B_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].b;
					B_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].b;
					B_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].b;
					
					this.Pixel_Matrix[i][j].r = (int)((R_sum * scaling_factor));
					this.Pixel_Matrix[i][j].g = (int)(G_sum * scaling_factor);
					this.Pixel_Matrix[i][j].b = (int)(B_sum * scaling_factor);
					
					R_sum=0;
					B_sum=0;
					G_sum=0;
				}
			}
			this.Commint_Matrix_Changes();
			this.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
			
		}
		else if(Mode.equals("Low_Pass")) {
			double Kernel[][] = new double[3][3];
			Kernel[0][0] =0;
			Kernel[0][1] =(double)1/8;
			Kernel[0][2] =0;
			Kernel[1][0] =(double)1/8;
			Kernel[1][1] =(double)1/2;
			Kernel[1][2] =(double)1/8;
			Kernel[2][0] =0;
			Kernel[2][1] =(double)1/8;
			Kernel[2][2] =0;

			this.Extended_Padding();
			double scaling_factor = (double)1/16;
			double R_sum =0,G_sum=0,B_sum=0;
			for(int i =1;i<this.Image_Height-1;i++) {
				for(int j=1;j<this.Image_Width-1;j++) {
					//red
					R_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].r;
					R_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].r;
					R_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].r;
					R_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].r;
					R_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].r;
					R_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].r;
					R_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].r;
					R_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].r;
					//green
					G_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].g;
					G_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].g;
					G_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].g;
					G_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].g;
					G_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].g;
					G_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].g;
					G_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].g;
					G_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].g;
					//Blue
					B_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].b;
					B_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].b;
					B_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].b;
					B_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].b;
					B_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].b;
					B_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].b;
					B_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].b;
					B_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].b;
					
					this.Pixel_Matrix[i][j].r = (int)((R_sum));
					this.Pixel_Matrix[i][j].g = (int)(G_sum);
					this.Pixel_Matrix[i][j].b = (int)(B_sum);
					
					R_sum=0;
					B_sum=0;
					G_sum=0;
				}
			}
			this.Commint_Matrix_Changes();
			this.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
			
		}
		else if(Mode.equals("High_Pass")) {
			double Kernel[][] = new double[3][3];
			Kernel[0][0] =(double)-1/9;
			Kernel[0][1] =(double)-1/9;
			Kernel[0][2] =(double)-1/9;
			Kernel[1][0] =(double)-1/9;
			Kernel[1][1] =(double)1;
			Kernel[1][2] =(double)-1/9;
			Kernel[2][0] =(double)-1/9;
			Kernel[2][1] =(double)-1/9;
			Kernel[2][2] =(double)-1/9;
			Image copy = new Image(this);
			this.Extended_Padding();
			copy.Extended_Padding();
			double R_sum =0,G_sum=0,B_sum=0;
			for(int i =1;i<this.Image_Height-1;i++) {
				for(int j=1;j<this.Image_Width-1;j++) {
					//red
					R_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].r;
					R_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].r;
					R_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].r;
					R_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].r;
					R_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].r;
					R_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].r;
					R_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].r;
					R_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].r;
					//green
					G_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].g;
					G_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].g;
					G_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].g;
					G_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].g;
					G_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].g;
					G_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].g;
					G_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].g;
					G_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].g;
					//Blue
					B_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].b;
					B_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].b;
					B_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].b;
					B_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].b;
					B_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].b;
					B_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].b;
					B_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].b;
					B_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].b;
					
					//clamping
					
					
					copy.Pixel_Matrix[i][j].r = (int)(((R_sum)));
					copy.Pixel_Matrix[i][j].g = (int)((G_sum));
					copy.Pixel_Matrix[i][j].b = (int)((B_sum));
					//copy.Pixel_Matrix[i][j].Clamp_Outliers();
					R_sum=0;
					B_sum=0;
					G_sum=0;
				}
			}

			this.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
			copy.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
			this.init_pixel_matrix();
			this.Arithmetic_Addition(copy);
			this.Commint_Matrix_Changes();

		}
		else if(Mode.equals("High_Pass_Streached")) {
			double Kernel[][] = new double[3][3];
			Kernel[0][0] =(double)-1/9;
			Kernel[0][1] =(double)-1/9;
			Kernel[0][2] =(double)-1/9;
			Kernel[1][0] =(double)-1/9;
			Kernel[1][1] =(double)-8/9;
			Kernel[1][2] =(double)-1/9;
			Kernel[2][0] =(double)-1/9;
			Kernel[2][1] =(double)-1/9;
			Kernel[2][2] =(double)-1/9;

			this.Extended_Padding();
			double R_sum =0,G_sum=0,B_sum=0;
			for(int i =1;i<this.Image_Height-1;i++) {
				for(int j=1;j<this.Image_Width-1;j++) {
					//red
					R_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].r;
					R_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].r;
					R_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].r;
					R_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].r;
					R_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].r;
					R_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].r;
					R_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].r;
					R_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].r;
					//green
					G_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].g;
					G_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].g;
					G_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].g;
					G_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].g;
					G_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].g;
					G_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].g;
					G_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].g;
					G_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].g;
					//Blue
					B_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].b;
					B_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].b;
					B_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].b;
					B_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].b;
					B_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].b;
					B_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].b;
					B_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].b;
					B_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].b;
					
					//clamping
					
					
					this.Pixel_Matrix[i][j].r = (int)(((R_sum/2)) + 128);
					this.Pixel_Matrix[i][j].g = (int)((G_sum/2)+ 128);
					this.Pixel_Matrix[i][j].b = (int)((B_sum/2)+ 128);
					this.Pixel_Matrix[i][j].Clamp_Outliers();
					if(this.Pixel_Matrix[i][j].r < 0 || this.Pixel_Matrix[i][j].g < 0 ||this.Pixel_Matrix[i][j].r < 0) {
						System.out.println("Found <0 !");
					}
					
					R_sum=0;
					B_sum=0;
					G_sum=0;
				}
			}
			this.Commint_Matrix_Changes();
			this.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
			this.Commint_Matrix_Changes();

		}
		else if(Mode.equals("Unsharp_Mask")) {
			double Kernel[][] = new double[3][3];
			Kernel[0][0] =(double)0;
			Kernel[0][1] =(double)1;
			Kernel[0][2] =(double)0;
			Kernel[1][0] =(double)1;
			Kernel[1][1] =(double)-4;
			Kernel[1][2] =(double)1;
			Kernel[2][0] =(double)0;
			Kernel[2][1] =(double)1;
			Kernel[2][2] =(double)0;
			
			
			
			this.Extended_Padding();
			Image Original = new Image(this);
			Image Copy  = new Image(this);
			
			double R_sum =0,G_sum=0,B_sum=0;
			for(int i =1;i<this.Image_Height-1;i++) {
				for(int j=1;j<this.Image_Width-1;j++) {
					//red
					R_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].r;
					R_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].r;
					R_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].r;
					R_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].r;
					R_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].r;
					R_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].r;
					R_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].r;
					R_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].r;
					//green
					G_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].g;
					G_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].g;
					G_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].g;
					G_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].g;
					G_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].g;
					G_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].g;
					G_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].g;
					G_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].g;
					//Blue
					B_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].b;
					B_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].b;
					B_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].b;
					B_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].b;
					B_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].b;
					B_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].b;
					B_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].b;
					B_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].b;
					
					//clamping
					
					
					Copy.Pixel_Matrix[i][j].r = (int)(((R_sum)) );
					Copy.Pixel_Matrix[i][j].g = (int)((G_sum));
					Copy.Pixel_Matrix[i][j].b = (int)((B_sum));
					
					R_sum=0;
					B_sum=0;
					G_sum=0;
				}
			}
			
			Copy.Commint_Matrix_Changes();
			Original.Arithmetic_Subtraction(Copy);
			Copy.Write_Image("Masked.png");
			
			for(int i = 0;i<this.Image_Height;i++) {
				for(int j = 0 ;j<this.Image_Width;j++) {
					this.Pixel_Matrix[i][j] = Original.Pixel_Matrix[i][j];
				}
			}
			
			this.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
			
			
			
			this.Commint_Matrix_Changes();

			
		}
		else if(Mode.equals("Sobel_Kernel")) {
			double Kernel_x[][] = new double[3][3];
			double Kernel_y[][] = new double[3][3];
			Image copy_y = new Image(this);
			Image copy = new Image(this);
			Kernel_x[0][0] =(double)-1;
			Kernel_x[0][1] =(double)-2;
			Kernel_x[0][2] =(double)-1;
			Kernel_x[1][0] =(double)0;
			Kernel_x[1][1] =(double)0;
			Kernel_x[1][2] =(double)0;
			Kernel_x[2][0] =(double)1;
			Kernel_x[2][1] =(double)2;
			Kernel_x[2][2] =(double)1;
			
			Kernel_y[0][0] =(double)-1;
			Kernel_y[0][1] =(double)0;
			Kernel_y[0][2] =(double)1;
			Kernel_y[1][0] =(double)-2;
			Kernel_y[1][1] =(double)0;
			Kernel_y[1][2] =(double)2;
			Kernel_y[2][0] =(double)-1;
			Kernel_y[2][1] =(double)0;
			Kernel_y[2][2] =(double)1;

			copy_y.Extended_Padding();
			copy.Extended_Padding();
			double R_sum =0,G_sum=0,B_sum=0;
			double R_sum_x =0,G_sum_x=0,B_sum_x=0;

			for(int i =1;i<copy_y.Image_Height-1;i++) {
				for(int j=1;j<copy_y.Image_Width-1;j++) {
					//red
					R_sum += Kernel_y[0][0] * copy_y.Pixel_Matrix[i-1][j-1].r;
					R_sum += Kernel_y[0][1] * copy_y.Pixel_Matrix[i-1][j].r;
					R_sum += Kernel_y[0][2] * copy_y.Pixel_Matrix[i-1][j+1].r;
					R_sum += Kernel_y[1][0] * copy_y.Pixel_Matrix[i][j-1].r;
					R_sum += Kernel_y[1][1] * copy_y.Pixel_Matrix[i][j].r;
					R_sum += Kernel_y[1][2] * copy_y.Pixel_Matrix[i][j+1].r;
					R_sum += Kernel_y[2][0] * copy_y.Pixel_Matrix[i+1][j-1].r;
					R_sum += Kernel_y[2][1] * copy_y.Pixel_Matrix[i+1][j].r;
					R_sum += Kernel_y[2][2] * copy_y.Pixel_Matrix[i+1][j+1].r;
					//green
					G_sum += Kernel_y[0][0] * copy_y.Pixel_Matrix[i-1][j-1].g;
					G_sum += Kernel_y[0][1] * copy_y.Pixel_Matrix[i-1][j].g;
					G_sum += Kernel_y[0][2] * copy_y.Pixel_Matrix[i-1][j+1].g;
					G_sum += Kernel_y[1][0] * copy_y.Pixel_Matrix[i][j-1].g;
					G_sum += Kernel_y[1][1] * copy_y.Pixel_Matrix[i][j].g;
					G_sum += Kernel_y[1][2] * copy_y.Pixel_Matrix[i][j+1].g;
					G_sum += Kernel_y[2][0] * copy_y.Pixel_Matrix[i+1][j-1].g;
					G_sum += Kernel_y[2][1] * copy_y.Pixel_Matrix[i+1][j].g;
					G_sum += Kernel_y[2][2] * copy_y.Pixel_Matrix[i+1][j+1].g;
					//Blue
					B_sum += Kernel_y[0][0] * copy_y.Pixel_Matrix[i-1][j-1].b;
					B_sum += Kernel_y[0][1] * copy_y.Pixel_Matrix[i-1][j].b;
					B_sum += Kernel_y[0][2] * copy_y.Pixel_Matrix[i-1][j+1].b;
					B_sum += Kernel_y[1][0] * copy_y.Pixel_Matrix[i][j-1].b;
					B_sum += Kernel_y[1][1] * copy_y.Pixel_Matrix[i][j].b;
					B_sum += Kernel_y[1][2] * copy_y.Pixel_Matrix[i][j+1].b;
					B_sum += Kernel_y[2][0] * copy_y.Pixel_Matrix[i+1][j-1].b;
					B_sum += Kernel_y[2][1] * copy_y.Pixel_Matrix[i+1][j].b;
					B_sum += Kernel_y[2][2] * copy_y.Pixel_Matrix[i+1][j+1].b;
					
					
					
					//red
					R_sum_x += Kernel_x[0][0] * copy_y.Pixel_Matrix[i-1][j-1].r;
					R_sum_x += Kernel_x[0][1] * copy_y.Pixel_Matrix[i-1][j].r;
					R_sum_x += Kernel_x[0][2] * copy_y.Pixel_Matrix[i-1][j+1].r;
					R_sum_x += Kernel_x[1][0] * copy_y.Pixel_Matrix[i][j-1].r;
					R_sum_x += Kernel_x[1][1] * copy_y.Pixel_Matrix[i][j].r;
					R_sum_x += Kernel_x[1][2] * copy_y.Pixel_Matrix[i][j+1].r;
					R_sum_x += Kernel_x[2][0] * copy_y.Pixel_Matrix[i+1][j-1].r;
					R_sum_x += Kernel_x[2][1] * copy_y.Pixel_Matrix[i+1][j].r;
					R_sum_x += Kernel_x[2][2] * copy_y.Pixel_Matrix[i+1][j+1].r;
					//green
					G_sum_x += Kernel_x[0][0] * copy_y.Pixel_Matrix[i-1][j-1].g;
					G_sum_x += Kernel_x[0][1] * copy_y.Pixel_Matrix[i-1][j].g;
					G_sum_x += Kernel_x[0][2] * copy_y.Pixel_Matrix[i-1][j+1].g;
					G_sum_x += Kernel_x[1][0] * copy_y.Pixel_Matrix[i][j-1].g;
					G_sum_x += Kernel_x[1][1] * copy_y.Pixel_Matrix[i][j].g;
					G_sum_x += Kernel_x[1][2] * copy_y.Pixel_Matrix[i][j+1].g;
					G_sum_x += Kernel_x[2][0] * copy_y.Pixel_Matrix[i+1][j-1].g;
					G_sum_x += Kernel_x[2][1] * copy_y.Pixel_Matrix[i+1][j].g;
					G_sum_x += Kernel_x[2][2] * copy_y.Pixel_Matrix[i+1][j+1].g;
					//Blue
					B_sum_x += Kernel_x[0][0] * copy_y.Pixel_Matrix[i-1][j-1].b;
					B_sum_x += Kernel_x[0][1] * copy_y.Pixel_Matrix[i-1][j].b;
					B_sum_x += Kernel_x[0][2] * copy_y.Pixel_Matrix[i-1][j+1].b;
					B_sum_x += Kernel_x[1][0] * copy_y.Pixel_Matrix[i][j-1].b;
					B_sum_x += Kernel_x[1][1] * copy_y.Pixel_Matrix[i][j].b;
					B_sum_x += Kernel_x[1][2] * copy_y.Pixel_Matrix[i][j+1].b;
					B_sum_x += Kernel_x[2][0] * copy_y.Pixel_Matrix[i+1][j-1].b;
					B_sum_x += Kernel_x[2][1] * copy_y.Pixel_Matrix[i+1][j].b;
					B_sum_x += Kernel_x[2][2] * copy_y.Pixel_Matrix[i+1][j+1].b;
					
					//clamping
					
					
					copy.Pixel_Matrix[i][j].r = (int) Math.round((Math.sqrt(R_sum_x*R_sum_x +  R_sum*R_sum)));
					copy.Pixel_Matrix[i][j].g = (int) Math.round((Math.sqrt(G_sum_x*G_sum_x +  G_sum*G_sum)));
					copy.Pixel_Matrix[i][j].b = (int) Math.round((Math.sqrt(B_sum_x*B_sum_x +  B_sum*B_sum)));
					copy.Pixel_Matrix[i][j].Clamp_Outliers();
					
					R_sum=0;
					B_sum=0;
					G_sum=0;
					R_sum_x=0;
					B_sum_x=0;
					G_sum_x=0;
				}
			}
			R_sum=0;
			B_sum=0;
			G_sum=0;
			copy.Commint_Matrix_Changes();
			copy.Crop_Image(1, 1, copy_y.Image_Height-1, copy_y.Image_Width-1);
			
			
			for(int i =0;i<this.Image_Height;i++) {
				for(int j =0;j<this.Image_Width;j++) {
					this.Pixel_Matrix[i][j].r = copy.Pixel_Matrix[i][j].r;
					this.Pixel_Matrix[i][j].g = copy.Pixel_Matrix[i][j].g;
					this.Pixel_Matrix[i][j].b = copy.Pixel_Matrix[i][j].b;
					this.Pixel_Matrix[i][j].Clamp_Outliers();
				}
			}
			this.Commint_Matrix_Changes();

			
		}
		
		
		
		
	}
	public void Scale_Down_By_Convolution(String Mode) {
		if(Mode.equals("Mean")) {
		int Kernel[][] = new int[3][3];
		Image Shrinked = new Image();
		Kernel[0][0] =1;
		Kernel[0][1] =1;
		Kernel[0][2] =1;
		Kernel[1][0] =1;
		Kernel[1][1] =1;
		Kernel[1][2] =1;
		Kernel[2][0] =1;
		Kernel[2][1] =1;
		Kernel[2][2] =1;
		this.Extended_Padding();
		Shrinked.Load_Blank_Canvas(this.Image_Height/3, this.Image_Width/3, new Pixel(0,0,0));
		double scaling_factor = (double)1/9;
		double R_sum =0,G_sum=0,B_sum=0;
		int sh=0,sw=0;
		for(int i =1;i<this.Image_Height-1;i+=3) {
			for(int j=1;j<this.Image_Width-1;j+=3) {
				//red
				R_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].r;
				R_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].r;
				R_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].r;
				R_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].r;
				R_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].r;
				R_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].r;
				R_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].r;
				R_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].r;
				R_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].r;
				//green
				G_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].g;
				G_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].g;
				G_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].g;
				G_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].g;
				G_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].g;
				G_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].g;
				G_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].g;
				G_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].g;
				G_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].g;
				//Blue
				B_sum += Kernel[0][0] * this.Pixel_Matrix[i-1][j-1].b;
				B_sum += Kernel[0][1] * this.Pixel_Matrix[i-1][j].b;
				B_sum += Kernel[0][2] * this.Pixel_Matrix[i-1][j+1].b;
				B_sum += Kernel[1][0] * this.Pixel_Matrix[i][j-1].b;
				B_sum += Kernel[1][1] * this.Pixel_Matrix[i][j].b;
				B_sum += Kernel[1][2] * this.Pixel_Matrix[i][j+1].b;
				B_sum += Kernel[2][0] * this.Pixel_Matrix[i+1][j-1].b;
				B_sum += Kernel[2][1] * this.Pixel_Matrix[i+1][j].b;
				B_sum += Kernel[2][2] * this.Pixel_Matrix[i+1][j+1].b;
				
				this.Pixel_Matrix[i][j].r = (int)((R_sum * scaling_factor));
				this.Pixel_Matrix[i][j].g = (int)(G_sum * scaling_factor);
				this.Pixel_Matrix[i][j].b = (int)(B_sum * scaling_factor);
				
				Shrinked.Pixel_Matrix[sh][sw] = this.Pixel_Matrix[i][j];
				sw++;
				R_sum=0;
				B_sum=0;
				G_sum=0;
			}
			sh++;
			sw=0;
		}
		Shrinked.Commint_Matrix_Changes();
		this.IMG = Shrinked.IMG;
		this.Image_Width=Shrinked.Image_Width;
		this.Image_Height=Shrinked.Image_Height;
		this.Pixel_Matrix = Shrinked.Pixel_Matrix;
		}	
		else if(Mode.equals("Median")) {
			int GroupR[] = new int[9];
			int GroupG[] = new int[9];
			int GroupB[] = new int[9];
			Image Shrinked = new Image();
			Math_Toolbox tlb = new Math_Toolbox();
			this.Extended_Padding();
			Shrinked.Load_Blank_Canvas(this.Image_Height/3, this.Image_Width/3, new Pixel(0,0,0));
			int sh=0,sw=0;

			
			for(int i =1;i<this.Image_Height-1;i+=3) {
				for(int j=1;j<this.Image_Width-1;j+=3) {
					//red
					GroupR[0] = this.Pixel_Matrix[i][j].r;
					GroupR[1] = this.Pixel_Matrix[i-1][j].r;
					GroupR[2] = this.Pixel_Matrix[i-1][j-1].r;
					GroupR[3] = this.Pixel_Matrix[i-1][j+1].r;
					GroupR[4] = this.Pixel_Matrix[i+1][j].r;
					GroupR[5] = this.Pixel_Matrix[i+1][j-1].r;
					GroupR[6] = this.Pixel_Matrix[i+1][j+1].r;
					GroupR[7] = this.Pixel_Matrix[i][j+1].r;
					GroupR[8] = this.Pixel_Matrix[i][j-1].r;
					//green
					GroupG[0] = this.Pixel_Matrix[i][j].g;
					GroupG[1] = this.Pixel_Matrix[i-1][j].g;
					GroupG[2] = this.Pixel_Matrix[i-1][j-1].g;
					GroupG[3] = this.Pixel_Matrix[i-1][j+1].g;
					GroupG[4] = this.Pixel_Matrix[i+1][j].g;
					GroupG[5] = this.Pixel_Matrix[i+1][j-1].g;
					GroupG[6] = this.Pixel_Matrix[i+1][j+1].g;
					GroupG[7] = this.Pixel_Matrix[i][j+1].g;
					GroupG[8] = this.Pixel_Matrix[i][j-1].g;
					//blue
					GroupB[0] = this.Pixel_Matrix[i][j].b;
					GroupB[1] = this.Pixel_Matrix[i-1][j].b;
					GroupB[2] = this.Pixel_Matrix[i-1][j-1].b;
					GroupB[3] = this.Pixel_Matrix[i-1][j+1].b;
					GroupB[4] = this.Pixel_Matrix[i+1][j].b;
					GroupB[5] = this.Pixel_Matrix[i+1][j-1].b;
					GroupB[6] = this.Pixel_Matrix[i+1][j+1].b;
					GroupB[7] = this.Pixel_Matrix[i][j+1].b;
					GroupB[8] = this.Pixel_Matrix[i][j-1].b;
					
					this.Pixel_Matrix[i][j].r = (int)tlb.getMedian(GroupR);
					this.Pixel_Matrix[i][j].g = (int)tlb.getMedian(GroupG);
					this.Pixel_Matrix[i][j].b = (int)tlb.getMedian(GroupB);
					Shrinked.Pixel_Matrix[sh][sw] = this.Pixel_Matrix[i][j];
					sw++;

				}
				sh++;
				sw=0;
			}
			Shrinked.Commint_Matrix_Changes();
			this.IMG = Shrinked.IMG;
			this.Image_Width=Shrinked.Image_Width;
			this.Image_Height=Shrinked.Image_Height;
			this.Pixel_Matrix = Shrinked.Pixel_Matrix;
			
		}
	}
	public void Dithering_Floyd_Steinberg(int Palette_Size) {
		ArrayList<Point> ACP = this.Get_Average_Color_Palette(Palette_Size,25);
		this.Extended_Padding();
		double minDistance=Double.MAX_VALUE;
		int pos=0;
		for(int i = 1 ; i<this.Image_Height-1;i++) {
			for(int j = 1 ; j < this.Image_Width-1;j++) {
				Pixel oldpixel = this.Pixel_Matrix[i][j];
				Pixel newpixel;
				for(int k = 0 ;k<Palette_Size;k++) {
					double distance = ACP.get(k).Distance(new Point(oldpixel.r,oldpixel.g,oldpixel.b));
					if(minDistance > distance) {
						minDistance = distance;
						//System.out.println(distance);

						pos = k;
					}
				}
				minDistance=Double.MAX_VALUE;
				newpixel = new Pixel((int)ACP.get(pos).x,(int)ACP.get(pos).y,(int)ACP.get(pos).z);
				this.Pixel_Matrix[i][j] = newpixel;
				double quant_error_r = (oldpixel.r-newpixel.r);
				double quant_error_g = (oldpixel.g-newpixel.g);
				double quant_error_b = (oldpixel.b-newpixel.b);
				this.Pixel_Matrix[i][j+1].r +=(int)Math.round((quant_error_r * (double)7/16));
				this.Pixel_Matrix[i][j+1].g +=(int)Math.round((quant_error_g * (double)7/16));
				this.Pixel_Matrix[i][j+1].b +=(int)Math.round((quant_error_b * (double)7/16));
				
				this.Pixel_Matrix[i+1][j-1].r +=(int)Math.round((quant_error_r * (double)3/16));
				this.Pixel_Matrix[i+1][j-1].g +=(int)Math.round((quant_error_g * (double)3/16));
				this.Pixel_Matrix[i+1][j-1].b +=(int)Math.round((quant_error_b * (double)3/16));
				
				this.Pixel_Matrix[i+1][j].r +=(int)Math.round((quant_error_r * (double)5/16));
				this.Pixel_Matrix[i+1][j].g +=(int)Math.round((quant_error_g * (double)5/16));
				this.Pixel_Matrix[i+1][j].b +=(int)Math.round((quant_error_b * (double)5/16));
				
				this.Pixel_Matrix[i+1][j+1].r +=(int)Math.round((quant_error_r * (double)1/16));
				this.Pixel_Matrix[i+1][j+1].g +=(int)Math.round((quant_error_g * (double)1/16));
				this.Pixel_Matrix[i+1][j+1].b +=(int)Math.round((quant_error_b * (double)1/16));

			}
		}
		this.Commint_Matrix_Changes();
		this.Crop_Image(1, 1, this.Image_Height-1, this.Image_Width-1);
	}
	public void Circle_Packing(int amount_of_circles,int max_circle_size) {
		class circle{
			int x,y,r;
			Pixel Color;
			circle(){}
			circle(int x,int y,int r,Pixel Color){
				this.x=x;
				this.y=y;
				this.r=r;
				this.Color=Color;
			}
			public int intersect_check(int x2,int y2, int r2) 
			{ 
			    int distSq = (this.x - x2) * (this.x - x2) + 
			                 (this.y - y2) * (this.y - y2); 
			    int radSumSq = (this.r + r2) * (this.r + r2); 
			    if (distSq == radSumSq) 
			        return 1; 
			    else if (distSq > radSumSq) 
			        return -1; 
			    else
			        return 0; 
			} 
		}
		Math_Toolbox tlb = new Math_Toolbox();
			ArrayList<circle> circles = new ArrayList<circle>();
			
			for(int i = 0;i<amount_of_circles;i++) {
				int r = tlb.random_int_in_range(1, max_circle_size);
				int x = tlb.random_int_in_range(1+r, this.Image_Width-1-r);
				int y = tlb.random_int_in_range(1+r, this.Image_Height-1-r);
				Pixel Color = new Pixel(this.Pixel_Matrix[y][x]);
				circle to_add = new circle(x,y,r,Color);
				for(int j = 0;j< circles.size();j++) {
					if(circles.get(j).intersect_check(x, y, r) == 0) {
						r = tlb.random_int_in_range(1, max_circle_size);
						x = tlb.random_int_in_range(1+r, this.Image_Width-2-r);
						y = tlb.random_int_in_range(1+r, this.Image_Height-2-r);
						Color = new Pixel(this.Pixel_Matrix[y][x]);
						j=0;
						to_add.r=r;
						to_add.x=x;
						to_add.Color=Color;
						to_add.y=y;
					}
				}
				circles.add(to_add);
			}
			this.Load_Blank_Canvas(this.Image_Height, this.Image_Width, new Pixel(0,0,0));
			for(int i = 0 ; i<circles.size();i++) {
				this.Draw_Circle(circles.get(i).x, circles.get(i).y, circles.get(i).r, circles.get(i).Color,"Fill");
			}
			
	
	
	}
	public void Add_Salt_and_Pepper_Noise(double Salt_Propability,double Pepper_Probability) {
		double rand = 0;
		Math_Toolbox tlb = new Math_Toolbox();
		
			if(Salt_Propability < Pepper_Probability) {
			
				for(int i = 0 ; i < this.Image_Height; i ++) {
					for(int j = 0 ; j < this.Image_Width; j++) {
						rand = tlb.random_double_in_range(0.0, 1.0);
						if(rand <= Salt_Propability) {
							this.Pixel_Matrix[i][j].r=255;
							this.Pixel_Matrix[i][j].g=255;
							this.Pixel_Matrix[i][j].b=255;
		
						}
						else if(rand <= Pepper_Probability) {
							this.Pixel_Matrix[i][j].r=0;
							this.Pixel_Matrix[i][j].g=0;
							this.Pixel_Matrix[i][j].b=0;
						}
					}
				}
			}
			else {
				
					for(int i = 0 ; i < this.Image_Height; i ++) {
						for(int j = 0 ; j < this.Image_Width; j++) {
							rand = tlb.random_double_in_range(0.0, 1.0);
							 if(rand <= Pepper_Probability) {
								this.Pixel_Matrix[i][j].r=0;
								this.Pixel_Matrix[i][j].g=0;
								this.Pixel_Matrix[i][j].b=0;
							}
							 else if(rand <= Salt_Propability) {
								this.Pixel_Matrix[i][j].r=255;
								this.Pixel_Matrix[i][j].g=255;
								this.Pixel_Matrix[i][j].b=255;
		
							}
						}
					
				}
			
		}

	}


	public void Image_Averaging(ArrayList<Image> Images) {
		int a_width = Images.get(0).Image_Width,a_height = Images.get(0).Image_Height;
		for(int i = 0 ; i< Images.size();i++) {
			if(Images.get(i).Image_Height != a_height || Images.get(i).Image_Width != a_width) {
				System.out.println("Not All Images Match In Size: Problomatic Image:" + Images.get(i).F_Path);
			}
		}
		
		this.Load_Blank_Canvas(a_height, a_width, new Pixel(0,0,0));
		for(int i = 0 ; i< Images.size();i++) {
			Image temp = Images.get(i);
			for(int k = 0 ;k <a_height;k++) {
				for(int j = 0;j<a_width;j++) {
					this.Pixel_Matrix[k][j].r += temp.Pixel_Matrix[k][j].r;
					this.Pixel_Matrix[k][j].g += temp.Pixel_Matrix[k][j].g;
					this.Pixel_Matrix[k][j].b += temp.Pixel_Matrix[k][j].b;

				}
			}
			
		}
		
		this.Arithmetic_Division(Images.size());
		
		
	}
	public Point Get_Image_Color_Means() {
		int Histogram_R[] = this.Get_Red_Histogram();
		int Histogram_G[] = this.Get_Green_Histogram();
		int Histogram_B[] = this.Get_Blue_Histogram();
		Point Var = new Point();
		double R_Mean = 0,G_Mean=0,B_Mean=0;
		for(int i =0;i<256;i++) {
			R_Mean += i *((double)Histogram_R[i]/(this.Image_Height*this.Image_Width));
			G_Mean += i *((double)Histogram_G[i]/(this.Image_Height*this.Image_Width));
			B_Mean += i *((double)Histogram_B[i]/(this.Image_Height*this.Image_Width));

		}
		Var.x = R_Mean;
		Var.y = G_Mean;
		Var.z = B_Mean;

		

		return Var;
	}
	public Point Get_Image_Color_Variance() {
		int Histogram_R[] = this.Get_Red_Histogram();
		int Histogram_G[] = this.Get_Green_Histogram();
		int Histogram_B[] = this.Get_Blue_Histogram();
		Point Var = new Point();
		double R_Mean = 0,G_Mean=0,B_Mean=0;
		double R_Var = 0,G_Var=0,B_Var=0;

		for(int i =0;i<256;i++) {
			R_Mean += i *((double)Histogram_R[i]/(this.Image_Height*this.Image_Width));
			G_Mean += i *((double)Histogram_G[i]/(this.Image_Height*this.Image_Width));
			B_Mean += i *((double)Histogram_B[i]/(this.Image_Height*this.Image_Width));

		}
		
		for(int i =0;i<256;i++) {
			R_Var += ((Histogram_R[i] - R_Mean)*(Histogram_R[i] - R_Mean)) * ((double)Histogram_R[i]/(this.Image_Height*this.Image_Width));
			G_Var += ((Histogram_G[i] - G_Mean)*(Histogram_G[i] - G_Mean)) * ((double)Histogram_G[i]/(this.Image_Height*this.Image_Width));
			B_Var += ((Histogram_B[i] - B_Mean)*(Histogram_B[i] - B_Mean)) * ((double)Histogram_B[i]/(this.Image_Height*this.Image_Width));

		}
		
		Var.x = R_Var;
		Var.y = G_Var;
		Var.z = B_Var;

		

		return Var;
	}	
	public Point Get_Image_Color_Variance(int nth_moment) {
		int Histogram_R[] = this.Get_Red_Histogram();
		int Histogram_G[] = this.Get_Green_Histogram();
		int Histogram_B[] = this.Get_Blue_Histogram();
		Point Var = new Point();
		double R_Mean = 0,G_Mean=0,B_Mean=0;
		double R_Var = 0,G_Var=0,B_Var=0;

		for(int i =0;i<256;i++) {
			R_Mean += i *((double)Histogram_R[i]/(this.Image_Height*this.Image_Width));
			G_Mean += i *((double)Histogram_G[i]/(this.Image_Height*this.Image_Width));
			B_Mean += i *((double)Histogram_B[i]/(this.Image_Height*this.Image_Width));

		}
		
		for(int i =0;i<256;i++) {
			R_Var += (Math.pow((Histogram_R[i] - R_Mean),nth_moment)) * ((double)Histogram_R[i]/(this.Image_Height*this.Image_Width));
			G_Var +=  (Math.pow((Histogram_G[i] - G_Mean),nth_moment)) * ((double)Histogram_G[i]/(this.Image_Height*this.Image_Width));
			B_Var +=  (Math.pow((Histogram_B[i] - B_Mean),nth_moment)) * ((double)Histogram_B[i]/(this.Image_Height*this.Image_Width));

		}
		
		Var.x = R_Var;
		Var.y = G_Var;
		Var.z = B_Var;

		

		return Var;
	}	
	public void Logarithmic_Transformation() {
		int max_mag_R=0;
		int max_mag_G=0;
		int max_mag_B=0;
		
		for(int i = 0 ; i<this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				if(this.Pixel_Matrix[i][j].r > max_mag_R ) {
					max_mag_R = this.Pixel_Matrix[i][j].r;
				}
				if(this.Pixel_Matrix[i][j].g > max_mag_G ) {
					max_mag_G = this.Pixel_Matrix[i][j].g;
				}
				if(this.Pixel_Matrix[i][j].b > max_mag_B ) {
					max_mag_B = this.Pixel_Matrix[i][j].b;
				}
			}
		}
		
		double scaling_R= (double)255/Math.log(1+Math.abs(max_mag_R));
		double scaling_G= (double)255/Math.log(1+Math.abs(max_mag_G));
		double scaling_B= (double)255/Math.log(1+Math.abs(max_mag_B));
		
		for(int i = 0 ; i<this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = (int) (scaling_R * (Math.log(1 + Math.abs(this.Pixel_Matrix[i][j].r))));
				this.Pixel_Matrix[i][j].g = (int) (scaling_G * (Math.log(1 + Math.abs(this.Pixel_Matrix[i][j].g))));
				this.Pixel_Matrix[i][j].b = (int) (scaling_B * (Math.log(1 + Math.abs(this.Pixel_Matrix[i][j].b))));

			}
		}
		this.Commint_Matrix_Changes();

	}
	public void Square_Root_Transformation() {
			for(int i = 0 ;i<this.Image_Height;i++) {
				for(int j = 0 ;j <this.Image_Width;j++) {
					this.Pixel_Matrix[i][j].r = (int)Math.sqrt(this.Pixel_Matrix[i][j].r);
					this.Pixel_Matrix[i][j].g = (int)Math.sqrt(this.Pixel_Matrix[i][j].g);
					this.Pixel_Matrix[i][j].b = (int)Math.sqrt(this.Pixel_Matrix[i][j].b);

	
			}
		}
			this.Commint_Matrix_Changes();
	}
	public Complex[][]  Fourier_Transform() {
		Complex Fourier_Matrix[][] = new Complex[this.Image_Height][this.Image_Width];
		Complex temp = new Complex(1,0);
		Complex Eval = new Complex(Math.E,0);
		Complex Epow;
		Complex Transition;
		Complex Sum = new Complex(0,0);
		double val = 0;
		for(int i = 0 ; i<this.Image_Height;i++) {
			for(int j = 0;j<this.Image_Width;j++) {
				
				for(int k = 0;k<this.Image_Height;k++) {
					for(int l = 0;l<this.Image_Width;l++) {
						temp.Multiplication(this.Pixel_Matrix[k][l].r);
						val = 2*Math.PI*((((double)(k*i)/this.Image_Height) + ((double)(j*l)/this.Image_Width)));
						//System.out.format("k: %d, l:%d ,i:%d j:%d  val :  %f  \n",k,l,i,j,val );
						Transition = new Complex(val,0);
						Epow = new Complex(0,-1);
						Epow = Epow.Multiplication(Transition);

						Eval = Eval.Power(Epow);
						temp = temp.Multiplication(Eval);
						
						Sum=Sum.Add(temp);
						
						temp.Real=1;
						temp.Imaginary=0;
						Eval.Imaginary=0;
						Eval.Real=Math.E;
						val=0;
						
					}

				}
				
			
				Fourier_Matrix[i][j] = new Complex(Sum);
			    Sum.Imaginary=0;
			    Sum.Real=0;

			}
		}
		
		for(int i = 0; i <this.Image_Height;i++) {
			for(int j =0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r =(int) Fourier_Matrix[i][j].Real; 
				this.Pixel_Matrix[i][j].g =(int) Fourier_Matrix[i][j].Real; 
				this.Pixel_Matrix[i][j].b =(int) Fourier_Matrix[i][j].Real; 

			}
		}
		
		this.Logarithmic_Transformation();
		return Fourier_Matrix;

	}
	public void Negative_Transformation() {
		for(int i = 0 ;i<this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				this.Pixel_Matrix[i][j].r = 255 - 1 - this.Pixel_Matrix[i][j].r;
				this.Pixel_Matrix[i][j].g = 255 - 1 - this.Pixel_Matrix[i][j].g;
				this.Pixel_Matrix[i][j].b = 255 - 1 - this.Pixel_Matrix[i][j].b;
				this.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Power_Law_Transformation(double Gamma) {
		Math_Toolbox tlb = new Math_Toolbox();
		for(int i = 0 ; i<this.Image_Height;i++) {
			for(int j = 0 ; j <this.Image_Width;j++) {
				
				this.Pixel_Matrix[i][j].r = (int) tlb.Remap((float)Math.pow(Pixel_Matrix[i][j].r, Gamma), 0, (float)Math.pow(255, Gamma), 0, 255);
				this.Pixel_Matrix[i][j].g = (int) tlb.Remap((float)Math.pow(Pixel_Matrix[i][j].g, Gamma), 0, (float)Math.pow(255, Gamma), 0, 255);
				this.Pixel_Matrix[i][j].b = (int) tlb.Remap((float)Math.pow(Pixel_Matrix[i][j].b, Gamma), 0, (float)Math.pow(255, Gamma), 0, 255);

			}
		}
		this.Commint_Matrix_Changes();
	}
	public void Bit_Plane_Slice(int Plane) {
		int plane = 0;
		plane = (int)Math.pow(2, Plane);
		
		
		for(int i = 0 ; i<this.Image_Height;i++) {
			for(int j = 0 ; j<this.Image_Width;j++) {
				if(((this.Pixel_Matrix[i][j].r  & plane) ==0)) {
					this.Pixel_Matrix[i][j].r = 0;
				}
				if(((this.Pixel_Matrix[i][j].g  & plane)==0)) {
					this.Pixel_Matrix[i][j].g = 0;
				}
				if(((this.Pixel_Matrix[i][j].b  & plane)==0)) {
					this.Pixel_Matrix[i][j].b= 0;
				}
			

			}
		}
		this.Commint_Matrix_Changes();
	}
	
	public void Add_Gaussian_Noise(double Mean,double Variance) {
		
		double eq_1,eq_2,eq_3;
		eq_1 = 1D/(Math.sqrt(Variance)*Math.sqrt(2*Math.PI));
		
		
	}


//end of image class
}













	
