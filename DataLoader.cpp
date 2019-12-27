#include "PCH.h"
#include "DataLoader.h"



DataLoader::DataLoader()
{
}


DataLoader::~DataLoader()
{
}

map<string, vector<std::pair<string, string>>> DataLoader::LoadDataFromFolder(vector<string> folders_name)
{
	m_dataMap.clear();
	
	for (auto const& value : folders_name) {
		string base_name = value + "/";
		string folderName = value.substr(value.find_last_of("/\\") + 1);

		vector<std::pair<string, string>>& labelImagePairList = m_dataMap[folderName];
		
		SearchDir(base_name.c_str(), folderName, 0, [&labelImagePairList](const string& path, const string& folderName, dirent* entry) {
			string dataPath = path + entry->d_name;

			labelImagePairList.push_back(std::make_pair(folderName, dataPath));
		});
	}

	return m_dataMap;
}