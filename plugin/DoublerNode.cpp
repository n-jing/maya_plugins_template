#include "DoublerNode.h"
#include <maya/MFnPlugin.h>
 
MTypeId DoublerNode::id(0x0a902301);
MObject DoublerNode::aInput;
MObject DoublerNode::aOutput;
 
void* DoublerNode::creator()
{
    return new DoublerNode;
}

MStatus DoublerNode::compute(const MPlug& plug, MDataBlock& data)
{
    if (plug != aOutput)
    {
        return MS::kUnknownParameter;
    }
    // Get the input
    float inputValue = data.inputValue(aInput).asFloat();
 
    // Double it
    inputValue *= 2.0f;
 
    // Set the output
    MDataHandle hOutput = data.outputValue(aOutput);
    hOutput.setFloat(inputValue);
    data.setClean(plug);
    return MS::kSuccess;
}
 
MStatus DoublerNode::initialize()
{
    MFnNumericAttribute nAttr;
 
    aOutput = nAttr.create("output", "out", MFnNumericData::kFloat);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aOutput);
 
    aInput = nAttr.create("input", "in", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    addAttribute(aInput);
    attributeAffects(aInput, aOutput);
 
    return MS::kSuccess;
}
 
MStatus initializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj, "jing", "1.0", "Any");
 
    status = plugin.registerNode("doublerNode", DoublerNode::id, DoublerNode::creator, DoublerNode::initialize);
    CHECK_MSTATUS_AND_RETURN_IT(status);
 
    return status;
}
 
MStatus uninitializePlugin(MObject obj) {
    MStatus status;
    MFnPlugin plugin(obj);
 
    status = plugin.deregisterNode(DoublerNode::id);
    CHECK_MSTATUS_AND_RETURN_IT(status);
 
    return status;
}
