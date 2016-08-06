# ArduinouClibcpp

Another uClibc++ port for arduino compare to StandardCplusplus[^1].

Not like the StandardCplusplus, we don't work on uClibc++[^2] source directly. So we could update uClibc++ easily when upstream have updates.

We wrote a simple python script to help download the lastest uClibc++ we supported and patch it then generate the "src" directory which arduino will search source from.

[^1]: [StandardCplusplus](https://github.com/maniacbug/StandardCplusplus)
[^2]: [uClibc++](https://git.uclibc.org/uClibc++)