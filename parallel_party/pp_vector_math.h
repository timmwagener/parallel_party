




#ifndef PP_VECTOR_MATH_H
#define PP_VECTOR_MATH_H





//pp_vector_math
//--------------------------------------------------
/*
Interface for vector math
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
#include "pp_cpu_vector_math.h"
#include "pp_cpu_vector_math_optimized.h"
#include "pp_gpu_vector_math.h"
#include "pp_gpu_vector_math_optimized.h"






//Functions
//--------------------------------------------------

namespace pp_vector_math
{
	
	//test_method
	std::string test_method();

	//sine_deform
	boost::python::list sine_deform(std::string, const boost::python::list&, float);

	//is_cuda_available
	int is_cuda_available();

	//get_device_attributes
	std::string get_device_attributes();

};











#endif