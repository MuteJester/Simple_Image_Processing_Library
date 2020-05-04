package JSipl;

import java.awt.BorderLayout;
import java.awt.image.BufferedImage;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class SIPL_Window extends JFrame{
	private static final long serialVersionUID = 1L;
	BufferedImage IMG;
	public boolean isopen;
	JLabel label;
	SIPL_Window(){
		this.isopen = true;

	}
	public SIPL_Window(BufferedImage img){
		this.IMG = img;
		//Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		label=new JLabel();
	    label.setIcon((Icon) new ImageIcon(IMG));
	    this.getContentPane().add(label,BorderLayout.CENTER);
	    //this.setLocationRelativeTo(null);
	    this.setSize(IMG.getWidth()+50, IMG.getHeight()+50);
		this.setVisible(true);
		this.setLayout(null);
		this.isopen = true;
	}
	public void start_window() {

		label=new JLabel();
	    this.setSize(300, 300);
		this.setVisible(true);
		this.setLayout(null);

	}
	
	public void Refresh_Frame(BufferedImage img) {
			this.IMG = img;
			label.setIcon((Icon) new ImageIcon(IMG));
		    this.setSize(IMG.getWidth(), IMG.getHeight());
		    this.revalidate();
		    this.repaint();
			//this.setVisible(true);
			//this.setLayout(null);
	}
	public void Refresh_Frame(BufferedImage img,int width,int height) {
		this.IMG = img;
		label.setIcon((Icon) new ImageIcon(IMG));
	    this.setSize(width, height);
	    this.revalidate();
	    this.repaint();
		//this.setVisible(true);
		//this.setLayout(null);
}
	
}
