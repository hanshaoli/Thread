// file1.cp// filetest2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "saomiao.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include   "afx.h "
#include   "afxtempl.h "
#include "windows.h"
#include <vector>
#include <algorithm>
#include   <iostream>
using namespace std;
int total=0;
class   Myfile
{
public:
	ULONGLONG  len;
	CString filename;
	//重载==
	bool operator==( const Myfile& objstruct)
	{
		return objstruct.len==len;
	}
	//重载<
	bool operator<(const Myfile& objstruct)
	{
		return len<objstruct.len;
	}
	//重载>
	bool operator>(const Myfile& objstuct) const
	{
		return len>objstuct.len;
	}
};

vector<Myfile> vect;
ULONGLONG totalBytes=0;
void Recurse(LPCTSTR pstr)
{
	CFileFind finder;
	CString strWildcard(pstr);
	strWildcard += _T("\\*.*");
	BOOL bWorking = finder.FindFile(strWildcard);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if (finder.IsDots())
			continue;
		
		if(finder.IsDirectory()){
			
			CString str=finder.GetFilePath();
			str+=_T("\\");
			Recurse(str);
		}
		else{
			if (finder.IsCompressed())
			{
				total++;
			}
			CString sFileName = finder.GetFileName();
            printf("%I64d",totalBytes);
             printf("%S",sFileName);
			totalBytes+=finder.GetLength();
            printf("%I64d",totalBytes);
// 			printf("%I64d",totalBytes/1024/1024);
// 			
//             printf("%d",(int)(totalBytes/1024/1024));
			cout<<endl;
			Myfile my;
			my.len=finder.GetLength();
			my.filename=sFileName;
			vect.push_back(my);
		}
	}
	finder.Close();
}

void Recurse1(LPCTSTR pstr)
{
	CFileFind finder;
	CString strWildcard(pstr);
	strWildcard += _T("\\*.*");
	BOOL bWorking = finder.FindFile(strWildcard);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if (finder.IsDots())
			continue;

		if(finder.IsDirectory()){
            // ++total;
			CString str=finder.GetFilePath();
			str+=_T("\\");
			Recurse1(str);
		}
	}
	finder.Close();
}

struct Bb
{
	ULONGLONG  len;
	CString filename;
	bool operator <(const Bb& my)
	{
		return len<my.len;
	}

};
void main()
{   
//    cout<<vect.max_size();
// 	Recurse(_T("H:"));
// 	printf("---------");
// 	printf("%d",total);
//      printf("---------");
// 	printf("%I64d",totalBytes);
// 	printf("---------");
// 	printf("%d",(int)(totalBytes/1024/1024/1024));

// 	
// 	sort(vect.begin(),vect.end()); //排序
// 
// 	for(vector<Myfile>::iterator it=vect.begin();it!=vect.end();++it)
// 	{  
// 		printf("%S",it->filename);
// 		cout<<"该文件大小为：";
// 		printf("%u",it->len);
// 		cout<<endl;
// 
// 		  
// 
// 	}

// 	vector<Bb> vs;
// 	for (int i=150000;i>0;i--)
// 	{
// 		Bb bb;
// 		bb.len=i;
// 		bb.filename="cc";
// 		vs.push_back(bb);
// 	}
//     sort(vs.begin(),vs.end()); 
// 	for(vector<Bb>::iterator it=vs.begin();it!=vs.end();++it)
// 	{  
// 		printf("%S",it->filename);
// 		cout<<"该文件大小为：";
// 		printf("%u",it->len);
// 		cout<<endl;
    

//     printf("%I64d",totalBytes);

	DWORDLONG qwFreeBytesToCaller,qwTotalBytes,qwFreeBytes;
  
  	BOOL bResult;
  	bResult=GetDiskFreeSpaceEx(_T("H:"),
  		(PULARGE_INTEGER)&qwFreeBytesToCaller,
  		(PULARGE_INTEGER)&qwTotalBytes,
  
  		(PULARGE_INTEGER)&qwFreeBytes);
//   	INT64 c=(int)(qwTotalBytes/1024-qwFreeBytes/1024);
   double bb;
  	if(bResult)
  	{
  		printf("使用GetDiskFreeSpaceEx获取磁盘空间信息\n");
  		printf("%I64d",qwFreeBytesToCaller);
  		cout<<endl;
  	    printf("%I64d",qwFreeBytes);
  		cout<<endl;
  		printf("%I64d",qwTotalBytes);
  		cout<<endl;
  		printf("%I64d",qwTotalBytes-qwFreeBytes);
  		cout<<endl;
  		printf("%d",(int)((qwTotalBytes-qwFreeBytesToCaller)/1024/1024/1024));
  	}
    
// 	cout<<"---";
// 	bb=(double)(qwTotalBytes-qwFreeBytes);
//      printf("%f",bb);
// 
	Recurse(_T("C:"));

  	printf("%d",total);
	

 // printf("%f",199.00/100.00);



}


