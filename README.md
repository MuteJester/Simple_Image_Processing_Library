
[![Commits][commits-shield]][commits-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/MuteJester/Simple_Image_Processing_Library">
    <img src="Misc/SIPL_Logo.png" alt="Logo" width="280" height="280">
  </a>

  <h3 align="center">SIPL - Image Processing Library</h3>

  <p align="center">
    A Plug And Play Solution For Working With Images And Image Processing
    <br />
    <a href="https://github.com/MuteJester/Simple_Image_Processing_Library/wiki"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/MuteJester/Simple_Image_Processing_Library/wiki">View Demo</a>
    ·
    <a href="https://github.com/MuteJester/Simple_Image_Processing_Library/issues">Report Bug</a>
    ·
    <a href="https://github.com/MuteJester/Simple_Image_Processing_Library/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Notice](#notice)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)



<!-- ABOUT THE PROJECT -->
## About The Project
There are more then a few great Image Handlers and Image Processing librarys available on GitHub, however, I didn't find one that really suit my needs, the need to simply drag a file into my project folder and start coding ,a library with straightforward method names so it can be used without searching to much the web or reading a whole insturction manual so I created this simple plug and play library. I want to create an Image Handaling,Processing and Analysis library so efficient and simple that it'll be the last one you ever need.

Here's why SIPL:
* Your time should be focused on algorithms,developing something amazing,not learning shortened method names of a library
* You shouldn't install a huge amount of external dependencies to your project - SIPL has no external dependencies !
* You should be able to read any code written using SIPL and clrealy understand whats going on from the method names

Of course, for the time being the library is still under development so still it will not serve all projects since your needs may be different then what the library currently supports for you language or even at all . functions and features will be added in the near future. You may also suggest changes by forking this repo and creating a pull request or opening an issue.



### Built With
This section should list any major frameworks that you built your project using. Leave any add-ons/plugins for the acknowledgements section. Here are a few examples.
* [Bootstrap](https://getbootstrap.com)
* [JQuery](https://jquery.com)
* [Laravel](https://laravel.com)



<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Notice

* __C++ Version-__

SIPL can be used just by adding to your project all the header files and CPP files located in the __SIPL Core__ folder.
including only the core of the library will allow you to use all core features and methods without
the added functionality of the subclasses.
the main core provides all needed tools for image processing, analysis, and handling.
SIPL-C++  works best with __.jpg__  format,
the infrastructure used to load image binary data
was recently updated for better performance
as for now, SIPL uses the [stb load/write lib](https://github.com/nothings/stb) to load image data to memory and
to write processed data back to drive.

visual studio users if getting security error while compiling  
please add  ___CRT_SECURE_NO_WARNINGS__ to your preprocessor definitions setting 


__!Important!__ all sub-libraries and functionality relay on the Core files always include the core folder first!.


* __Java Version-__

SIPL can be used by adding to your projects /src folder  the "Image" java class file located under the __Java__ folder.
adding the the class file will allow you to use all core features and methods without
the added functionality of the subclasses.
the main core provides all needed tools for image processing, analysis, and handling

* __Python Version-__
SIPL can be used by adding to your projects folder the "SIPL_Python.py" file located under the __Python__ folder.
adding the the py file will allow you to import all core features and methods without
the added functionality of the subclasses.
the main core provides all needed tools for image processing, analysis, and handling

* Detailed tutorials about how to work with SIPL can be found in the wiki tab of this repository 




### Installation
1. Download The Corresponding Files From The Repository Folder Of Required Language 
* [Python Version](https://github.com/MuteJester/Simple_Image_Processing_Library/tree/master/Python)
* [C++ Version](https://github.com/MuteJester/Simple_Image_Processing_Library/tree/master/SIPL%20Core)
* [Java Version](https://github.com/MuteJester/Simple_Image_Processing_Library/tree/master/Java)
2. Copy All Classes/Files Into Your Projects /src or /main Folder
3. You Are Ready To Code!


<!-- USAGE EXAMPLES -->
## Usage


#### Face Detection (Real-Time Parametric)

<img src="Examples/FaceDetectionEX.jpg" alt="Logo" width="450" height="450">
SIPL Offers A Real-Time face detection algorithm which is parametric ,meaning theres is no machine learning involved in this spesific algorithm ,it tries to detect a face by color difference stated by the user. The success rate of the algorithm depends on the parameters passed to the function and they are individual for each image!.

#### Image Color Segmentation 

<img src="Examples/Kmeans 2-16.jpeg" alt="Logo" width="750" height="250">
SIPL Offers A Quick Algorithm For Image Color Segmentation Using K Means, useful for color variance reduction



* _For more Detailed Instructions, please refer to the [User Instructions](https://github.com/MuteJester/Simple_Image_Processing_Library/wiki/)_



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/othneildrew/Best-README-Template/issues) for a list of proposed features (and known issues).



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open-source community such a powerful place to create new ideas, inspire, and make progress. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Your Name - [Thomas Konstantin]() - thomaskon90@gmail.com

Project Link: [https://github.com/MuteJester/Simple_Image_Processing_Library](Link)




<!-- MARKDOWN LINKS & IMAGES -->
[commits-shield]: https://img.shields.io/github/commit-activity/m/MuteJester/Simple_Image_Processing_Library
[commits-url]: https://github.com/MuteJester/Simple_Image_Processing_Library
[stars-shield]: https://img.shields.io/github/stars/MuteJester/Simple_Image_Processing_Library.svg?style=flat-square
[stars-url]: https://github.com/MuteJester/Simple_Image_Processing_Library/stargazers
[issues-shield]:https://img.shields.io/github/issues/MuteJester/Simple_Image_Processing_Library?style=flat-square
[issues-url]: https://github.com/MuteJester/Simple_Image_Processing_Library/issues
[license-shield]: https://img.shields.io/github/license/MuteJester/Simple_Image_Processing_Library?style=flat-square
[license-url]: https://github.com/MuteJester/Simple_Image_Processing_Library/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/thomas-konstantinovsky-56230117b/

