/***********************************************************************
BIOTYPES


***********************************************************************/

#ifndef BIOTYPES_H
#define BIOTYPES_H

#include "../Core/include/BVariables.h"

namespace BEngine 
{
	
	struct SWindowSizeParameters
	{
		uint32 windowWidth;
		uint32 windowHeiht;
		uint32 clientWidth;
		uint32 clientHeigth;
	};

	struct SKeyEvent
	{

	};

	enum class EElementState
	{
		INPUT_EVENT_STATE_UP,
		INPUT_EVENT_STATE_DOWN
	};
	typedef EElementState EKeyEventType, EMouseEventState;


	enum class EKeyId
	{
		KEY_Escape = 1,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_0,
		KEY_Minus,
		KEY_Equals,
		KEY_Backspace,
		KEY_Tab,
		KEY_Q,
		KEY_W,
		KEY_E,
		KEY_R,
		KEY_T,
		KEY_Y,
		KEY_U,
		KEY_I,
		KEY_O,
		KEY_P,
		KEY_LBracket,
		KEY_RBracket,
		KEY_Enter,
		KEY_LCtrl,
		KEY_A,
		KEY_S,
		KEY_D,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_Semicolon,
		KEY_Apostrophe,
		KEY_Tilde,
		KEY_LShift,
		KEY_Backslash,
		KEY_Z,
		KEY_X,
		KEY_C,
		KEY_V,
		KEY_B,
		KEY_N,
		KEY_M,
		KEY_Comma,
		KEY_Period,
		KEY_Slash,
		KEY_RShift,
		KEY_NP_Multiply,
		KEY_LAlt,
		KEY_Space,
		KEY_CapsLock,
		KEY_F1,
		KEY_F2,
		KEY_F3,
		KEY_F4,
		KEY_F5,
		KEY_F6,
		KEY_F7,
		KEY_F8,
		KEY_F9,
		KEY_F10,
		KEY_NumLock,
		KEY_ScrollLock,
		KEY_NP_7,
		KEY_NP_8,
		KEY_NP_9,
		KEY_NP_Substract,
		KEY_NP_4,
		KEY_NP_5,
		KEY_NP_6,
		KEY_NP_Add,
		KEY_NP_1,
		KEY_NP_2,
		KEY_NP_3,
		KEY_NP_0,
		KEY_F11,
		KEY_F12,
		KEY_F13,
		KEY_F14,
		KEY_F15,
		KEY_Colon,
		KEY_Underline,
		KEY_NP_Enter,
		KEY_RCtrl,
		KEY_NP_Period,
		KEY_NP_Divide,
		KEY_Print,
		KEY_RAlt,
		KEY_Pause,
		KEY_Home,
		KEY_Up,
		KEY_PgUp,
		KEY_Left,
		KEY_Right,
		KEY_End,
		KEY_Down,
		KEY_PgDn,
		KEY_Insert,
		KEY_Delete,
		KEY_LWin,
		KEY_RWin,
		KEY_Apps,
		KEY_OEM_102,
	};

} //namespace BEngine

#endif //BIOTYPES_H