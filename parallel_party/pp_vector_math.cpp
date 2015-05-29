






//pp_vector_math
//--------------------------------------------------
/*
Interface for vector math
*/


//Preprocessor
//--------------------------------------------------




//Include
//--------------------------------------------------

//own
#include "pp_vector_math.h"









//Functions
//--------------------------------------------------

//test_method
std::string pp_vector_math::test_method()
{
	return "test_method";
};

//sine_deform
boost::python::list pp_vector_math::sine_deform(std::string mode, const boost::python::list& source_list, float random)
{
	//execute in correct mode
	//CPU_SERIAL
	if(mode.compare("CPU_SERIAL") == 0)
		return cpu_serial::sine_deform(source_list, random);
	//CPU_OPENMP
	else if(mode.compare("CPU_OPENMP") == 0)
		return cpu_openmp::sine_deform(source_list, random);
	//GPU_CUDA
	else if(mode.compare("GPU_CUDA") == 0)
		return gpu_cuda::sine_deform(source_list, random);
	//DEFAULT (CPU_SERIAL)
	else
		return cpu_serial::sine_deform(source_list, random);
};

//is_cuda_available
int pp_vector_math::is_cuda_available()
{
	//gpu_cuda::is_cuda_available
	return gpu_cuda::is_cuda_available();
};

//get_device_attributes
std::string pp_vector_math::get_device_attributes()
{
	//gpu_cuda::get_device_attributes
	return gpu_cuda::get_device_attributes();
};