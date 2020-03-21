from imageio import *
from numpy import *
import os

class Pixel:
    Color = []
    def __init__(self,r : int ,g : int , b : int):
        self.Color = [r,g,b]
    def __str__(self):
        return "R: " + str(self.Color[0]) +" G: " + str(self.Color[1]) + " B: "+ str(self.Color[2])
    def __int__(self):
        return [self.Color[0],self.Color[1],self.Color[2]]

class Blob:
    Upleft_X = None
    Upleft_Y = None
    Downright_X= None
    Downright_Y = None
    Distnace_Treshold = None
    def __init__(self,x , y ,Distnace_Treshold):
        self.Downright_X = x
        self.Downright_Y = y
        self.Upleft_X = x
        self.Upleft_Y = y
        self.Distnace_Treshold = Distnace_Treshold
    def near(self,x,y):
        CenterX,CenterY,Dist = None
        CenterX = max(min(x,self.Upleft_X),self.Downright_X)
        CenterY = max(min(y,self.Upleft_Y),self.Downright_Y)
        Dist = cordinate_distance(CenterX,CenterY,x,y)
        if(Dist < self.Distnace_Treshold*self.Distnace_Treshold):
            return True
        else:
            return False
    def add(self,px,py):
        self.Downright_X = min(self.Downright_X,px)
        self.Downright_Y = min(self.Downright_Y,py)

        self.Upleft_X = max(self.Upleft_X,px)
        self.Upleft_Y = max(self.Upleft_Y,py)

    def clear(self):
        self.Upleft_Y = self.Upleft_X = self.Downright_Y = self.Downright_X = -1
    def set_props(self,x,y):
        self.Downright_X = x
        self.Downright_Y = y
        self.Upleft_X = x
        self.Upleft_Y = y
    def size(self):
        return abs((self.Upleft_X-self.Downright_X)*(self.Upleft_Y-self.Downright_Y))

