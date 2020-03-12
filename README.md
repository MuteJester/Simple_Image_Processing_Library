# _Simple Image Processing Library_

__General Info__

Simple Image Processing Library or __SIPL__ , Just Include The Header Files And Your Are Ready To Code!
A simple solution if you desire to process image data or work with images in general without altering 
projects linker settings and without adding additional dependencies.

SIPL works best with __.jpg__  format,
the infrastructure used to load image binary data
was recently updated for better performance
as for now, SIPL uses the stb-image library to load image data to memory and
to write processed data back to drive.

#### In order To Use SIPL:

SIPL can be used just by adding to your project all the header files and CPP files located in the __SIPL Core__ folder.
including only the core of the library will allow you to use all core features and methods without
the added functionality of the subclasses.
the main core provides all needed tools for image processing, analysis, and handling.
__!Important!__ all sub-libraries and functionality relay on the Core files always include the core folder first!.


* Detailed tutorials about how to work with SIPL can be found in the wiki tab of this repository 

if getting security error while compiling  
please add  ___CRT_SECURE_NO_WARNINGS__ to your preprocessor definitions setting 



## Library Functionality:

__Face Detection (Alpha Version Still Under Development)__:

Use:

`void Detect_Faces();`

The method scans image pixels and tries to detect and mark faces with a red square
if #define FaceDebug is defined then it will also mark and print in console all the verification steps
taken when the algorithm tries to recognize if it is looking at a face or not.
the algorithm uses real-time data without comparing to eigenface or templates from memory nor any kind
of AI.

Example :
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/FaceDetectionEX.jpg  )


__Figure Detection__

Use:

`	void Figure_Detection(int const &blob_distance_treshold, int const &color_distance_treshold,int const &Thresholding_level);`

The method runs an analysis and mark all the significant objects in the picture (compared to the the whole image)
and loads an edited image to object's memory , all the "significant" objects will be marked by a red frame around the object.

Example:

![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/OD%20example%204.jpg)




__Image Segmentation__

Use:

` void Image_Segmentation(int const &k, int const &iterations, int const &alter);`

Calling the method will segment the image into the specified amount of colors depending on the average colors of the given image,
the method uses machine learning in order to find the specified amount of average colors and segment the image.
detailed use instructions can be find in the wiki tab under the SIPL-Core tab.

Examples:

Original Image: ![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image5.jpg)

Segmentation Using K = {2,3,4,5,8,16} - 

![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Kmeans%202-16.jpeg)




__Channel Graph__

Use:

`void Write_ChannelGraph();`

The method analyzes images data and saves a new image with RGB graphs which show the amount of each color in each one of the image rows.
the image in the project folder will be named "ChannelGraph.jpg"

Example: 
![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/ChannelGraph.jpg )


__Getting Average Color Palette__

Use:

 `void Write_Average_Color_Palette(int const &palette_size);`
 
 The method takes an integer as argument ,depending on the value the method will use machine learning in order  to find the passed value amount of dominant colors in the image , the method will output a .jpg image representing the average color palette of the image loaded on objects memory, detailed use instructions can be found in the wiki tab.
 
 Examples:
 
 Original Image: ![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image5.jpg)
 
 Palettes of images 4,8 and 16 average colors:
 
4:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Average_4_Color_Palette.jpg)
8:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Average_8_Color_Palette.jpg)
16:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Average_16_Color_Palette.jpg)




__Pixel Compressor__

Use:

`void Compress();`

The method performs a check if and in what level the image pixel could be compressed then the method prompts the user
to select a level of compression and saves the compressed image to project directory as well as modifying image data inside
the carrying object itself.
image is saved in directory as "Compressed.jpg"

example:
before: ![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image3.jpg)

after:![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Compressed.jpg )


__Locate Pixel Difference__

Use:

`void Write_Pixel_Difference(Image &Source,const char *mode, int min_diff);`

The method takes as arguments another image object, you can also specify "Copy" in the mode argument in order to write an image with
an exact copy of the different pixels between both images that will also require you to add a value that will represent the minimum difference to be considered.
leaving the method call with just another image will result in an image inside the project directory which will only color red the
Area and shape of different pixels;
the image will be saved as Pixel_Diffrence.jpg inside the project directory.

example:

Here are two images with some differences between them.

Imgage1:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/D6_1.jpg)

Image2:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/D6_2.jpg)

After Running the difference writing algorithm: 

![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Pixel_Diffrence.jpg)


There is a method for marking of different pixels as well.
 functionality usage:

void Image::Mark_Identical_Pixels(Image &Source,const char *mode);

