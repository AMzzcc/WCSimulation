#include "FileProcess.h"
using namespace std;

string file::GetFilePathByGUI(CommandInfo commandInfo)
{
	string filePath = getFilePathByGUI().GetBuffer(0);
	ifstream file;
	file.open(filePath, ios::in);
	if (!file.is_open())
	{
		commandInfo.HasError(fileError);
		exit(-1);
	}
	file.close();
	return filePath;
}

CString file::getFilePathByGUI()
{
	CString path;
	OPENFILENAME open;// �����Ի���ṹ��
	char file[MAX_PATH];// ���������ȡ�ļ����ƵĻ������� 
	ZeroMemory(&open, sizeof(OPENFILENAME)); // ��ʼ��ѡ���ļ��Ի���
	open.lStructSize = sizeof(OPENFILENAME);//ָ������ṹ�Ĵ�С�����ֽ�Ϊ��λ��
	open.lpstrFile = file;//�򿪵��ļ���ȫ·��
	open.lpstrTitle = "ѡ���ļ�";//���ڵı���
	open.lpstrFile[0] = '\0'; //��һ���ַ����ǹ�������������ʾ�ַ���
	open.nMaxFile = MAX_PATH;  //ָ��lpstrFile����Ĵ�С����TCHARsΪ��λ
	open.lpstrFilter = "�ı��ļ�(*.txt)\0*.txt\0�����ļ�(*.*)\0*.*\0\0";  //���ļ�����
	open.nFilterIndex = 1;  //ָ�����ļ����Ϳؼ��е�ǰѡ��Ĺ�����������
	open.lpstrFileTitle = NULL; // ָ�����ѡ����ļ����ļ�������չ���Ļ��壨����·����Ϣ���������Ա������NULL��
	open.nMaxFileTitle = 0;  //ָ��lpstrFileTitle����Ĵ�С����TCHARsΪ��λ
	open.lpstrInitialDir = NULL;  //ָ���Կ��ַ��������ַ���������������ַ�����ָ����ʼĿ¼��
	open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;//λ��ǵ����ã������ʹ������ʼ���Ի���
	if (GetOpenFileName(&open))  // ��ʾ��ѡ���ļ��Ի���  
	{
		path = file;
		cout<<path + "\n";
	}
	return path;
}