class Color_Palette:
    def Black(self):
          return [0,0,0]
    def White(self):
         return [255, 255, 255]
    def Red(self):
         return [255, 0, 0]
    def Lime(self):
        return [0, 255, 0]
    def Blue(self):
         return [0, 0, 255]
    def Yellow(self):
        return [255, 255, 0]
    def Cyan(self):
        return [0, 255, 255]
    def Magenta(self):
     return [255, 0, 255]
    def Silver(self):
        return [192, 192, 192]
    def Gray(self):
        return [128, 128, 128]
    def Maroon(self):
        return [128, 0, 0]
    def Olive(self):
        return [128, 128, 0]
    def Green(self):
        return [0, 128, 0]
    def Purple(self):
        return [128, 0, 128]
    def Teal(self):
        return [0, 128, 128]
    def Navy(self):
        return [0, 0, 128]
    def Dark_Red(self):
        return [139, 0, 0]
    def Brown(self):
        return [165, 42, 42]
    def Firebrick(self):
        return [178, 34, 34]
    def Crimson(self):(220, 20, 60)
    def Tomato(self):
        return [255, 99, 71]
    def Coral(self):
        return [255, 127, 80]
    def Indian_Red(self):
        return [205, 92, 92]
    def Light_Coral(self):
        return [240, 128, 128]
    def Dark_Salmon(self):
        return [233, 150, 122]
    def Salmon(self):
        return [250, 128, 114]
    def Light_Salmon(self):
        return [255,160,122]
    def Orange_Red(self):
        return [255,69,0]
    def Dark_Orange(self):
        return [255,140,0]
    def Orange(self):
        return [255,165,0]
    def Gold(self):
        return [255,215,0]
    def Dark_Golden_Rod(self):
        return [184,134,11]
    def Golden_Rod(self):
        return [218,165,32]
    def Pale_Golden_Rod(self):
        return [238,232,170]
    def Dark_Khaki(self):
        return [189,183,107]
    def Khaki(self):
        return [240,230,140]
    def Yellow_Green(self):
        return [154,205,50]
    def Dark_Olive_Green(self):
        return [85,107,47]
    def Olive_Drab(self):
        return [107,142,35]
    def Lawn_Green(self):
        return [142,252,0]
    def Chart_Reuse(self):
        return [127,255,0]
    def Green_Yellow(self):
        return [173,255,47]
    def Dark_Green(self):
        return [0,100,0]
    def Forest_Green(self):
        return [34,139,34]
    def Lime_Green(self):
        return [50,205,50]
    def Light_Green(self):
        return [144,238,144]
    def Pale_Green(self):
        return [152,251,152]
    def Dark_Sea_Green(self):
        return [143,188,143]
    def Medium_Spring_Green(self):
        return [0,250,154]
    def Spring_Green(self):
        return [0,255,127]
    def Sea_Green(self):
        return [46,139,87]
    def Medium_Aqua_Marine(self):
        return [102,205,170]
    def Medium_Sea_Green(self):
        return [60,179,113]
    def Light_Sea_Green(self):
        return [32,178,170]
    def Dark_Slate_Gray(self):
        return [47,79,79]
    def Dark_Cyan(self):
        return [0,139,139]
    def Light_Cyan(self):
        return [224,255,255]
    def Dark_Turquoise(self):
        return [0,206,209]
    def Turquoise(self):
        return [64,224,208]
    def Medium_Turquoise(self):
        return [72,209,204]
    def Pale_Turquoise(self):
        return [175,238,238]
    def Aqua_Marine(self):
        return [127,255,212]
    def Powder_Blue(self):
        return [176,224,230]
    def Cadet_Blue(self):
        return [95,158,160]
    def Steel_Blue(self):
        return [70,130,180]
    def Corn_Flower_Blue(self):
        return [100,149,237]
    def Deep_Sky_Blue(self):
        return [0,191,255]
    def Dodger_Blue(self):
        return [30,144,255]
    def Light_Blue(self):
        return [173,216,230]
    def Sky_Blue(self):
        return [135,206,235]
    def Light_Bky_Blue(self):
        return [135,206,250]
    def Midnight_Blue(self):
        return [25,25,112]
    def Dark_Blue(self):
        return [0,0,139]
    def Medium_Blue(self):
        return [0,0,205]
    def Royal_Blue(self):
        return [65,105,225]
    def Blue_Violet(self):
        return [138,43,226]
    def Indigo(self):
        return [75,0,130]
    def Dark_Slate_Blue(self):
        return [72,61,139]
    def Slate_Blue(self):
        return [106,90,205]
    def Medium_Slate_Blue(self):
        return [123,104,238]
    def Medium_Purple(self):
        return [147,112,219]
    def Dark_Magenta(self):
        return [139,0,139]
    def Dark_Violet(self):
        return [148,0,211]
    def Dark_Orchid(self):
        return [153,50,204]
    def Medium_Orchid(self):
        return [186,85,211]
    def Thistle(self):
        return [216,191,216]
    def Plum(self):
        return [221,160,221]
    def Violet(self):
        return [238,130,238]
    def Orchid(self):
        return [218,112,214]
    def Medium_Violet_Red(self):
        return [199,21,133]
    def Pale_Violet_Red(self):
        return [219,112,147]
    def Deep_Pink(self):
        return [255,20,147]
    def Hot_Pink(self):
        return [255,105,180]
    def Light_Pink(self):
        return [255,182,193]
    def Pink(self):
        return [255,192,203]
    def Antique_White(self):
        return [250,235,215]
    def Beige(self):
        return [245,245,220]
    def Bisque(self):
        return [255,228,196]
    def Blanched_Almond(self):
        return [195,135,205]
    def Wheat(self):
        return [245,222,179]
    def Corn_Silk(self):
        return [255,248,220]
    def Lemon_Chiffon(self):
        return [255,250,205]
    def Light_Golden_Rod_Yellow(self):
        return [250,250,210]
    def Light_Yellow(self):
        return [255,255,224]
    def Saddle_Brown(self):
        return [139,69,19]
    def Sienna(self):
        return [160,82,45]
    def Chocolate(self):
        return [210,105,30]
    def Peru(self):
        return [205,133,63]
    def Sandy_Brown(self):
        return [244,164,96]
    def Burly_Wood(self):
        return [222,184,135]
    def Tan(self):
        return [210,180,140]
    def Rosy_Brown(self):
        return [188,143,143]
    def Moccasin(self):
        return [255,228,181]
    def Navajo_White(self):
        return [255,222,173]
    def Peach_Puff(self):
        return [255,218,185]
    def Misty_Rose(self):
        return [255,228,225]
    def Lavender_Blush(self):
        return [255,240,245]
    def Linen(self):
        return [250,240,230]
    def Old_Lace(self):
        return [253,245,230]
    def Papaya_Whip(self):
        return [255,239,213]
    def Sea_Shell(self):
        return [255,245,255]
    def Mint_Cream(self):
        return [245,255,250]
    def Slate_Gray(self):
        return [112,128,144]
    def Light_Slate_Gray(self):
        return [119,136,153]
    def Light_Steel_Blue(self):
        return [176,196,222]
    def Lavender(self):
        return [230,230,250]
    def Floral_White(self):
        return [255,250,240]
    def Alice_Blue(self):
        return [240,248,255]
    def Ghost_White(self):
        return [240,248,255]
    def Honeydew(self):
        return [240,255,240]
    def Ivory(self):
        return [255,255,240]
    def Azure(self):
        return [240,255,255]
    def Snow(self):
        return [255,250,250]
    def Dim_Gray(self):
        return [105,105,105]
    def Dark_Gray(self):
        return [169,169,169]
    def Light_Gray(self):
        return [211,211,211]
    def Gainsboro(self):
        return [220,220,220]
    def White_Smoke(self):
        return [245,245,245]

