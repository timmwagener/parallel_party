

#import
#---------------------------------------

import math
import time
import parallel_party as pp


#Utility functions
#---------------------------------------

def print_msg(msg = 'sick'):
    print(msg)

def get_upstream_node_parm_values_hash(node):
    """Get upstream node parm values as hash string"""

    #parm_list
    parm_list = []

    #upstream_nodes_list
    upstream_nodes_list = list(node.inputAncestors())

    #upstream_parms_values_list
    upstream_parms_values_list = []

    #iterate
    for upstream_nodes in upstream_nodes_list:
        for parameter in upstream_nodes.parms():
            upstream_parms_values_list.append(parameter.eval())

    #upstream_parms_values_tuple
    upstream_parms_values_tuple = sorted(tuple(upstream_parms_values_list))

    #hash tuple and return
    return hash(str(upstream_parms_values_tuple))



#Cook
#---------------------------------------
#---------------------------------------

# This code is called when instances of this SOP cook.
node = hou.pwd()
geo = node.geometry()

#hou_point_list
hou_point_list = geo.points()


#start_frame
start_frame = 1
#current_frame
current_frame = hou.frame()




#Evaluate hashes
#---------------------------------------

#assign old upstream_values_hash
if('new_upstream_values_hash' in locals()):
    #old_upstream_values_hash
    old_upstream_values_hash = new_upstream_values_hash

#new_upstream_values_hash
new_upstream_values_hash = get_upstream_node_parm_values_hash(node)

#assign old upstream_values_hash
if not('old_upstream_values_hash' in locals()):
    #old_upstream_values_hash
    old_upstream_values_hash = new_upstream_values_hash

#check if hashes match
hashes_match = old_upstream_values_hash == new_upstream_values_hash
if not(hashes_match):
    print('Hashes match: {0} (Frame: {1})'.format(hashes_match, current_frame))



#Recompute if necessary
#---------------------------------------

#recompute point_list
if(current_frame <= start_frame or not hashes_match):

    #upstream_values_hash
    upstream_values_hash = get_upstream_node_parm_values_hash(node)

    #point_list
    point_list = [[point.position()[0], point.position()[1], point.position()[2]] for 
                    point in 
                    hou_point_list]

    #sine_deform_optimizer
    sine_deform_optimizer = pp.vector_math.Pp_gpu_vector_math_optimized(point_list)

    print('Recompute point list')




#Compute point position
#---------------------------------------

#start_time
start_time = time.clock()

#execute only if point_list exists
if('point_list' in locals()):
    
    #modified_point_list
    modified_point_list = sine_deform_optimizer.sine_deform(current_frame * 0.05)
    print(modified_point_list)


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




