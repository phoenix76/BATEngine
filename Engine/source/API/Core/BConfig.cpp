#include "BConfig.h"
#include "pugixml.hpp"

namespace BEngine
{
	CBConfig::CBConfig() 
	{
		m_loadConfigXMLFile();
	}
	void CBConfig::m_loadConfigXMLFile()
	{
		m_configFile = new pugi::xml_document();
		auto result = m_configFile->load_file("config.xml");
		if (result == pugi::status_ok)
		{

		}
		else
		{
			//
			exit(0);
		}
	}
} //namespace BEngine