class SPoint:
    x =None
    y =None
    z =None
    def __init__(self,x,y,z):
        self.x =x
        self.y =y
        self.z =z


def get_square(x):
    return x*x
def color_distance(a : list, b : list):
    record = (a.b - b.b) + (a.r - b.r) + (a.g - b.g)
    if (record < 0):
      record *= -1
    return record;
def cordinate_distance(x0,y0,x1,y1):
    return pow((x1-x0),2)+pow((y1-y0),2)
def squared_3Point_distance(first : SPoint,second : SPoint):
    return get_square(first.x - second.x) + get_square(first.y - second.y) + get_square(first.z - second.z)
def color_delta( A, B):
    R_Gag = (A[0] + B[0]) / 2
    r = A[0] - B[0]
    g = A[1] - B[1]
    b = A[2] - B[2]
    return sqrt((((512 + R_Gag) * r * r) >> 8) + 4 * g * g + (((767 - R_Gag) * b * b) >> 8))
def color_distance_sq(a : list, b : list):
    return int(sqrt(get_square((int(int(b[0]) - int(a[0])))) + get_square((int(int(b[1]) - int(a[1])))) + get_square((int(int(b[2]) - int(a[2]))))))


class Simage:
    pixel_matrix = None
    Image_Width = None
    Image_Height = None

    def load_image(self,file_name : str):
        self.pixel_matrix = imread(file_name)
        tup = self.pixel_matrix.shape
        self.Image_Height = tup[0]
        self.Image_Width = tup[1]

    def write_image(self,save_name : str):
        imwrite(save_name, self.pixel_matrix)

    def convert_to_grayscale(self):

        for i in range(self.Image_Height-1):
            for j in range(self.Image_Width-1):
             if self.pixel_matrix[i][j][2] >= self.pixel_matrix[i][j][0] and self.pixel_matrix[i][j][2] >= self.pixel_matrix[i][j][1]:
               self.pixel_matrix[i][j][0] = self.pixel_matrix[i][j][2]
               self.pixel_matrix[i][j][1] = self.pixel_matrix[i][j][2]
             elif self.pixel_matrix[i][j][0] >= self.pixel_matrix[i][j][2] and self.pixel_matrix[i][j][0] >= self.pixel_matrix[i][j][1]:
                 self.pixel_matrix[i][j][2] = self.pixel_matrix[i][j][0]
                 self.pixel_matrix[i][j][1] = self.pixel_matrix[i][j][0]
             elif self.pixel_matrix[i][j][1] >= self.pixel_matrix[i][j][0] and self.pixel_matrix[i][j][1] >= self.pixel_matrix[i][j][2]:
                self.pixel_matrix[i][j][0] = self.pixel_matrix[i][j][1]
                self.pixel_matrix[i][j][2] = self.pixel_matrix[i][j][1]

    def draw_line(self,start_y,start_x,target_y,target_x,Color : list):
        dx = None
        sx = None
        dy = None
        sy = None
        err  = None
        e2 = None
        x0 = start_y
        x1 = target_y
        y0 = start_x
        y1 = target_x
        dx = abs(target_y - start_y)
        if start_y < target_x:
            sx = 1
        else:
            sx = -1
        dy = -abs(target_x - start_x)
        if start_x < target_x:
            sy = 1
        else:
            sy = -1
        err = dx + dy

        while True:
            if x0 == x1 and y0 == y1:
              self.pixel_matrix[(x0)][(y0)] = Color
              break
            self.pixel_matrix[(x0)][(y0)] = Color

            e2 = 2 * err
            if e2 >= dy:
                err += dy
                x0 += sx

            if e2 <= dx:
                err += dx
                y0 += sy

    def draw_square(self, center_x, center_y, s_width, s_height, color, mode):
        if mode == "Fill":
            if center_x + s_width > self.Image_Width or center_y + s_height > self.Image_Height or center_x - s_width < 0 or center_y - s_height < 0:
                print("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n")
                print("Height Of Image: " + str(self.Image_Height))
                print("Width Of Image: " + str(self.Image_Width))
                return
            for j in range(center_y - s_height, center_y + s_height):
                for i in range(center_x - s_width, center_x + s_width):
                    self.pixel_matrix[j][i] = color
        elif mode == "Checkered":
            if center_x + s_width > self.Image_Width or center_y + s_height > self.Image_Height or center_x - s_width < 0 or center_y - s_height < 0:
                print("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n")
                print("Height Of Image: " + str(self.Image_Height))
                print("Width Of Image: " + str(self.Image_Width))
                return
            for j in range(center_y - s_height, center_y + s_height,2):
                for i in range(center_x - s_width, center_x + s_width, 2):
                    self.pixel_matrix[j][i] = color

        elif mode == "Corners":
            if center_x + s_width > self.Image_Width or center_y + s_height > self.Image_Height or center_x - s_width < 0 or center_y - s_height < 0:
                 print("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n")
                 print("Height Of Image: " + str(self.Image_Height))
                 print("Width Of Image: " + str(self.Image_Width))
                 return
            self.Draw_Line(center_x, center_y, s_width, center_y, color)
            self.Draw_Line(center_x, center_y, center_x, s_height, color)
            self.Draw_Line(center_x, s_height, s_width, s_height, color)
            self.Draw_Line(s_width, center_y, s_width, s_height, color)
        else:
            if center_x + s_width > self.Image_Width or center_y + s_height > self.Image_Height or center_x - s_width < 0 or center_y - s_height < 0:
                print("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n")
                print("Height Of Image: " + str(self.Image_Height))
                print("Width Of Image: " + str(self.Image_Width))
                return
            for i in range(center_x - s_width, center_x + s_width):
                self.pixel_matrix[center_y + s_height][i] = color
            for i in range(center_x - s_width, center_x + s_width):
                self.pixel_matrix[center_y - s_height][i] = color
            for i in range(center_y - s_height, center_y + s_height):
                self.pixel_matrix[i][center_x - s_width] = color
            for i in range(center_y - s_height, center_y + s_height):
                self.pixel_matrix[i][center_x + s_width] = color

    def draw_circle(self, center_x, center_y, c_radius, color, Mode):
        if Mode == "Fill":
            x = None
            y = None
            if center_x + c_radius > self.Image_Width or center_x - c_radius < 0 or center_y + c_radius > self.Image_Height or center_y - c_radius < 0:
                print("Out of image bounds")
                return
            for y in range(-c_radius, c_radius):
                for x in range(-c_radius, c_radius):
                    if (x * x) + (y * y) <= (c_radius * c_radius):
                        self.pixel_matrix[center_y + y][center_x + x] = color
        else:
            if center_x + c_radius > self.Image_Width or center_x - c_radius < 0 or center_y + c_radius > self.Image_Height or center_y - c_radius < 0:
                print("Out of image bounds")
                return
            r2 = c_radius * c_radius
            y = None
            for x in range(-c_radius, c_radius):
                y = int(sqrt(r2 - x * x) + 0.5)
                self.pixel_matrix[center_y + y][center_x + x] = color
                self.pixel_matrix[center_y + y][center_x - x] = color

            for x in range(-c_radius, c_radius):
                y = int(sqrt(r2 - x * x) + 0.5)
                self.pixel_matrix[center_y - y][center_x + x] = color
                self.pixel_matrix[center_y - y][center_x - x] = color

            for x in range(-c_radius, c_radius):
                y = int(sqrt(r2 - x * x) + 0.5)
                self.pixel_matrix[center_y - x][center_x + y] = color
                self.pixel_matrix[center_y - x][center_x - y] = color

    def load_blank_canvas(self,Height,Width,Background):
        self.pixel_matrix = zeros(shape =(Height,Width,3),dtype=uint8)
        for i in range(Height):
            for j in range(Width):
                self.pixel_matrix[i][j] = Background
        self.Image_Height = Height
        self.Image_Width = Width

    def image_difference_value(self, b):
        result = 0
        for i in range(self.Image_Height):
            for j in range(self.Image_Width):
                result = result + int(color_distance_sq(self.pixel_matrix[i][j], b.pixel_matrix[i][j]))
        return (result / self.Image_Height * self.Image_Width)

    def distance_neighbors(self, max_distance, i, j):
        point = None
        center = self.pixel_matrix[i][j]
        dist = 0
        if (i - 1 < 0 and j + 1 < self.Image_Width and j - 1 > 0 and i + 1 < self.Image_Height):
            point = self.pixel_matrix[i][j + 1]
            dist = (color_distance_sq(point, center))
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i][j - 1]
            dist = (color_distance_sq(point, center))
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i + 1][j]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i + 1][j - 1];
            dist = color_distance_sq(point, center);
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i + 1][j + 1];
            dist = color_distance_sq(point, center);
            if dist > max_distance:
                return False
        if (i + 1 > self.Image_Height and j + 1 < self.Image_Width and j - 1 > 0 and i - 1 > 0):
            point = self.pixel_matrix[i][j + 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i][j - 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
              return False
            point = self.pixel_matrix[i - 1][j]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i - 1][j + 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i - 1][j - 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
        if (j - 1 < 0 and i + 1 < self.Image_Height and i - 1 > 0 and j + 1 < self.Image_Width):
            point = self.pixel_matrix[i + 1][j]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i + 1][j + 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i - 1][j + 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i - 1][j]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i][j + 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False

        if (j + 1 > self.Image_Width and i + 1 < self.Image_Height and i - 1 > 0 and j - 1 > 0):
            point = self.pixel_matrix[i][j - 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i - 1][j]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False

            point = self.pixel_matrix[i - 1][j - 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i + 1][j]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
            point = self.pixel_matrix[i + 1][j - 1]
            dist = color_distance_sq(point, center)
            if dist > max_distance:
                return False
        return True


CSET = Color_Palette()
x = Simage()
y = Simage()
x.load_image("Image3.jpg")
y.load_image("Image3.jpg")
y.draw_circle(50,50,5,CSET.Red(),"def")
#x.draw_circle(500,500,50,CSET.Red(),"DEf")
print(x.distance_neighbors(330,50,50))
x.write_image("test.png")
#os.system("test.png")