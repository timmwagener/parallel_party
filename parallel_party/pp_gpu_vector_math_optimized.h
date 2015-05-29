




#ifndef PP_GPU_VECTOR_MATH_OPTIMIZED_H
#define PP_GPU_VECTOR_MATH_OPTIMIZED_H





//pp_gpu_vector_math_optimized
//--------------------------------------------------
/*
Declaration for gpu vector math optimized class
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
#include <math.h>

//boost
#include <boost/python.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

//own
#include "pp_cuda_vector_math.h"





//Pp_gpu_vector_math_optimized
//--------------------------------------------------

class Pp_gpu_vector_math_optimized
{

private:
	//Attrs
	int source_list_len;
	boost::python::list source_list;
	//host arrays
	float* ptr_float_x;
	float* ptr_float_y;
	float* ptr_float_z;
	float* ptr_result_float_x;
	float* ptr_result_float_y;
	float* ptr_result_float_z;
	
	//Methods

public:
	//Attrs

	
	//Methods
	Pp_gpu_vector_math_optimized();
	Pp_gpu_vector_math_optimized(boost::python::list);
	~Pp_gpu_vector_math_optimized();
	boost::python::list sine_deform(float);
	boost::python::list list_from_vector(float, float, float);

};



#endif