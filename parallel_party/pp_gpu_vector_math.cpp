






//pp_gpu_vector_math
//--------------------------------------------------
/*
Implementation of gpu vector math
*/


//Preprocessor
//--------------------------------------------------




//Include
//--------------------------------------------------

//own
#include "pp_gpu_vector_math.h"












//gpu_cuda
//--------------------------------------------------

//is_cuda_available
int gpu_cuda::is_cuda_available()
{
	//cuda::is_cuda_available
	return cuda::is_cuda_available();
};


//sine_deform
boost::python::list gpu_cuda::sine_deform(const boost::python::list& new_source_list, float random)
{
	
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
		result_list.append(utility::list_from_vector(ptr_result_float_x[index], 
											ptr_result_float_y[index], 
											ptr_result_float_z[index])
											);
	}

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
	
	//return
	return result_list;
};


//get_device_attributes
std::string gpu_cuda::get_device_attributes()
{
	//cuda::get_device_attributes
	return cuda::get_device_attributes();
};