Passing aside another image one of 2 strings which represent mods:
1)"Strict" - will find and mark anything even slightly different between 2 image pixels
2)"Loose" - will find and mark pixels which share no more than a color distance of 40 between both images

__Kronecker Product__

Use:

`void Kronecker_product(Image &b,const char *mode, const int Alter)`

The method converts both images to matrices and preforms Kronecker multiplication between all pixels creating
a new image loaded to the matrix part of the object.
if alter argument will be passed as '1' the pixel data of the image itself held in the object will be altered as well as the height and width.

please keep in mind Kronecker product takes Image A an m × n Image and B is a p × q Image,  Kronecker product will create a
new image A ⊗ B that will be:
the mp × nq of original A and B, meaning if you use two images 100x100 pixels, the new image created will be 10,000x10,000 pixels
and the weight of the image will be corresponding. 
also please keep in mind there is a maximum a jpg can carry, the maximum is 65,535×65,535 pixels.
processing time may vary from 1 to 6 minutes depending on both image sizes.

the method contains 4 mods;
1. "Mul" - method will perform a simple, classic Kronecker multiplication 
2. "Size" - method will create a  Kronecker Product where the biggest pixels is selected each iteration 
3. "Build_From" - method will construct calling objects images using passed by argument image (as shown in the example)
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

the method takes as argument one of RGB colors as,'r','g','b'.
and saves to project directory only the selected channel of the picture;
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

the method takes as arguments one of current 2 mods and a value of difference on which the algorithm will run the thresholding
process, the larger the value of the "value" argument the saturation effected will be greater.

The two modes are:
1)"Trunc" - method using this mode will drop the lower pixel value and increase the larger
2)"EdgeTriggerd" - will drop pixels that are different than the sequel before them. and increase the ones that follow the same weight.

example:

"Edge Triggerd":

![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Tresholding%20EdgeTriggerd.jpg)

"Trunc":
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Tresholding%20trunc.jpg)



__Image Convolution__

Use:
  `	void Image_Convolution(int const &iterations, int const &alter,const char *Type);`
  
  Or
  
  `	void Image_Convolution(double Kernel[3][3],int const &iterations,int const &alter);`
  
  The Method will preforme a convolution on the images via a kernel passed by arguemnt or by one of the built in kernels 
  which can be used by passing there names a aruments ,
  currently there are 2 built in blur kernels ,"Mean" blur and "Gaussian" Blur .
  
  Example of a "Mean" Blur:
  
  Original:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Image311.jpg)
  Blured:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Mean%20Blur.jpg)
  
  Example Of A "Gaussian" Blur:
  Original:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Image511.jpg)
  Blured:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Gaussian%20Blur.jpg)


__Feature Matching__

Use:

`void Feature_Matching(const int source_x, const int source_y);`

the method takes a sample from the pixel located at passed by argument coordinates,
runs trough images data in order to find the same pixel inside the image.
it's not enough for a pixel to have the same color it also needs to have the same surrounding, meaning
it will only mark the pixel that is identical to the one selected (if there is one such)
in the example, I copied the same image with some small differences.
you can see the algorithms marks in blue_red circles the matching pixels(the ones located in the position passed by argument).
the algorithm connects the identical pixels with a blue line.

example:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Feature%20Matching%20Example.jpg)



__Edge Detection__

Use:

`void Image::Edge_Detection(const int max_color_gap);`

the method runs trough image data and modifying the loaded data in an object in a way where only the edges of the image
remain colored in white.
the passed argument is the maximum color gap allowed between pixels.
the higher the number the looser the algorithm will treat pixel difference.

example:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Image5.jpg)

after methood is called:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/EdgeDetection.jpg)


You can also use :

`void Mark_Contour(const char color, const int max_color_gap)`

to mark the Contour of an image without blacking the rest of the pixels.

Example:
![Alt text](https://github.com/MuteJester/Cpp-Image-Handle-Class/blob/master/Examples/Mark%20Countur.jpg)




__Recreate Using Machine Learning And Drawing Lines__

Use:

`void Image::Image_Rebuild_With_Lines(int const &Iterations)`

The method will run a machine learning algorithm which will try to recreate the original image loaded to objects memory by creating
random lines with random lengths and positions, the machine learning itself will need to select the colors for the randomly appearing lines in order to get closer to the original image , the greater the value of iterations the closer the output image will be to the original .

Here is the logo of Holon institute  of technology:

![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Image7.jpg)

And here is a short gif of the firt few thousand of iterations made and the process of the machine in those few thousand rounds.

![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/hit-ML-gif.gif)


And another small example:

Original: ![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Image61.jpg)


After a few thousand iterations:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/im4_example_gif.gif)


