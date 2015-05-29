




#ifndef PP_CPU_VECTOR_MATH_OPTIMIZED_H
#define PP_CPU_VECTOR_MATH_OPTIMIZED_H





//pp_cpu_vector_math_optimized
//--------------------------------------------------
/*
Declaration for cpu vector math optimized class
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







//Pp_cpu_vector_math_optimized
//--------------------------------------------------

class Pp_cpu_vector_math_optimized
{

private:
	//Attrs
	int source_list_len;
	boost::python::list source_list;
	float* ptr_float_x;
	float* ptr_float_y;
	float* ptr_float_z;
	
	//Methods

public:
	//Attrs

	
	//Methods
	Pp_cpu_vector_math_optimized();
	Pp_cpu_vector_math_optimized(boost::python::list);
	~Pp_cpu_vector_math_optimized();
	boost::python::list sine_deform(float);
	boost::python::list list_from_vector(float, float, float);
	

};










#endif