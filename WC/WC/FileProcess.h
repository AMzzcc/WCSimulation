#pragma once
#include<iostream>
#include<fstream>
#include <windows.h>
#include <ShlObj.h>
#include <stdio.h>
#include <stdlib.h>
#include <atlstr.h>
#include"CommandProcess.h"
using namespace std;
class file
{
public:
	string GetFilePathByGUI(CommandInfo commandInfo);
	//��ȡ�ļ�������ļ���ȷ��

private:
	CString getFilePathByGUI();
	//����OPENFILENAME�Ի���
};


