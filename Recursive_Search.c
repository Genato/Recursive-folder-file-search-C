/* PATH Example --> C:\\Users\\Korisnik\\Pictures\\*  */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void RecursiveFileSearch();
 
int main()
{
	char start_path[MAX_PATH] = "E:\\PROGRAMMING\\C++\\LAN_spy_GUI\\*";

	RecursiveFileSearch(start_path);
}

void RecursiveFileSearch(char* p)
{
	char path[MAX_PATH];
	WIN32_FIND_DATAA findfiledata;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	strcpy(path, p);

	if((hFind = FindFirstFileA(path, &findfiledata)) == INVALID_HANDLE_VALUE)
	{
		printf ("FindFirstFile failed (%d) \n", GetLastError());
	}

	if(strchr(findfiledata.cFileName, '.')) 
	{
		FindNextFileA(hFind, &findfiledata);
	}

	while(FindNextFileA(hFind, &findfiledata))
	{
		if(findfiledata.dwFileAttributes == 38)
			FindNextFileA(hFind, &findfiledata);

		if(findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			printf("%s\n",findfiledata.cFileName);
			RecursiveFileSearch(strcat(strcat(strcat(strtok(path, "*"), findfiledata.cFileName), "\\"), "*"));
			strcpy(path, p);
		}

		if(!(findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			printf("%s\n",findfiledata.cFileName);
		}
	}
		
}
