#include "Pch.h"
#include "maincamera.h"
#include "Globals.h"

MainCamera::MainCamera()
{
	printf("[MainCamera] Initialized\n");
	uint64_t maincamera = TargetProcess.Read<uint64_t>(TargetProcess.GetModuleAddress(L"GameAssembly.dll") + Class); // Get Class Start Address
	printf("[MainCamera] MainCamera: 0x%llX\n", maincamera);
	this->StaticField = TargetProcess.Read<uint64_t>(maincamera + StaticField); // Set Static Padding
	printf("[MainCamera] Static Fields: 0x%llX\n", StaticField);
	this->Camera = TargetProcess.Read<uint64_t>(StaticField + Camera); // Current MainCamera
	printf("[MainCamera] Camera: 0x%llX\n", Camera);

}