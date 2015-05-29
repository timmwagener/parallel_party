

<div align="center">
	<a href="https://vimeo.com/timmwagener/parallelparty" target="_blank"><img src="http://www.kiiia.com/parallel_party/repo_images/parallel_party_5.jpg"></a>
</div>
-----------------------
<div align="left">
	<a href="http://www.kiiia.com/parallel_party/repo_images/parallel_party_1.jpg" target="_blank"><img width="80" height="80" src="http://www.kiiia.com/parallel_party/repo_images/parallel_party_1_thumb.jpg"></a>
	<a href="http://www.kiiia.com/parallel_party/repo_images/parallel_party_2.jpg" target="_blank"><img width="80" height="80" src="http://www.kiiia.com/parallel_party/repo_images/parallel_party_2_thumb.jpg"></a>
	<a href="http://www.kiiia.com/parallel_party/repo_images/parallel_party_3.jpg" target="_blank"><img width="80" height="80" src="http://www.kiiia.com/parallel_party/repo_images/parallel_party_3_thumb.jpg"></a>
	<a href="http://www.kiiia.com/parallel_party/repo_images/parallel_party_4.jpg" target="_blank"><img width="80" height="80" src="http://www.kiiia.com/parallel_party/repo_images/parallel_party_4_thumb.jpg"></a>
	<a href="http://www.kiiia.com/parallel_party/repo_images/parallel_party_5.jpg" target="_blank"><img width="80" height="80" src="http://www.kiiia.com/parallel_party/repo_images/parallel_party_5_thumb.jpg"></a>
	<a href="http://www.kiiia.com/parallel_party/repo_images/parallel_party_6.jpg" target="_blank"><img width="80" height="80" src="http://www.kiiia.com/parallel_party/repo_images/parallel_party_6_thumb.jpg"></a>
	<a href="http://www.kiiia.com/parallel_party/repo_images/parallel_party_7.jpg" target="_blank"><img width="80" height="80" src="http://www.kiiia.com/parallel_party/repo_images/parallel_party_7_thumb.jpg"></a>
</div>
-----------------------

[![Gitter chat](https://badges.gitter.im/gitterHQ/gitter.png)](https://gitter.im/timmwagener/tw_cloth_solver)

-----------------------


What is it ?
-----------------------
**parallel_party** - Custom Python module wrapping CUDA in a pythonic way (test). A general purpose Python multithreading module offering easy and pythonic access to CPU or GPU parallelization (CUDA).
This is a test or proof of concept i have done for learning purposes, and it is not ment to become any larger or evolve into a serious project.


Its features include:
* Process Python types (lists etc.) in parallel on the GPU
* DCC agnostic
* Accelleration structures for minimized uploading to GPU memory or naive complete-process computation


Know issues
-----------------------
* Extracting data out of Python types and packaging them again is not threadsafe and therefore has to be done serial. That is a major limiting factor right now, and a big hit for performance. Im not sure if there is any way to speed this up? Ideas or suggestions are welcome!


Specs
-----------------------
Wrapping: Boost Python
Python Version: 2.6x64, 2.7x64
CUDA: 5.5
Maya Versions: 2012, 2013, 2013.5, 2014


-----------------------

[**Vimeo**](https://vimeo.com/timmwagener/parallelparty) [**More info**](http://www.timmwagener.com/parallel_party.html) [**Author**](http://www.timmwagener.com/)

-----------------------