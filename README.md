# ArduinouClibcpp

Another uClibc++ port for arduino compare to StandardCplusplus.

Not like the StandardCplusplus, we don't work on uClibc++ source directly. So we could update uClibc++ easily when upstream have updates.

We wrote a simple python script to help download the lastest uClibc++ we supported.

The downloaded uClibc++ sources will be patched after put into "src" directory.

1. [StandardCplusplus](https://github.com/maniacbug/StandardCplusplus)
2. [uClibc++](https://git.uclibc.org/uClibc++)