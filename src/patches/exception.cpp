
#include <exception>

namespace std{
  _UCXXEXPORT static const char * __std_exception_what_value = "exception";

	//We are providing our own versions to be sneaky


	_UCXXEXPORT exception::~exception() throw(){
		//Empty function
	}

	_UCXXEXPORT const char* exception::what() const throw(){
		return __std_exception_what_value;
	}

	_UCXXEXPORT bad_exception::~bad_exception() throw(){

	}


}
