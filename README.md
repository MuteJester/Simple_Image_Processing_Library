# _C++ Simple Image Processing Library_

__General Info__

Simple Image Processing Library For C++ or __SIPL__ ,Just Include The Header Files And Your Are Ready To Code!
A simple solution if you desire to process image data our work with images in general without altering 
projects linker settings and without adding additional dependencies .

SIPL work best with __.jpg__  format ,
the infrastructure used to load image binray data
was recently updated for better preformance
as for now SIPL uses stb-image library to load image data to memory and
to write processed data back to drive.

#### Inorder To Use SIPL:

SIPL can be used just by adding to your project all the 
header files and cpp files located in the __SIPL Core__ folder.
include only the core of the library will allow you to use all core features and methods without
the added functionality of the sub class.
the main core provides all needed tools for image processing and handeling.
__!Important!__ all sub librarys and functionality relay on the Core files always include core folder first!.

if getting security error while compiling  
please add  ___CRT_SECURE_NO_WARNINGS__ to your preprocessor defenitions setting 



## Class Functionality:

__Face Detection (Alpha Version Still Under Development)__:

Use:

`void Detect_Faces();`

Method scans image pixels and tries to detect and mark faces with a red square
if #define FaceDebug is defined then it will also mark and print in console all the verification steps
taken when the algorithm tries to recognize if it is looking at a face or not.
the algorithm uses real time data without comparing to eigenface or templates from memory nor any kind
of AI.

Example :
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/FaceDetectionEX.jpg  )

__Channel Graph__

Use:

`void Write_ChannelGraph();`

Method analyzes images data an saves a new image with RGB graps which show the amount of each color 
in each one of the image rows.
the image in project folder will be named "ChannelGraph.jpg"

Example: 
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/ChannelGraph%20Example.jpg )

__Pixel Compressor__

Use:

`void Compress();`

Method runs performs a check if and in what level the image pixel could be compressed then the method prompts the user
to select a level of compression and saves the compressed image to project diractory as well as modifying image data inside
the carrying object itself.
image is saved in diractory as "Compressed.jpg"

example:
before: ![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image3.jpg)

after:![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Compressed.jpg )


__Locate Pixel Difference__

Use:

`void Write_Pixel_Difference(Image &Source,const char *mode, int min_diff);`

Method takes as arguments ,another image object , you can also spesify "Copy" in the mode arguemnt in order to write and image with
an exact copy of the diffrent pixel between both images that will also require you to add the min differnce you allow to count
as a diffrent pixel.
leaving the method call with just another image will result an image inside the project diractory which will only color red the
Area and shape of diffrent pixels;
image will be saved as Pixel_Diffrence.jpg inside project diractory.

example:

Here are two images with some diffrences between them.

Imgage1:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/D6_1.jpg)

Image2:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/D6_2.jpg)

After Running the differnce writing algorithm: 

![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Pixel_Diffrence.jpg)


A method is availabe to mark the diffrene on the image it self.
for marking functionality use:

void Image::Mark_Identical_Pixels(Image &Source,const char *mode);

Passing aside another image one of 2 string which represent modes:
1)"Strict" - will find and mark anything even slightly different between 2 image pixels
2)"Loose" - will find and mark pixel which share no more then a color distance of 40 between both images

__Kronecker Product__

Use:

`void Kronecker_product(Image &b,const char *mode, const int Alter)`

Method converts both images to matrices and preforms Kronecker multiplication between all pixel creating
a new image loaded to the matrix part of object.
if alter arguemnt will be passed as one the pixel data of the image itself holded in object will be alterd as well as 
the height and width.

please keep in mind Kronecker product takes Image A an m × n Image and B is a p × q Image ,  Kronecker product will create a
new image A ⊗ B that will be:
the mp × nq of oiginal A and B, meaning if you use to images 100x100 pixels , the new image created will be 10,000x10,000 pixel
and the weight of the image will be corresponding. 
also please keep in mind there is a maximum an jpg can carry , the maximum is 65,535×65,535 pixels.
processing time may vary from 1 to 6 minutes depending on both image sizes.

the method contains 4 mode;
1. "Mul" - method will preforme a simple ,classic Kronecker multiplication 
2. "Size" - method will create a  Kronecker Product where the biggest pixels is selected each iteration 
3. "Build_From" - method will construct calling objects images using passed by argument image (as shown in example)
4. "Mix" - method will mix between the pixel of both images creating the Kroneckers Product of  the pixel mixture ;
 
 example:
 Image A:![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image6.jpg)
 
 Image B:![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image1.jpg)
 
 "Build From" Result:![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/KP.png)
 ![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/KP2.png)
 ![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/KP3.png)
 ![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/KP4.png)



