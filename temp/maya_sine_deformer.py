#import
#--------------------------------------------------

#maya
import maya.OpenMayaMPx as OpenMayaMPx
import maya.OpenMaya as OpenMaya
import maya.OpenMayaAnim as OpenMayaAnim
import maya.cmds as cmds
import pymel.core as pm

#own
import parallel_party as pp


class Sine_wave(OpenMayaMPx.MPxDeformerNode):

	kPluginNodeId = OpenMaya.MTypeId(0x00000002)

	a_input_time = OpenMaya.MObject()

	def __init__(self):
		OpenMayaMPx.MPxDeformerNode.__init__(self)


	def deform(self, data, itGeo, localToWorldMatrix, mIndex):

		#point_count
		point_count = itGeo.exactCount()

		#envelope
		envelope = OpenMayaMPx.cvar.MPxDeformerNode_envelope
		env = data.inputValue(envelope).asFloat()

		#input_time
		input_time = data.inputValue(Sine_wave.a_input_time).asFloat()

		#point_list
		point_list = []
		while not itGeo.isDone():
			point = itGeo.position()
			point_list.append([point.x, point.y, point.z])
			itGeo.next()

		#reset
		itGeo.reset()

		#current_frame
		current_frame = pm.currentTime(query=True)

		#solve on gpu
		#modified_point_list
		modified_point_list = pp.vector_math.sine_deform('GPU_CUDA', point_list, input_time * 0.05)

		#set points
		while not itGeo.isDone():
			index = itGeo.index()
			point = OpenMaya.MPoint(modified_point_list[index][0], modified_point_list[index][1], modified_point_list[index][2])
			itGeo.setPosition(point)
			itGeo.next()

		return True

def creator():
	return OpenMayaMPx.asMPxPtr(Sine_wave())

def initialize():
	tAttr = OpenMaya.MFnTypedAttribute()
	nAttr = OpenMaya.MFnNumericAttribute()

	#a_input_time
	Sine_wave.a_input_time = nAttr.create('input_time', 'input_time', OpenMaya.MFnNumericData.kFloat, 1.0)
	Sine_wave.addAttribute(Sine_wave.a_input_time)
	outputGeom = OpenMayaMPx.cvar.MPxDeformerNode_outputGeom
	Sine_wave.attributeAffects(Sine_wave.a_input_time, outputGeom)


def initializePlugin(obj):
	plugin = OpenMayaMPx.MFnPlugin(obj, 'Timm Wagener', '1.0', 'Any')
	try:
		plugin.registerNode('Sine_wave', Sine_wave.kPluginNodeId, creator, initialize, OpenMayaMPx.MPxNode.kDeformerNode)
	except:
		raise RuntimeError, 'Failed to register node'


def uninitializePlugin(obj):
	plugin = OpenMayaMPx.MFnPlugin(obj)
	try:
		plugin.deregisterNode(Sine_wave.kPluginNodeId)
	except:
		raise RuntimeError, 'Failed to deregister node'