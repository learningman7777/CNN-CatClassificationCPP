#include "PCH.h"
#include "DataLoader.h"



DataLoader::DataLoader()
{
}


DataLoader::~DataLoader()
{
}

std::pair<vector<string>, vector<string>> DataLoader::LoadDataFromFolder(vector<string> folders_name)
{
	vector<string> list_images;
	vector<string> list_labels;
	int indent = 0;
	int label = 0;
	for (auto const& value : folders_name) {
		
		string base_name = value + "/";
		string folderName;
		SearchDir(base_name.c_str(), folderName, 0, [&list_labels, &list_images](const string& path, const string& folderName, dirent* entry) {
			string dataPath = path + entry->d_name;
			list_images.push_back(dataPath);
			list_labels.push_back(folderName);
		});
	}

	return std::make_pair(list_images, list_labels);
}