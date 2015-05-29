

#import
import math
import time

# This code is called when instances of this SOP cook.
node = hou.pwd()
geo = node.geometry()


#start_time
start_time = time.clock()

# Add code to modify the contents of geo.
f = hou.frame()
for p in geo.points():
    pos = p.position()
    pos[1] = math.sin(pos[0]  + pos[2]  + f * 0.05)
    p.setPosition(pos)
    
    
    #make interruptible
    if hou.updateProgressAndCheckForInterrupt():
        break


#end_time
end_time = time.clock()

#elapsed_time
print('Elapsed Time: {0}'.format(end_time - start_time))