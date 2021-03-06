//========================================================================
// MinVR
// Platform:    Any
// API version: 1.0
//------------------------------------------------------------------------
// Copyright (c) 2013 Regents of the University of Minnesota and Brown University
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice, this
//   list of conditions and the following disclaimer in the documentation and/or
//   other materials provided with the distribution.
//
// * Neither the name of the University of Minnesota, Brown University, nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
// ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//========================================================================

/**
   \author     Daniel Keefe (dfk)
   \maintainer Daniel Keefe (dfk)
   
   \created 2004-01-28
   \edited  2004-01-28
   
   \file  VRPNButtonDevice.H
   
   \brief A driver that connects to VRPN and creates Events
          based on button data from VRPN.
*/

#ifndef VRPNBUTTONDEVICE_H
#define VRPNBUTTONDEVICE_H

// Note: This include ordering is important, don't screw with it!
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

#include "MVRCore/AbstractInputDevice.H"
#include "MVRCore/ConfigMap.H"

#include <boost/log/trivial.hpp>
#define BOOST_ASSERT_MSG_OSTREAM std::cout
#include <boost/assert.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/attributes/constant.hpp>

#ifdef USE_VRPN
class vrpn_Button_Remote;
#endif

namespace MinVR {

/**
*/
class InputDeviceVRPNButton : public AbstractInputDevice
{
public:
#ifdef USE_VRPN
	InputDeviceVRPNButton(const std::string &vrpnButtonDeviceName, const std::vector<std::string> &eventsToGenerate);
	InputDeviceVRPNButton(const std::string name, const ConfigMapRef map);

	virtual ~InputDeviceVRPNButton();

	void pollForInput(std::vector<EventRef> &events);

	std::string getEventName(int buttonNumber);
	void sendEvent(int buttonNumber, bool down, const boost::posix_time::ptime &msg_time);

private:
	vrpn_Button_Remote  *_vrpnDevice;
	std::vector<std::string>   _eventNames;
	std::vector<EventRef>      _pendingEvents;
#else
	InputDeviceVRPNButton(const std::string &vrpnButtonDeviceName, const std::vector<std::string> &eventsToGenerate)
	{
		BOOST_ASSERT_MSG(false, "VRPN is currently unsupported. Set cmake option USE_VRPN to ON and recompile.");
	}
	InputDeviceVRPNButton(const std::string name, const ConfigMapRef map)
	{
		BOOST_ASSERT_MSG(false, "VRPN is currently unsupported. Set cmake option USE_VRPN to ON and recompile.");
	}

	virtual ~InputDeviceVRPNButton() {}
	void pollForInput(std::vector<EventRef> &events) {}
#endif // USE_VRPN defined
};

} // end namespace

#endif