__Write Channels__

Use:

`void Write_Channel(const char color);`

method takes as argument one of RGB colors as ,'r','g','b'.
and saves to project diractory only the selected channel of the picture;
example:

Image ![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image3.jpg)

R channel:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/WriteChannel%20R.jpg)
G channel:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/WriteChannel%20G.jpg)
B channel:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/WriteChannel%20B.jpg)



__Image Thresholding__

Use:

`void Tresholding(const char *mode,int value);`

methood takes as arguments one of current 2 modes and a value of diffrence on which the algorithm will run the tresholding
process ,the larger the value of "value" argument the staturation effected will be greater.

The two mode are:
1)"Trunc" - method using this mode will drop the lower pixel value and increase the larger
2)"EdgeTriggerd" - will drop pixels that are diffrent then the sequal before them. and increse the ones that follow the same weight.

example:

"Edge Triggerd":

![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Tresholding%20EdgeTriggerd.jpg)

"Trunc":
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Tresholding%20trunc.jpg)


__Feature Matching__

Use:

`void Feature_Matching(const int source_x, const int source_y);`

method takes a sample from the pixel located at passed by argument coordinates ,
runs trough images data inorder to find the same pixel in side the image.
its not enough for a pixel to have the same color it also needs to have the same surrounding,meaning
it will only mark the pixel that is identical to the one selected (if there is one such)
in the example i copied a the same image with some small differences .
you can see the algorithms marks in blue_red circles the matching pixels(the ones located in the postion passed by argument).
the algorithm connects the identical pixels with a blue line.

example:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Feature%20Matching%20Example.jpg)



__Edge Detection__

Use:

`void Image::Edge_Detection(const int max_color_gap);`

methood runs trough image data and modifying the loaded data in object in a way where only the edges of the image
remain colored in white.
the passed agrument is the maxium color gap allowed between pixels.
the higher the number the more loose the algorithm will treat pixel difference.

example:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image5.jpg)

after methood is called:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/EdgeDetection.jpg)


You can also use :

`void Mark_Contour(const char color, const int max_color_gap)`

to mark the Contour of an images without blacking the rest of the pixels.

Example:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Mark%20Countur.jpg)






###### Basic Operations



__Modifying A Single Index__ 


	void Set_Pixel_By_Inedx(int index, uint8_t value) :-
  
  Use an index in order to modify a spesific 1/3 pixel of an image
  keep in mind the each pixel consists of 3 index's
  
  __Loading A Blank Frame__
  
	void Load_Blank_Canvas() ;-
  
  Use the following function in order to load into class memory a black image
  when calling the methood it will prompt the user to input all needed data for 
  creation of the Canvas.
  
  
	void Load_Blank_Canvas(int width,int height,char set_color) :-
  
  Create clear canvas and load it the calss memory with starting fill defined by "set_color"
  the height of the canvas and the width passed to the method as argumetns
  no user prompt in the methood itself;
  
  __Printing Pixel Data To Console__
 
	void printImdata() ;-
  
  prints to consle a matrix of pixel (already compressed each 3 index's into a single color)
  the matrix is a char matrix where each char represents the color in the same position in the
  image , meaning if the (i,j) in matrix are = "b" it meants the(i,j) pixel in the image is
  blue, same goes for all base colors,
  for colors which are'nt in the base color group ,(r,g,b,W,B,G,y) , the matrix will display 'M'
  for "mixed" .
  
 
 __Prompt Drawing Method__
 
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
  
  
  __Load An Image Into Created Object__
  
  
	void Load_Image();
  
   calling the methood will prompt the user to load an image into method memory.
  
	void Load_Image(const char *f_name);
  
  overload of Load_Image() ,allows to load image into memory with prompting user simply by sending the method the file name.
  
  __Write The Image Data From Object To a .jpg In Poject Diractory__
  
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
  
  
  # Additional SIPL SubLibraries
  
  ## SIPL-Mole
  
  Mole is a direction based drawer , mole takes angles and distances as parameters and draws the equivalent on a jpg image
  Here are some examples of Mole functionality.
  more info about Mole Usage can be found in the wiki tab of this project.
  
Example1:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/MoleExample3.jpg)

Example2:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/MoleExample1.jpg)
  
  
  
  
## SIPL- Grapher

Grapher is another SIPL sub library ,
Grapher allows you to plot graphs with an orientation to graph theory graphs.
More info about the usage of Grapher can be found in the wiki tab of this project.

Examples Of Grapher.

An image created of an Interval Graph made from intervals loaded to Interval_Graph class.
![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/GrapherExample1.jpg)

  
