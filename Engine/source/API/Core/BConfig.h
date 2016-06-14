/***********************************************************************
CONFIG

This class will be responsible for working with config.xml file.
Currently at prototype state, mutexes are required for multi-threading
synchronizations. If mutexes will be used it is important to note that 
it is important not to call getXInfo() too often, but for example each
engine core system manager could get configuration info once, 
and possibly update it if settings are changed, this way there won't be
too much of over-head.
If any settings are changed then saveMethod needs to be called.
***********************************************************************/

#ifndef CBCONFIG_H
#define CBCONFIG_H


namespace pugi
{
	class xml_document;
}

namespace BEngine 
{
	class CBConfig 
	{
		public:
			static CBConfig& getInstance() 
			{
				static CBConfig cInstance;
				return cInstance;
			}
			
		private:
			CBConfig();
			~CBConfig(){};
			CBConfig(const CBConfig&); // Prevent construction by copying
    		CBConfig& operator=(const CBConfig&); // Prevent assignment

			void m_loadConfigXMLFile();

			pugi::xml_document* m_configFile;
	};
} //namespace BEngine
#endif //CBCONFIG_H


