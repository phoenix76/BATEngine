/***********************************************************************
CONFIG

IMPORTANT THIS CLASS MUST BE INITIALISED BEFORE OTHER ENGINE COMPONENTS
ARE INITIALISED !!! THE ONLY EXCEOTION IS THE LOGGER CLASS!

TO INITIALISE BCONFIG JUST CALL: CBConfig::getInstnace();

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

#include <mutex>

#include "include/BStringUtils.h"

//Pugi XML document class forward declaration
namespace pugi { class xml_document; }

static const char* CONFIG_FILE_NAME = "..\\..\\config.xml";

// ****** TODO: If failed to initialize add Log Write: failed to load config.xml file.
namespace BEngine 
{
	// ****** TODO: Consider these structure and enum objects that will be added
	//here to move them to the separate header file as there will be a lot of them.

	struct SWindowParameters 
	{
		bool fullScreen;
		int width;
		int height;
	};

	struct SEnginePaths
	{
		BString modelsFolderPath;
		BString texturesFolderPath;
	};

	//-----------------------------------------------------------------------
	//CBConfig Class
	//
	//IMPORTANT THIS CLASS MUST BE INITIALISED BEFORE OTHER ENGINE COMPONENTS
	//ARE INITIALISED !!! THE ONLY EXCEPTION IS THE LOGGER CLASS!
	//TO INITIALISE BCONFIG JUST CALL: CBConfig::getInstnace();
	//For more detailed description see file header.
	//-----------------------------------------------------------------------
	class CBConfig 
	{
		public:
			static CBConfig& getInstance() 
			{
				static CBConfig cInstance;
				return cInstance;
			}

			bool saveConfig() const;
			bool saveConfig(const char* fileName) const;
			bool saveConfig(const BString& fileName) const;

			//Get methods
			const SWindowParameters& getWindowParameters() const;
			const SEnginePaths& getEnginePaths() const;

			//Set methods, note even if you set any parameters
			//you still have got to overwrite the configuration file.
			// ****** TODO: Think how the set parameters will be applied to the engine, either create a new method
			//void applyParameters() or restart the engine so the new parameters could be applied.
			void setWindowParameters(const SWindowParameters&);
			void setEnginePaths(const SEnginePaths&);
			
		private:
			CBConfig();
			~CBConfig(){};
			CBConfig(const CBConfig&) {};
			CBConfig& operator=(const CBConfig&) {};

			void m_loadConfigXMLFile();

			pugi::xml_document* m_configurationFile;
			mutable std::mutex m_saveConfigMutex;

			//Configuration structures and their respective lockers
			SWindowParameters m_windowParameters;
			SEnginePaths m_enginePaths;

			mutable std::mutex m_windowParametersMutex;
			mutable std::mutex m_enginePathsMutex;
	};
	typedef CBConfig BConfig;
} //namespace BEngine
#endif //CBCONFIG_H
