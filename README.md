# AOP_Project 
<hr>

# This are the raw instructions and readme. Will be improved further.

This project attempted to test AspectC++ on a Qt program. This was to be achieved by
simulating a chess game in a Qt environment, and then using AspectC++ to add/modify
additional functionalities to the original program, without actually modifying the source.

Installation Procedure:
Platform:

This project was done on Ubuntu 14 using VMware Player 6.0.4.
Similar results can be expected on a native Ubuntu installation as well.

Installing Qt:

 username@ubuntu:~/Folder_name$ apt-get build-dep libqt4-core \
libqt4-dev

Get all the dependencies by executing the above line.
This project requires Qt 4.8 to be installed on your system.
Unpack the source files for Qt 4.8 and change inside that directory.
To prevent Qt from taking too much time install it from sources using the following
options.

username@ubuntu:~/Folder_name$ ./configure \
-debug-and-release \
-opensource \
-developer-build \
-no-webkit \
-nomake examples \
-nomake demos \
-nomake docs \
-fast

Then make so it builds the required files. This step took approximately 30 minutes.
username@ubuntu:~/Folder_name$ make

Then install those files, on receiving no major errors while building
username@ubuntu:~/Folder_name$ install

Setting up AspectC++:
Make sure g++ is installed on your system.
username@ubuntu:~/Folder_name$ sudo apt-get install g++

Download the source files for AspectC++ and unpack and install them
username@ubuntu:~/Folder_name$ sudo apt-get install aspectc++

Calls to ac++, ag++, g++ and c++ should call the respective compilers.

Executing a Qt project with aspects :

Download the acxx.prf from the AspectC++ page. The feature file acxx.prf will tell
qmake to replace the C++ compiler by ag++ and to take into account that all object files
depend
on all aspect headers.

Once all the software requirements are setup the appropriate calls need to be made to
execute the AspectC++ on the Qt project.
Firstly while in the project folder to compile the example, we must make sure that
qmake will find the feature file acxx.prf via the environment variable
QMAKEFEATURES. Execute the following,
username@ubuntu:~/Folder_name$ export QMAKEFEATURES=.

Call qmake to make the .pro project file
username@ubuntu:~/Folder_name$ qmake -project

Open the .pro file and add the following line before the # Input files declaration
CONFIG += acxx.prf

Call qmake to make the platform specific Makefile, containing special rules, for example
to use ag++ instead of g++.
username@ubuntu:~/Folder_name$ qmake project_name.pro

This should display a message, “Project MESSAGE: AspectC++ Feature selected “.
Call make to create the modified executable.
username@ubuntu:~/Folder_name$ make

Run the project executable
username@ubuntu:~/Folder_name$ project_name

Thank you.
