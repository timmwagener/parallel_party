




#ifndef PP_VECTOR_MATH_UTILITY_H
#define PP_VECTOR_MATH_UTILITY_H





//pp_vector_math_utility
//--------------------------------------------------
/*
Declaration for vector math utilities
*/





//Preprocessor
//--------------------------------------------------

#ifndef BOOST_PYTHON_STATIC_LIB
#define BOOST_PYTHON_STATIC_LIB
#endif




//Include
//--------------------------------------------------

//std
#include <string>
#include <iostream>
#include <vector>

//boost
#include <boost/python.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

//own






//Functions
//--------------------------------------------------

namespace utility
{
	//list_from_vector
	boost::python::list list_from_vector(float, float, float);
}







#endif