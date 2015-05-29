




#ifndef PP_CPU_VECTOR_MATH_H
#define PP_CPU_VECTOR_MATH_H





//pp_cpu_vector_math
//--------------------------------------------------
/*
Implementation for cpu vector math
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
#include "pp_vector_math_utility.h"





//Functions
//--------------------------------------------------

namespace cpu_serial
{

	//sine_deform
	boost::python::list sine_deform(const boost::python::list&, float);

	

};

namespace cpu_openmp
{

	//sine_deform
	boost::python::list sine_deform(const boost::python::list&, float);

	

};











#endif