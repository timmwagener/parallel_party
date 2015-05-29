






//pp_cpu_vector_math_optimized
//--------------------------------------------------
/*
Implementation of cpu vector math optimized
*/


//Preprocessor
//--------------------------------------------------




//Include
//--------------------------------------------------

//own
#include "pp_cpu_vector_math_optimized.h"




//Pp_cpu_vector_math_optimized
//--------------------------------------------------

//Constructor
Pp_cpu_vector_math_optimized::Pp_cpu_vector_math_optimized() {};

Pp_cpu_vector_math_optimized::Pp_cpu_vector_math_optimized(boost::python::list new_source_list):
ptr_float_x(0), ptr_float_y(0), ptr_float_z(0)
{
	//assign source list
	source_list = boost::python::list(new_source_list);
	//assign source_list_len
	source_list_len = boost::python::len(source_list);

	//allocate and assign
	ptr_float_x = new float[source_list_len];
	ptr_float_y = new float[source_list_len];
	ptr_float_z = new float[source_list_len];

	//iterate and fill ptr_float
	for(int index = 0; index < source_list_len; index++)
	{
		//append
		ptr_float_x[index] = boost::python::extract<float>(source_list[index][0]);
		ptr_float_y[index] = boost::python::extract<float>(source_list[index][1]);
		ptr_float_z[index] = boost::python::extract<float>(source_list[index][2]);
	}
};


//Destructor
Pp_cpu_vector_math_optimized::~Pp_cpu_vector_math_optimized()
{
	//delete ptr
	if(ptr_float_x)
		delete [] ptr_float_x;
	if(ptr_float_y)
		delete [] ptr_float_y;
	if(ptr_float_z)
		delete [] ptr_float_z;
};


//sine_deform
boost::python::list Pp_cpu_vector_math_optimized::sine_deform(float random)
{
	//result_list
	boost::python::list result_list;


	//parallel math
	#pragma omp parallel for
	for(int index = 0; index < source_list_len; index++)
	{
		//modulate y
		ptr_float_y[index] = std::sin(ptr_float_x[index] + ptr_float_z[index] + random);
	};

	
	//append to result_list
	for(int index = 0; index < source_list_len; index++)
	{
		//append to result_list
		result_list.append(list_from_vector(ptr_float_x[index], ptr_float_y[index], ptr_float_z[index]));
	}

	return result_list;
};


//list_from_vector
boost::python::list Pp_cpu_vector_math_optimized::list_from_vector(float x, float y, float z)
{
	//result_list
	boost::python::list result_list;

	//append
	result_list.append(x);
	result_list.append(y);
	result_list.append(z);

	return result_list;
};