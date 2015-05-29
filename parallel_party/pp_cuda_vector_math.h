




#ifndef PP_CUDA_VECTOR_MATH_H
#define PP_CUDA_VECTOR_MATH_H





//pp_cuda_vector_math
//--------------------------------------------------
/*
Implementation for cuda vector math
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
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>







//Functions
//--------------------------------------------------

namespace cuda
{

	//is_cuda_available
	int is_cuda_available();

	//get_device_attributes
	std::string get_device_attributes();

	//get_dev_properties_str
	std::string get_dev_properties_str(void*);

	//sine_deform
	void sine_deform(float*&, float*&, float*&, float*&, float*&, float*&, float, int);
};











#endif