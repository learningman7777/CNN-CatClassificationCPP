#pragma once

#include "PCH.h"


class DataLoader
{
public:
	DataLoader();
	~DataLoader();

	map<string, vector<std::pair<string, string>>> LoadDataFromFolder(vector<string> folders_name);

	template <typename DirLambdaFunction>
	void SearchDir(const string& name, const string& folderName, int depth, DirLambdaFunction&& dirFunction);

private:
	map<string, vector<std::pair<string, string>>> m_dataMap;
};

template<typename DirLambdaFunction>
inline void DataLoader::SearchDir(const string& name, const string& folderName, int depth, DirLambdaFunction&& dirFunction)
{
	DIR* dir;
	struct dirent* entry;

	if (!(dir = opendir(name.c_str())))
		return;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_DIR) {

			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;

			string path = name;
			string d_name = entry->d_name;
			path += "/";
			path += d_name;

			SearchDir(path, d_name, depth+1, dirFunction);
		}
		else {
			dirFunction(name, folderName, entry);
		}
	}
	closedir(dir);
}
