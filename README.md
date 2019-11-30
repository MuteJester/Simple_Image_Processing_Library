# Cpp-Image-Handle-Class
A small class based on the stb image library created for simple use and analysis of image pixel data in cpp

After searching the web for an easy and quick image handling library the closest thing i found that didnt include importing a nice amount 
data into each project was the std-image library which is a fantastic tool so first of all a big thank you to the creators and programers
of std library
https://github.com/nothings/stb

all you need to start using this class is to import 
the class header file and cpp file
as well as  the "stb_image_write.h"
and  "stb_image.h" and you are ready to code!


Class Functionality:

	void Set_Pixel_By_Inedx(int index, uint8_t value) :-
  
  Use an index in order to modify a spesific 1/3 pixel of an image
  keep in mind the each pixel consists of 3 index's
  
  
	void Load_Blank_Canvas() ;-
  
  Use the following function in order to load into class memory a black image
  when calling the methood it will prompt the user to input all needed data for 
  creation of the Canvas.
  
  
	void Load_Blank_Canvas(int width,int height,char set_color) :-
  
  Create clear canvas and load it the calss memory with starting fill defined by "set_color"
  the height of the canvas and the width passed to the method as argumetns
  no user prompt in the methood itself;
  
 
	void printImdata() ;-
  
  prints to consle a matrix of pixel (already compressed each 3 index's into a single color)
  the matrix is a char matrix where each char represents the color in the same position in the
  image , meaning if the (i,j) in matrix are = "b" it meants the(i,j) pixel in the image is
  blue, same goes for all base colors,
  for colors which are'nt in the base color group ,(r,g,b,W,B,G,y) , the matrix will display 'M'
  for "mixed" .
  
 
	void Manual_Draw():-
  
  calling this method prompts the user to use the arrow keys inorder to draw on loaded image\canvas
  it is not recomended for large images or canvas sizes as for the interface is being displayed on the
  consle window and large images will cause the console to shift values as for lack of space.
  
  Useage:
  arrow key to navigate accross pixels;
  press 'e' when the selector '[]',
  is on the disierd pixel.
  
  Insure that the selctor changed into "input mode" ,
  after hiting 'e', the selctor should go from '[]',to '_'.
  
  choose the new color by pressing one of the registred color keys (r,g,b,G,B,W,Y)
  after pressing one of the color keys the selector should display that the edit  
  was executed successfully and change from '_' to,'["Color_Pressed"]',
  example : 
    [] - press e 
    _ -  press g
    [g] <- color changed to green in the selected pixel.
  
  
  
	void Load_Image();
  
   calling the methood will prompt the user to load an image into method memory.
  
	void Load_Image(const char *f_name);
  
  overload of Load_Image() ,allows to load image into memory with prompting user simply by sending the method the file name.
  
	void Write_Image();
  
  prompts the user the saving sequance of the data loaded into calss memory.
  
	void Write_Image(const char *f_name);

  overload of the Write_Image() method, allows to saved the image data in calss by the name passed in the method call.
  
	void Color_Spec(int w, int h, char color);
  
   method allows to change the color of the image ,it takes 'w' and 'h' ,as the 'x' and 'y' cords of the disired pixel and 
   modify it to the passed color 'color'.
  
	void Color_Spec(int index, char color);
  
  overload of the Color_Spec() method, change a spesific pixel color by its starting index.
  (changes the whole pixel sequance of the spesific pixel)
