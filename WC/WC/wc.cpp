#include<iostream>
#include"wc.h"
using namespace std;

int main(int argc, char* argv[])
{

	CommandInfo commandInfo=CommandInput(argc,++argv);	//1.��ָ��
	ErrorMessage(commandInfo);

	file File;											//2.ѡ���ļ�
	commandInfo.filePath=File.GetFilePathByGUI(commandInfo);
	ErrorMessage(commandInfo);

	function Function=function(commandInfo);
	FileMessage(commandInfo,Function);
	system("pause");
	return 0;
}

void ErrorMessage(CommandInfo commandInfo)
{
	if (commandInfo.isError)
	{
		if (commandInfo.errorType == commandError)
		{
			cout << "����ָ�����" << endl;
			exit(-1);
		}
		if (commandInfo.errorType == fileError)
		{
			cout << "ѡ���ļ�����" << endl;
			exit(-1);
		}
		
	}
}

void FileMessage(CommandInfo commandInfo, function Function)
{
	CommandType commandType = commandInfo.commandType;
	DLC dlc = Function.DlcCount();
	if (commandType.c)
	{
		cout << "�ַ���: \t" << Function.CharacterCount() << endl;
	}
	if (commandType.w)
	{
		cout << "������: \t" << Function.WordCount() << endl;
	}
	if (commandType.l)
	{
		cout << "����: \t" << Function.LineCount() << endl;
	}
	if (commandType.a)
	{
		cout << "������: \t" << dlc.nullLine << endl;
		cout << "��������: \t" << dlc.codeLine << endl;
		cout << "ע������: \t" << dlc.noteLine << endl;
	}
}
