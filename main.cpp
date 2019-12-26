#include "PCH.h"
#include "DataLoader.h"

int main() {
	DataLoader dataLoader;

	vector<string> folderList = { "D:/development/CNN-CatClassificationCPP/data/TRAIN", "D:/development/CNN-CatClassificationCPP/data/VAL" };
	dataLoader.LoadDataFromFolder(folderList);


}