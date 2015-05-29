






//pp_cpu_vector_math
//--------------------------------------------------
/*
Implementation of cpu vector math
*/


//Preprocessor
//--------------------------------------------------




//Include
//--------------------------------------------------

//own
#include "pp_cpu_vector_math.h"












//cpu_serial
//--------------------------------------------------


//sine_deform
boost::python::list cpu_serial::sine_deform(const boost::python::list& source_list, float random)
{
	
	//std::cout << "CPU_SERIAL: sine_deform" << std::endl;

	//result_list;
	boost::python::list result_list;

	//vec_float_x,y,z
	std::vector<float> vec_float_x;
	std::vector<float> vec_float_y;
	std::vector<float> vec_float_z;

	//iterate and fill vec_float
	for(int index = 0; index < boost::python::len(source_list); index++)
	{
		//append
		vec_float_x.push_back(boost::python::extract<float>(source_list[index][0]));
		vec_float_y.push_back(boost::python::extract<float>(source_list[index][1]));
		vec_float_z.push_back(boost::python::extract<float>(source_list[index][2]));

		//modulate y
		vec_float_y[index] = std::sin(vec_float_x[index] + vec_float_z[index] + random);
		
		
		//append to result_list
		result_list.append(utility::list_from_vector(vec_float_x[index], 
														vec_float_y[index], 
														vec_float_z[index])
														);

	};
	
	return result_list;
};



//cpu_openmp
//--------------------------------------------------


//sine_deform
boost::python::list cpu_openmp::sine_deform(const boost::python::list& source_list, float random)
{
	
	//std::cout << "CPU_OPENMP: sine_deform" << std::endl;

	//source_list_len
	int source_list_len = boost::python::len(source_list);

	//result_list;
	boost::python::list result_list;

	

	//vec_float_x,y,z
	float* vec_float_x = new float[source_list_len];
	float* vec_float_y = new float[source_list_len];
	float* vec_float_z = new float[source_list_len];

	//iterate and fill vec_float
	for(int index = 0; index < source_list_len; index++)
	{
		//append
		vec_float_x[index] = boost::python::extract<float>(source_list[index][0]);
		vec_float_y[index] = boost::python::extract<float>(source_list[index][1]);
		vec_float_z[index] = boost::python::extract<float>(source_list[index][2]);
	}

	//parallel math
	#pragma omp parallel for
	for(int index = 0; index < source_list_len; index++)
	{
		//modulate y
		vec_float_y[index] = std::sin(vec_float_x[index] + vec_float_z[index] + random);

		
	};

	
	//append to result_list
	for(int index = 0; index < source_list_len; index++)
	{
		//append to result_list
		result_list.append(utility::list_from_vector(vec_float_x[index], 
														vec_float_y[index], 
														vec_float_z[index])
														);
	}
	

	//delete
	delete [] vec_float_x;
	delete [] vec_float_y;
	delete [] vec_float_z;
	
	return result_list;
};




