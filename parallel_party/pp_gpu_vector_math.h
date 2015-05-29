




#ifndef PP_GPU_VECTOR_MATH_H
#define PP_GPU_VECTOR_MATH_H





//pp_gpu_vector_math
//--------------------------------------------------
/*
Implementation for gpu vector math
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
#include "pp_cuda_vector_math.h"
#include "pp_vector_math_utility.h"



//Functions
//--------------------------------------------------

namespace gpu_cuda
{

	//is_cuda_available
	int is_cuda_available();

	//get_device_attributes
	std::string get_device_attributes();

	//sine_deform
	boost::python::list sine_deform(const boost::python::list&, float);

	

};


#endif