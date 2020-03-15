#include"CommandProcess.h"

CommandInfo CommandInput(int commandNum,char* command[])
{
	int i = 0;
	CommandInfo commandInfo;
	while (command[i] != NULL)
	{
		if (command[i][0] == '-')
		{
			switch (command[i][1])
			{
			case 'c':

				commandInfo.commandType.c = true;
				++i;
				break;
			case 'w':
				commandInfo.commandType.w = true;
				++i;
				break;
			case 'l':
				commandInfo.commandType.l = true;
				++i;
				break;
			case'a':
				commandInfo.commandType.a = true;
				++i;
				break;
			case'x':
				commandInfo.commandType.x = true;
				++i;
				break;
			default:
				commandInfo.HasError(commandError);
				++i;
				break;
			}

		}
		else
		{
			ifstream file;
			file.open(command[i], ios::in);
			if (!file.is_open())
			{
				commandInfo.HasError(fileError);
				break;
			}
			else
			{
				commandInfo.filePath = command[i];
				break;
			}
			commandInfo.HasError(commandError);
			break;
		}
	}
	return commandInfo;
}
