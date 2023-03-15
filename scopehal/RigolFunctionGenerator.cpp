/***********************************************************************************************************************
*                                                                                                                      *
* libscopehal v0.1                                                                                                     *
*                                                                                                                      *
* Copyright (c) 2012-2023 Andrew D. Zonenberg and contributors                                                         *
* All rights reserved.                                                                                                 *
*                                                                                                                      *
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the     *
* following conditions are met:                                                                                        *
*                                                                                                                      *
*    * Redistributions of source code must retain the above copyright notice, this list of conditions, and the         *
*      following disclaimer.                                                                                           *
*                                                                                                                      *
*    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the       *
*      following disclaimer in the documentation and/or other materials provided with the distribution.                *
*                                                                                                                      *
*    * Neither the name of the author nor the names of any contributors may be used to endorse or promote products     *
*      derived from this software without specific prior written permission.                                           *
*                                                                                                                      *
* THIS SOFTWARE IS PROVIDED BY THE AUTHORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL *
* THE AUTHORS BE HELD LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES        *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR       *
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                                                          *
*                                                                                                                      *
***********************************************************************************************************************/

#include "scopehal.h"
#include "RigolFunctionGenerator.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Construction / destruction

RigolFunctionGenerator::RigolFunctionGenerator(SCPITransport* transport)
	: SCPIDevice(transport)
	, SCPIInstrument(transport)
{
}

RigolFunctionGenerator::~RigolFunctionGenerator()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Instrument

unsigned int RigolFunctionGenerator::GetInstrumentTypes()
{
	return INST_FUNCTION;
}

uint32_t RigolFunctionGenerator::GetInstrumentTypesForChannel(size_t i)
{
	if(i < 2)
		return INST_FUNCTION;
	else
		return 0;
}

bool RigolFunctionGenerator::AcquireData()
{
	return true;
}

string RigolFunctionGenerator::GetDriverNameInternal()
{
	return "rigol_awg";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FunctionGenerator

int RigolFunctionGenerator::GetFunctionChannelCount()
{
	//All DG4000 series have two channels
	return 2;
}

string RigolFunctionGenerator::GetFunctionChannelName(int chan)
{
	return string("SOURCE") + to_string(chan+1);
}

vector<FunctionGenerator::WaveShape> RigolFunctionGenerator::GetAvailableWaveformShapes(int chan)
{
	vector<WaveShape> ret;
	return ret;
}

bool RigolFunctionGenerator::GetFunctionChannelActive(int chan)
{
	return false;
}

void RigolFunctionGenerator::SetFunctionChannelActive(int chan, bool on)
{
}

float RigolFunctionGenerator::GetFunctionChannelDutyCycle(int chan)
{
	return 0.5;
}

void RigolFunctionGenerator::SetFunctionChannelDutyCycle(int chan, float duty)
{
}

float RigolFunctionGenerator::GetFunctionChannelAmplitude(int chan)
{
	return 1;
}

void RigolFunctionGenerator::SetFunctionChannelAmplitude(int chan, float amplitude)
{
}

float RigolFunctionGenerator::GetFunctionChannelOffset(int chan)
{
	return 0;
}

void RigolFunctionGenerator::SetFunctionChannelOffset(int chan, float offset)
{
}

float RigolFunctionGenerator::GetFunctionChannelFrequency(int chan)
{
	return 1e6;
}

void RigolFunctionGenerator::SetFunctionChannelFrequency(int chan, float hz)
{
}

FunctionGenerator::WaveShape RigolFunctionGenerator::GetFunctionChannelShape(int chan)
{
	return SHAPE_SINE;
}

void RigolFunctionGenerator::SetFunctionChannelShape(int chan, WaveShape shape)
{
}

bool RigolFunctionGenerator::HasFunctionRiseFallTimeControls(int /*chan*/)
{
	return false;
}

FunctionGenerator::OutputImpedance RigolFunctionGenerator::GetFunctionChannelOutputImpedance(int chan)
{
	return IMPEDANCE_HIGH_Z;
}

void RigolFunctionGenerator::SetFunctionChannelOutputImpedance(int chan, FunctionGenerator::OutputImpedance z)
{
}
