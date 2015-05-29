

#import
import math
import time
import parallel_party as pp

# This code is called when instances of this SOP cook.
node = hou.pwd()
geo = node.geometry()

#start_time
start_time = time.clock()

#hou_point_list
hou_point_list = geo.points()

#end_time
end_time = time.clock()

#elapsed_time
print('Elapsed Time geo.points: {0}'.format(end_time - start_time))

#start_frame
start_frame = 1
#current_frame
current_frame = hou.frame()


#start_time
start_time = time.clock()

#point_list
if(current_frame <= start_frame):

    #point_list
    point_list = [[point.position()[0], point.position()[1], point.position()[2]] for 
                    point in 
                    hou_point_list]

    print('Reassign point list')

#end_time
end_time = time.clock()

#elapsed_time
print('Elapsed Time point_list: {0}'.format(end_time - start_time))



#start_time
start_time = time.clock()

#execute only if point_list exists
if(point_list):
    #modified_point_list
    modified_point_list = pp.vector_math.sine_deform('CPU_OPENMP', point_list, current_frame * 0.05)


    #modify geo
    for index, point in enumerate(hou_point_list):
        #hou_vector3
        hou_vector3 = hou.Vector3()
        hou_vector3.setTo(modified_point_list[index])
        #set position
        point.setPosition(hou_vector3)
        
        
        #make interruptible
        if hou.updateProgressAndCheckForInterrupt():
            break

#end_time
end_time = time.clock()

#elapsed_time
print('Elapsed Time: {0}'.format(end_time - start_time))
