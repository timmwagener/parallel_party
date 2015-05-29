






//pp_vector_math_utility
//--------------------------------------------------
/*
Interface for vector math utility
*/


//Preprocessor
//--------------------------------------------------




//Include
//--------------------------------------------------

//own
#include "pp_vector_math_utility.h"









//Functions
//--------------------------------------------------

//utility
//--------------------------------------------------

//list_from_vector
boost::python::list utility::list_from_vector(float x, float y, float z)
{
	//result_list
	boost::python::list result_list;

	//append
	result_list.append(x);
	result_list.append(y);
	result_list.append(z);

	return result_list;
};