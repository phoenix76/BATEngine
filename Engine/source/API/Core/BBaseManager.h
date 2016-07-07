/***********************************************************************
BBASEMANAGER


***********************************************************************/

#ifndef BBASEMANAGER_H
#define BBASEMANAGER_H

namespace BEngine 
{
	class CIBaseManager 
	{
		public:
			CIBaseManager() {}
			virtual ~CIBaseManager() {}

			virtual bool initialize() = 0;
			virtual void update() = 0;
			virtual void shutdown() = 0;
			
		protected:
		
		private:
		
	};
} //namespace BEngine

#endif //BBASEMANAGER_H