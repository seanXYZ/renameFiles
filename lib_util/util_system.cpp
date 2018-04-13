/*
 * util_system.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: sean
 */

#include "util_system.h"

#if __linux__
#include <unistd.h>
#include <dirent.h>

void getFiles(
		const char* path,
		const char* fileMode,
		std::vector<std::string> &files)
{
	DIR *dir = NULL;
	struct dirent * ptr = NULL;
	files.clear();
	dir = opendir(path);
	if( NULL == dir)
		return;

	while ((ptr=readdir(dir)) != NULL)
	{
		char temp[1024];

		if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
		{
			continue;
		}
		else if(ptr->d_type == 8)    ///file
		{
			sprintf(temp, "%s/%s",path,ptr->d_name);
			std::string  str = std::string(temp, 0, strlen(temp) + 1);
//			printf("%s\n", str.c_str());
			int idx = str.find(fileMode, strlen(temp)- strlen(fileMode));

			if(idx > 0)
			{
				files.push_back(str);
			}
		}
		else if(ptr->d_type == 10)    ///link file
		{
			sprintf(temp, "%s/%s",path,ptr->d_name);
		}
		else if(ptr->d_type == 4)    ///dir
		{
			sprintf(temp, "%s/%s",path,ptr->d_name);
//			readFileList(base);
		}
	}

	closedir(dir);
}

#endif

#if (defined __WIN32)  || (defined __WIN64)
void getFiles(
		const char* path,
		const char* fileMode,
		std::vector<std::string> &files)
{
	// TODO
}

#endif

