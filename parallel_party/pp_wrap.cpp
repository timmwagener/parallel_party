

//pp_wrap
//--------------------------------------------------
/*
Source file that implements all the wrapping with Boost
*/




//Preprocessor
//--------------------------------------------------

#ifndef BOOST_PYTHON_STATIC_LIB
#define BOOST_PYTHON_STATIC_LIB
#endif






//Constants
//--------------------------------------------------






//Include
//--------------------------------------------------

//boost
#include <boost/python.hpp>


//own
#include "pp_vector_math.h"






//Utility Functions
//--------------------------------------------------
//--------------------------------------------------

//create_submodule
boost::python::object create_submodule(std::string submodule_name, std::string parent_module_path, boost::python::scope &parent_scope)
{
	//submodule_path
	std::string submodule_path;

	//format submodule_path
	submodule_path = parent_module_path;
	submodule_path = submodule_path.append(".");
	submodule_path = submodule_path.append(submodule_name);

	//submodule_vector_math
	boost::python::object submodule(boost::python::borrowed(PyImport_AddModule(submodule_path.c_str())));
	
	//add submodule under parent scope
	parent_scope.attr(submodule_name.c_str()) = submodule;

	return submodule;
};









//Wrap
//--------------------------------------------------
//--------------------------------------------------


//parallel_party
BOOST_PYTHON_MODULE(parallel_party)
{	
    //converter registration
	//--------------------------------------------------
	


	
	
	//main module
	//--------------------------------------------------

	//base_module_name
	boost::python::scope scope_current;
	std::string base_module_name(boost::python::extract<const char*>(scope_current.attr("__name__")));
	
	
	
	
	
	
	//submodule vector_math
	//--------------------------------------------------

	//submodule_vector_math
	boost::python::object submodule_vector_math = create_submodule("vector_math", base_module_name, scope_current);

	//add submodule members
	{
		
		// Switch the scope to the submodule, add methods and classes.
		boost::python::scope scope_submodule_vector_math = submodule_vector_math;
		boost::python::def("test_method", &pp_vector_math::test_method);
		boost::python::def("sine_deform", &pp_vector_math::sine_deform);
		boost::python::def("is_cuda_available", &pp_vector_math::is_cuda_available);
		boost::python::def("get_device_attributes", &pp_vector_math::get_device_attributes);

		
		//Pp_cpu_vector_math_optimized
		boost::python::class_<Pp_cpu_vector_math_optimized>("Pp_cpu_vector_math_optimized")
			//__init__
			.def(boost::python::init<>())
			.def(boost::python::init<boost::python::list>())
		
			//Methods
			.def("sine_deform", &Pp_cpu_vector_math_optimized::sine_deform)
			;

		
		//Pp_gpu_vector_math_optimized
		boost::python::class_<Pp_gpu_vector_math_optimized>("Pp_gpu_vector_math_optimized")
			//__init__
			.def(boost::python::init<>())
			.def(boost::python::init<boost::python::list>())
		
			//Methods
			.def("sine_deform", &Pp_gpu_vector_math_optimized::sine_deform)
			;
	}
	
	
};





