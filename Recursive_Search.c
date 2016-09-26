//NAPOMENA\\ Obavezno koristit \\ u putanji i na kraju putanje \\*  <<PRIMJER>> --> C:\\Users\\Korisnik\\Pictures\\*
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void recu_dir_fil();
 
int main()
{
	char start_path[MAX_PATH] = "E:\\PROGRAMMING\\C++\\LAN_spy_GUI\\*";

	recu_dir_fil(start_path);
}

void recu_dir_fil(char* p)
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
			recu_dir_fil(strcat(strcat(strcat(strtok(path, "*"), findfiledata.cFileName), "\\"), "*"));
			strcpy(path, p);
		}

		if(!(findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			printf("%s\n",findfiledata.cFileName);
		}
	}
		
}




//void recu_dir_fil(char* pp)
//{
//	char path[MAX_PATH];
//	WIN32_FIND_DATAA findfiledata;
//	HANDLE hFind = INVALID_HANDLE_VALUE;
//
//	strcpy(path, pp);
//	strcat(path, "*");
//	
//	if((hFind = FindFirstFileA(path, &findfiledata)) == INVALID_HANDLE_VALUE)
//	{
//		printf ("FindFirstFile failed (%d) \n", GetLastError());
//	}
//	
//	if(strchr(findfiledata.cFileName, '.') != NULL) 
//		{
//			FindNextFileA(hFind, &findfiledata);
//			printf("%s\n",findfiledata.cFileName);				
//			FindNextFileA(hFind, &findfiledata);
//			if(findfiledata.dwFileAttributes == 38)
//				FindNextFileA(hFind, &findfiledata);
//		} 
//
//	if(findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//	{
//		strcat(pp, findfiledata.cFileName);
//		strcat(pp, "\\");
//		printf("%s\n",findfiledata.cFileName);
//		recu_dir_fil(pp);
//		strcpy(pp, path);
//	}
//	else
//	{
//		printf("%s\n",findfiledata.cFileName);
//		while(FindNextFileA(hFind, &findfiledata) != 0)
//		{
//			if(findfiledata.dwFileAttributes == 38)
//				FindNextFileA(hFind, &findfiledata);
//			printf("%s\n",findfiledata.cFileName);
//			if(findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//				{
//					strtok(path, "*");
//					recu_dir_fil(strcat(strcat(path, findfiledata.cFileName), "\\"));
//					strcpy(path, pp);
//				}
//		}
//	}
//
//	
//
//	FindClose(hFind);
//	return;
//}