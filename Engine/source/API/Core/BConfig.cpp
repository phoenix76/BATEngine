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
		m_configurationFile = new pugi::xml_document();
		auto result = m_configurationFile->load_file(CONFIG_FILE_NAME);
		if (result.status == pugi::xml_parse_status::status_ok)
		{
			//Get "engine" node from the xml file.
			auto engineNode = m_configurationFile->child("Engine");

			//Get child node WindowParam
			auto windowParamNode = engineNode.child("WindowParam");
			m_windowParameters.fullScreen = windowParamNode.attribute("fullScreen").as_bool();
			m_windowParameters.width = windowParamNode.child("Size").attribute("width").as_int();
			m_windowParameters.height = windowParamNode.child("Size").attribute("height").as_int();

			//Get child node Paths
			auto pathsNode = engineNode.child("Paths");
			m_enginePaths.modelsFolderPath = pathsNode.child("Models").attribute("path").as_string();
			m_enginePaths.texturesFolderPath = pathsNode.child("Textures").attribute("path").as_string();
		}
		else
		{
			// ****** TODO: Add log here that the configuration file couldn't be read.
			exit(0);
		}
	}	
	bool CBConfig::saveConfig() const
	{
		std::lock_guard<std::mutex> guard(m_saveConfigMutex);
		if (m_configurationFile != nullptr) {
			return m_configurationFile->save_file(CONFIG_FILE_NAME);
		} else {
			return false;
		}
	}
	bool CBConfig::saveConfig(const char* fileName) const
	{
		std::lock_guard<std::mutex> guard(m_saveConfigMutex);
		if (m_configurationFile != nullptr) {
			return m_configurationFile->save_file(fileName);
		} else {
			return false;
		}
	}
	bool CBConfig::saveConfig(const BString& fileName) const
	{
		std::lock_guard<std::mutex> guard(m_saveConfigMutex);
		if (m_configurationFile != nullptr) {
			return m_configurationFile->save_file(&fileName[0]);
		} else {
			return false;
		}
	}
	//-----------------------------------------------------------------------
	//Here start get methods.
	//-----------------------------------------------------------------------
	const SWindowParameters& CBConfig::getWindowParameters() const
	{
		std::lock_guard<std::mutex> guard(m_windowParametersMutex);
		return m_windowParameters;
	}
	const SEnginePaths & CBConfig::getEnginePaths() const
	{
		std::lock_guard<std::mutex> guard(m_enginePathsMutex);
		return m_enginePaths;
	}
	//-----------------------------------------------------------------------
	//Here start set methods.
	//-----------------------------------------------------------------------
	void CBConfig::setWindowParameters(const SWindowParameters& params)
	{
		std::lock_guard<std::mutex> guard(m_windowParametersMutex);
		m_windowParameters = params;
	}
	void CBConfig::setEnginePaths(const SEnginePaths& params)
	{
		std::lock_guard<std::mutex> guard(m_enginePathsMutex);
		m_enginePaths = params;
	}
} //namespace BEngine
