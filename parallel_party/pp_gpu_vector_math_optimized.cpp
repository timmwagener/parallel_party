






//pp_gpu_vector_math_optimized
//--------------------------------------------------
/*
Implementation of gpu vector math optimized
*/


//Preprocessor
//--------------------------------------------------




//Include
//--------------------------------------------------

//own
#include "pp_gpu_vector_math_optimized.h"




//Pp_gpu_vector_math_optimized
//--------------------------------------------------

//Constructor
Pp_gpu_vector_math_optimized::Pp_gpu_vector_math_optimized() {};

Pp_gpu_vector_math_optimized::Pp_gpu_vector_math_optimized(boost::python::list new_source_list):
	ptr_float_x(0), ptr_float_y(0), ptr_float_z(0), ptr_result_float_x(0), ptr_result_float_y(0), ptr_result_float_z(0)
{
	//assign source list
	source_list = boost::python::list(new_source_list);
	//assign source_list_len
	source_list_len = boost::python::len(source_list);

	
	//allocate and assign host
	//--------------------------------------------------
	ptr_float_x = new float[source_list_len];
	ptr_float_y = new float[source_list_len];
	ptr_float_z = new float[source_list_len];

	ptr_result_float_x = new float[source_list_len];
	ptr_result_float_y = new float[source_list_len];
	ptr_result_float_z = new float[source_list_len];

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
Pp_gpu_vector_math_optimized::~Pp_gpu_vector_math_optimized()
{
	//delete ptr
	if(ptr_float_x)
		delete [] ptr_float_x;
	if(ptr_float_y)
		delete [] ptr_float_y;
	if(ptr_float_z)
		delete [] ptr_float_z;
	if(ptr_result_float_x)
		delete [] ptr_result_float_x;
	if(ptr_result_float_y)
		delete [] ptr_result_float_y;
	if(ptr_result_float_z)
		delete [] ptr_result_float_z;
};


//sine_deform
boost::python::list Pp_gpu_vector_math_optimized::sine_deform(float random)
{
	//result_list
	boost::python::list result_list;
	
	//cuda::sine_deform
	cuda::sine_deform(ptr_float_x, ptr_float_y, ptr_float_z,
						ptr_result_float_x, ptr_result_float_y, ptr_result_float_z,
						random,
						source_list_len);

	//append to result_list
	for(int index = 0; index < source_list_len; index++)
	{
		//append to result_list
		result_list.append(list_from_vector(ptr_result_float_x[index], 
											ptr_result_float_y[index], 
											ptr_result_float_z[index])
											);
	}
	
	
	return result_list;
};


//list_from_vector
boost::python::list Pp_gpu_vector_math_optimized::list_from_vector(float x, float y, float z)
{
	//result_list
	boost::python::list result_list;

	//append
	result_list.append(x);
	result_list.append(y);
	result_list.append(z);

	return result_list;
};