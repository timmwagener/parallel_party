






//pp_cuda_vector_math
//--------------------------------------------------
/*
Implementation of cuda vector math and kernels. Encapsulated to be compiled with nvcc
*/


//Preprocessor
//--------------------------------------------------




//Include
//--------------------------------------------------
//cuda
#include "helper_math.h"

//own
#include "pp_cuda_vector_math.h"






//kernels
//--------------------------------------------------
namespace kernel
{

	//sine_deform
	__global__ void sine_deform(float* x, float* y, float* z, float* result_x, float* result_y, float* result_z, float random, int size)
	{
		//thread_index
		int index = blockDim.x * blockIdx.x + threadIdx.x;

		//check and add
		if(index < size)
		{
			result_x[index] = x[index];
			result_y[index] = sin(x[index] + z[index] + random);
			result_z[index] = z[index];
		};
		
	};

	//print_pointer
	__global__ void print_pointer(float* ptr, int size)
	{
		for(int index = 0; index < size; index++)
		{
			printf("Value: %d \n", ptr[index]);
		};
	};

};



//cuda
//--------------------------------------------------

//is_cuda_available
int cuda::is_cuda_available()
{
	int deviceCount = 0;
	cudaError_t cudaErrorId;
	cudaErrorId = cudaGetDeviceCount(&deviceCount);
	return deviceCount;
};


//get_device_attributes
std::string cuda::get_device_attributes()
{
	
	//deviceCount
	int deviceCount = is_cuda_available();

	//no device available
	if(!deviceCount)
		return "No device available";
	
	//cudaDeviceProperties
	cudaDeviceProp cudaDeviceProperties;

	//get device properties
	cudaGetDeviceProperties(&cudaDeviceProperties, deviceCount - 1);

	//cudaDeviceProperties_str
	std::string cudaDeviceProperties_str = get_dev_properties_str(&cudaDeviceProperties);

	return cudaDeviceProperties_str;
};


//get_dev_properties_str
std::string cuda::get_dev_properties_str(void* ptr)
{
	
	//cudaDeviceProp*
	cudaDeviceProp* devProp = static_cast<cudaDeviceProp*>(ptr);

	//format_string
	boost::format format_string("\n\nCUDA device information:\n"
								"--------------------------------------\n"
								"Major revision number:         %d\n"
								"Minor revision number:         %d\n"
								"Name:                          %s\n"
								
								"Total global memory:           %u\n"
								"Total shared memory per block: %u\n"
								"Total registers per block:     %d\n"
								"Warp size:                     %d\n"
								"Maximum memory pitch:          %u\n"
								
								"Maximum threads per block:     %d\n"
								"Maximum X dimension of block:  %d\n"
								"Maximum Y dimension of block:  %d\n"
								"Maximum Z dimension of block:  %d\n"

								"Maximum X dimension of grid:   %d\n"
								"Maximum Y dimension of grid:   %d\n"
								"Maximum Z dimension of grid:   %d\n"

								"Clock rate:                    %d\n"
								"Total constant memory:         %u\n"
								"Texture alignment:             %u\n"
								"Concurrent copy and execution: %s\n"
								"Number of multiprocessors:     %d\n"
								"Kernel execution timeout:      %s\n"
								"--------------------------------------\n\n"
								);

	//format
	format_string % devProp->major 
		% devProp->minor 
		% devProp->name
		
		% devProp->totalGlobalMem
		% devProp->sharedMemPerBlock
		% devProp->regsPerBlock
		% devProp->warpSize
		% devProp->memPitch

		% devProp->maxThreadsPerBlock
		% devProp->maxThreadsDim[0]
		% devProp->maxThreadsDim[1]
		% devProp->maxThreadsDim[2]

		% devProp->maxGridSize[0]
		% devProp->maxGridSize[1]
		% devProp->maxGridSize[2]

		% devProp->clockRate
		% devProp->totalConstMem
		% devProp->textureAlignment
		% (devProp->deviceOverlap ? "Yes" : "No")
		% devProp->multiProcessorCount
		% (devProp->kernelExecTimeoutEnabled ? "Yes" : "No")
		;

	return format_string.str();
}







//Pp_gpu_vector_math_optimized
//--------------------------------------------------

//sine_deform
void cuda::sine_deform(float*& ptr_float_x, float*& ptr_float_y, float*& ptr_float_z,
						float*& ptr_result_float_x, float*& ptr_result_float_y, float*& ptr_result_float_z,
						float random, int size)
{
	std::cout << "Execute sine_deform kernel" << std::endl;
	

	//Create and allocate device ptr
	//--------------------------------------------------
	//size_t
	size_t array_size = size * sizeof(float);

	//create device pointer
	float* ptr_d_float_x;
	float* ptr_d_float_y;
	float* ptr_d_float_z;

	float* ptr_d_result_float_x;
	float* ptr_d_result_float_y;
	float* ptr_d_result_float_z;
	
	//allocate device memory
	cudaMalloc(&ptr_d_float_x, array_size);
	cudaMalloc(&ptr_d_float_y, array_size);
	cudaMalloc(&ptr_d_float_z, array_size);

	cudaMalloc(&ptr_d_result_float_x, array_size);
	cudaMalloc(&ptr_d_result_float_y, array_size);
	cudaMalloc(&ptr_d_result_float_z, array_size);

	
	
	//memcpy to device
	//--------------------------------------------------
	
	//memcpy
	cudaMemcpy(ptr_d_float_x, ptr_float_x, array_size, cudaMemcpyHostToDevice);
	cudaMemcpy(ptr_d_float_y, ptr_float_y, array_size, cudaMemcpyHostToDevice);
	cudaMemcpy(ptr_d_float_z, ptr_float_z, array_size, cudaMemcpyHostToDevice);

	
	
	
	//kernel
	//--------------------------------------------------

	//thread_count
	int thread_count = 512;
	//grid_dim
	dim3 grid_dim((size + (thread_count - 1)) / thread_count);
	std::cout << ((size + (thread_count - 1)) / thread_count) << std::endl;
	
	//kernel::sine_deform
	kernel::sine_deform<<<grid_dim, thread_count>>> (ptr_d_float_x, ptr_d_float_y, ptr_d_float_z,
									ptr_d_result_float_x, ptr_d_result_float_y, ptr_d_result_float_z,
									random,
									size
									);




	//copy to host
	//--------------------------------------------------

	//memcpy
	cudaMemcpy(ptr_result_float_x, ptr_d_result_float_x, array_size, cudaMemcpyDeviceToHost);
	cudaMemcpy(ptr_result_float_y, ptr_d_result_float_y, array_size, cudaMemcpyDeviceToHost);
	cudaMemcpy(ptr_result_float_z, ptr_d_result_float_z, array_size, cudaMemcpyDeviceToHost);

	
	//free memory
	//--------------------------------------------------

	cudaFree(ptr_d_float_x);
	cudaFree(ptr_d_float_y);
	cudaFree(ptr_d_float_z);
	
	cudaFree(ptr_d_result_float_x);
	cudaFree(ptr_d_result_float_x);
	cudaFree(ptr_d_result_float_x);


};