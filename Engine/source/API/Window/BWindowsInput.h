/***********************************************************************
BWINDOWSINPUT


***********************************************************************/

#ifndef BWINDOWSINPUT_H
#define BWINDOWSINPUT_H

#include "../Core/BContainers.h"
#include "BBaseInput.h"
#include "BIOTypes.h"

namespace BEngine 
{
	class CWindowsInput : public CIBaseInputSystem
	{
	public:
		CWindowsInput() {}
		~CWindowsInput() {}

		bool initialize();
		void shutdown() { return; }

		void receiveKeyEvent(const SKeyEvent& ev);
		void receiveMouseButtonEvent(const SMouseButtonEvent& ev);
		void receiveNewCursorCoordinates(uint32 x, uint32 y);
		void receiveMouseDeltaWheel(int32 wheelValue);

	private:
		bvector<SKeyContainer> m_keys;
		bvector<SMouseButtonContainer> m_mouseButtons;

	};
} //namespace BEngine

#endif //BWINDOWSINPUT_H