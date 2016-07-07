/***********************************************************************
BBASEINPUTSYSTEM


***********************************************************************/

#ifndef BBASEINPUTSYSTEM_H
#define BBASEINPUTSYSTEM_H

namespace BEngine 
{
	class CIBaseInputSystem 
	{
		public:
			CIBaseInputSystem() {}
			virtual ~CIBaseInputSystem() {}

			virtual bool initialize() = 0;
			virtual void shutdown() = 0;
			
		protected:
		
		private:
		
	};
} //namespace BEngine

#endif //BBASEINPUTSYSTEM_H