#include "BWindowsInput.h"
#include <string>

namespace BEngine
{

	bool CWindowsInput::initialize()
	{
		for(int key = 0; key <= 109; key++)
		{
			if(HIWORD(GetAsyncKeyState(key)))
				m_keys.push_back(SKeyContainer(static_cast<EKeyId>(key), EKeyState::KEY_STATE_PRESSED));
			else
				m_keys.push_back(SKeyContainer(static_cast<EKeyId>(key), EKeyState::KEY_STATE_RELEASED));
		}
		return true;
	}

	void CWindowsInput::receiveKeyEvent(const SKeyEvent& ev)
	{
		if(ev.eventType == EKeyEventType::INPUT_EVENT_TYPE_PRESS) //Key down
		{
			if(!(m_keys[static_cast<int>(ev.id)] == ev))
				m_keys[static_cast<int>(ev.id)] = ev;
			// ****** TODO: Here must be SendMessage method
			MessageBoxA(NULL, std::to_string(static_cast<int>(ev.id)).c_str(), "KEYDOWN", MB_OK);
		}
		else if(ev.eventType == EKeyEventType::INPUT_EVENT_TYPE_RELEASE) //Key up
		{
			if(!(m_keys[static_cast<int>(ev.id)] == ev))
				m_keys[static_cast<int>(ev.id)] = ev;
			// ****** TODO: Here must be SendMessage method
		}
	}

}