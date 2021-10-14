

## Installation

All the code has been developed and tested with following system specifications.  
    - Ubuntu 20.04  
    - Qt 5.13.2  
    - VTK 7.0  
    - PCL 1.12  
    - CMake > 3.0  
    - gcc 9.3.0  
    - C compiler  
    - OpenGL  
    - X lib  
    - Eigen 3.3  
    - FLANN  
    - Boost  
    - libpng  
    - libQhull
    - OpenNI  
    - OpenNI2  
    - libglew  
    - libusb  
    - pcap  


## Setup  

1. Install gcc and C compiler:  

        sudo apt-get install build-essential  

2. Install OpenGL:  

        sudo apt-get install libgl1-mesa-dev  

3. Install X lib:  
        
        sudo apt-get install libxt-dev  

4. Install Eigen:  

        sudo apt-get install libeigen3-dev  

5. Install FLANN:  

        sudo apt-get install -y libflann-dev  

6. Install Boost:  

        sudo apt-get install libboost-all-dev  

7. Install libpng  
        
        sudo apt install libpng-dev

8. Install libQhull  

        sudo apt-get install -y libqhull-dev

9. Install OpenNI  

        sudo apt-get install -y openni-utils

10. Install OpenNI2  

        sudo apt-get install libopenni2-dev

11. Install libglew  

        sudo apt-get install -y libglew-dev

12. Install libusb  

        sudo apt-get install -y libusb-1.0-0
		
13. Install pcap  

		sudo apt-get install libpcap-dev

14. Install Qt 5.13.2:  

	a. Create account on Qt [website](https://login.qt.io/register).  
	b. Download online installer from [here](https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4).  
	c. Right click on the downloaded file, properties->Permissions, click on **Execute** option.  
	d. Double click on the downloaded file, provide login credentials in **Welcome** page. Click **Next**.  
	e. On **Open Source Obligations** page click on **I have read and approve the obligations of using Open Source Qt** option.  
	f. Enter the company name in the field provided. Click **Next**.  
	g. On **Setup-Qt** page click **Next**.  
	h. On **Contribute to Qt Development** page click **Disable sending pseudonymous usage statistics in Qt Creator**  option and click **Next**.  
	i. On **Installation Folder**	browse and select the installation folder to be used like `/home/user/Qt` and click **Next**.  
	j. On **Select Components** page, under **QT** tag select Qt 5.13.2 from the list. Click **Next**.  
	k. On **License Agreement** page, click on **I have read and agree to the terms contained in the license agreement** option and click **Next**.  
	l. On **Ready to Install** page click **Install**.  
	m. After installation is complete, click **Finish** or close the window of installer.  
	n. Qt will be installed in provided Qt folder.  

15. Install VTK  

	a. Three software packages need to be installed before compiling VTK: X11, OpenGL, CMake.  
  
		sudo apt-get install libx11-dev libxext-dev libxtst-dev libxrender-dev libxmu-dev libxmuu-dev  
		sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev  
		sudo apt-get install cmake cmake-qt-gui  

	b. Download source of VTK 7.1.1 from [here](https://vtk.org/download/).  
	c. UnzipVTK-7.1.1.tar.gz, create a build folder in the VTK-7.1.1 folder.  
	d. Create environment variable from Qt installation folder(location of folder **5.13.2**):  

		export Qt5_PATH="<Qt installation folder>"  

	e. Following commands will be used for VTK installation:  

		cmake .. -DVTK_Group_Qt:BOOL=TRUE -DVTK_QT_VERSION:VALUE=5 -DQT_QMAKE_EXECUTABLE:FILEPATH="${Qt5_PATH}/5.13.2/gcc_64/bin/qmake" -DQt5_DIR:PATH="${Qt5_PATH}/5.13.2/gcc_64/lib/cmake/Qt5" -DCMAKE_BUILD_TYPE:VALUE=Release  
		sudo make -j<Number of processors>  
		sudo make install  

    f. Locate the VTK directory containing the header files. This location is needed to be placed in **include_directories** command in line number **43** of **CMakeLists.txt**.  

16. Install PCL:  
    a. Download PCL 1.12 source code tar.gz from https://github.com/PointCloudLibrary/pcl/releases.  
    b. Create **PCL\_ROOT** folder, extract the tar.gz file inside it.  
    c. In **PCL\_ROOT** folder open terminal and provide following commands:  

		mkdir build && cd build  
		cmake ..  
		make -j<Number of processors>  
		sudo make install  
		
	Note:
	1. VTK and Qt dependencies are automatically detected by CMake for building but sometimes there is error thrown when they are not detected automatically. In that case follow below steps.  
		a. Create environment variable from Qt installation folder(location of folder **5.13.2**):   

			export Qt5_PATH="<Qt installation folder>"  

        	b. Find the location of VTKConfig.cmake which was installed with VTK (eg, `/usr/local/lib/cmake/vtk-7.1`)  
 
			export VTK_PATH="<Location of VTKConfig.cmake>"  

		c. Run following commands:  

            cmake ../pcl-pcl-1.12.0/ -DQt5_DIR:PATH="${Qt5_PATH}/5.13.2/gcc_64/lib/cmake/Qt5" -DVTK_DIR:PATH=${VTK_PATH}  
		    make -j<Number of processors>  
		    sudo make install  
		
17. Configure VTK with QT.  
	a. After the VTK is built, inside **/VTK-7.1.1/build/lib** folder **libQVTKWidgetPlugin.so** file is generated. Go to the file location and open terminal.  
	b. Copy **libQVTKWidgetPlugin.so** to `<Qt_Installation_Path>/Tools/QtCreator/lib/Qt/plugins/designer` folder using following commands in terminal:  
		
		export Qt5_PATH="<Qt installation folder>"  
		cp libQVTKWidgetPlugin.so $Qt5_PATH/Tools/QtCreator/lib/Qt/plugins/designer/

