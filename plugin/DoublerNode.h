#pragma once


#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MStatus.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MPxNode.h>

class DoublerNode : public MPxNode
{
public:
    DoublerNode() {}
    virtual MStatus compute(const MPlug& plug, MDataBlock& data);
    static void* creator();
    static MStatus initialize();
  
    static MTypeId id;
    static MObject aInput;
    static MObject aOutput;
};