###### Basic Operations



__Modifying A Single Index__ 


    void Set_Pixel_By_Inedx(int index, uint8_t value) :-
  
  Use an index to modify a specific 1/3 pixel of an image
  keep in mind each pixel consists of 3 index's
  
  __Loading A Blank Frame__
  
    void Load_Blank_Canvas() ;-
  
  Use the following function to load into class memory a black image
  when calling the method it will prompt the user to input all needed data for 
  creation of the Canvas.
  
  
    void Load_Blank_Canvas(int width,int height,char set_color) :-
  
  Create a clear canvas and load it the class memory with starting fill defined by "set_color"
  the height of the canvas and the width passed to the method as arguments
  no user prompt in the method itself;
  
  __Printing Pixel Data To Console__
 
    void printImdata() ;-
  
  prints to console a matrix of pixels (already compressed each 3 index's into a single color)
  the matrix is a char matrix where each char represents the color in the same position in the
  image , meaning if the (i,j) in matrix are = "b" it means the(i,j) pixel in the image is
  blue, same goes for all base colors,
  for colors which aren't in the base color group ,(r,g,b,W,B,G,y) , the matrix will display 'M'
  for "mixed".
  
 
 __Prompt Drawing Method__
 
    void Manual_Draw():-
  
  calling this method prompts the user to use the arrow keys in order to draw on loaded image\canvas
  it is not recommended for large images or canvas sizes as for the interface is being displayed on the
  console window and large images will cause the console to shift values as for lack of space.
  
  Usage:
  arrow key to navigate across pixels;
  Press 'e' when the selector '[]',
  is on the desired pixel.
  
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
  
   calling the method will prompt the user to load an image into method memory.
  
    void Load_Image(const char *f_name);
  
  overload of Load_Image() , allows loading image into memory with prompting user simply by sending the method the file name.
  
  __Write The Image Data From Object To a .jpg In Project Diractory__
  
    void Write_Image();
  
  prompts the user the saving sequence of the data loaded into class memory.
  
    void Write_Image(const char *f_name);

  overload of the Write_Image() method, allows us to save the image data in class by the name passed in the method call.
  
    void Color_Spec(int w, int h, char color);
  
   the method allows to change the color of the image, it takes 'w' and 'h' , as the 'x' and 'y' cords of the desired pixel and 
   modify it to the passed color 'color'.
  
    void Color_Spec(int index, char color);
  
  overload of the Color_Spec() method, change a specific pixel color by its starting index.
  (changes the whole pixel sequence of the specific pixel)
  
  
  # Additional SIPL SubLibraries
  
  ## SIPL-Mole
  
  Mole is a direction based drawer, mole takes angles and distances as parameters and draws the equivalent on a jpg image
  Here are some examples of Mole functionality.
  more info about Mole Usage can be found in the wiki tab of this project.
  
* Example1:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/MoleExample3.jpg)

* Example2:![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/MoleExample1.jpg)
  
* Example3: ![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/Mole%20Example2.jpg)
  
  
  
## SIPL- Grapher

Grapher is another SIPL sub library,
Grapher allows you to plot graphs with an orientation to graph theory graphs.
More info about the usage of Grapher can be found in the wiki tab of this project.

Examples Of Grapher.

An image created of an Interval Graph made from intervals loaded to Interval_Graph class.
![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/GrapherExample1.jpg)

A Regular Graph Illustration:
* Example of a graph G made from 4 vertices and 4 edges between {V0-V1,V0-V3,V1-V2,V1-V3};

![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/G%20Example%20Drawer.jpg)

* the method also allows the user to choose if to out put the regular graph or its complement ,here is the complement  of the above example :

![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/G%20comp%20Example%20Drawer.jpg)



Detailed instructions on how to use SIPL - Grapher can be found in the wiki tab;



  ## SIPL-Algiplot
  
  Algiplot is another SIPL sub library which allows plotting of 2D and 3D graphs ,
  currently Algiplot only supports ploting of the graph frame and point creation on the graph plane,
  Algiplot as any other SIPL library runs using the SIPL-Core library .
  
 More information on how to use Algiplot can be found in the wiki tab.
  
  Examples of 2D and 3D ploting;
  
  * 2D:
  
  ![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/2d%20plot%20wpoint.jpg)


* 3D:  

 ![Alt text](https://github.com/MuteJester/Cpp_Simple_Image_Processing_Library/blob/master/Examples/3d%20w-points%20example.jpg)



  
