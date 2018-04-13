#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "./lib_util/util_system.h"

using namespace std;


void renameFiles(
		const char* path,
		const char* fileType,
		const char* preFix)
{
	vector<string> fileNames;

	getFiles(path, fileType, fileNames);

	for( size_t i = 0; i < fileNames.size(); i++)
	{
		char newName[1024];
		char cmdStr[2048];

		sprintf(newName, "%s/%s_%d%s", path, preFix, (int)i, fileType);
		sprintf(cmdStr, "mv \"%s\" \"%s\" ", fileNames[i].c_str(), newName);

		system(cmdStr);
	}

}

void help()
{
	printf("\n");
	printf("Usage: \n");
	printf("    renameFiles  filePath  fileType  preFix \n");
	printf("example: \n");
	printf("    renameFiles  ~/imgs  .bmp  pos_ \n");
}

int main(int argc, char** argv)
{

#if 1
	if(argc < 4)
	{
		help();
		return -1;
	}

	const char* path     = argv[1];
	const char* fileType = argv[2];
	const char* preFix   = argv[3];
#else
	const char* path     = "/home/sean/Projects/TrainDetector/img_cable20K_fast/bg";
	const char* fileType = ".png";
	const char* preFix   = "bg";
#endif

	renameFiles(
			path,
			fileType,
			preFix);

	return 0;

}
